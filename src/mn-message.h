/* Generated by GOB (v2.0.14)   (do not edit directly) */

#include <glib.h>
#include <glib-object.h>


#include <time.h>
#include "mn-mailbox.h"

#ifndef __MN_MESSAGE_H__
#define __MN_MESSAGE_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */



typedef enum
{
  MN_MESSAGE_NEW	= 1 << 0	/* unseen message */
} MNMessageFlags;


/*
 * Type checking and casting macros
 */
#define MN_TYPE_MESSAGE	(mn_message_get_type())
#define MN_MESSAGE(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), mn_message_get_type(), MNMessage)
#define MN_MESSAGE_CONST(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), mn_message_get_type(), MNMessage const)
#define MN_MESSAGE_CLASS(klass)	G_TYPE_CHECK_CLASS_CAST((klass), mn_message_get_type(), MNMessageClass)
#define MN_IS_MESSAGE(obj)	G_TYPE_CHECK_INSTANCE_TYPE((obj), mn_message_get_type ())

#define MN_MESSAGE_GET_CLASS(obj)	G_TYPE_INSTANCE_GET_CLASS((obj), mn_message_get_type(), MNMessageClass)

/*
 * Main object structure
 */
#ifndef __TYPEDEF_MN_MESSAGE__
#define __TYPEDEF_MN_MESSAGE__
typedef struct _MNMessage MNMessage;
#endif
struct _MNMessage {
	GObject __parent__;
	/*< public >*/
	MNMailbox * mailbox;
	char * error;
	time_t sent_time;
	char * id;
	char * from;
	char * subject;
	char * uri;
	MNMessageFlags flags;
};

/*
 * Class definition
 */
typedef struct _MNMessageClass MNMessageClass;
struct _MNMessageClass {
	GObjectClass __parent__;
	gboolean (* can_open_impl) (MNMessage * self);
	gboolean (* open_impl) (MNMessage * self, GError ** err);
	gboolean (* can_mark_as_read_impl) (MNMessage * self);
	gboolean (* mark_as_read_impl) (MNMessage * self, GError ** err);
	gboolean (* can_mark_as_spam) (MNMessage * self);
	gboolean (* can_mark_as_spam_impl) (MNMessage * self);
	gboolean (* mark_as_spam_impl) (MNMessage * self, GError ** err);
	gboolean (* can_delete) (MNMessage * self);
	gboolean (* can_delete_impl) (MNMessage * self);
	gboolean (* delete_impl) (MNMessage * self, GError ** err);
};


/*
 * Public methods
 */
GType	mn_message_get_type	(void);
gboolean 	mn_message_can_open	(MNMessage * self);
gboolean 	mn_message_open	(MNMessage * self,
					GError ** err);
gboolean 	mn_message_can_mark_as_read	(MNMessage * self);
gboolean 	mn_message_mark_as_read	(MNMessage * self,
					GError ** err);
gboolean 	mn_message_can_mark_as_spam	(MNMessage * self);
gboolean 	mn_message_mark_as_spam	(MNMessage * self,
					GError ** err);
gboolean 	mn_message_can_delete	(MNMessage * self);
gboolean 	mn_message_delete	(MNMessage * self,
					GError ** err);
MNMessage * 	mn_message_new	(MNMailbox * mailbox,
					const char * error,
					time_t sent_time,
					const char * id,
					const char * from,
					const char * subject,
					const char * uri,
					MNMessageFlags flags);
MNMessage * 	mn_message_new_from_error	(MNMailbox * mailbox,
					const char * error,
					MNMessageFlags flags);
xmlNode * 	mn_message_xml_node_new	(MNMessage * self);

/*
 * Argument wrapping macros
 */
#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
#define MN_MESSAGE_PROP_MAILBOX(arg)    	"mailbox", __extension__ ({MNMailbox * z = (arg); z;})
#define MN_MESSAGE_GET_PROP_MAILBOX(arg)	"mailbox", __extension__ ({MNMailbox * *z = (arg); z;})
#define MN_MESSAGE_PROP_ERROR(arg)    	"error", __extension__ ({gchar *z = (arg); z;})
#define MN_MESSAGE_GET_PROP_ERROR(arg)	"error", __extension__ ({gchar **z = (arg); z;})
#define MN_MESSAGE_PROP_SENT_TIME(arg)    	"sent_time", __extension__ ({time_t z = (arg); z;})
#define MN_MESSAGE_GET_PROP_SENT_TIME(arg)	"sent_time", __extension__ ({time_t *z = (arg); z;})
#define MN_MESSAGE_PROP_ID(arg)    	"id", __extension__ ({gchar *z = (arg); z;})
#define MN_MESSAGE_GET_PROP_ID(arg)	"id", __extension__ ({gchar **z = (arg); z;})
#define MN_MESSAGE_PROP_FROM(arg)    	"from", __extension__ ({gchar *z = (arg); z;})
#define MN_MESSAGE_GET_PROP_FROM(arg)	"from", __extension__ ({gchar **z = (arg); z;})
#define MN_MESSAGE_PROP_SUBJECT(arg)    	"subject", __extension__ ({gchar *z = (arg); z;})
#define MN_MESSAGE_GET_PROP_SUBJECT(arg)	"subject", __extension__ ({gchar **z = (arg); z;})
#define MN_MESSAGE_PROP_URI(arg)    	"uri", __extension__ ({gchar *z = (arg); z;})
#define MN_MESSAGE_GET_PROP_URI(arg)	"uri", __extension__ ({gchar **z = (arg); z;})
#define MN_MESSAGE_GET_PROP_FILENAME(arg)	"filename", __extension__ ({gchar **z = (arg); z;})
#define MN_MESSAGE_PROP_FLAGS(arg)    	"flags", __extension__ ({guint z = (arg); z;})
#define MN_MESSAGE_GET_PROP_FLAGS(arg)	"flags", __extension__ ({guint *z = (arg); z;})
#else /* __GNUC__ && !__STRICT_ANSI__ */
#define MN_MESSAGE_PROP_MAILBOX(arg)    	"mailbox",(MNMailbox * )(arg)
#define MN_MESSAGE_GET_PROP_MAILBOX(arg)	"mailbox",(MNMailbox * *)(arg)
#define MN_MESSAGE_PROP_ERROR(arg)    	"error",(gchar *)(arg)
#define MN_MESSAGE_GET_PROP_ERROR(arg)	"error",(gchar **)(arg)
#define MN_MESSAGE_PROP_SENT_TIME(arg)    	"sent_time",(time_t )(arg)
#define MN_MESSAGE_GET_PROP_SENT_TIME(arg)	"sent_time",(time_t *)(arg)
#define MN_MESSAGE_PROP_ID(arg)    	"id",(gchar *)(arg)
#define MN_MESSAGE_GET_PROP_ID(arg)	"id",(gchar **)(arg)
#define MN_MESSAGE_PROP_FROM(arg)    	"from",(gchar *)(arg)
#define MN_MESSAGE_GET_PROP_FROM(arg)	"from",(gchar **)(arg)
#define MN_MESSAGE_PROP_SUBJECT(arg)    	"subject",(gchar *)(arg)
#define MN_MESSAGE_GET_PROP_SUBJECT(arg)	"subject",(gchar **)(arg)
#define MN_MESSAGE_PROP_URI(arg)    	"uri",(gchar *)(arg)
#define MN_MESSAGE_GET_PROP_URI(arg)	"uri",(gchar **)(arg)
#define MN_MESSAGE_GET_PROP_FILENAME(arg)	"filename",(gchar **)(arg)
#define MN_MESSAGE_PROP_FLAGS(arg)    	"flags",(guint )(arg)
#define MN_MESSAGE_GET_PROP_FLAGS(arg)	"flags",(guint *)(arg)
#endif /* __GNUC__ && !__STRICT_ANSI__ */


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
