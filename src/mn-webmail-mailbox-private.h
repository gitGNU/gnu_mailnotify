/* Generated by GOB (v2.0.14)   (do not edit directly) */

#ifndef __MN_WEBMAIL_MAILBOX_PRIVATE_H__
#define __MN_WEBMAIL_MAILBOX_PRIVATE_H__

#include "mn-webmail-mailbox.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void 	mn_webmail_mailbox_parse_username	(MNWebmailMailbox * self, char ** username, char ** domain);
char * 	mn_webmail_mailbox_create_spool_file	(GError ** err);
char * 	mn_webmail_mailbox_write_temporary_file	(const char * contents, GError ** err);
void 	mn_webmail_mailbox_display_config	(MNWebmailMailbox * self, const char * config);
gboolean 	mn_webmail_mailbox_run_helper	(MNWebmailMailbox * self, const char * name, const char * command, GError ** err);
gboolean 	mn_webmail_mailbox_read_spool_file	(MNWebmailMailbox * self, const char * spool_file, GError ** err);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
