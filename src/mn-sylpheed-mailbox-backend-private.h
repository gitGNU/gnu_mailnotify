/* Generated by GOB (v2.0.14)   (do not edit directly) */

#ifndef __MN_SYLPHEED_MAILBOX_BACKEND_PRIVATE_H__
#define __MN_SYLPHEED_MAILBOX_BACKEND_PRIVATE_H__

#include "mn-sylpheed-mailbox-backend.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#line 25 "mn-sylpheed-mailbox-backend.gob"

#include "mn-locked-callback.h"

#line 18 "mn-sylpheed-mailbox-backend-private.h"
struct _MNSylpheedMailboxBackendPrivate {
#line 70 "mn-sylpheed-mailbox-backend.gob"
	MNLockedGSource * monitor_timeout_source;
#line 71 "mn-sylpheed-mailbox-backend.gob"
	gboolean can_lock_mark_file;
#line 24 "mn-sylpheed-mailbox-backend-private.h"
};

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif