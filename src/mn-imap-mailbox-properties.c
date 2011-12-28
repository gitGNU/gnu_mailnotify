/* Generated by GOB (v2.0.9) on Thu Aug 19 00:41:31 2004
   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 9

#define selfp (self->_priv)

#include "mn-imap-mailbox-properties.h"

#include "mn-imap-mailbox-properties-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 22 "mn-imap-mailbox-properties.gob"

#include "config.h"
#include <glib/gi18n-lib.h>
#include "mn-mailbox-properties.h"
#include "mn-mailbox-properties-util.h"
#include "mn-pi-mailbox-properties-private.h"
#include "mn-uri.h"
#include "mn-auth-combo-box.h"
#include "mn-util.h"

#line 36 "mn-imap-mailbox-properties.c"
/* self casting macros */
#define SELF(x) MN_IMAP_MAILBOX_PROPERTIES(x)
#define SELF_CONST(x) MN_IMAP_MAILBOX_PROPERTIES_CONST(x)
#define IS_SELF(x) MN_IS_IMAP_MAILBOX_PROPERTIES(x)
#define TYPE_SELF MN_TYPE_IMAP_MAILBOX_PROPERTIES
#define SELF_CLASS(x) MN_IMAP_MAILBOX_PROPERTIES_CLASS(x)

#define SELF_GET_CLASS(x) MN_IMAP_MAILBOX_PROPERTIES_GET_CLASS(x)

/* self typedefs */
typedef MNIMAPMailboxProperties Self;
typedef MNIMAPMailboxPropertiesClass SelfClass;

/* here are local prototypes */
static void ___object_get_property (GObject *object, guint property_id, GValue *value, GParamSpec *pspec);
static void mn_imap_mailbox_properties_init (MNIMAPMailboxProperties * o) G_GNUC_UNUSED;
static void mn_imap_mailbox_properties_class_init (MNIMAPMailboxPropertiesClass * class) G_GNUC_UNUSED;
static GObject * ___2_mn_imap_mailbox_properties_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_params) G_GNUC_UNUSED;
static void mn_imap_mailbox_properties_radio_toggled_h (GtkToggleButton * togglebutton, gpointer user_data) G_GNUC_UNUSED;
static gboolean mn_imap_mailbox_properties_set_uri (MNMailboxProperties * properties, const char * uri) G_GNUC_UNUSED;
static char * mn_imap_mailbox_properties_get_uri (MNMailboxProperties * properties) G_GNUC_UNUSED;

enum {
	PROP_0,
	PROP_COMPLETE
};

/* pointer to the class of our parent */
static MNPIMailboxPropertiesClass *parent_class = NULL;

/* Short form macros */
#define self_radio_toggled_h mn_imap_mailbox_properties_radio_toggled_h
#define self_set_uri mn_imap_mailbox_properties_set_uri
#define self_get_uri mn_imap_mailbox_properties_get_uri


static void
___MN_Mailbox_Properties_init (MNMailboxPropertiesIface *iface)
{
#line 146 "mn-imap-mailbox-properties.gob"
	iface->set_uri = self_set_uri;
#line 189 "mn-imap-mailbox-properties.gob"
	iface->get_uri = self_get_uri;
#line 80 "mn-imap-mailbox-properties.c"
}

GType
mn_imap_mailbox_properties_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (MNIMAPMailboxPropertiesClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) mn_imap_mailbox_properties_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (MNIMAPMailboxProperties),
			0 /* n_preallocs */,
			(GInstanceInitFunc) mn_imap_mailbox_properties_init,
			NULL
		};

		static const GInterfaceInfo MN_Mailbox_Properties_info = {
			(GInterfaceInitFunc) ___MN_Mailbox_Properties_init,
			NULL,
			NULL
		};

		type = g_type_register_static (MN_TYPE_PI_MAILBOX_PROPERTIES, "MNIMAPMailboxProperties", &info, (GTypeFlags)0);
		g_type_add_interface_static (type,
			MN_TYPE_MAILBOX_PROPERTIES,
			&MN_Mailbox_Properties_info);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((MNIMAPMailboxProperties *)g_object_new(mn_imap_mailbox_properties_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static MNIMAPMailboxProperties * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static MNIMAPMailboxProperties *
GET_NEW_VARG (const char *first, ...)
{
	MNIMAPMailboxProperties *ret;
	va_list ap;
	va_start (ap, first);
	ret = (MNIMAPMailboxProperties *)g_object_new_valist (mn_imap_mailbox_properties_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox:Properties::finalize"
	MNIMAPMailboxProperties *self  G_GNUC_UNUSED = MN_IMAP_MAILBOX_PROPERTIES (obj_self);
	gpointer priv = self->_priv;
	if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(obj_self);
	g_free (priv);
}
#undef __GOB_FUNCTION__

static void 
mn_imap_mailbox_properties_init (MNIMAPMailboxProperties * o G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox:Properties::init"
	o->_priv = g_new0 (MNIMAPMailboxPropertiesPrivate, 1);
}
#undef __GOB_FUNCTION__
#line 70 "mn-imap-mailbox-properties.gob"
static void 
mn_imap_mailbox_properties_class_init (MNIMAPMailboxPropertiesClass * class G_GNUC_UNUSED)
#line 157 "mn-imap-mailbox-properties.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox:Properties::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) class;

	parent_class = g_type_class_ref (MN_TYPE_PI_MAILBOX_PROPERTIES);

#line 79 "mn-imap-mailbox-properties.gob"
	g_object_class->constructor = ___2_mn_imap_mailbox_properties_constructor;
#line 166 "mn-imap-mailbox-properties.c"
	g_object_class->finalize = ___finalize;
	g_object_class->get_property = ___object_get_property;
    {
	g_object_class_override_property (g_object_class,
		PROP_COMPLETE,
		"complete");
    }
 {
#line 71 "mn-imap-mailbox-properties.gob"

    MNPIMailboxPropertiesClass *pi_class = MN_PI_MAILBOX_PROPERTIES_CLASS(class);

    pi_class->label = "IMAP";
    pi_class->default_port[0] = MN_URI_IMAP_PORT(FALSE);
    pi_class->default_port[1] = MN_URI_IMAP_PORT(TRUE);
  
#line 183 "mn-imap-mailbox-properties.c"
 }
}
#undef __GOB_FUNCTION__

static void
___object_get_property (GObject *object,
	guint property_id,
	GValue *VAL G_GNUC_UNUSED,
	GParamSpec *pspec G_GNUC_UNUSED)
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox:Properties::get_property"
{
	MNIMAPMailboxProperties *self G_GNUC_UNUSED;

	self = MN_IMAP_MAILBOX_PROPERTIES (object);

	switch (property_id) {
	case PROP_COMPLETE:
		{
#line 37 "mn-imap-mailbox-properties.gob"

      MNPIMailboxProperties *pi = MN_PI_MAILBOX_PROPERTIES(self);
      gboolean complete;
      const char *username;
      const char *password;
      const char *hostname;
      gboolean other_active;
      const char *mailbox;
      
      mn_pi_mailbox_properties_get_contents(pi,
					    NULL,
					    &username,
					    &password,
					    NULL,
					    &hostname,
					    NULL);
      
      other_active = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(selfp->other_radio));
      mailbox = gtk_entry_get_text(GTK_ENTRY(selfp->mailbox_entry));

      complete = *username && *password && *hostname && (! other_active || *mailbox);
#ifndef WITH_SSL
      if (complete)
	complete = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(pi->conn_radio[0]));
#endif /* WITH_SSL */

      g_value_set_boolean(VAL, complete);
    
#line 231 "mn-imap-mailbox-properties.c"
		}
		break;
	default:
/* Apparently in g++ this is needed, glib is b0rk */
#ifndef __PRETTY_FUNCTION__
#  undef G_STRLOC
#  define G_STRLOC	__FILE__ ":" G_STRINGIFY (__LINE__)
#endif
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}
#undef __GOB_FUNCTION__



#line 79 "mn-imap-mailbox-properties.gob"
static GObject * 
___2_mn_imap_mailbox_properties_constructor (GType type G_GNUC_UNUSED, guint n_construct_properties, GObjectConstructParam * construct_params)
#line 251 "mn-imap-mailbox-properties.c"
#define PARENT_HANDLER(___type,___n_construct_properties,___construct_params) \
	((G_OBJECT_CLASS(parent_class)->constructor)? \
		(* G_OBJECT_CLASS(parent_class)->constructor)(___type,___n_construct_properties,___construct_params): \
		((GObject * )0))
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox:Properties::constructor"
{
#line 81 "mn-imap-mailbox-properties.gob"
	
    GObject *object;
    Self *self;
    MNPIMailboxProperties *pi;
    GtkWidget *hbox;
    GtkWidget *label;
    
    object = PARENT_HANDLER(type, n_construct_properties, construct_params);
    self = SELF(object);
    pi = MN_PI_MAILBOX_PROPERTIES(object);

    label = gtk_label_new(_("Mailbox:"));
    gtk_misc_set_alignment(GTK_MISC(label), 0.0, 0.5);
    gtk_size_group_add_widget(pi->details_size_group, label);

    selfp->inbox_radio = gtk_radio_button_new_with_mnemonic(NULL, _("in_box"));
    
    hbox = gtk_hbox_new(FALSE, 12);
    gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), selfp->inbox_radio, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(pi->details_vbox), hbox, FALSE, FALSE, 0);
    gtk_widget_show_all(hbox);

    label = gtk_label_new(NULL);
    gtk_size_group_add_widget(pi->details_size_group, label);

    selfp->other_radio = gtk_radio_button_new_with_mnemonic_from_widget(GTK_RADIO_BUTTON(selfp->inbox_radio), _("oth_er:"));
    selfp->mailbox_entry = gtk_entry_new();
    gtk_widget_set_sensitive(selfp->mailbox_entry, FALSE);

    hbox = gtk_hbox_new(FALSE, 12);
    gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), selfp->other_radio, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), selfp->mailbox_entry, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pi->details_vbox), hbox, FALSE, FALSE, 0);
    gtk_widget_show_all(hbox);
    
    mn_auth_combo_box_append(MN_AUTH_COMBO_BOX(pi->auth_combo), "+LOGIN", "IMAP LOGIN");

    mn_tooltips_set_tips(pi->tooltips,
			 pi->hostname_entry, _("The hostname or IP address of the IMAP server"),
			 pi->username_entry, _("Your username on the IMAP server"),
			 pi->password_entry, _("Your password on the IMAP server"),
			 pi->port_spin[0], _("The port number of the IMAP server"),
			 pi->port_spin[1], _("The port number of the IMAP server"),
			 selfp->mailbox_entry, _("The mailbox name"),
			 NULL);

    g_signal_connect(G_OBJECT(selfp->inbox_radio), "toggled", G_CALLBACK(self_radio_toggled_h), self);
    g_signal_connect(G_OBJECT(selfp->other_radio), "toggled", G_CALLBACK(self_radio_toggled_h), self);
    g_signal_connect(G_OBJECT(selfp->mailbox_entry), "changed", G_CALLBACK(mn_pi_mailbox_properties_entry_changed_h), self);
    
    return object;
  }}
#line 314 "mn-imap-mailbox-properties.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 136 "mn-imap-mailbox-properties.gob"
static void 
mn_imap_mailbox_properties_radio_toggled_h (GtkToggleButton * togglebutton, gpointer user_data)
#line 321 "mn-imap-mailbox-properties.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox:Properties::radio_toggled_h"
#line 136 "mn-imap-mailbox-properties.gob"
	g_return_if_fail (togglebutton != NULL);
#line 136 "mn-imap-mailbox-properties.gob"
	g_return_if_fail (GTK_IS_TOGGLE_BUTTON (togglebutton));
#line 136 "mn-imap-mailbox-properties.gob"
	g_return_if_fail (user_data != NULL);
#line 330 "mn-imap-mailbox-properties.c"
{
#line 139 "mn-imap-mailbox-properties.gob"
	
    Self *self = user_data;

    gtk_widget_set_sensitive(selfp->mailbox_entry, gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(selfp->other_radio)));
    g_object_notify(G_OBJECT(self), "complete");
  }}
#line 339 "mn-imap-mailbox-properties.c"
#undef __GOB_FUNCTION__

#line 146 "mn-imap-mailbox-properties.gob"
static gboolean 
mn_imap_mailbox_properties_set_uri (MNMailboxProperties * properties, const char * uri)
#line 345 "mn-imap-mailbox-properties.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox:Properties::set_uri"
#line 146 "mn-imap-mailbox-properties.gob"
	g_return_val_if_fail (properties != NULL, (gboolean )0);
#line 146 "mn-imap-mailbox-properties.gob"
	g_return_val_if_fail (MN_IS_MAILBOX_PROPERTIES (properties), (gboolean )0);
#line 146 "mn-imap-mailbox-properties.gob"
	g_return_val_if_fail (uri != NULL, (gboolean )0);
#line 354 "mn-imap-mailbox-properties.c"
{
#line 149 "mn-imap-mailbox-properties.gob"
	
    Self *self = SELF(properties);
    gboolean ssl;
    char *username;
    char *password;
    char *authmech;
    char *hostname;
    int port;
    char *mailbox;
    
    if (mn_uri_parse_imap(uri, &ssl, &username, &password, &authmech, &hostname, &port, &mailbox))
      {
	mn_pi_mailbox_properties_set_contents(MN_PI_MAILBOX_PROPERTIES(properties),
					      ssl,
					      username,
					      password,
					      authmech,
					      hostname,
					      port);
	
	if (! strcmp(mailbox, "INBOX"))
	  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(selfp->inbox_radio), TRUE);
	else
	  {
	    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(selfp->other_radio), TRUE);
	    gtk_entry_set_text(GTK_ENTRY(selfp->mailbox_entry), mailbox);
	  }

	g_free(username);
	g_free(password);
	g_free(authmech);
	g_free(hostname);
	g_free(mailbox);

	return TRUE;
      }
    else
      return FALSE;
  }}
#line 396 "mn-imap-mailbox-properties.c"
#undef __GOB_FUNCTION__

#line 189 "mn-imap-mailbox-properties.gob"
static char * 
mn_imap_mailbox_properties_get_uri (MNMailboxProperties * properties)
#line 402 "mn-imap-mailbox-properties.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox:Properties::get_uri"
#line 189 "mn-imap-mailbox-properties.gob"
	g_return_val_if_fail (properties != NULL, (char * )0);
#line 189 "mn-imap-mailbox-properties.gob"
	g_return_val_if_fail (MN_IS_MAILBOX_PROPERTIES (properties), (char * )0);
#line 409 "mn-imap-mailbox-properties.c"
{
#line 191 "mn-imap-mailbox-properties.gob"
	
    Self *self = SELF(properties);
    gboolean ssl;
    const char *username;
    const char *password;
    char *authmech;
    const char *hostname;
    int port;
    const char *mailbox = NULL;
    char *uri;

    mn_pi_mailbox_properties_get_contents(MN_PI_MAILBOX_PROPERTIES(properties),
					  &ssl,
					  &username,
					  &password,
					  &authmech,
					  &hostname,
					  &port);

    mailbox = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(selfp->inbox_radio))
      ? "INBOX"
      : gtk_entry_get_text(GTK_ENTRY(selfp->mailbox_entry));

    uri = mn_uri_build_imap(ssl, username, password, authmech, hostname, port, mailbox);
    g_free(authmech);

    return uri;
  }}
#line 440 "mn-imap-mailbox-properties.c"
#undef __GOB_FUNCTION__
