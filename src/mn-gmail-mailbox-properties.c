/* Generated by GOB (v2.0.9) on Thu Aug 19 00:41:31 2004
   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 9

#define selfp (self->_priv)

#include "mn-gmail-mailbox-properties.h"

#include "mn-gmail-mailbox-properties-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 22 "mn-gmail-mailbox-properties.gob"

#include "config.h"
#include <glib/gi18n-lib.h>
#include "mn-mailbox-properties.h"
#include "mn-mailbox-properties-util.h"
#include "mn-uri.h"
#include "mn-util.h"

#line 34 "mn-gmail-mailbox-properties.c"
/* self casting macros */
#define SELF(x) MN_GMAIL_MAILBOX_PROPERTIES(x)
#define SELF_CONST(x) MN_GMAIL_MAILBOX_PROPERTIES_CONST(x)
#define IS_SELF(x) MN_IS_GMAIL_MAILBOX_PROPERTIES(x)
#define TYPE_SELF MN_TYPE_GMAIL_MAILBOX_PROPERTIES
#define SELF_CLASS(x) MN_GMAIL_MAILBOX_PROPERTIES_CLASS(x)

#define SELF_GET_CLASS(x) MN_GMAIL_MAILBOX_PROPERTIES_GET_CLASS(x)

/* self typedefs */
typedef MNGmailMailboxProperties Self;
typedef MNGmailMailboxPropertiesClass SelfClass;

/* here are local prototypes */
static void ___object_set_property (GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);
static void ___object_get_property (GObject *object, guint property_id, GValue *value, GParamSpec *pspec);
static void mn_gmail_mailbox_properties_init (MNGmailMailboxProperties * o) G_GNUC_UNUSED;
static void mn_gmail_mailbox_properties_class_init (MNGmailMailboxPropertiesClass * c) G_GNUC_UNUSED;
static GObject * ___1_mn_gmail_mailbox_properties_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_params) G_GNUC_UNUSED;
static void mn_gmail_mailbox_properties_entry_changed_h (GtkEditable * editable, gpointer user_data) G_GNUC_UNUSED;
static gboolean mn_gmail_mailbox_properties_set_uri (MNMailboxProperties * self, const char * uri) G_GNUC_UNUSED;
static char * mn_gmail_mailbox_properties_get_uri (MNMailboxProperties * self) G_GNUC_UNUSED;

enum {
	PROP_0,
	PROP_LABEL,
	PROP_SIZE_GROUP,
	PROP_COMPLETE
};

/* pointer to the class of our parent */
static GtkVBoxClass *parent_class = NULL;

/* Short form macros */
#define self_entry_changed_h mn_gmail_mailbox_properties_entry_changed_h
#define self_set_uri mn_gmail_mailbox_properties_set_uri
#define self_get_uri mn_gmail_mailbox_properties_get_uri


static void
___MN_Mailbox_Properties_init (MNMailboxPropertiesIface *iface)
{
#line 100 "mn-gmail-mailbox-properties.gob"
	iface->set_uri = self_set_uri;
#line 121 "mn-gmail-mailbox-properties.gob"
	iface->get_uri = self_get_uri;
#line 81 "mn-gmail-mailbox-properties.c"
}

GType
mn_gmail_mailbox_properties_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (MNGmailMailboxPropertiesClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) mn_gmail_mailbox_properties_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (MNGmailMailboxProperties),
			0 /* n_preallocs */,
			(GInstanceInitFunc) mn_gmail_mailbox_properties_init,
			NULL
		};

		static const GInterfaceInfo MN_Mailbox_Properties_info = {
			(GInterfaceInitFunc) ___MN_Mailbox_Properties_init,
			NULL,
			NULL
		};

		type = g_type_register_static (GTK_TYPE_VBOX, "MNGmailMailboxProperties", &info, (GTypeFlags)0);
		g_type_add_interface_static (type,
			MN_TYPE_MAILBOX_PROPERTIES,
			&MN_Mailbox_Properties_info);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((MNGmailMailboxProperties *)g_object_new(mn_gmail_mailbox_properties_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static MNGmailMailboxProperties * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static MNGmailMailboxProperties *
GET_NEW_VARG (const char *first, ...)
{
	MNGmailMailboxProperties *ret;
	va_list ap;
	va_start (ap, first);
	ret = (MNGmailMailboxProperties *)g_object_new_valist (mn_gmail_mailbox_properties_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static void
___dispose (GObject *obj_self)
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox:Properties::dispose"
	MNGmailMailboxProperties *self G_GNUC_UNUSED = MN_GMAIL_MAILBOX_PROPERTIES (obj_self);
	if (G_OBJECT_CLASS (parent_class)->dispose) \
		(* G_OBJECT_CLASS (parent_class)->dispose) (obj_self);
#line 36 "mn-gmail-mailbox-properties.gob"
	if(self->_priv->size_group) { ((*(void (*)(void *))g_object_unref)) (self->_priv->size_group); self->_priv->size_group = NULL; }
#line 145 "mn-gmail-mailbox-properties.c"
#line 53 "mn-gmail-mailbox-properties.gob"
	if(self->_priv->tooltips) { ((*(void (*)(void *))g_object_unref)) (self->_priv->tooltips); self->_priv->tooltips = NULL; }
#line 148 "mn-gmail-mailbox-properties.c"
}
#undef __GOB_FUNCTION__


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox:Properties::finalize"
	MNGmailMailboxProperties *self  G_GNUC_UNUSED = MN_GMAIL_MAILBOX_PROPERTIES (obj_self);
	gpointer priv = self->_priv;
	if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(obj_self);
	g_free (priv);
}
#undef __GOB_FUNCTION__

static void 
mn_gmail_mailbox_properties_init (MNGmailMailboxProperties * o G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox:Properties::init"
	o->_priv = g_new0 (MNGmailMailboxPropertiesPrivate, 1);
#line 53 "mn-gmail-mailbox-properties.gob"
	o->_priv->tooltips = mn_tooltips_new();
#line 172 "mn-gmail-mailbox-properties.c"
}
#undef __GOB_FUNCTION__
static void 
mn_gmail_mailbox_properties_class_init (MNGmailMailboxPropertiesClass * c G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox:Properties::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) c;

	parent_class = g_type_class_ref (GTK_TYPE_VBOX);

#line 55 "mn-gmail-mailbox-properties.gob"
	g_object_class->constructor = ___1_mn_gmail_mailbox_properties_constructor;
#line 185 "mn-gmail-mailbox-properties.c"
	g_object_class->dispose = ___dispose;
	g_object_class->finalize = ___finalize;
	g_object_class->get_property = ___object_get_property;
	g_object_class->set_property = ___object_set_property;
    {
	g_object_class_override_property (g_object_class,
		PROP_LABEL,
		"label");
	g_object_class_override_property (g_object_class,
		PROP_SIZE_GROUP,
		"size_group");
	g_object_class_override_property (g_object_class,
		PROP_COMPLETE,
		"complete");
    }
}
#undef __GOB_FUNCTION__

static void
___object_set_property (GObject *object,
	guint property_id,
	const GValue *VAL G_GNUC_UNUSED,
	GParamSpec *pspec G_GNUC_UNUSED)
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox:Properties::set_property"
{
	MNGmailMailboxProperties *self G_GNUC_UNUSED;

	self = MN_GMAIL_MAILBOX_PROPERTIES (object);

	switch (property_id) {
	case PROP_SIZE_GROUP:
		{
#line 37 "mn-gmail-mailbox-properties.gob"
{ GObject *___old = (GObject *)self->_priv->size_group; self->_priv->size_group = (void *)g_value_dup_object (VAL); if (___old != NULL) { g_object_unref (G_OBJECT (___old)); } }
#line 220 "mn-gmail-mailbox-properties.c"
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

static void
___object_get_property (GObject *object,
	guint property_id,
	GValue *VAL G_GNUC_UNUSED,
	GParamSpec *pspec G_GNUC_UNUSED)
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox:Properties::get_property"
{
	MNGmailMailboxProperties *self G_GNUC_UNUSED;

	self = MN_GMAIL_MAILBOX_PROPERTIES (object);

	switch (property_id) {
	case PROP_LABEL:
		{
#line 34 "mn-gmail-mailbox-properties.gob"
 g_value_set_string(VAL, "Gmail"); 
#line 251 "mn-gmail-mailbox-properties.c"
		}
		break;
	case PROP_SIZE_GROUP:
		{
#line 37 "mn-gmail-mailbox-properties.gob"
g_value_set_object (VAL, (gpointer)self->_priv->size_group);
#line 258 "mn-gmail-mailbox-properties.c"
		}
		break;
	case PROP_COMPLETE:
		{
#line 41 "mn-gmail-mailbox-properties.gob"

      const char *username;
      const char *password;

      username = gtk_entry_get_text(GTK_ENTRY(selfp->username_entry));
      password = gtk_entry_get_text(GTK_ENTRY(selfp->password_entry));
      
      g_value_set_boolean(VAL, *username && *password);
    
#line 273 "mn-gmail-mailbox-properties.c"
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



#line 55 "mn-gmail-mailbox-properties.gob"
static GObject * 
___1_mn_gmail_mailbox_properties_constructor (GType type G_GNUC_UNUSED, guint n_construct_properties, GObjectConstructParam * construct_params)
#line 293 "mn-gmail-mailbox-properties.c"
#define PARENT_HANDLER(___type,___n_construct_properties,___construct_params) \
	((G_OBJECT_CLASS(parent_class)->constructor)? \
		(* G_OBJECT_CLASS(parent_class)->constructor)(___type,___n_construct_properties,___construct_params): \
		((GObject * )0))
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox:Properties::constructor"
{
#line 57 "mn-gmail-mailbox-properties.gob"
	
    GObject *object;
    Self *self;
    GtkWidget *label1;
    GtkWidget *label2;

    object = PARENT_HANDLER(type, n_construct_properties, construct_params);
    self = SELF(object);

    gtk_box_set_spacing(GTK_BOX(self), 6);

    mn_mailbox_properties_credentials_new(GTK_VBOX(self),
					  &label1,
					  &selfp->username_entry,
					  &label2,
					  &selfp->password_entry);

    gtk_size_group_add_widget(selfp->size_group, label1);
    gtk_size_group_add_widget(selfp->size_group, label2);

    mn_tooltips_set_tips(selfp->tooltips,
			 selfp->username_entry, _("Your Gmail username"),
			 selfp->password_entry, _("Your Gmail password"),
			 NULL);

    mn_mailbox_properties_link_entries(GTK_ENTRY(selfp->username_entry),
				       GTK_ENTRY(selfp->password_entry),
				       NULL);

    g_signal_connect(G_OBJECT(selfp->username_entry), "changed", G_CALLBACK(self_entry_changed_h), self);
    g_signal_connect(G_OBJECT(selfp->password_entry), "changed", G_CALLBACK(self_entry_changed_h), self);
    
    return object;
  }}
#line 336 "mn-gmail-mailbox-properties.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 92 "mn-gmail-mailbox-properties.gob"
static void 
mn_gmail_mailbox_properties_entry_changed_h (GtkEditable * editable, gpointer user_data)
#line 343 "mn-gmail-mailbox-properties.c"
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox:Properties::entry_changed_h"
#line 92 "mn-gmail-mailbox-properties.gob"
	g_return_if_fail (editable != NULL);
#line 92 "mn-gmail-mailbox-properties.gob"
	g_return_if_fail (GTK_IS_EDITABLE (editable));
#line 92 "mn-gmail-mailbox-properties.gob"
	g_return_if_fail (user_data != NULL);
#line 352 "mn-gmail-mailbox-properties.c"
{
#line 95 "mn-gmail-mailbox-properties.gob"
	
    Self *self = user_data;
    g_object_notify(G_OBJECT(self), "complete");
  }}
#line 359 "mn-gmail-mailbox-properties.c"
#undef __GOB_FUNCTION__

#line 100 "mn-gmail-mailbox-properties.gob"
static gboolean 
mn_gmail_mailbox_properties_set_uri (MNMailboxProperties * self, const char * uri)
#line 365 "mn-gmail-mailbox-properties.c"
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox:Properties::set_uri"
#line 100 "mn-gmail-mailbox-properties.gob"
	g_return_val_if_fail (self != NULL, (gboolean )0);
#line 100 "mn-gmail-mailbox-properties.gob"
	g_return_val_if_fail (MN_IS_MAILBOX_PROPERTIES (self), (gboolean )0);
#line 100 "mn-gmail-mailbox-properties.gob"
	g_return_val_if_fail (uri != NULL, (gboolean )0);
#line 374 "mn-gmail-mailbox-properties.c"
{
#line 103 "mn-gmail-mailbox-properties.gob"
	
    char *username;
    char *password;

    if (mn_uri_parse_gmail(uri, &username, &password))
      {
	gtk_entry_set_text(GTK_ENTRY(SELF(self)->_priv->username_entry), username);
	gtk_entry_set_text(GTK_ENTRY(SELF(self)->_priv->password_entry), password);

	g_free(username);
	g_free(password);

	return TRUE;
      }
    else
      return FALSE;
  }}
#line 394 "mn-gmail-mailbox-properties.c"
#undef __GOB_FUNCTION__

#line 121 "mn-gmail-mailbox-properties.gob"
static char * 
mn_gmail_mailbox_properties_get_uri (MNMailboxProperties * self)
#line 400 "mn-gmail-mailbox-properties.c"
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox:Properties::get_uri"
#line 121 "mn-gmail-mailbox-properties.gob"
	g_return_val_if_fail (self != NULL, (char * )0);
#line 121 "mn-gmail-mailbox-properties.gob"
	g_return_val_if_fail (MN_IS_MAILBOX_PROPERTIES (self), (char * )0);
#line 407 "mn-gmail-mailbox-properties.c"
{
#line 123 "mn-gmail-mailbox-properties.gob"
	
    const char *username;
    const char *password;

    username = gtk_entry_get_text(GTK_ENTRY(SELF(self)->_priv->username_entry));
    password = gtk_entry_get_text(GTK_ENTRY(SELF(self)->_priv->password_entry));

    return mn_uri_build_gmail(username, password);
  }}
#line 419 "mn-gmail-mailbox-properties.c"
#undef __GOB_FUNCTION__