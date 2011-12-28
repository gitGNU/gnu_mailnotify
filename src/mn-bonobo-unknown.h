/* Generated by GOB (v2.0.14)   (do not edit directly) */

#include <glib.h>
#include <glib-object.h>


#include <libbonobo.h>

#ifndef __MN_BONOBO_UNKNOWN_H__
#define __MN_BONOBO_UNKNOWN_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*
 * Type checking and casting macros
 */
#define MN_TYPE_BONOBO_UNKNOWN	(mn_bonobo_unknown_get_type())
#define MN_BONOBO_UNKNOWN(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), mn_bonobo_unknown_get_type(), MNBonoboUnknown)
#define MN_BONOBO_UNKNOWN_CONST(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), mn_bonobo_unknown_get_type(), MNBonoboUnknown const)
#define MN_BONOBO_UNKNOWN_CLASS(klass)	G_TYPE_CHECK_CLASS_CAST((klass), mn_bonobo_unknown_get_type(), MNBonoboUnknownClass)
#define MN_IS_BONOBO_UNKNOWN(obj)	G_TYPE_CHECK_INSTANCE_TYPE((obj), mn_bonobo_unknown_get_type ())

#define MN_BONOBO_UNKNOWN_GET_CLASS(obj)	G_TYPE_INSTANCE_GET_CLASS((obj), mn_bonobo_unknown_get_type(), MNBonoboUnknownClass)

/* Private structure type */
typedef struct _MNBonoboUnknownPrivate MNBonoboUnknownPrivate;

/*
 * Main object structure
 */
#ifndef __TYPEDEF_MN_BONOBO_UNKNOWN__
#define __TYPEDEF_MN_BONOBO_UNKNOWN__
typedef struct _MNBonoboUnknown MNBonoboUnknown;
#endif
struct _MNBonoboUnknown {
	GObject __parent__;
	/*< private >*/
	MNBonoboUnknownPrivate *_priv;
};

/*
 * Class definition
 */
typedef struct _MNBonoboUnknownClass MNBonoboUnknownClass;
struct _MNBonoboUnknownClass {
	GObjectClass __parent__;
};


/*
 * Public methods
 */
GType	mn_bonobo_unknown_get_type	(void);
Bonobo_Unknown 	mn_bonobo_unknown_get_object	(MNBonoboUnknown * self);
void 	mn_bonobo_unknown_set_object	(MNBonoboUnknown * self,
					Bonobo_Unknown val);
MNBonoboUnknown * 	mn_bonobo_unknown_new	(const char * iid);

/*
 * Argument wrapping macros
 */
#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
#define MN_BONOBO_UNKNOWN_PROP_OBJECT(arg)    	"object", __extension__ ({Bonobo_Unknown z = (arg); z;})
#define MN_BONOBO_UNKNOWN_GET_PROP_OBJECT(arg)	"object", __extension__ ({Bonobo_Unknown *z = (arg); z;})
#define MN_BONOBO_UNKNOWN_PROP_IID(arg)    	"iid", __extension__ ({gchar *z = (arg); z;})
#define MN_BONOBO_UNKNOWN_GET_PROP_IID(arg)	"iid", __extension__ ({gchar **z = (arg); z;})
#else /* __GNUC__ && !__STRICT_ANSI__ */
#define MN_BONOBO_UNKNOWN_PROP_OBJECT(arg)    	"object",(Bonobo_Unknown )(arg)
#define MN_BONOBO_UNKNOWN_GET_PROP_OBJECT(arg)	"object",(Bonobo_Unknown *)(arg)
#define MN_BONOBO_UNKNOWN_PROP_IID(arg)    	"iid",(gchar *)(arg)
#define MN_BONOBO_UNKNOWN_GET_PROP_IID(arg)	"iid",(gchar **)(arg)
#endif /* __GNUC__ && !__STRICT_ANSI__ */


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif