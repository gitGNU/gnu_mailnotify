/* Generated by GOB (v2.0.9) on Mon Aug 16 18:13:53 2004
   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 9

#define selfp (self->_priv)

#include <string.h> /* memset() */

#include "mn-unsupported-mailbox.h"

#include "mn-unsupported-mailbox-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 22 "mn-unsupported-mailbox.gob"

#include "config.h"
#include <glib/gi18n-lib.h>
#include "mn-stock.h"

#line 33 "mn-unsupported-mailbox.c"
/* self casting macros */
#define SELF(x) MN_UNSUPPORTED_MAILBOX(x)
#define SELF_CONST(x) MN_UNSUPPORTED_MAILBOX_CONST(x)
#define IS_SELF(x) MN_IS_UNSUPPORTED_MAILBOX(x)
#define TYPE_SELF MN_TYPE_UNSUPPORTED_MAILBOX
#define SELF_CLASS(x) MN_UNSUPPORTED_MAILBOX_CLASS(x)

#define SELF_GET_CLASS(x) MN_UNSUPPORTED_MAILBOX_GET_CLASS(x)

/* self typedefs */
typedef MNUnsupportedMailbox Self;
typedef MNUnsupportedMailboxClass SelfClass;

/* here are local prototypes */
static void ___object_set_property (GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);
static void ___object_get_property (GObject *object, guint property_id, GValue *value, GParamSpec *pspec);
static void mn_unsupported_mailbox_init (MNUnsupportedMailbox * o) G_GNUC_UNUSED;
static void mn_unsupported_mailbox_class_init (MNUnsupportedMailboxClass * class) G_GNUC_UNUSED;

enum {
	PROP_0,
	PROP_REASON
};

/* pointer to the class of our parent */
static MNMailboxClass *parent_class = NULL;

/* Short form macros */
#define self_get_reason mn_unsupported_mailbox_get_reason
#define self_new mn_unsupported_mailbox_new
GType
mn_unsupported_mailbox_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (MNUnsupportedMailboxClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) mn_unsupported_mailbox_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (MNUnsupportedMailbox),
			0 /* n_preallocs */,
			(GInstanceInitFunc) mn_unsupported_mailbox_init,
			NULL
		};

		type = g_type_register_static (MN_TYPE_MAILBOX, "MNUnsupportedMailbox", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((MNUnsupportedMailbox *)g_object_new(mn_unsupported_mailbox_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static MNUnsupportedMailbox * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static MNUnsupportedMailbox *
GET_NEW_VARG (const char *first, ...)
{
	MNUnsupportedMailbox *ret;
	va_list ap;
	va_start (ap, first);
	ret = (MNUnsupportedMailbox *)g_object_new_valist (mn_unsupported_mailbox_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "MN:Unsupported:Mailbox::finalize"
	MNUnsupportedMailbox *self  G_GNUC_UNUSED = MN_UNSUPPORTED_MAILBOX (obj_self);
	gpointer priv = self->_priv;
	if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(obj_self);
#line 30 "mn-unsupported-mailbox.gob"
	if(self->_priv->reason) { ((*(void (*)(void *))g_free)) (self->_priv->reason); self->_priv->reason = NULL; }
#line 117 "mn-unsupported-mailbox.c"
	g_free (priv);
}
#undef __GOB_FUNCTION__

static void 
mn_unsupported_mailbox_init (MNUnsupportedMailbox * o G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:Unsupported:Mailbox::init"
	o->_priv = g_new0 (MNUnsupportedMailboxPrivate, 1);
}
#undef __GOB_FUNCTION__
#line 35 "mn-unsupported-mailbox.gob"
static void 
mn_unsupported_mailbox_class_init (MNUnsupportedMailboxClass * class G_GNUC_UNUSED)
#line 132 "mn-unsupported-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:Unsupported:Mailbox::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) class;

	parent_class = g_type_class_ref (MN_TYPE_MAILBOX);

	g_object_class->finalize = ___finalize;
	g_object_class->get_property = ___object_get_property;
	g_object_class->set_property = ___object_set_property;
    {
	GParamSpec   *param_spec;

	param_spec = g_param_spec_string
		("reason" /* name */,
		 NULL /* nick */,
		 _("The reason why the mailbox is unsupported") /* blurb */,
		 NULL /* default_value */,
		 (GParamFlags)(G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (g_object_class,
		PROP_REASON,
		param_spec);
    }
 {
#line 36 "mn-unsupported-mailbox.gob"

    MN_MAILBOX_CLASS(class)->stock_id = MN_STOCK_UNSUPPORTED;
    MN_MAILBOX_CLASS(class)->format = _("unsupported");
  
#line 161 "mn-unsupported-mailbox.c"
 }
}
#undef __GOB_FUNCTION__

static void
___object_set_property (GObject *object,
	guint property_id,
	const GValue *VAL G_GNUC_UNUSED,
	GParamSpec *pspec G_GNUC_UNUSED)
#define __GOB_FUNCTION__ "MN:Unsupported:Mailbox::set_property"
{
	MNUnsupportedMailbox *self G_GNUC_UNUSED;

	self = MN_UNSUPPORTED_MAILBOX (object);

	switch (property_id) {
	case PROP_REASON:
		{
#line 31 "mn-unsupported-mailbox.gob"
{ char *old = self->_priv->reason; self->_priv->reason = g_value_dup_string (VAL); g_free (old); }
#line 182 "mn-unsupported-mailbox.c"
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
#define __GOB_FUNCTION__ "MN:Unsupported:Mailbox::get_property"
{
	MNUnsupportedMailbox *self G_GNUC_UNUSED;

	self = MN_UNSUPPORTED_MAILBOX (object);

	switch (property_id) {
	case PROP_REASON:
		{
#line 31 "mn-unsupported-mailbox.gob"
g_value_set_string (VAL, self->_priv->reason);
#line 213 "mn-unsupported-mailbox.c"
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


#line 33 "mn-unsupported-mailbox.gob"
const char * 
mn_unsupported_mailbox_get_reason (MNUnsupportedMailbox * self)
#line 232 "mn-unsupported-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:Unsupported:Mailbox::get_reason"
#line 33 "mn-unsupported-mailbox.gob"
	g_return_val_if_fail (self != NULL, (const char * )0);
#line 33 "mn-unsupported-mailbox.gob"
	g_return_val_if_fail (MN_IS_UNSUPPORTED_MAILBOX (self), (const char * )0);
#line 239 "mn-unsupported-mailbox.c"
{
#line 33 "mn-unsupported-mailbox.gob"
	 return selfp->reason; }}
#line 243 "mn-unsupported-mailbox.c"
#undef __GOB_FUNCTION__


#line 41 "mn-unsupported-mailbox.gob"
MNMailbox * 
mn_unsupported_mailbox_new (const char * uri, const char * reason)
#line 250 "mn-unsupported-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:Unsupported:Mailbox::new"
#line 41 "mn-unsupported-mailbox.gob"
	g_return_val_if_fail (uri != NULL, (MNMailbox * )0);
#line 41 "mn-unsupported-mailbox.gob"
	g_return_val_if_fail (reason != NULL, (MNMailbox * )0);
#line 257 "mn-unsupported-mailbox.c"
{
#line 44 "mn-unsupported-mailbox.gob"
	
    return g_object_new(TYPE_SELF,
			MN_MAILBOX_PROP_URI((char *) uri),
			MN_UNSUPPORTED_MAILBOX_PROP_REASON((char *) reason),
			NULL);
  }}
#line 266 "mn-unsupported-mailbox.c"
#undef __GOB_FUNCTION__
