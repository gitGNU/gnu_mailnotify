/* Generated by GOB (v2.0.14)   (do not edit directly) */

#ifndef __MN_BONOBO_UNKNOWN_PRIVATE_H__
#define __MN_BONOBO_UNKNOWN_PRIVATE_H__

#include "mn-bonobo-unknown.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#line 29 "mn-bonobo-unknown.gob"

#include "mn-locked-callback.h"

#line 18 "mn-bonobo-unknown-private.h"
struct _MNBonoboUnknownPrivate {
#line 39 "mn-bonobo-unknown.gob"
	Bonobo_Unknown object;
#line 53 "mn-bonobo-unknown.gob"
	char * iid;
#line 56 "mn-bonobo-unknown.gob"
	MNLockedGSource * monitor_source;
#line 26 "mn-bonobo-unknown-private.h"
};

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif