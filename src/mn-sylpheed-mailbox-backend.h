/* Generated by GOB (v2.0.14)   (do not edit directly) */

#include <glib.h>
#include <glib-object.h>


#include "mn-vfs-mailbox-backend.h"

#ifndef __MN_SYLPHEED_MAILBOX_BACKEND_H__
#define __MN_SYLPHEED_MAILBOX_BACKEND_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*
 * Type checking and casting macros
 */
#define MN_TYPE_SYLPHEED_MAILBOX_BACKEND	(mn_sylpheed_mailbox_backend_get_type())
#define MN_SYLPHEED_MAILBOX_BACKEND(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), mn_sylpheed_mailbox_backend_get_type(), MNSylpheedMailboxBackend)
#define MN_SYLPHEED_MAILBOX_BACKEND_CONST(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), mn_sylpheed_mailbox_backend_get_type(), MNSylpheedMailboxBackend const)
#define MN_SYLPHEED_MAILBOX_BACKEND_CLASS(klass)	G_TYPE_CHECK_CLASS_CAST((klass), mn_sylpheed_mailbox_backend_get_type(), MNSylpheedMailboxBackendClass)
#define MN_IS_SYLPHEED_MAILBOX_BACKEND(obj)	G_TYPE_CHECK_INSTANCE_TYPE((obj), mn_sylpheed_mailbox_backend_get_type ())

#define MN_SYLPHEED_MAILBOX_BACKEND_GET_CLASS(obj)	G_TYPE_INSTANCE_GET_CLASS((obj), mn_sylpheed_mailbox_backend_get_type(), MNSylpheedMailboxBackendClass)

/* Private structure type */
typedef struct _MNSylpheedMailboxBackendPrivate MNSylpheedMailboxBackendPrivate;

/*
 * Main object structure
 */
#ifndef __TYPEDEF_MN_SYLPHEED_MAILBOX_BACKEND__
#define __TYPEDEF_MN_SYLPHEED_MAILBOX_BACKEND__
typedef struct _MNSylpheedMailboxBackend MNSylpheedMailboxBackend;
#endif
struct _MNSylpheedMailboxBackend {
	MNVFSMailboxBackend __parent__;
	/*< private >*/
	MNSylpheedMailboxBackendPrivate *_priv;
};

/*
 * Class definition
 */
typedef struct _MNSylpheedMailboxBackendClass MNSylpheedMailboxBackendClass;
struct _MNSylpheedMailboxBackendClass {
	MNVFSMailboxBackendClass __parent__;
};


/*
 * Public methods
 */
GType	mn_sylpheed_mailbox_backend_get_type	(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif