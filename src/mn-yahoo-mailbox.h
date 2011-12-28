/* Generated by GOB (v2.0.14)   (do not edit directly) */

#include <glib.h>
#include <glib-object.h>


#include "mn-webmail-mailbox.h"

#ifndef __MN_YAHOO_MAILBOX_H__
#define __MN_YAHOO_MAILBOX_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*
 * Type checking and casting macros
 */
#define MN_TYPE_YAHOO_MAILBOX	(mn_yahoo_mailbox_get_type())
#define MN_YAHOO_MAILBOX(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), mn_yahoo_mailbox_get_type(), MNYahooMailbox)
#define MN_YAHOO_MAILBOX_CONST(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), mn_yahoo_mailbox_get_type(), MNYahooMailbox const)
#define MN_YAHOO_MAILBOX_CLASS(klass)	G_TYPE_CHECK_CLASS_CAST((klass), mn_yahoo_mailbox_get_type(), MNYahooMailboxClass)
#define MN_IS_YAHOO_MAILBOX(obj)	G_TYPE_CHECK_INSTANCE_TYPE((obj), mn_yahoo_mailbox_get_type ())

#define MN_YAHOO_MAILBOX_GET_CLASS(obj)	G_TYPE_INSTANCE_GET_CLASS((obj), mn_yahoo_mailbox_get_type(), MNYahooMailboxClass)

/*
 * Main object structure
 */
#ifndef __TYPEDEF_MN_YAHOO_MAILBOX__
#define __TYPEDEF_MN_YAHOO_MAILBOX__
typedef struct _MNYahooMailbox MNYahooMailbox;
#endif
struct _MNYahooMailbox {
	MNWebmailMailbox __parent__;
};

/*
 * Class definition
 */
typedef struct _MNYahooMailboxClass MNYahooMailboxClass;
struct _MNYahooMailboxClass {
	MNWebmailMailboxClass __parent__;
};


/*
 * Public methods
 */
GType	mn_yahoo_mailbox_get_type	(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
