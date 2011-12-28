/* 
 * Copyright (c) 2003, 2004 Jean-Yves Lefort <jylefort@brutele.be>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include "config.h"
#include <glib/gi18n-lib.h>
#include "mn-mailbox-properties-dialog.h"
#include "mn-mailbox-properties.h"
#include "mn-autodetect-mailbox-properties.h"
#include "mn-system-mailbox-properties.h"
#ifdef WITH_POP3
#include "mn-pop3-mailbox-properties.h"
#endif
#ifdef WITH_IMAP
#include "mn-imap-mailbox-properties.h"
#endif
#ifdef WITH_GMAIL
#include "mn-gmail-mailbox-properties.h"
#endif
#include "mn-conf.h"
#include "mn-util.h"
#include "mn-uri.h"
#include "mn-stock.h"

/*** types *******************************************************************/

typedef struct
{
  GtkWidget				*mailbox_type_label;
  GtkWidget				*mailbox_type_combo;
  GtkWidget				*properties_event_box;
  
  MNMailboxPropertiesDialogMode		mode;
  char					*uri;
  GtkWidget				*apply_button;
  GtkWidget				*accept_button;
  GtkListStore				*store;
} Private;

enum {
  COLUMN_PROPERTIES,
  COLUMN_TEXT,
  N_COLUMNS
};
    
/*** variables ***************************************************************/

static GType selected_type = 0;

/*** functions ***************************************************************/

static void mn_mailbox_properties_dialog_private_free (Private *private);

static void mn_mailbox_properties_dialog_add_type (MNMailboxPropertiesDialog *dialog,
						   GType properties_type);

static void mn_mailbox_properties_dialog_select_properties (MNMailboxPropertiesDialog *dialog);
static void mn_mailbox_properties_dialog_set_active_properties (MNMailboxPropertiesDialog *dialog, MNMailboxProperties *properties);
static MNMailboxProperties *mn_mailbox_properties_dialog_get_active_properties (MNMailboxPropertiesDialog *dialog);
static MNMailboxProperties *mn_mailbox_properties_dialog_get_properties_by_type (MNMailboxPropertiesDialog *dialog, GType type);

static void mn_mailbox_properties_dialog_set_uri_internal (MNMailboxPropertiesDialog *dialog, const char *uri);
static void mn_mailbox_properties_dialog_update_sensitivity (MNMailboxPropertiesDialog *dialog);

/*** implementation **********************************************************/

GtkWidget *
mn_mailbox_properties_dialog_new (GtkWindow *parent,
				  MNMailboxPropertiesDialogMode mode)
{
  MNMailboxPropertiesDialog *dialog;
  Private *private;
  GtkCellRenderer *renderer;

  private = g_new0(Private, 1);
  mn_create_interface("mailbox-properties",
		      "dialog", (GtkWidget **) &dialog,
		      "mailbox_type_label", &private->mailbox_type_label,
		      "mailbox_type_combo", &private->mailbox_type_combo,
		      "properties_event_box", &private->properties_event_box,
		      NULL);
  private->mode = mode;

  g_object_set_data_full(G_OBJECT(dialog),
			 MN_MAILBOX_PROPERTIES_DIALOG_PRIVATE_KEY,
			 private,
			 (GDestroyNotify) mn_mailbox_properties_dialog_private_free);

  if (parent)
    gtk_window_set_transient_for(GTK_WINDOW(dialog), parent);

  gtk_dialog_add_button(GTK_DIALOG(dialog), GTK_STOCK_HELP, GTK_RESPONSE_HELP);
  if (mode == MN_MAILBOX_PROPERTIES_DIALOG_MODE_ADD)
    {
      gtk_window_set_title(GTK_WINDOW(dialog), _("Add a Mailbox"));

      gtk_dialog_add_button(GTK_DIALOG(dialog), GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL);
      private->accept_button = gtk_dialog_add_button(GTK_DIALOG(dialog), GTK_STOCK_ADD, GTK_RESPONSE_ACCEPT);
    }
  else if (mode == MN_MAILBOX_PROPERTIES_DIALOG_MODE_EDIT)
    {
      /* title will be set in _set_uri_internal() */

      private->apply_button = gtk_dialog_add_button(GTK_DIALOG(dialog), GTK_STOCK_APPLY, GTK_RESPONSE_APPLY);
      gtk_dialog_add_button(GTK_DIALOG(dialog), GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL);
      private->accept_button = gtk_dialog_add_button(GTK_DIALOG(dialog), GTK_STOCK_OK, GTK_RESPONSE_OK);
    }
  else
    g_return_val_if_reached(NULL);
  gtk_widget_grab_default(private->accept_button);
      
  /* finish the combo box */

  private->store = gtk_list_store_new(N_COLUMNS,
				      GTK_TYPE_WIDGET,
				      G_TYPE_STRING);

  mn_mailbox_properties_dialog_add_type(dialog, MN_TYPE_AUTODETECT_MAILBOX_PROPERTIES);
  mn_mailbox_properties_dialog_add_type(dialog, MN_TYPE_SYSTEM_MAILBOX_PROPERTIES);
#ifdef WITH_POP3
  mn_mailbox_properties_dialog_add_type(dialog, MN_TYPE_POP3_MAILBOX_PROPERTIES);
#endif
#ifdef WITH_IMAP
  mn_mailbox_properties_dialog_add_type(dialog, MN_TYPE_IMAP_MAILBOX_PROPERTIES);
#endif
#ifdef WITH_GMAIL
  mn_mailbox_properties_dialog_add_type(dialog, MN_TYPE_GMAIL_MAILBOX_PROPERTIES);
#endif

  renderer = gtk_cell_renderer_text_new();
  gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(private->mailbox_type_combo), renderer, TRUE);
  gtk_cell_layout_set_attributes(GTK_CELL_LAYOUT(private->mailbox_type_combo), renderer,
				 "markup", COLUMN_TEXT,
				 NULL);

  gtk_combo_box_set_model(GTK_COMBO_BOX(private->mailbox_type_combo), GTK_TREE_MODEL(private->store));

  if (mode == MN_MAILBOX_PROPERTIES_DIALOG_MODE_ADD)
    {
      MNMailboxProperties *properties;

      if (! selected_type)
	selected_type = MN_TYPE_AUTODETECT_MAILBOX_PROPERTIES;

      properties = mn_mailbox_properties_dialog_get_properties_by_type(dialog, selected_type);
      mn_mailbox_properties_dialog_set_active_properties(dialog, properties);
    }

  return GTK_WIDGET(dialog);
}

static void
mn_mailbox_properties_dialog_private_free (Private *private)
{
  g_return_if_fail(private != NULL);

  g_free(private->uri);
  g_object_unref(private->store);
  g_free(private);
}

static void
mn_mailbox_properties_dialog_add_type (MNMailboxPropertiesDialog *dialog,
				       GType properties_type)
{
  Private *private;
  GtkSizeGroup *size_group;
  MNMailboxProperties *properties;
  char *label;
  GtkTreeIter iter;

  g_return_if_fail(MN_IS_MAILBOX_PROPERTIES_DIALOG(dialog));
  private = MN_MAILBOX_PROPERTIES_DIALOG_PRIVATE(dialog);

  size_group = gtk_size_group_new(GTK_SIZE_GROUP_HORIZONTAL);
  properties = g_object_new(properties_type, "size-group", size_group, NULL);
  g_object_unref(size_group);

  g_object_ref(properties);
  gtk_object_sink(GTK_OBJECT(properties));

  gtk_list_store_append(private->store, &iter);

  label = mn_mailbox_properties_get_label(properties);
  gtk_list_store_set(private->store, &iter,
		     COLUMN_PROPERTIES, properties,
		     COLUMN_TEXT, label,
		     -1);
  g_free(label);

  gtk_widget_show(GTK_WIDGET(properties));
  g_signal_connect_swapped(G_OBJECT(properties), "notify::complete", G_CALLBACK(mn_mailbox_properties_dialog_update_sensitivity), dialog);

  g_object_unref(properties);	/* now it belongs to the store */
}

static void
mn_mailbox_properties_dialog_select_properties (MNMailboxPropertiesDialog *dialog)
{
  Private *private;
  MNMailboxProperties *properties;
  GtkSizeGroup *size_group;

  g_return_if_fail(MN_IS_MAILBOX_PROPERTIES_DIALOG(dialog));
  private = MN_MAILBOX_PROPERTIES_DIALOG_PRIVATE(dialog);

  properties = (MNMailboxProperties *) GTK_BIN(private->properties_event_box)->child;
  if (properties)
    {
      size_group = mn_mailbox_properties_get_size_group(properties);
      gtk_size_group_remove_widget(size_group, private->mailbox_type_label);
      gtk_container_remove(GTK_CONTAINER(private->properties_event_box), GTK_WIDGET(properties));
    }
  
  properties = mn_mailbox_properties_dialog_get_active_properties(dialog);
  gtk_container_add(GTK_CONTAINER(private->properties_event_box), GTK_WIDGET(properties));
  size_group = mn_mailbox_properties_get_size_group(properties);
  gtk_size_group_add_widget(size_group, private->mailbox_type_label);

  /* force the dialog to recalculate its size */
  gtk_window_resize(GTK_WINDOW(dialog), 1, 1);
}

static void
mn_mailbox_properties_dialog_set_active_properties (MNMailboxPropertiesDialog *dialog,
						    MNMailboxProperties *properties)
{
  Private *private;
  gboolean valid;
  GtkTreeIter iter;

  g_return_if_fail(MN_IS_MAILBOX_PROPERTIES_DIALOG(dialog));
  g_return_if_fail(MN_IS_MAILBOX_PROPERTIES(properties));
  private = MN_MAILBOX_PROPERTIES_DIALOG_PRIVATE(dialog);

  valid = gtk_tree_model_get_iter_first(GTK_TREE_MODEL(private->store), &iter);
  while (valid)
    {
      MNMailboxProperties *these_properties;

      gtk_tree_model_get(GTK_TREE_MODEL(private->store), &iter, COLUMN_PROPERTIES, &these_properties, -1);
      g_object_unref(these_properties);

      if (these_properties == properties)
	{
	  gtk_combo_box_set_active_iter(GTK_COMBO_BOX(private->mailbox_type_combo), &iter);
	  break;
	}

      valid = gtk_tree_model_iter_next(GTK_TREE_MODEL(private->store), &iter);
    }
}

static MNMailboxProperties *
mn_mailbox_properties_dialog_get_active_properties (MNMailboxPropertiesDialog *dialog)
{
  Private *private;
  GtkTreeIter iter;
  MNMailboxProperties *properties = NULL;

  g_return_val_if_fail(MN_IS_MAILBOX_PROPERTIES_DIALOG(dialog), 0);
  private = MN_MAILBOX_PROPERTIES_DIALOG_PRIVATE(dialog);

  if (gtk_combo_box_get_active_iter(GTK_COMBO_BOX(private->mailbox_type_combo), &iter))
    {
      gtk_tree_model_get(GTK_TREE_MODEL(private->store), &iter, COLUMN_PROPERTIES, &properties, -1);
      g_object_unref(properties);
    }

  return properties;
}

static MNMailboxProperties *
mn_mailbox_properties_dialog_get_properties_by_type (MNMailboxPropertiesDialog *dialog,
						     GType type)
{
  Private *private;
  gboolean valid;
  GtkTreeIter iter;

  g_return_val_if_fail(MN_IS_MAILBOX_PROPERTIES_DIALOG(dialog), NULL);
  private = MN_MAILBOX_PROPERTIES_DIALOG_PRIVATE(dialog);

  valid = gtk_tree_model_get_iter_first(GTK_TREE_MODEL(private->store), &iter);
  while (valid)
    {
      MNMailboxProperties *properties;

      gtk_tree_model_get(GTK_TREE_MODEL(private->store), &iter, COLUMN_PROPERTIES, &properties, -1);
      g_object_unref(properties);

      if (G_TYPE_CHECK_INSTANCE_TYPE(properties, type))
	return properties;

      valid = gtk_tree_model_iter_next(GTK_TREE_MODEL(private->store), &iter);
    }

  return NULL;
}

static void
mn_mailbox_properties_dialog_set_uri_internal (MNMailboxPropertiesDialog *dialog,
					       const char *uri)
{
  Private *private;
  char *name;
  char *title;

  g_return_if_fail(MN_IS_MAILBOX_PROPERTIES_DIALOG(dialog));
  g_return_if_fail(uri != NULL);
  private = MN_MAILBOX_PROPERTIES_DIALOG_PRIVATE(dialog);

  g_free(private->uri);
  private->uri = g_strdup(uri);

  name = mn_uri_format_for_display(private->uri);
  title = g_strdup_printf(_("%s Properties"), name);
  g_free(name);

  gtk_window_set_title(GTK_WINDOW(dialog), title);
  g_free(title);
}

void
mn_mailbox_properties_dialog_set_uri (MNMailboxPropertiesDialog *dialog,
				      const char *uri)
{
  Private *private;
  gboolean valid;
  GtkTreeIter iter;
  MNMailboxProperties *properties;
  gboolean found = FALSE;

  g_return_if_fail(MN_IS_MAILBOX_PROPERTIES_DIALOG(dialog));
  private = MN_MAILBOX_PROPERTIES_DIALOG_PRIVATE(dialog);
  g_return_if_fail(private->uri == NULL);

  mn_mailbox_properties_dialog_set_uri_internal(dialog, uri);

  valid = gtk_tree_model_get_iter_first(GTK_TREE_MODEL(private->store), &iter);
  while (valid)
    {
      gtk_tree_model_get(GTK_TREE_MODEL(private->store), &iter, COLUMN_PROPERTIES, &properties, -1);
      g_object_unref(properties);

      if (! MN_IS_AUTODETECT_MAILBOX_PROPERTIES(properties)
	  && mn_mailbox_properties_set_uri(properties, uri))
	{
	  found = TRUE;
	  break;
	}

      valid = gtk_tree_model_iter_next(GTK_TREE_MODEL(private->store), &iter);
    }

  if (! found)
    {
      properties = mn_mailbox_properties_dialog_get_properties_by_type(dialog, MN_TYPE_AUTODETECT_MAILBOX_PROPERTIES);
      mn_mailbox_properties_set_uri(properties, uri);
    }
  mn_mailbox_properties_dialog_set_active_properties(dialog, properties);
}

char *
mn_mailbox_properties_dialog_get_uri (MNMailboxPropertiesDialog *dialog)
{
  Private *private;
  MNMailboxProperties *properties;

  g_return_val_if_fail(MN_IS_MAILBOX_PROPERTIES_DIALOG(dialog), NULL);
  private = MN_MAILBOX_PROPERTIES_DIALOG_PRIVATE(dialog);

  properties = mn_mailbox_properties_dialog_get_active_properties(dialog);
  return mn_mailbox_properties_get_uri(properties);
}

void
mn_mailbox_properties_dialog_apply (MNMailboxPropertiesDialog *dialog)
{
  Private *private;
  char *new_uri;

  g_return_if_fail(MN_IS_MAILBOX_PROPERTIES_DIALOG(dialog));
  private = MN_MAILBOX_PROPERTIES_DIALOG_PRIVATE(dialog);

  new_uri = mn_mailbox_properties_dialog_get_uri(dialog);
  g_return_if_fail(new_uri != NULL);

  if (mn_uri_cmp(new_uri, private->uri))
    {
      GSList *gconf_mailboxes;
      GSList *elem;

      gconf_mailboxes = eel_gconf_get_string_list(MN_CONF_MAILBOXES);

      elem = g_slist_find_custom(gconf_mailboxes, private->uri, (GCompareFunc) mn_uri_cmp);
      if (elem)
	{
	  g_free(elem->data);
	  elem->data = g_strdup(new_uri);
	}
      
      eel_gconf_set_string_list(MN_CONF_MAILBOXES, gconf_mailboxes);
      mn_pointers_free(gconf_mailboxes);
      
      mn_mailbox_properties_dialog_set_uri_internal(dialog, new_uri);
    }
  g_free(new_uri);
}

static void
mn_mailbox_properties_dialog_update_sensitivity (MNMailboxPropertiesDialog *dialog)
{
  Private *private;
  MNMailboxProperties *properties;

  g_return_if_fail(MN_IS_MAILBOX_PROPERTIES_DIALOG(dialog));
  private = MN_MAILBOX_PROPERTIES_DIALOG_PRIVATE(dialog);

  properties = mn_mailbox_properties_dialog_get_active_properties(dialog);
  if (properties)
    {
      gboolean complete;

      g_object_get(G_OBJECT(properties), "complete", &complete, NULL);

      if (private->apply_button)
	gtk_widget_set_sensitive(private->apply_button, complete);
      gtk_widget_set_sensitive(private->accept_button, complete);
    }
}

/* libglade callbacks */

void
mn_mailbox_properties_dialog_mailbox_type_changed_h (gpointer user_data,
						     GtkComboBox *combobox)
{
  MNMailboxPropertiesDialog *dialog = user_data;
  Private *private;

  private = MN_MAILBOX_PROPERTIES_DIALOG_PRIVATE(dialog);

  mn_mailbox_properties_dialog_select_properties(dialog);
  if (private->mode == MN_MAILBOX_PROPERTIES_DIALOG_MODE_ADD)
    {
      MNMailboxProperties *properties;
      
      properties = mn_mailbox_properties_dialog_get_active_properties(dialog);
      selected_type = G_TYPE_FROM_INSTANCE(properties);
    }

  mn_mailbox_properties_dialog_update_sensitivity(dialog);
}