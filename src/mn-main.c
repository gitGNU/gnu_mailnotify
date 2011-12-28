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
#include <stdlib.h>
#include <signal.h>
#include <gnome.h>
#include <libgnomevfs/gnome-vfs.h>
#ifdef WITH_MIME
#include <gmime/gmime.h>
#include "mn-gmime-stream-vfs.h"
#endif
#include "mn-conf.h"
#include "mn-util.h"
#include "mn-stock.h"
#include "mn-automation.h"
#include "mn-shell.h"
#include "mn-pending-mailbox.h"
#include "mn-unsupported-mailbox.h"

/*** cpp *********************************************************************/

#define AUTOMATION_IID			"OAFIID:GNOME_MailNotification_Automation"
#define AUTOMATION_FACTORY_IID		"OAFIID:GNOME_MailNotification_Automation_Factory"

/*** variables ***************************************************************/

static gboolean arg_enable_info = FALSE;

/*** functions ***************************************************************/

static BonoboObject *mn_main_automation_factory_cb (BonoboGenericFactory *factory,
						    const char *iid,
						    gpointer closure);
static void	mn_main_list_features	(void);
static void	mn_main_info_log_cb	(const char	*log_domain,
					 GLogLevelFlags	log_level,
					 const char	*message,
					 gpointer	user_data);

static void	mn_main_init_classes	(void);

/*** implementation **********************************************************/

static BonoboObject *
mn_main_automation_factory_cb (BonoboGenericFactory *factory,
			       const char *iid,
			       gpointer closure)
{
  if (! strcmp(iid, AUTOMATION_IID))
    return BONOBO_OBJECT(mn_automation_new());

  g_return_val_if_reached(NULL);
}

static void
mn_main_list_features (void)
{
  GString *backends;
  GString *features;
  int i;

#define ADD_FEATURE(string, feature)		\
  {						\
    if (*(string)->str)				\
      g_string_append((string), ", ");		\
    g_string_append((string), (feature));	\
  }

  backends = g_string_new(NULL);

  for (i = 0; mn_mailbox_types[i]; i++)
    {
      MNMailboxClass *class;
      
      class = g_type_class_peek(mn_mailbox_types[i]);
      g_return_if_fail(class != NULL);

      ADD_FEATURE(backends, class->format);
    }

  g_print(_("Compiled-in mailbox backends: %s\n"), backends->str);
  g_string_free(backends, TRUE);

  features = g_string_new(NULL);
#ifdef WITH_SSL
  ADD_FEATURE(features, "SSL/TLS");
#endif
#ifdef WITH_SASL
  ADD_FEATURE(features, "SASL");
#endif
#ifdef WITH_IPV6
  ADD_FEATURE(features, "IPv6");
#endif
#ifdef WITH_MIME
  ADD_FEATURE(features, "MIME");
#endif

  g_print(_("Compiled-in features: %s\n"), features->str);
  g_string_free(features, TRUE);
}

static void
mn_main_info_log_cb (const char *log_domain,
		     GLogLevelFlags log_level,
		     const char *message,
		     gpointer user_data)
{
  if (arg_enable_info)
    g_log_default_handler(log_domain, log_level, message, user_data);
}

static void
mn_main_init_classes (void)
{
  int i;

  g_type_class_ref(MN_TYPE_AUTOMATION);
#ifdef WITH_MIME
  g_type_class_ref(MN_TYPE_GMIME_STREAM_VFS);
#endif
  g_type_class_ref(MN_TYPE_MAILBOX);
  for (i = 0; mn_mailbox_types[i]; i++)
    g_type_class_ref(mn_mailbox_types[i]);
  g_type_class_ref(MN_TYPE_MAILBOXES);
  g_type_class_ref(MN_TYPE_MESSAGE);
  g_type_class_ref(MN_TYPE_PENDING_MAILBOX);
  g_type_class_ref(MN_TYPE_SHELL);
  g_type_class_ref(MN_TYPE_UNSUPPORTED_MAILBOX);
  g_type_class_ref(MN_TYPE_URI);
}

int
main (int argc, char **argv)
{
  gboolean arg_list_features = FALSE;
  gboolean arg_display_mail_summary = FALSE;
  gboolean arg_display_properties = FALSE;
  gboolean arg_display_about = FALSE;
  gboolean arg_close_popup = FALSE;
  gboolean arg_update = FALSE;
  gboolean arg_report = FALSE;
  gboolean arg_unset_obsolete_configuration = FALSE;
  const struct poptOption popt_options[] = {
    {
      "enable-info",
      'i',
      POPT_ARG_NONE,
      &arg_enable_info,
      0,
      N_("Enable informational output"),
      NULL
    },
    {
      "list-features",
      'l',
      POPT_ARG_NONE,
      &arg_list_features,
      0,
      N_("List compiled-in features and exit"),
      NULL
    },
    {
      "display-mail-summary",
      'm',
      POPT_ARG_NONE,
      &arg_display_mail_summary,
      0,
      N_("Display the mail summary dialog"),
      NULL
    },
    {
      "display-properties",
      'p',
      POPT_ARG_NONE,
      &arg_display_properties,
      0,
      N_("Display the properties dialog"),
      NULL
    },
    {
      "display-about",
      'a',
      POPT_ARG_NONE,
      &arg_display_about,
      0,
      N_("Display the about dialog"),
      NULL
    },
    {
      "close-popup",
      'c',
      POPT_ARG_NONE,
      &arg_close_popup,
      0,
      N_("Close the mail summary popup"),
      NULL
    },
    {
      "update",
      'u',
      POPT_ARG_NONE,
      &arg_update,
      0,
      N_("Update the mail status"),
      NULL
    },
    {
      "report",
      'r',
      POPT_ARG_NONE,
      &arg_report,
      0,
      N_("Report the mail status"),
      NULL
    },
    {
      "unset-obsolete-configuration",
      '\0',
      POPT_ARG_NONE,
      &arg_unset_obsolete_configuration,
      0,
      N_("Unset obsolete GConf configuration and exit"),
      NULL
    },
    POPT_TABLEEND
  };
  BonoboGenericFactory *automation_factory;
  GClosure *automation_factory_closure;
  CORBA_Environment ev;
  GNOME_MNAutomation automation;
  Bonobo_RegistrationResult result;
      
  g_log_set_fatal_mask(G_LOG_DOMAIN, G_LOG_LEVEL_CRITICAL);
  g_log_set_handler(G_LOG_DOMAIN, G_LOG_LEVEL_INFO, mn_main_info_log_cb, NULL);

#ifdef ENABLE_NLS
  bindtextdomain(GETTEXT_PACKAGE, GNOMELOCALEDIR);
  bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
  textdomain(GETTEXT_PACKAGE);
#endif

  g_thread_init(NULL);
  if (! g_thread_supported())
    /*
     * We can't use mn_error_dialog() because gtk_init() has not been
     * called yet.
     */
    g_critical(_("multi-threading is not available"));
  gdk_threads_init();

  gnome_program_init(PACKAGE,
		     VERSION,
		     LIBGNOMEUI_MODULE,
		     argc,
		     argv,
		     GNOME_PARAM_HUMAN_READABLE_NAME, _("Mail Notification"),
		     GNOME_PROGRAM_STANDARD_PROPERTIES,
		     GNOME_PARAM_POPT_TABLE, popt_options,
		     NULL);

  if (arg_list_features)
    {
      mn_main_list_features();
      exit(0);
    }

  if (arg_unset_obsolete_configuration)
    {
      mn_conf_unset_obsolete();
      exit(0);
    }
  
  /* mn-client-session uses sockets, we don't want to die on SIGPIPE */
  signal(SIGPIPE, SIG_IGN);

  GDK_THREADS_ENTER();

  mn_stock_init();
  bonobo_activate();

  automation_factory = g_object_new(bonobo_generic_factory_get_type(), NULL);
  automation_factory_closure = g_cclosure_new(G_CALLBACK(mn_main_automation_factory_cb), NULL, NULL);
  bonobo_generic_factory_construct_noreg(automation_factory, AUTOMATION_FACTORY_IID, automation_factory_closure);

  CORBA_exception_init(&ev);
  result = bonobo_activation_register_active_server(AUTOMATION_FACTORY_IID, BONOBO_OBJREF(automation_factory), NULL);
  switch (result)
    {
    case Bonobo_ACTIVATION_REG_ALREADY_ACTIVE:
    case Bonobo_ACTIVATION_REG_SUCCESS:
      automation = bonobo_activation_activate_from_id(AUTOMATION_IID, 0, NULL, &ev);
      if (CORBA_Object_is_nil(automation, &ev))
	mn_fatal_error_dialog(NULL, _("Bonobo could not locate the automation object. Please check your Mail Notification installation."));

      if (result != Bonobo_ACTIVATION_REG_ALREADY_ACTIVE)
	{
	  if (! gnome_vfs_init())
	    mn_fatal_error_dialog(NULL, _("Unable to initialize the GnomeVFS library."));
#ifdef WITH_MIME
	  g_mime_init(0);
#endif

	  mn_conf_init();
	  /*
	   * Work around
	   * http://bugzilla.gnome.org/show_bug.cgi?id=64764:
	   * initialize our non GTK-based classes before any thread is
	   * created.
	   */
	  mn_main_init_classes();
	  mn_shell_new();

	  if (! eel_gconf_get_boolean(MN_CONF_ALREADY_RUN))
	    {
	      if (! arg_display_properties)
		mn_shell_run_welcome(mn_shell);
	      eel_gconf_set_boolean(MN_CONF_ALREADY_RUN, TRUE);
	    }
	}
      
      if (arg_display_mail_summary)
	GNOME_MNAutomation_displayMailSummary(automation, &ev);
      if (arg_display_properties)
	GNOME_MNAutomation_displayProperties(automation, &ev);
      if (arg_display_about)
	GNOME_MNAutomation_displayAbout(automation, &ev);
      if (arg_close_popup)
	GNOME_MNAutomation_closePopup(automation, &ev);

      if (result == Bonobo_ACTIVATION_REG_ALREADY_ACTIVE)
	{
	  if (arg_update)
	    {
	      g_message(_("updating the mail status"));
	      GNOME_MNAutomation_update(automation, &ev);
	    }
	  if (arg_report)
	    {
	      CORBA_char *report;

	      GNOME_MNAutomation_report(automation, &report, &ev);
	      g_print("%s", report);
	      CORBA_free(report);
	    }

	  if (! (arg_display_mail_summary
		 || arg_display_properties
		 || arg_display_about
		 || arg_close_popup
		 || arg_update
		 || arg_report))
	    g_message(_("Mail Notification is already running"));
	}
      
      bonobo_object_release_unref(automation, &ev);
      break;

    case Bonobo_ACTIVATION_REG_NOT_LISTED:
      mn_fatal_error_dialog(NULL, _("Bonobo could not locate the GNOME_MailNotification_Automation.server file. Please check your Mail Notification installation."));
      break;

    case Bonobo_ACTIVATION_REG_ERROR:
      mn_fatal_error_dialog(NULL, _("Bonobo was unable to register the automation server. Please check your Mail Notification installation."));
      break;

    default:
      g_return_val_if_reached(1);
    }
  CORBA_exception_free(&ev);
  gdk_notify_startup_complete();
  
  if (result != Bonobo_ACTIVATION_REG_ALREADY_ACTIVE)
    gtk_main();

  GDK_THREADS_LEAVE();

  return 0;
}
