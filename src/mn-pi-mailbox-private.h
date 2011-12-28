/* Generated by GOB (v2.0.14)   (do not edit directly) */

#ifndef __MN_PI_MAILBOX_PRIVATE_H__
#define __MN_PI_MAILBOX_PRIVATE_H__

#include "mn-pi-mailbox.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#line 29 "mn-pi-mailbox.gob"

#include <gtk/gtk.h>
#include "mn-client-session.h"

#define MN_PI_MAILBOX_SESSION_PRIVATE \
  MNMailbox		*mailbox;	\
  MNPIMailbox		*pi_mailbox;	\
  MNClientSession	*session

#line 24 "mn-pi-mailbox-private.h"
struct _MNPIMailboxPrivate {
#line 90 "mn-pi-mailbox.gob"
	GtkWidget * auth_dialog;
#line 93 "mn-pi-mailbox.gob"
	gboolean auth_failed;
#line 30 "mn-pi-mailbox-private.h"
};
gboolean 	mn_pi_mailbox_split_uri	(const char * uri, int maxlen, char * scheme, char * auth, char * location, gboolean * has_auth);
gboolean 	mn_pi_mailbox_split_uri_auth	(const char * auth, int maxlen, char * username, char * authmech, gboolean * has_username, gboolean * has_authmech);
void 	mn_pi_mailbox_split_uri_hostport	(const char * hostport, int maxlen, char * hostname, int * port);
void 	mn_pi_mailbox_auth_failed	(MNPIMailbox * self);
gboolean 	mn_pi_mailbox_fill_credentials	(MNPIMailbox * self, gboolean need_username, gboolean need_password);
void 	mn_pi_mailbox_session_private_init	(MNPIMailbox * self, MNClientSessionPrivate * priv);
gboolean 	mn_pi_mailbox_sasl_get_credentials_cb	(MNClientSession * session, MNClientSessionPrivate * priv, const char ** username, const char ** password);
void 	mn_pi_mailbox_notice_cb	(MNClientSession * session, const char * message, MNClientSessionPrivate * priv);
void 	mn_pi_mailbox_warning_cb	(MNClientSession * session, const char * message, MNClientSessionPrivate * priv);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif