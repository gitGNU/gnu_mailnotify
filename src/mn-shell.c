/* Generated by GOB (v2.0.14)   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 14

#define selfp (self->_priv)

#include <string.h> /* memset() */

#include "mn-shell.h"

#include "mn-shell-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 34 "mn-shell.gob"

#include "config.h"
#include <signal.h>
#include <glib/gi18n.h>
#include <eel/eel.h>
#include <libxml/tree.h>
#include "mn-properties-dialog.h"
#include "mn-util.h"
#include "mn-conf.h"
#include "mn-mailboxes.h"
#include "mn-about-dialog.h"
#include "mn-standard-message-view.h"
#include "mn-compact-message-view.h"
#include "mn-message.h"
#include "mn-stock.h"
#include "mn-locked-callback.h"

MNShell *mn_shell = NULL;

typedef struct
{
  int		num;
  const char	*name;
} UnixSignalInfo;

#define SIGNAL_INFO(name) { name, #name }

static const UnixSignalInfo unix_quit_signals[] = {
  SIGNAL_INFO(SIGHUP),
  SIGNAL_INFO(SIGINT),
  SIGNAL_INFO(SIGTERM),
  SIGNAL_INFO(SIGUSR1),
  SIGNAL_INFO(SIGUSR2)
};

#line 62 "mn-shell.c"
static const GEnumValue _mn_shell_tooltip_mail_summary_values[] = {
	{ MN_SHELL_TOOLTIP_MAIL_SUMMARY_STANDARD, (char *)"MN_SHELL_TOOLTIP_MAIL_SUMMARY_STANDARD", (char *)"standard" },
	{ MN_SHELL_TOOLTIP_MAIL_SUMMARY_COMPACT, (char *)"MN_SHELL_TOOLTIP_MAIL_SUMMARY_COMPACT", (char *)"compact" },
	{ MN_SHELL_TOOLTIP_MAIL_SUMMARY_NONE, (char *)"MN_SHELL_TOOLTIP_MAIL_SUMMARY_NONE", (char *)"none" },
	{ 0, NULL, NULL }
};

GType
mn_shell_tooltip_mail_summary_get_type (void)
{
	static GType type = 0;
	if ___GOB_UNLIKELY(type == 0)
		type = g_enum_register_static ("MNShellTooltipMailSummary", _mn_shell_tooltip_mail_summary_values);
	return type;
}

/* self casting macros */
#define SELF(x) MN_SHELL(x)
#define SELF_CONST(x) MN_SHELL_CONST(x)
#define IS_SELF(x) MN_IS_SHELL(x)
#define TYPE_SELF MN_TYPE_SHELL
#define SELF_CLASS(x) MN_SHELL_CLASS(x)

#define SELF_GET_CLASS(x) MN_SHELL_GET_CLASS(x)

/* self typedefs */
typedef MNShell Self;
typedef MNShellClass SelfClass;

/* here are local prototypes */
static void mn_shell_class_init (MNShellClass * c) G_GNUC_UNUSED;
static void mn_shell_init (MNShell * self) G_GNUC_UNUSED;
static void ___2_mn_shell_dispose (GObject * object) G_GNUC_UNUSED;
static const UnixSignalInfo * mn_shell_lookup_unix_quit_signal (int signum) G_GNUC_UNUSED;
static void mn_shell_unix_quit_signal_handler (int signum) G_GNUC_UNUSED;
static void mn_shell_weak_notify_cb (gpointer data, GObject * former_object) G_GNUC_UNUSED;
static void mn_shell_messages_changed_h (MNMailboxes * mailboxes, gboolean has_new, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_play_new_mail_sound (MNShell * self) G_GNUC_UNUSED;
static void mn_shell_mailbox_removed_h (MNMailboxes * mailboxes, MNMailbox * mailbox, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_init_icon (MNShell * self) G_GNUC_UNUSED;
static void mn_shell_notify_icon_cb (GConfClient * client, unsigned int cnxn_id, GConfEntry * entry, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_notify_mail_reader_cb (GConfClient * client, unsigned int cnxn_id, GConfEntry * entry, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_notify_tooltip_mail_summary_cb (GConfClient * client, unsigned int cnxn_id, GConfEntry * entry, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_icon_activate_h (MNMailIcon * icon, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_icon_activate_mail_reader_h (MNMailIcon * icon, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_icon_activate_open_latest_message_h (MNMailIcon * icon, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_icon_activate_properties_h (MNMailIcon * icon, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_icon_activate_help_h (MNMailIcon * icon, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_icon_activate_about_h (MNMailIcon * icon, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_icon_destroy_h (GtkObject * object, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_update_sensitivity (MNShell * self) G_GNUC_UNUSED;
static void mn_shell_update_icon (MNShell * self) G_GNUC_UNUSED;
static void mn_shell_update_tooltip (MNShell * self) G_GNUC_UNUSED;
static int mn_shell_new_mailboxes_compare_cb (MNMailbox * a, MNMailbox * b) G_GNUC_UNUSED;
static GtkWidget * mn_shell_tooltip_section_new (GtkVBox ** vbox, const char * title) G_GNUC_UNUSED;
static void mn_shell_tooltip_text_section_new (GtkVBox ** vbox, const char * title, const char * text) G_GNUC_UNUSED;
static void mn_shell_open_latest_message (MNShell * self) G_GNUC_UNUSED;
static void mn_shell_display_window (MNShell * self, GType type, GtkWidget ** ptr, guint32 timestamp) G_GNUC_UNUSED;
static void mn_shell_mailbox_properties_dialog_weak_notify_cb (gpointer data, GObject * former_object) G_GNUC_UNUSED;

/* pointer to the class of our parent */
static GObjectClass *parent_class = NULL;

/* Short form macros */
#define self_lookup_unix_quit_signal mn_shell_lookup_unix_quit_signal
#define self_unix_quit_signal_handler mn_shell_unix_quit_signal_handler
#define self_weak_notify_cb mn_shell_weak_notify_cb
#define self_messages_changed_h mn_shell_messages_changed_h
#define self_play_new_mail_sound mn_shell_play_new_mail_sound
#define self_mailbox_removed_h mn_shell_mailbox_removed_h
#define self_init_icon mn_shell_init_icon
#define self_notify_icon_cb mn_shell_notify_icon_cb
#define self_notify_mail_reader_cb mn_shell_notify_mail_reader_cb
#define self_notify_tooltip_mail_summary_cb mn_shell_notify_tooltip_mail_summary_cb
#define self_icon_activate_h mn_shell_icon_activate_h
#define self_icon_activate_mail_reader_h mn_shell_icon_activate_mail_reader_h
#define self_icon_activate_open_latest_message_h mn_shell_icon_activate_open_latest_message_h
#define self_icon_activate_properties_h mn_shell_icon_activate_properties_h
#define self_icon_activate_help_h mn_shell_icon_activate_help_h
#define self_icon_activate_about_h mn_shell_icon_activate_about_h
#define self_icon_destroy_h mn_shell_icon_destroy_h
#define self_update_sensitivity mn_shell_update_sensitivity
#define self_update_icon mn_shell_update_icon
#define self_update_tooltip mn_shell_update_tooltip
#define self_new_mailboxes_compare_cb mn_shell_new_mailboxes_compare_cb
#define self_tooltip_section_new mn_shell_tooltip_section_new
#define self_tooltip_text_section_new mn_shell_tooltip_text_section_new
#define self_open_latest_message mn_shell_open_latest_message
#define self_new mn_shell_new
#define self_consider_new_mail_as_read mn_shell_consider_new_mail_as_read
#define self_update mn_shell_update
#define self_quit mn_shell_quit
#define self_display_properties_dialog mn_shell_display_properties_dialog
#define self_display_about_dialog mn_shell_display_about_dialog
#define self_display_window mn_shell_display_window
#define self_add_mailbox_properties_dialog mn_shell_add_mailbox_properties_dialog
#define self_mailbox_properties_dialog_weak_notify_cb mn_shell_mailbox_properties_dialog_weak_notify_cb
#define self_get_mailbox_properties_dialog mn_shell_get_mailbox_properties_dialog
#define self_get_summary mn_shell_get_summary
GType
mn_shell_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (MNShellClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) mn_shell_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (MNShell),
			0 /* n_preallocs */,
			(GInstanceInitFunc) mn_shell_init,
			NULL
		};

		type = g_type_register_static (G_TYPE_OBJECT, "MNShell", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((MNShell *)g_object_new(mn_shell_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static MNShell * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static MNShell *
GET_NEW_VARG (const char *first, ...)
{
	MNShell *ret;
	va_list ap;
	va_start (ap, first);
	ret = (MNShell *)g_object_new_valist (mn_shell_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "MN:Shell::finalize"
	MNShell *self G_GNUC_UNUSED = MN_SHELL (obj_self);
	gpointer priv G_GNUC_UNUSED = self->_priv;
	if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(obj_self);
}
#undef __GOB_FUNCTION__

static void 
mn_shell_class_init (MNShellClass * c G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:Shell::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) c;

	g_type_class_add_private(c,sizeof(MNShellPrivate));

	parent_class = g_type_class_ref (G_TYPE_OBJECT);

#line 143 "mn-shell.gob"
	g_object_class->dispose = ___2_mn_shell_dispose;
#line 228 "mn-shell.c"
	g_object_class->finalize = ___finalize;
}
#undef __GOB_FUNCTION__
#line 92 "mn-shell.gob"
static void 
mn_shell_init (MNShell * self G_GNUC_UNUSED)
#line 235 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::init"
	self->_priv = G_TYPE_INSTANCE_GET_PRIVATE(self,MN_TYPE_SHELL,MNShellPrivate);
 {
#line 93 "mn-shell.gob"

    int i;

    g_assert(mn_shell == NULL);

    mn_shell = self;
    g_object_weak_ref(G_OBJECT(self), self_weak_notify_cb, NULL);

    selfp->sound_player = mn_sound_player_new();
    eel_add_weak_pointer(&selfp->sound_player);

    /*
     * self->mailboxes is assigned in MNMailboxes itself, so that
     * mailboxes can access it even during construction of
     * MNMailboxes.
     */
    mn_mailboxes_new();
    eel_add_weak_pointer(&self->mailboxes);

    self_init_icon(self);

    mn_g_object_gconf_notifications_add_gdk_locked(self,
						   MN_CONF_BLINK_ON_ERRORS, self_notify_icon_cb, self,
						   MN_CONF_ALWAYS_DISPLAY_ICON, self_notify_icon_cb, self,
						   MN_CONF_DISPLAY_MESSAGE_COUNT, self_notify_icon_cb, self,
						   MN_CONF_GNOME_MAIL_READER_NAMESPACE, self_notify_mail_reader_cb, self,
						   MN_CONF_TOOLTIP_MAIL_SUMMARY, self_notify_tooltip_mail_summary_cb, self,
						   NULL);

    g_object_connect(self->mailboxes,
		     "signal::messages-changed", self_messages_changed_h, self,
		     "signal::mailbox-removed", self_mailbox_removed_h, self,
		     "swapped-signal::notify::manually-checkable", self_update_sensitivity, self,
		     "swapped-signal::list-changed", self_update_tooltip, self,
		     "swapped-signal::list-changed", self_update_icon, self,
		     "swapped-signal::error-changed", self_update_tooltip, self,
		     "swapped-signal::error-changed", self_update_icon, self,
		     NULL);

    self->popups = mn_popups_new();
    eel_add_weak_pointer(&self->popups);

    /*
     * Exit cleanly (by unreferencing our components) when receiving a
     * UNIX signal.
     */
    for (i = 0; i < G_N_ELEMENTS(unix_quit_signals); i++)
      signal(unix_quit_signals[i].num, self_unix_quit_signal_handler);
  
#line 290 "mn-shell.c"
 }
}
#undef __GOB_FUNCTION__



#line 143 "mn-shell.gob"
static void 
___2_mn_shell_dispose (GObject * object G_GNUC_UNUSED)
#line 300 "mn-shell.c"
#define PARENT_HANDLER(___object) \
	{ if(G_OBJECT_CLASS(parent_class)->dispose) \
		(* G_OBJECT_CLASS(parent_class)->dispose)(___object); }
{
#define __GOB_FUNCTION__ "MN:Shell::dispose"
{
#line 145 "mn-shell.gob"
	
    Self *self = SELF(object);

    /*
     * We explicitly unreference or destroy each component, even
     * though MN will exit after the shell is finalized. This is done
     * for the sake of respecting encapsulation: we should not know
     * whether a particular component has something to do on exit or
     * not (for instance, MNSoundPlayer must kill the play process).
     *
     * Of course, the order in which we get rid of the components
     * matters: for instance, when destroyed, MNPropertiesDialog might
     * remove the test mailbox and thus requires a valid MNMailboxes
     * object. We destroy the components in the inverse order of their
     * creation.
     *
     * Also note that we do not need to nullify the pointers after
     * destruction since we use eel_add_weak_pointer() at creation
     * time.
     */

    g_slist_foreach(selfp->mailbox_properties_dialogs, (GFunc) gtk_widget_destroy, NULL);
    /* the list is freed in mailbox_properties_dialog_weak_notify_cb() */

    if (selfp->properties_dialog)
      gtk_widget_destroy(selfp->properties_dialog);

    if (selfp->about_dialog)
      gtk_widget_destroy(selfp->about_dialog);

    mn_g_object_null_unref(self->popups);

    if (self->icon)
      {
	/* do not recreate the icon after we destroy it */
	g_signal_handlers_disconnect_by_func(self->icon, self_icon_destroy_h, self);
	gtk_widget_destroy(GTK_WIDGET(self->icon));
      }

    mn_g_object_null_unref(self->mailboxes);

    mn_g_object_null_unref(selfp->sound_player);

    PARENT_HANDLER(object);
  }}
#line 353 "mn-shell.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 191 "mn-shell.gob"
static const UnixSignalInfo * 
mn_shell_lookup_unix_quit_signal (int signum)
#line 360 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::lookup_unix_quit_signal"
{
#line 193 "mn-shell.gob"
	
    int i;

    for (i = 0; i < G_N_ELEMENTS(unix_quit_signals); i++)
      if (unix_quit_signals[i].num == signum)
	return &unix_quit_signals[i];

    g_assert_not_reached();
    return NULL;
  }}
#line 375 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 204 "mn-shell.gob"
static void 
mn_shell_unix_quit_signal_handler (int signum)
#line 381 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::unix_quit_signal_handler"
{
#line 206 "mn-shell.gob"
	
    int i;
    const UnixSignalInfo *info;

    /*
     * Uninstall signal handlers, in case another signal is received
     * while we are quitting.
     */
    for (i = 0; i < G_N_ELEMENTS(unix_quit_signals); i++)
      signal(unix_quit_signals[i].num, SIG_DFL);

    info = self_lookup_unix_quit_signal(signum);

    g_message(_("received %s signal, exiting"), info->name);
    self_quit(mn_shell);
  }}
#line 402 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 223 "mn-shell.gob"
static void 
mn_shell_weak_notify_cb (gpointer data, GObject * former_object)
#line 408 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::weak_notify_cb"
{
#line 225 "mn-shell.gob"
	
    gtk_main_quit();
  }}
#line 416 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 229 "mn-shell.gob"
static void 
mn_shell_messages_changed_h (MNMailboxes * mailboxes, gboolean has_new, gpointer user_data)
#line 422 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::messages_changed_h"
{
#line 233 "mn-shell.gob"
	
    Self *self = user_data;

    if (mn_conf_has_command(MN_CONF_COMMANDS_MAIL_CHANGED_NAMESPACE))
      mn_conf_execute_command(MN_CONF_COMMANDS_MAIL_CHANGED_COMMAND);

    if (has_new)
      {
	self_play_new_mail_sound(self);

	if (mn_conf_has_command(MN_CONF_COMMANDS_NEW_MAIL_NAMESPACE))
	  mn_conf_execute_command(MN_CONF_COMMANDS_NEW_MAIL_COMMAND);
      }

    self_update_sensitivity(self);
    self_update_tooltip(self);
    self_update_icon(self);
  }}
#line 445 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 252 "mn-shell.gob"
static void 
mn_shell_play_new_mail_sound (MNShell * self)
#line 451 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::play_new_mail_sound"
#line 252 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 252 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 458 "mn-shell.c"
{
#line 254 "mn-shell.gob"
	
    char *file;

    if (! eel_gconf_get_boolean(MN_CONF_SOUNDS_NEW_MAIL_ENABLED))
      return;

    file = eel_gconf_get_string(MN_CONF_SOUNDS_NEW_MAIL_FILE);

    if (file && *file)
      mn_sound_player_play(selfp->sound_player, file, NULL);

    g_free(file);
  }}
#line 474 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 268 "mn-shell.gob"
static void 
mn_shell_mailbox_removed_h (MNMailboxes * mailboxes, MNMailbox * mailbox, gpointer user_data)
#line 480 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::mailbox_removed_h"
{
#line 272 "mn-shell.gob"
	
    Self *self = user_data;
    MNMailboxPropertiesDialog *dialog;

    /* destroy the associated properties dialog, if any */
    dialog = self_get_mailbox_properties_dialog(self, mailbox);
    if (dialog)
      gtk_widget_destroy(GTK_WIDGET(dialog));
  }}
#line 494 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 282 "mn-shell.gob"
static void 
mn_shell_init_icon (MNShell * self)
#line 500 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::init_icon"
#line 282 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 282 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 507 "mn-shell.c"
{
#line 284 "mn-shell.gob"
	
    self->icon = MN_MAIL_ICON(mn_mail_icon_new());
    eel_add_weak_pointer(&self->icon);

    g_object_connect(self->icon,
		     "signal::activate", self_icon_activate_h, self,
		     "signal::activate-mail-reader", self_icon_activate_mail_reader_h, self,
		     "signal::activate-open-latest-message", self_icon_activate_open_latest_message_h, self,
		     "swapped-signal::activate-consider-new-mail-as-read", self_consider_new_mail_as_read, self,
		     "swapped-signal::activate-update", self_update, self,
		     "signal::activate-properties", self_icon_activate_properties_h, self,
		     "signal::activate-help", self_icon_activate_help_h, self,
		     "signal::activate-about", self_icon_activate_about_h, self,
		     "swapped-signal::activate-remove", self_quit, self,
		     "signal::destroy", self_icon_destroy_h, self,
		     NULL);

    self_update_sensitivity(self);
    self_update_tooltip(self);
    self_update_icon(self);
  }}
#line 531 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 306 "mn-shell.gob"
static void 
mn_shell_notify_icon_cb (GConfClient * client, unsigned int cnxn_id, GConfEntry * entry, gpointer user_data)
#line 537 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::notify_icon_cb"
{
#line 311 "mn-shell.gob"
	
    Self *self = user_data;

    self_update_icon(self);
  }}
#line 547 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 317 "mn-shell.gob"
static void 
mn_shell_notify_mail_reader_cb (GConfClient * client, unsigned int cnxn_id, GConfEntry * entry, gpointer user_data)
#line 553 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::notify_mail_reader_cb"
{
#line 322 "mn-shell.gob"
	
    Self *self = user_data;

    self_update_sensitivity(self);
  }}
#line 563 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 328 "mn-shell.gob"
static void 
mn_shell_notify_tooltip_mail_summary_cb (GConfClient * client, unsigned int cnxn_id, GConfEntry * entry, gpointer user_data)
#line 569 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::notify_tooltip_mail_summary_cb"
{
#line 333 "mn-shell.gob"
	
    Self *self = user_data;

    self_update_tooltip(self);
  }}
#line 579 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 339 "mn-shell.gob"
static void 
mn_shell_icon_activate_h (MNMailIcon * icon, gpointer user_data)
#line 585 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::icon_activate_h"
{
#line 341 "mn-shell.gob"
	
    MNShell *self = user_data;
    MNAction action;

    action = mn_conf_get_enum_value(MN_TYPE_ACTION, MN_CONF_CLICK_ACTION);

    switch (action)
      {
      case MN_ACTION_LAUNCH_MAIL_READER:
	if (mn_conf_has_command(MN_CONF_GNOME_MAIL_READER_NAMESPACE))
	  mn_conf_execute_mail_reader();
	else
	  mn_error_dialog_with_markup(NULL,
				      _("No mail reader is configured"),
				      _("You can configure a mail reader by choosing <b>System → Preferences → Preferred Applications</b>."));
	break;

      case MN_ACTION_OPEN_LATEST_MESSAGE:
	if (self->mailboxes->messages)
	  {
	    MNMessage *message = self->mailboxes->messages->data;
	    if (mn_message_can_open(message))
	      self_open_latest_message(self);
	    else
	      mn_error_dialog(NULL,
			      _("Unable to open the latest message"),
			      _("Messages of mailbox \"%s\" cannot be opened."),
			      message->mailbox->runtime_name);
	  }
	else
	  mn_error_dialog(NULL,
			  _("Unable to open the latest message"),
			  _("You have no new mail."));
	break;

      case MN_ACTION_CONSIDER_NEW_MAIL_AS_READ:
	self_consider_new_mail_as_read(self);
	break;

      case MN_ACTION_UPDATE_MAIL_STATUS:
	mn_mailboxes_check(self->mailboxes);
	break;

      default:
	g_assert_not_reached();
      }
  }}
#line 637 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 389 "mn-shell.gob"
static void 
mn_shell_icon_activate_mail_reader_h (MNMailIcon * icon, gpointer user_data)
#line 643 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::icon_activate_mail_reader_h"
{
#line 391 "mn-shell.gob"
	
    mn_conf_execute_mail_reader();
  }}
#line 651 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 395 "mn-shell.gob"
static void 
mn_shell_icon_activate_open_latest_message_h (MNMailIcon * icon, gpointer user_data)
#line 657 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::icon_activate_open_latest_message_h"
{
#line 397 "mn-shell.gob"
	
    Self *self = user_data;
    self_open_latest_message(self);
  }}
#line 666 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 402 "mn-shell.gob"
static void 
mn_shell_icon_activate_properties_h (MNMailIcon * icon, gpointer user_data)
#line 672 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::icon_activate_properties_h"
{
#line 404 "mn-shell.gob"
	
    Self *self = user_data;
    self_display_properties_dialog(self, gtk_get_current_event_time());
  }}
#line 681 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 409 "mn-shell.gob"
static void 
mn_shell_icon_activate_help_h (MNMailIcon * icon, gpointer user_data)
#line 687 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::icon_activate_help_h"
{
#line 411 "mn-shell.gob"
	
    mn_display_help(NULL, NULL);
  }}
#line 695 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 415 "mn-shell.gob"
static void 
mn_shell_icon_activate_about_h (MNMailIcon * icon, gpointer user_data)
#line 701 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::icon_activate_about_h"
{
#line 417 "mn-shell.gob"
	
    Self *self = user_data;
    self_display_about_dialog(self, gtk_get_current_event_time());
  }}
#line 710 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 422 "mn-shell.gob"
static void 
mn_shell_icon_destroy_h (GtkObject * object, gpointer user_data)
#line 716 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::icon_destroy_h"
{
#line 424 "mn-shell.gob"
	
    Self *self = user_data;

    /* The Notification Area applet has been terminated. Recreate the icon. */
    self_init_icon(self);
  }}
#line 727 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 431 "mn-shell.gob"
static void 
mn_shell_update_sensitivity (MNShell * self)
#line 733 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::update_sensitivity"
#line 431 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 431 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 740 "mn-shell.c"
{
#line 433 "mn-shell.gob"
	
    gtk_widget_set_sensitive(self->icon->mail_reader_item, mn_conf_has_command(MN_CONF_GNOME_MAIL_READER_NAMESPACE));
    gtk_widget_set_sensitive(self->icon->open_latest_message_item, self->mailboxes->messages && mn_message_can_open(self->mailboxes->messages->data));
    gtk_widget_set_sensitive(self->icon->consider_new_mail_as_read_item, self->mailboxes->messages != NULL);
    gtk_widget_set_sensitive(self->icon->update_item, mn_mailboxes_get_manually_checkable(self->mailboxes));
  }}
#line 749 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 440 "mn-shell.gob"
static void 
mn_shell_update_icon (MNShell * self)
#line 755 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::update_icon"
#line 440 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 440 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 762 "mn-shell.c"
{
#line 442 "mn-shell.gob"
	
    GList *l;
    gboolean has_new = FALSE;
    gboolean blink = FALSE;
    gboolean always = eel_gconf_get_boolean(MN_CONF_ALWAYS_DISPLAY_ICON);

    MN_LIST_FOREACH(l, self->mailboxes->list)
      {
	MNMailbox *mailbox = l->data;

	if (mailbox->messages)
	  has_new = TRUE;
	if (mailbox->error)
	  blink = TRUE;
      }

    if (selfp->has_new && ! has_new && mn_conf_has_command(MN_CONF_COMMANDS_MAIL_READ_NAMESPACE))
      mn_conf_execute_command(MN_CONF_COMMANDS_MAIL_READ_COMMAND);
    selfp->has_new = has_new;

    if (blink && ! eel_gconf_get_boolean(MN_CONF_BLINK_ON_ERRORS))
      blink = FALSE;

    if (has_new || blink || always)
      {
	int count;

	if (eel_gconf_get_boolean(MN_CONF_DISPLAY_MESSAGE_COUNT))
	  count = g_slist_length(self->mailboxes->messages);
	else
	  count = 0;

	mn_mail_icon_set_from_stock(self->icon, has_new ? MN_STOCK_MAIL : MN_STOCK_NO_MAIL);
	mn_mail_icon_set_blinking(self->icon, blink);
	mn_mail_icon_set_count(self->icon, count);
	gtk_widget_show(GTK_WIDGET(self->icon));
      }
    else
      {
	gtk_widget_hide(GTK_WIDGET(self->icon));
	mn_mail_icon_set_blinking(self->icon, FALSE);
      }
  }}
#line 808 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 486 "mn-shell.gob"
static void 
mn_shell_update_tooltip (MNShell * self)
#line 814 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::update_tooltip"
#line 486 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 486 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 821 "mn-shell.c"
{
#line 488 "mn-shell.gob"
	
    GtkVBox *vbox = NULL;

    if (self->mailboxes->list)
      {
	GList *la;
	GSList *lb;
	GSList *new_mailboxes = NULL;
	GSList *error_mailboxes = NULL;

	MN_LIST_FOREACH(la, self->mailboxes->list)
          {
	    MNMailbox *mailbox = la->data;

	    if (mailbox->messages)
	      new_mailboxes = g_slist_insert_sorted(new_mailboxes, mailbox, (GCompareFunc) self_new_mailboxes_compare_cb);

	    if (mailbox->error)
	      error_mailboxes = g_slist_insert_sorted(error_mailboxes, mailbox, mn_mailboxes_compare_by_name_func);
	  }

	if (new_mailboxes)
	  {
	    GString *string = g_string_new(NULL);

	    MN_LIST_FOREACH(lb, new_mailboxes)
	      {
		MNMailbox *mailbox = lb->data;

		g_assert(mailbox->n_messages > 0);

		if (*string->str)
		  g_string_append_c(string, '\n');

		g_string_append_printf(string, _("%s (%i)"), mailbox->runtime_name, mailbox->n_messages);
	      }
	    g_slist_free(new_mailboxes);

	    /* translators: header capitalization */
	    self_tooltip_text_section_new(&vbox, _("Mailboxes Having New Mail"), string->str);
	    g_string_free(string, TRUE);
	  }

	if (error_mailboxes)
	  {
	    GString *string = g_string_new(NULL);

	    MN_LIST_FOREACH(lb, error_mailboxes)
	      {
		MNMailbox *mailbox = lb->data;

		if (*string->str)
		  g_string_append_c(string, '\n');
		g_string_append_printf(string, _("%s: %s"), mailbox->runtime_name, mailbox->error);
	      }
	    g_slist_free(error_mailboxes);

	    /* translators: header capitalization */
	    self_tooltip_text_section_new(&vbox, _("Errors"), string->str);
	    g_string_free(string, TRUE);
	  }
      }

    if (self->mailboxes->messages)
      {
	MNShellTooltipMailSummary mail_summary;

	mail_summary = mn_conf_get_enum_value(MN_TYPE_SHELL_TOOLTIP_MAIL_SUMMARY, MN_CONF_TOOLTIP_MAIL_SUMMARY);
	if (mail_summary != MN_SHELL_TOOLTIP_MAIL_SUMMARY_NONE)
	  {
	    GtkWidget *alignment;
	    GtkWidget *message_view;

	    /* translators: header capitalization */
	    alignment = self_tooltip_section_new(&vbox, _("Mail Summary"));

	    switch (mail_summary)
	      {
	      case MN_SHELL_TOOLTIP_MAIL_SUMMARY_STANDARD:
		message_view = mn_standard_message_view_new();
		break;

	      case MN_SHELL_TOOLTIP_MAIL_SUMMARY_COMPACT:
		message_view = mn_compact_message_view_new();
		break;

	      default:
		g_assert_not_reached();
		break;
	      }

	    gtk_widget_set_name(message_view, "mn-message-view");
	    mn_message_view_set_messages(MN_MESSAGE_VIEW(message_view), self->mailboxes->messages);
	    gtk_container_add(GTK_CONTAINER(alignment), message_view);
	  }
      }

    if (vbox)
      {
	gtk_widget_show_all(GTK_WIDGET(vbox));
	mn_mail_icon_set_tip_widget(self->icon, GTK_WIDGET(vbox));
      }
    else
      mn_mail_icon_set_tip(self->icon, _("You have no new mail."));
  }}
#line 929 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 594 "mn-shell.gob"
static int 
mn_shell_new_mailboxes_compare_cb (MNMailbox * a, MNMailbox * b)
#line 935 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::new_mailboxes_compare_cb"
{
#line 596 "mn-shell.gob"
	
    int cmp;

    /* sort by timestamp (descending order) */
    cmp = b->timestamp - a->timestamp;
    /* else sort by number of messages (descending order) */
    if (cmp == 0)
      {
	cmp = b->n_messages - a->n_messages;
	/* else sort by name (ascending order) */
	if (cmp == 0)
	  cmp = mn_mailboxes_compare_by_name_func(a, b);
      }

    return cmp;
  }}
#line 956 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 613 "mn-shell.gob"
static GtkWidget * 
mn_shell_tooltip_section_new (GtkVBox ** vbox, const char * title)
#line 962 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::tooltip_section_new"
#line 613 "mn-shell.gob"
	g_return_val_if_fail (vbox != NULL, (GtkWidget * )0);
#line 613 "mn-shell.gob"
	g_return_val_if_fail (title != NULL, (GtkWidget * )0);
#line 969 "mn-shell.c"
{
#line 616 "mn-shell.gob"
	
    GtkWidget *section;
    GtkWidget *label;
    GtkWidget *alignment;

    if (! *vbox)
      *vbox = GTK_VBOX(gtk_vbox_new(FALSE, 18));

    section = mn_hig_section_new(title, &label, &alignment);

    gtk_widget_set_name(label, "mn-tooltip-section-title");

    gtk_box_pack_start(GTK_BOX(*vbox), section, TRUE, TRUE, 0);

    return alignment;
  }}
#line 988 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 633 "mn-shell.gob"
static void 
mn_shell_tooltip_text_section_new (GtkVBox ** vbox, const char * title, const char * text)
#line 994 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::tooltip_text_section_new"
#line 633 "mn-shell.gob"
	g_return_if_fail (vbox != NULL);
#line 633 "mn-shell.gob"
	g_return_if_fail (title != NULL);
#line 633 "mn-shell.gob"
	g_return_if_fail (text != NULL);
#line 1003 "mn-shell.c"
{
#line 637 "mn-shell.gob"
	
    GtkWidget *alignment;
    GtkWidget *label;

    alignment = self_tooltip_section_new(vbox, title);

    label = gtk_label_new(text);
    gtk_widget_set_name(label, "mn-tooltip-section-body");
    gtk_misc_set_alignment(GTK_MISC(label), 0.0, 0.5);

    gtk_container_add(GTK_CONTAINER(alignment), label);
  }}
#line 1018 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 650 "mn-shell.gob"
static void 
mn_shell_open_latest_message (MNShell * self)
#line 1024 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::open_latest_message"
#line 650 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 650 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 1031 "mn-shell.c"
{
#line 652 "mn-shell.gob"
	
    MNMessage *message;
    GError *err = NULL;

    g_return_if_fail(self->mailboxes->messages != NULL);

    message = self->mailboxes->messages->data;
    g_return_if_fail(mn_message_can_open(message));

    if (! mn_message_open(message, &err))
      {
	mn_error_dialog(NULL, _("Unable to open the latest message"), "%s", err->message);
	g_error_free(err);
      }
  }}
#line 1049 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 668 "mn-shell.gob"
MNShell * 
mn_shell_new (void)
#line 1055 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::new"
{
#line 670 "mn-shell.gob"
	
    return GET_NEW;
  }}
#line 1063 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 674 "mn-shell.gob"
void 
mn_shell_consider_new_mail_as_read (MNShell * self)
#line 1069 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::consider_new_mail_as_read"
#line 674 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 674 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 1076 "mn-shell.c"
{
#line 676 "mn-shell.gob"
	
    GList *l;

    MN_LIST_FOREACH(l, self->mailboxes->list)
      {
	MNMailbox *mailbox = l->data;
	mn_mailbox_consider_as_read_list(mailbox->messages);
      }
  }}
#line 1088 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 686 "mn-shell.gob"
void 
mn_shell_update (MNShell * self)
#line 1094 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::update"
#line 686 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 686 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 1101 "mn-shell.c"
{
#line 688 "mn-shell.gob"
	
    mn_mailboxes_check(self->mailboxes);
  }}
#line 1107 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 692 "mn-shell.gob"
void 
mn_shell_quit (MNShell * self)
#line 1113 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::quit"
#line 692 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 692 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 1120 "mn-shell.c"
{
#line 694 "mn-shell.gob"
	
    g_object_unref(self);
  }}
#line 1126 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 698 "mn-shell.gob"
void 
mn_shell_display_properties_dialog (MNShell * self, guint32 timestamp)
#line 1132 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::display_properties_dialog"
#line 698 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 698 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 1139 "mn-shell.c"
{
#line 700 "mn-shell.gob"
	
    self_display_window(self, MN_TYPE_PROPERTIES_DIALOG, &selfp->properties_dialog, timestamp);
  }}
#line 1145 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 704 "mn-shell.gob"
void 
mn_shell_display_about_dialog (MNShell * self, guint32 timestamp)
#line 1151 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::display_about_dialog"
#line 704 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 704 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 1158 "mn-shell.c"
{
#line 706 "mn-shell.gob"
	
    self_display_window(self, MN_TYPE_ABOUT_DIALOG, &selfp->about_dialog, timestamp);
  }}
#line 1164 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 710 "mn-shell.gob"
static void 
mn_shell_display_window (MNShell * self, GType type, GtkWidget ** ptr, guint32 timestamp)
#line 1170 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::display_window"
#line 710 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 710 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 710 "mn-shell.gob"
	g_return_if_fail (type != 0);
#line 710 "mn-shell.gob"
	g_return_if_fail (ptr != NULL);
#line 1181 "mn-shell.c"
{
#line 715 "mn-shell.gob"
	
    if (*ptr)
      {
	if (timestamp)
	  gtk_window_present_with_time(GTK_WINDOW(*ptr), timestamp);
	else
	  gtk_window_present(GTK_WINDOW(*ptr));
	return;
      }

    *ptr = g_object_new(type, NULL);
    eel_add_weak_pointer(ptr);

    gtk_widget_show(*ptr);
  }}
#line 1199 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 731 "mn-shell.gob"
void 
mn_shell_add_mailbox_properties_dialog (MNShell * self, MNMailboxPropertiesDialog * dialog)
#line 1205 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::add_mailbox_properties_dialog"
#line 731 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 731 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 731 "mn-shell.gob"
	g_return_if_fail (dialog != NULL);
#line 731 "mn-shell.gob"
	g_return_if_fail (MN_IS_MAILBOX_PROPERTIES_DIALOG (dialog));
#line 1216 "mn-shell.c"
{
#line 733 "mn-shell.gob"
	
    selfp->mailbox_properties_dialogs = g_slist_append(selfp->mailbox_properties_dialogs, dialog);
    g_object_weak_ref(G_OBJECT(dialog), self_mailbox_properties_dialog_weak_notify_cb, self);
  }}
#line 1223 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 738 "mn-shell.gob"
static void 
mn_shell_mailbox_properties_dialog_weak_notify_cb (gpointer data, GObject * former_object)
#line 1229 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::mailbox_properties_dialog_weak_notify_cb"
{
#line 741 "mn-shell.gob"
	
    Self *self = data;

    selfp->mailbox_properties_dialogs = g_slist_remove(selfp->mailbox_properties_dialogs, former_object);
  }}
#line 1239 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 747 "mn-shell.gob"
MNMailboxPropertiesDialog * 
mn_shell_get_mailbox_properties_dialog (MNShell * self, MNMailbox * mailbox)
#line 1245 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::get_mailbox_properties_dialog"
#line 747 "mn-shell.gob"
	g_return_val_if_fail (self != NULL, (MNMailboxPropertiesDialog * )0);
#line 747 "mn-shell.gob"
	g_return_val_if_fail (MN_IS_SHELL (self), (MNMailboxPropertiesDialog * )0);
#line 747 "mn-shell.gob"
	g_return_val_if_fail (mailbox != NULL, (MNMailboxPropertiesDialog * )0);
#line 747 "mn-shell.gob"
	g_return_val_if_fail (MN_IS_MAILBOX (mailbox), (MNMailboxPropertiesDialog * )0);
#line 1256 "mn-shell.c"
{
#line 749 "mn-shell.gob"
	
    GSList *l;

    MN_LIST_FOREACH(l, selfp->mailbox_properties_dialogs)
      {
	MNMailboxPropertiesDialog *dialog = l->data;
	MNMailbox *this_mailbox;
	gboolean found;

	this_mailbox = mn_mailbox_properties_dialog_get_mailbox(dialog);
	found = this_mailbox == mailbox;
	g_object_unref(this_mailbox);

	if (found)
	  return dialog;
      }

    return NULL;
  }}
#line 1278 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 769 "mn-shell.gob"
char * 
mn_shell_get_summary (MNShell * self)
#line 1284 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::get_summary"
#line 769 "mn-shell.gob"
	g_return_val_if_fail (self != NULL, (char * )0);
#line 769 "mn-shell.gob"
	g_return_val_if_fail (MN_IS_SHELL (self), (char * )0);
#line 1291 "mn-shell.c"
{
#line 771 "mn-shell.gob"
	
    int indent;
    xmlDoc *doc;
    xmlNode *root;
    GSList *l;
    xmlChar *summary;

    indent = xmlIndentTreeOutput;
    xmlIndentTreeOutput = 1;

    doc = xmlNewDoc("1.0");
    root = xmlNewNode(NULL, "messages");
    xmlDocSetRootElement(doc, root);

    MN_LIST_FOREACH(l, self->mailboxes->messages)
      {
	MNMessage *message = l->data;
	xmlNode *node;

	node = mn_message_xml_node_new(message);
	xmlAddChild(root, node); /* owns node */
      }

    xmlDocDumpFormatMemory(doc, &summary, NULL, 1);

    xmlFreeDoc(doc);
    xmlIndentTreeOutput = indent;

    return summary;
  }}
#line 1324 "mn-shell.c"
#undef __GOB_FUNCTION__
static const GEnumValue _mn_action_values[] = {
	{ MN_ACTION_LAUNCH_MAIL_READER, (char *)"MN_ACTION_LAUNCH_MAIL_READER", (char *)"launch-mail-reader" },
	{ MN_ACTION_OPEN_LATEST_MESSAGE, (char *)"MN_ACTION_OPEN_LATEST_MESSAGE", (char *)"open-latest-message" },
	{ MN_ACTION_CONSIDER_NEW_MAIL_AS_READ, (char *)"MN_ACTION_CONSIDER_NEW_MAIL_AS_READ", (char *)"consider-new-mail-as-read" },
	{ MN_ACTION_UPDATE_MAIL_STATUS, (char *)"MN_ACTION_UPDATE_MAIL_STATUS", (char *)"update-mail-status" },
	{ 0, NULL, NULL }
};

GType
mn_action_get_type (void)
{
	static GType type = 0;
	if ___GOB_UNLIKELY(type == 0)
		type = g_enum_register_static ("MNAction", _mn_action_values);
	return type;
}

static const GEnumValue _mn_expiration_enabled_values[] = {
	{ MN_EXPIRATION_ENABLED_DEFAULT, (char *)"MN_EXPIRATION_ENABLED_DEFAULT", (char *)"default" },
	{ MN_EXPIRATION_ENABLED_FALSE, (char *)"MN_EXPIRATION_ENABLED_FALSE", (char *)"false" },
	{ MN_EXPIRATION_ENABLED_TRUE, (char *)"MN_EXPIRATION_ENABLED_TRUE", (char *)"true" },
	{ 0, NULL, NULL }
};

GType
mn_expiration_enabled_get_type (void)
{
	static GType type = 0;
	if ___GOB_UNLIKELY(type == 0)
		type = g_enum_register_static ("MNExpirationEnabled", _mn_expiration_enabled_values);
	return type;
}

static const GEnumValue _mn_popup_position_values[] = {
	{ MN_POPUP_POSITION_ATTACHED, (char *)"MN_POPUP_POSITION_ATTACHED", (char *)"attached" },
	{ MN_POPUP_POSITION_FREE, (char *)"MN_POPUP_POSITION_FREE", (char *)"free" },
	{ 0, NULL, NULL }
};

GType
mn_popup_position_get_type (void)
{
	static GType type = 0;
	if ___GOB_UNLIKELY(type == 0)
		type = g_enum_register_static ("MNPopupPosition", _mn_popup_position_values);
	return type;
}

