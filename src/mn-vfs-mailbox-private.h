/* Generated by GOB (v2.0.14)   (do not edit directly) */

#ifndef __MN_VFS_MAILBOX_PRIVATE_H__
#define __MN_VFS_MAILBOX_PRIVATE_H__

#include "mn-vfs-mailbox.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#line 31 "mn-vfs-mailbox.gob"

#include "mn-locked-callback.h"
#include "mn-vfs-mailbox-backend.h"

#line 19 "mn-vfs-mailbox-private.h"
struct _MNVFSMailboxPrivate {
#line 76 "mn-vfs-mailbox.gob"
	GSList * monitors;
#line 77 "mn-vfs-mailbox.gob"
	MNVFSMailboxBackend * backend;
#line 78 "mn-vfs-mailbox.gob"
	MNLockedGSource * update_poll_source;
#line 27 "mn-vfs-mailbox-private.h"
};
void 	mn_vfs_mailbox_monitor	(MNVFSMailbox * self, const char * uri, MNVFSMailboxBackend * owner, GnomeVFSMonitorType type, GnomeVFSMonitorCallback callback, gpointer user_data);
void 	mn_vfs_mailbox_remove_monitors_by_owner	(MNVFSMailbox * self, MNVFSMailboxBackend * owner);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif