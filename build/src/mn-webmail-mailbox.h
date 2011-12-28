/* Generated by GOB (v2.0.15)   (do not edit directly) */

#include <glib.h>
#include <glib-object.h>


#include "mn-authenticated-mailbox.h"

#ifndef __MN_WEBMAIL_MAILBOX_H__
#define __MN_WEBMAIL_MAILBOX_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*
 * Type checking and casting macros
 */
#define MN_TYPE_WEBMAIL_MAILBOX	(mn_webmail_mailbox_get_type())
#define MN_WEBMAIL_MAILBOX(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), mn_webmail_mailbox_get_type(), MNWebmailMailbox)
#define MN_WEBMAIL_MAILBOX_CONST(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), mn_webmail_mailbox_get_type(), MNWebmailMailbox const)
#define MN_WEBMAIL_MAILBOX_CLASS(klass)	G_TYPE_CHECK_CLASS_CAST((klass), mn_webmail_mailbox_get_type(), MNWebmailMailboxClass)
#define MN_IS_WEBMAIL_MAILBOX(obj)	G_TYPE_CHECK_INSTANCE_TYPE((obj), mn_webmail_mailbox_get_type ())

#define MN_WEBMAIL_MAILBOX_GET_CLASS(obj)	G_TYPE_INSTANCE_GET_CLASS((obj), mn_webmail_mailbox_get_type(), MNWebmailMailboxClass)

/*
 * Main object structure
 */
#ifndef __TYPEDEF_MN_WEBMAIL_MAILBOX__
#define __TYPEDEF_MN_WEBMAIL_MAILBOX__
typedef struct _MNWebmailMailbox MNWebmailMailbox;
#endif
struct _MNWebmailMailbox {
	MNAuthenticatedMailbox __parent__;
	/*< public >*/
	char * folder;
};

/*
 * Class definition
 */
typedef struct _MNWebmailMailboxClass MNWebmailMailboxClass;
struct _MNWebmailMailboxClass {
	MNAuthenticatedMailboxClass __parent__;
	char * (* get_error_message) (MNWebmailMailbox * self, const char * helper_stdout, const char * helper_stderr, gboolean * is_auth_failure);
	gboolean (* webmail_check) (MNWebmailMailbox * self, GError ** err);
	const char * default_domain;
};


/*
 * Public methods
 */
GType	mn_webmail_mailbox_get_type	(void) G_GNUC_CONST;
#line 351 "src/mn-webmail-mailbox.gob"
char * 	mn_webmail_mailbox_build_name	(MNWebmailMailboxClass * class,
					const char * username,
					const char * folder);
#line 62 "mn-webmail-mailbox.h"

/*
 * Argument wrapping macros
 */
#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
#define MN_WEBMAIL_MAILBOX_PROP_FOLDER(arg)    	"folder", __extension__ ({gchar *z = (arg); z;})
#define MN_WEBMAIL_MAILBOX_GET_PROP_FOLDER(arg)	"folder", __extension__ ({gchar **z = (arg); z;})
#else /* __GNUC__ && !__STRICT_ANSI__ */
#define MN_WEBMAIL_MAILBOX_PROP_FOLDER(arg)    	"folder",(gchar *)(arg)
#define MN_WEBMAIL_MAILBOX_GET_PROP_FOLDER(arg)	"folder",(gchar **)(arg)
#endif /* __GNUC__ && !__STRICT_ANSI__ */


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif