/* Generated by GOB (v2.0.14)   (do not edit directly) */

#ifndef __MN_PI_MAILBOX_PROPERTIES_PRIVATE_H__
#define __MN_PI_MAILBOX_PROPERTIES_PRIVATE_H__

#include "mn-pi-mailbox-properties.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void 	mn_pi_mailbox_properties_get_contents	(MNPIMailboxProperties * self, MNPIMailboxConnectionType * connection_type, char ** authmech, const char ** hostname, int * port);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
