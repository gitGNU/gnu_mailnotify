/* Generated by GOB (v2.0.9) on Mon Aug 16 18:13:52 2004
   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 9

#define selfp (self->_priv)

#include "mn-imap-mailbox.h"

#include "mn-imap-mailbox-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 25 "mn-imap-mailbox.gob"

#include "config.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <glib/gi18n-lib.h>
#include <libgnomevfs/gnome-vfs-utils.h>
#include "mn-mailbox-private.h"
#include "mn-util.h"
#include "mn-uri.h"
#include "mn-client-session.h"

#define HAS_CURRENT_TAG(response, priv)	(! strcmp((response)->tag, (priv)->tag))
#define IS(response, token)		(! strcmp((response)->response, (token)))
#define IS_OK(response)			IS(response, "OK")
#define IS_NO(response)			IS(response, "NO")
#define IS_BAD(response)		IS(response, "BAD")
#define IS_BYE(response)		IS(response, "BYE")

  enum
  {
    STATE_GREETING = MN_CLIENT_SESSION_INITIAL_STATE,
    STATE_CAPABILITY,
#ifdef WITH_SASL
    STATE_AUTHENTICATE,
#endif
    STATE_LOGIN,
    STATE_STATUS,
    STATE_LOGOUT
  };
  
  enum
  {
    RESULT_ERROR_LOGOUT		= -1, /* server reported an error, logout normally */
    RESULT_ERROR_END		= -2, /* server reported an error, close the connection */
    RESULT_DEFAULT_HANDLER	= -3  /* invoke the default response handler */
  };

  struct _MNClientSessionPrivate
  {
    MNIMAPMailbox	*mailbox;
    MNClientSession	*session;
    int			numeric_tag;
    char		*tag;
    char		**capabilities;
    GSList		*auth_mechanisms;
    gboolean		status_received;
#ifdef WITH_SASL
    const char		*sasl_mechanism;
#endif
  };

  struct _MNClientSessionResponse
  {
    char		*continuation;
    char		*tag;
    char		*response;
    char		*code;
    char		*arguments;
  };

#line 87 "mn-imap-mailbox.c"
/* self casting macros */
#define SELF(x) MN_IMAP_MAILBOX(x)
#define SELF_CONST(x) MN_IMAP_MAILBOX_CONST(x)
#define IS_SELF(x) MN_IS_IMAP_MAILBOX(x)
#define TYPE_SELF MN_TYPE_IMAP_MAILBOX
#define SELF_CLASS(x) MN_IMAP_MAILBOX_CLASS(x)

#define SELF_GET_CLASS(x) MN_IMAP_MAILBOX_GET_CLASS(x)

/* self typedefs */
typedef MNIMAPMailbox Self;
typedef MNIMAPMailboxClass SelfClass;

/* here are local prototypes */
static void mn_imap_mailbox_init (MNIMAPMailbox * o) G_GNUC_UNUSED;
static void mn_imap_mailbox_class_init (MNIMAPMailboxClass * class) G_GNUC_UNUSED;
static GObject * ___2_mn_imap_mailbox_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_params) G_GNUC_UNUSED;
static gboolean ___3_mn_imap_mailbox_impl_is (MNMailbox * dummy, const char * uri) G_GNUC_UNUSED;
static int mn_imap_mailbox_handle_greeting_cb (MNClientSession * session, MNClientSessionResponse * response, MNClientSessionPrivate * priv) G_GNUC_UNUSED;
static int mn_imap_mailbox_enter_capability_cb (MNClientSession * session, MNClientSessionPrivate * priv) G_GNUC_UNUSED;
static int mn_imap_mailbox_handle_capability_cb (MNClientSession * session, MNClientSessionResponse * response, MNClientSessionPrivate * priv) G_GNUC_UNUSED;
static int mn_imap_mailbox_enter_authenticate_cb (MNClientSession * session, MNClientSessionPrivate * priv) G_GNUC_UNUSED;
static int mn_imap_mailbox_handle_authenticate_cb (MNClientSession * session, MNClientSessionResponse * response, MNClientSessionPrivate * priv) G_GNUC_UNUSED;
static int mn_imap_mailbox_enter_login_cb (MNClientSession * session, MNClientSessionPrivate * priv) G_GNUC_UNUSED;
static int mn_imap_mailbox_handle_login_cb (MNClientSession * session, MNClientSessionResponse * response, MNClientSessionPrivate * priv) G_GNUC_UNUSED;
static int mn_imap_mailbox_enter_status_cb (MNClientSession * session, MNClientSessionPrivate * priv) G_GNUC_UNUSED;
static int mn_imap_mailbox_handle_status_cb (MNClientSession * session, MNClientSessionResponse * response, MNClientSessionPrivate * priv) G_GNUC_UNUSED;
static int mn_imap_mailbox_enter_logout_cb (MNClientSession * session, MNClientSessionPrivate * priv) G_GNUC_UNUSED;
static int mn_imap_mailbox_handle_logout_cb (MNClientSession * session, MNClientSessionResponse * response, MNClientSessionPrivate * priv) G_GNUC_UNUSED;
static void ___f_mn_imap_mailbox_impl_threaded_check (MNMailbox * mailbox) G_GNUC_UNUSED;
static void mn_imap_mailbox_notice_cb (MNClientSession * session, const char * str, MNClientSessionPrivate * priv) G_GNUC_UNUSED;
static MNClientSessionResponse * mn_imap_mailbox_response_new_cb (MNClientSession * session, const char * input, MNClientSessionPrivate * priv) G_GNUC_UNUSED;
static void mn_imap_mailbox_response_free_cb (MNClientSession * session, MNClientSessionResponse * response, MNClientSessionPrivate * priv) G_GNUC_UNUSED;
static int mn_imap_mailbox_custom_handler_cb (MNClientSession * session, MNClientSessionResponse * response, int result, MNClientSessionPrivate * priv) G_GNUC_UNUSED;
static void mn_imap_mailbox_session_set_error_from_arguments (MNClientSessionPrivate * priv, MNClientSessionResponse * response) G_GNUC_UNUSED;
static int mn_imap_mailbox_session_write (MNClientSessionPrivate * priv, const char * format, ...) G_GNUC_UNUSED;
static void mn_imap_mailbox_session_parse_capabilities (MNClientSessionPrivate * priv, const char * capabilities) G_GNUC_UNUSED;
static gboolean mn_imap_mailbox_session_has_capability (MNClientSessionPrivate * priv, const char * capability) G_GNUC_UNUSED;
static int mn_imap_mailbox_session_authenticate (MNClientSessionPrivate * priv) G_GNUC_UNUSED;
static int mn_imap_mailbox_session_authenticate_fallback (MNClientSessionPrivate * priv) G_GNUC_UNUSED;

/* pointer to the class of our parent */
static MNMailboxClass *parent_class = NULL;

/* Short form macros */
#define self_handle_greeting_cb mn_imap_mailbox_handle_greeting_cb
#define self_enter_capability_cb mn_imap_mailbox_enter_capability_cb
#define self_handle_capability_cb mn_imap_mailbox_handle_capability_cb
#define self_enter_authenticate_cb mn_imap_mailbox_enter_authenticate_cb
#define self_handle_authenticate_cb mn_imap_mailbox_handle_authenticate_cb
#define self_enter_login_cb mn_imap_mailbox_enter_login_cb
#define self_handle_login_cb mn_imap_mailbox_handle_login_cb
#define self_enter_status_cb mn_imap_mailbox_enter_status_cb
#define self_handle_status_cb mn_imap_mailbox_handle_status_cb
#define self_enter_logout_cb mn_imap_mailbox_enter_logout_cb
#define self_handle_logout_cb mn_imap_mailbox_handle_logout_cb
#define self_notice_cb mn_imap_mailbox_notice_cb
#define self_response_new_cb mn_imap_mailbox_response_new_cb
#define self_response_free_cb mn_imap_mailbox_response_free_cb
#define self_custom_handler_cb mn_imap_mailbox_custom_handler_cb
#define self_session_set_error_from_arguments mn_imap_mailbox_session_set_error_from_arguments
#define self_session_write mn_imap_mailbox_session_write
#define self_session_parse_capabilities mn_imap_mailbox_session_parse_capabilities
#define self_session_has_capability mn_imap_mailbox_session_has_capability
#define self_session_authenticate mn_imap_mailbox_session_authenticate
#define self_session_authenticate_fallback mn_imap_mailbox_session_authenticate_fallback
GType
mn_imap_mailbox_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (MNIMAPMailboxClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) mn_imap_mailbox_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (MNIMAPMailbox),
			0 /* n_preallocs */,
			(GInstanceInitFunc) mn_imap_mailbox_init,
			NULL
		};

		type = g_type_register_static (MN_TYPE_MAILBOX, "MNIMAPMailbox", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((MNIMAPMailbox *)g_object_new(mn_imap_mailbox_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static MNIMAPMailbox * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static MNIMAPMailbox *
GET_NEW_VARG (const char *first, ...)
{
	MNIMAPMailbox *ret;
	va_list ap;
	va_start (ap, first);
	ret = (MNIMAPMailbox *)g_object_new_valist (mn_imap_mailbox_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::finalize"
	MNIMAPMailbox *self  G_GNUC_UNUSED = MN_IMAP_MAILBOX (obj_self);
	gpointer priv = self->_priv;
	if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(obj_self);
#line 89 "mn-imap-mailbox.gob"
	if(self->_priv->hostname) { ((*(void (*)(void *))g_free)) (self->_priv->hostname); self->_priv->hostname = NULL; }
#line 207 "mn-imap-mailbox.c"
#line 91 "mn-imap-mailbox.gob"
	if(self->_priv->username) { ((*(void (*)(void *))g_free)) (self->_priv->username); self->_priv->username = NULL; }
#line 210 "mn-imap-mailbox.c"
#line 92 "mn-imap-mailbox.gob"
	if(self->_priv->password) { ((*(void (*)(void *))g_free)) (self->_priv->password); self->_priv->password = NULL; }
#line 213 "mn-imap-mailbox.c"
#line 93 "mn-imap-mailbox.gob"
	if(self->_priv->authmech) { ((*(void (*)(void *))g_free)) (self->_priv->authmech); self->_priv->authmech = NULL; }
#line 216 "mn-imap-mailbox.c"
#line 94 "mn-imap-mailbox.gob"
	if(self->_priv->mailbox) { ((*(void (*)(void *))g_free)) (self->_priv->mailbox); self->_priv->mailbox = NULL; }
#line 219 "mn-imap-mailbox.c"
	g_free (priv);
}
#undef __GOB_FUNCTION__

static void 
mn_imap_mailbox_init (MNIMAPMailbox * o G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::init"
	o->_priv = g_new0 (MNIMAPMailboxPrivate, 1);
}
#undef __GOB_FUNCTION__
#line 97 "mn-imap-mailbox.gob"
static void 
mn_imap_mailbox_class_init (MNIMAPMailboxClass * class G_GNUC_UNUSED)
#line 234 "mn-imap-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) class;
	MNMailboxClass *mn_mailbox_class = (MNMailboxClass *)class;

	parent_class = g_type_class_ref (MN_TYPE_MAILBOX);

#line 102 "mn-imap-mailbox.gob"
	g_object_class->constructor = ___2_mn_imap_mailbox_constructor;
#line 133 "mn-imap-mailbox.gob"
	mn_mailbox_class->impl_is = ___3_mn_imap_mailbox_impl_is;
#line 374 "mn-imap-mailbox.gob"
	mn_mailbox_class->impl_threaded_check = ___f_mn_imap_mailbox_impl_threaded_check;
#line 248 "mn-imap-mailbox.c"
	g_object_class->finalize = ___finalize;
 {
#line 98 "mn-imap-mailbox.gob"

    MN_MAILBOX_CLASS(class)->format = "IMAP";
  
#line 255 "mn-imap-mailbox.c"
 }
}
#undef __GOB_FUNCTION__



#line 102 "mn-imap-mailbox.gob"
static GObject * 
___2_mn_imap_mailbox_constructor (GType type G_GNUC_UNUSED, guint n_construct_properties, GObjectConstructParam * construct_params)
#line 265 "mn-imap-mailbox.c"
#define PARENT_HANDLER(___type,___n_construct_properties,___construct_params) \
	((G_OBJECT_CLASS(parent_class)->constructor)? \
		(* G_OBJECT_CLASS(parent_class)->constructor)(___type,___n_construct_properties,___construct_params): \
		((GObject * )0))
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::constructor"
{
#line 104 "mn-imap-mailbox.gob"
	
    GObject *object;
    MNMailbox *mailbox;
    Self *self;

    object = PARENT_HANDLER(type, n_construct_properties, construct_params);
    mailbox = MN_MAILBOX(object);
    self = SELF(object);

    if (mn_uri_parse_imap(mn_mailbox_get_uri(mailbox),
			  &selfp->ssl,
			  &selfp->username,
			  &selfp->password,
			  &selfp->authmech,
			  &selfp->hostname,
			  &selfp->port,
			  &selfp->mailbox))
      {
#ifndef WITH_SSL
	if (selfp->ssl)
	  mn_mailbox_set_init_error(mailbox, _("SSL support has not been compiled in"));
#endif /* WITH_SSL */
      }
    else
      mn_mailbox_set_init_error(mailbox, _("unable to parse IMAP URI"));

    return object;
  }}
#line 302 "mn-imap-mailbox.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 133 "mn-imap-mailbox.gob"
static gboolean 
___3_mn_imap_mailbox_impl_is (MNMailbox * dummy G_GNUC_UNUSED, const char * uri)
#line 309 "mn-imap-mailbox.c"
#define PARENT_HANDLER(___dummy,___uri) \
	((MN_MAILBOX_CLASS(parent_class)->impl_is)? \
		(* MN_MAILBOX_CLASS(parent_class)->impl_is)(___dummy,___uri): \
		((gboolean )0))
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::impl_is"
#line 133 "mn-imap-mailbox.gob"
	g_return_val_if_fail (uri != NULL, (gboolean )0);
#line 318 "mn-imap-mailbox.c"
{
#line 135 "mn-imap-mailbox.gob"
	
    char *scheme;
    gboolean is;

    scheme = gnome_vfs_get_uri_scheme(uri);
    is = scheme && (! strcmp(scheme, "imap") || ! strcmp(scheme, "imaps"));
    g_free(scheme);

    return is;
  }}
#line 331 "mn-imap-mailbox.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 146 "mn-imap-mailbox.gob"
static int 
mn_imap_mailbox_handle_greeting_cb (MNClientSession * session, MNClientSessionResponse * response, MNClientSessionPrivate * priv)
#line 338 "mn-imap-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::handle_greeting_cb"
#line 146 "mn-imap-mailbox.gob"
	g_return_val_if_fail (session != NULL, (int )0);
#line 146 "mn-imap-mailbox.gob"
	g_return_val_if_fail (response != NULL, (int )0);
#line 146 "mn-imap-mailbox.gob"
	g_return_val_if_fail (priv != NULL, (int )0);
#line 347 "mn-imap-mailbox.c"
{
#line 150 "mn-imap-mailbox.gob"
	
    priv->session = session;

    if (! response->tag && IS_OK(response))
      {
	if (response->code)
	  {
	    if (! strcmp(response->code, "CAPABILITY"))
	      self_session_parse_capabilities(priv, NULL);
	    else if (! strncmp(response->code, "CAPABILITY ", 11))
	      self_session_parse_capabilities(priv, response->code + 11);
	  }
	
	return priv->capabilities
	  ? self_session_authenticate(priv)
	  : STATE_CAPABILITY;
      }
    else if (! response->tag && IS(response, "PREAUTH"))
      return STATE_STATUS;
    else if (! response->tag && IS_BYE(response))
      return RESULT_ERROR_END;
    else
      return MN_CLIENT_SESSION_RESULT_BAD_RESPONSE_FOR_CONTEXT;
  }}
#line 374 "mn-imap-mailbox.c"
#undef __GOB_FUNCTION__

#line 175 "mn-imap-mailbox.gob"
static int 
mn_imap_mailbox_enter_capability_cb (MNClientSession * session, MNClientSessionPrivate * priv)
#line 380 "mn-imap-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::enter_capability_cb"
#line 175 "mn-imap-mailbox.gob"
	g_return_val_if_fail (session != NULL, (int )0);
#line 175 "mn-imap-mailbox.gob"
	g_return_val_if_fail (priv != NULL, (int )0);
#line 387 "mn-imap-mailbox.c"
{
#line 178 "mn-imap-mailbox.gob"
	
    return self_session_write(priv, "CAPABILITY");
  }}
#line 393 "mn-imap-mailbox.c"
#undef __GOB_FUNCTION__

#line 182 "mn-imap-mailbox.gob"
static int 
mn_imap_mailbox_handle_capability_cb (MNClientSession * session, MNClientSessionResponse * response, MNClientSessionPrivate * priv)
#line 399 "mn-imap-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::handle_capability_cb"
#line 182 "mn-imap-mailbox.gob"
	g_return_val_if_fail (session != NULL, (int )0);
#line 182 "mn-imap-mailbox.gob"
	g_return_val_if_fail (response != NULL, (int )0);
#line 182 "mn-imap-mailbox.gob"
	g_return_val_if_fail (priv != NULL, (int )0);
#line 408 "mn-imap-mailbox.c"
{
#line 186 "mn-imap-mailbox.gob"
	
    if (response->tag)
      {
	if (HAS_CURRENT_TAG(response, priv))
	  {
	    if (IS_OK(response))
	      {
		return priv->capabilities
		  ? self_session_authenticate(priv)
		  : mn_client_session_error(session, _("server did not send capabilities"));
	      }
	    else if (IS_BAD(response))
	      return RESULT_ERROR_LOGOUT;
	    else
	      return MN_CLIENT_SESSION_RESULT_BAD_RESPONSE_FOR_CONTEXT;
	  }
      }
    else if (IS(response, "CAPABILITY"))
      {
	self_session_parse_capabilities(priv, response->arguments);
	return MN_CLIENT_SESSION_RESULT_CONTINUE;
      }
    
    return RESULT_DEFAULT_HANDLER;
  }}
#line 436 "mn-imap-mailbox.c"
#undef __GOB_FUNCTION__

#line 212 "mn-imap-mailbox.gob"
static int 
mn_imap_mailbox_enter_authenticate_cb (MNClientSession * session, MNClientSessionPrivate * priv)
#line 442 "mn-imap-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::enter_authenticate_cb"
#line 212 "mn-imap-mailbox.gob"
	g_return_val_if_fail (session != NULL, (int )0);
#line 212 "mn-imap-mailbox.gob"
	g_return_val_if_fail (priv != NULL, (int )0);
#line 449 "mn-imap-mailbox.c"
{
#line 215 "mn-imap-mailbox.gob"
	
#ifdef WITH_SASL
    if (mn_client_session_sasl_authentication_start(priv->session,
						    "imap",
						    priv->auth_mechanisms,
						    priv->mailbox->_priv->authmech,
						    &priv->sasl_mechanism))
      return self_session_write(priv, "AUTHENTICATE %s", priv->sasl_mechanism);
    else
      return self_session_authenticate_fallback(priv);
#else
    g_return_val_if_reached(0);
#endif /* WITH_SASL */
  }}
#line 466 "mn-imap-mailbox.c"
#undef __GOB_FUNCTION__

#line 230 "mn-imap-mailbox.gob"
static int 
mn_imap_mailbox_handle_authenticate_cb (MNClientSession * session, MNClientSessionResponse * response, MNClientSessionPrivate * priv)
#line 472 "mn-imap-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::handle_authenticate_cb"
#line 230 "mn-imap-mailbox.gob"
	g_return_val_if_fail (session != NULL, (int )0);
#line 230 "mn-imap-mailbox.gob"
	g_return_val_if_fail (response != NULL, (int )0);
#line 230 "mn-imap-mailbox.gob"
	g_return_val_if_fail (priv != NULL, (int )0);
#line 481 "mn-imap-mailbox.c"
{
#line 234 "mn-imap-mailbox.gob"
	
#ifdef WITH_SASL
    if (response->tag)
      {
	if (HAS_CURRENT_TAG(response, priv))
	  {
	    if (IS_OK(response))
	      {
		return mn_client_session_sasl_authentication_done(session)
		  ? STATE_STATUS
		  : MN_CLIENT_SESSION_RESULT_END;
	      }
	    else if (IS_NO(response) || IS_BAD(response))
	      return self_session_authenticate_fallback(priv);
	    else
	      return MN_CLIENT_SESSION_RESULT_BAD_RESPONSE_FOR_CONTEXT;
	  }
      }
    else if (response->continuation)
      return mn_client_session_sasl_authentication_step(session, response->continuation);
    
    return RESULT_DEFAULT_HANDLER;
#else
    g_return_val_if_reached(0);
#endif /* WITH_SASL */
  }}
#line 510 "mn-imap-mailbox.c"
#undef __GOB_FUNCTION__

#line 261 "mn-imap-mailbox.gob"
static int 
mn_imap_mailbox_enter_login_cb (MNClientSession * session, MNClientSessionPrivate * priv)
#line 516 "mn-imap-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::enter_login_cb"
#line 261 "mn-imap-mailbox.gob"
	g_return_val_if_fail (session != NULL, (int )0);
#line 261 "mn-imap-mailbox.gob"
	g_return_val_if_fail (priv != NULL, (int )0);
#line 523 "mn-imap-mailbox.c"
{
#line 264 "mn-imap-mailbox.gob"
	
    if (self_session_has_capability(priv, "LOGINDISABLED"))
    {
      mn_client_session_notice(session, _("server advertised LOGINDISABLED, not using LOGIN authentication"));
      mn_client_session_error(session, _("unable to login"));
      return STATE_LOGOUT;
    }
    else
      return self_session_write(priv, "LOGIN %s %s",
				priv->mailbox->_priv->username,
				priv->mailbox->_priv->password);
  }}
#line 538 "mn-imap-mailbox.c"
#undef __GOB_FUNCTION__

#line 277 "mn-imap-mailbox.gob"
static int 
mn_imap_mailbox_handle_login_cb (MNClientSession * session, MNClientSessionResponse * response, MNClientSessionPrivate * priv)
#line 544 "mn-imap-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::handle_login_cb"
#line 277 "mn-imap-mailbox.gob"
	g_return_val_if_fail (session != NULL, (int )0);
#line 277 "mn-imap-mailbox.gob"
	g_return_val_if_fail (response != NULL, (int )0);
#line 277 "mn-imap-mailbox.gob"
	g_return_val_if_fail (priv != NULL, (int )0);
#line 553 "mn-imap-mailbox.c"
{
#line 281 "mn-imap-mailbox.gob"
	
    if (response->tag)
      {
	if (HAS_CURRENT_TAG(response, priv))
	  {
	    if (IS_OK(response))
	      return STATE_STATUS;
	    else if (IS_NO(response) || IS_BAD(response))
	      return RESULT_ERROR_LOGOUT;
	    else
	      return MN_CLIENT_SESSION_RESULT_BAD_RESPONSE_FOR_CONTEXT;
	  }
      }
    
    return RESULT_DEFAULT_HANDLER;
  }}
#line 572 "mn-imap-mailbox.c"
#undef __GOB_FUNCTION__

#line 298 "mn-imap-mailbox.gob"
static int 
mn_imap_mailbox_enter_status_cb (MNClientSession * session, MNClientSessionPrivate * priv)
#line 578 "mn-imap-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::enter_status_cb"
#line 298 "mn-imap-mailbox.gob"
	g_return_val_if_fail (session != NULL, (int )0);
#line 298 "mn-imap-mailbox.gob"
	g_return_val_if_fail (priv != NULL, (int )0);
#line 585 "mn-imap-mailbox.c"
{
#line 301 "mn-imap-mailbox.gob"
	
    return self_session_write(priv, "STATUS \"%s\" (UNSEEN)", priv->mailbox->_priv->mailbox);
  }}
#line 591 "mn-imap-mailbox.c"
#undef __GOB_FUNCTION__

#line 305 "mn-imap-mailbox.gob"
static int 
mn_imap_mailbox_handle_status_cb (MNClientSession * session, MNClientSessionResponse * response, MNClientSessionPrivate * priv)
#line 597 "mn-imap-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::handle_status_cb"
#line 305 "mn-imap-mailbox.gob"
	g_return_val_if_fail (session != NULL, (int )0);
#line 305 "mn-imap-mailbox.gob"
	g_return_val_if_fail (response != NULL, (int )0);
#line 305 "mn-imap-mailbox.gob"
	g_return_val_if_fail (priv != NULL, (int )0);
#line 606 "mn-imap-mailbox.c"
{
#line 309 "mn-imap-mailbox.gob"
	
    if (response->tag)
      {
	if (HAS_CURRENT_TAG(response, priv))
	  {
	    if (IS_OK(response))
	      {
		if (priv->status_received)
		  return STATE_LOGOUT;
		else		/* compliance error */
		  return mn_client_session_error(session, _("server did not send status"));
	      }
	    else if (IS_NO(response) || IS_BAD(response))
	      return RESULT_ERROR_LOGOUT;
	    else
	      return MN_CLIENT_SESSION_RESULT_BAD_RESPONSE_FOR_CONTEXT;
	  }
      }
    else if (IS(response, "STATUS"))
      {
	int count;
	
	if (response->arguments && sscanf(response->arguments, "%*s (UNSEEN %i)", &count) == 1)
	  {
	    priv->status_received = TRUE;
	    
	    GDK_THREADS_ENTER();
	    mn_mailbox_set_has_new(MN_MAILBOX(priv->mailbox), count != 0);
	    gdk_flush();
	    GDK_THREADS_LEAVE();
	    
	    return MN_CLIENT_SESSION_RESULT_CONTINUE;
	  }
	else
	  return MN_CLIENT_SESSION_RESULT_BAD_RESPONSE_FOR_CONTEXT;
      }
    
    return RESULT_DEFAULT_HANDLER;
  }}
#line 648 "mn-imap-mailbox.c"
#undef __GOB_FUNCTION__

#line 349 "mn-imap-mailbox.gob"
static int 
mn_imap_mailbox_enter_logout_cb (MNClientSession * session, MNClientSessionPrivate * priv)
#line 654 "mn-imap-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::enter_logout_cb"
#line 349 "mn-imap-mailbox.gob"
	g_return_val_if_fail (session != NULL, (int )0);
#line 349 "mn-imap-mailbox.gob"
	g_return_val_if_fail (priv != NULL, (int )0);
#line 661 "mn-imap-mailbox.c"
{
#line 352 "mn-imap-mailbox.gob"
	
    return self_session_write(priv, "LOGOUT");
  }}
#line 667 "mn-imap-mailbox.c"
#undef __GOB_FUNCTION__

#line 356 "mn-imap-mailbox.gob"
static int 
mn_imap_mailbox_handle_logout_cb (MNClientSession * session, MNClientSessionResponse * response, MNClientSessionPrivate * priv)
#line 673 "mn-imap-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::handle_logout_cb"
#line 356 "mn-imap-mailbox.gob"
	g_return_val_if_fail (session != NULL, (int )0);
#line 356 "mn-imap-mailbox.gob"
	g_return_val_if_fail (response != NULL, (int )0);
#line 356 "mn-imap-mailbox.gob"
	g_return_val_if_fail (priv != NULL, (int )0);
#line 682 "mn-imap-mailbox.c"
{
#line 360 "mn-imap-mailbox.gob"
	
    if (response->tag && HAS_CURRENT_TAG(response, priv))
      {
	if (IS_OK(response))
	  return MN_CLIENT_SESSION_RESULT_END;
	else if (IS_BAD(response))
	  return RESULT_ERROR_END;
	else
	  return MN_CLIENT_SESSION_RESULT_BAD_RESPONSE_FOR_CONTEXT;
      }
    else
      return MN_CLIENT_SESSION_RESULT_CONTINUE;
  }}
#line 698 "mn-imap-mailbox.c"
#undef __GOB_FUNCTION__

#line 374 "mn-imap-mailbox.gob"
static void 
___f_mn_imap_mailbox_impl_threaded_check (MNMailbox * mailbox G_GNUC_UNUSED)
#line 704 "mn-imap-mailbox.c"
#define PARENT_HANDLER(___mailbox) \
	{ if(MN_MAILBOX_CLASS(parent_class)->impl_threaded_check) \
		(* MN_MAILBOX_CLASS(parent_class)->impl_threaded_check)(___mailbox); }
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::impl_threaded_check"
#line 374 "mn-imap-mailbox.gob"
	g_return_if_fail (mailbox != NULL);
#line 374 "mn-imap-mailbox.gob"
	g_return_if_fail (MN_IS_MAILBOX (mailbox));
#line 714 "mn-imap-mailbox.c"
{
#line 376 "mn-imap-mailbox.gob"
	
    Self *self = SELF(mailbox);
    MNClientSessionState states[] = {
      { STATE_GREETING,		NULL,				self_handle_greeting_cb },
      { STATE_CAPABILITY,	self_enter_capability_cb,	self_handle_capability_cb },
#ifdef WITH_SASL
      { STATE_AUTHENTICATE,	self_enter_authenticate_cb,	self_handle_authenticate_cb },
#endif
      { STATE_LOGIN,		self_enter_login_cb,		self_handle_login_cb },
      { STATE_STATUS,		self_enter_status_cb,		self_handle_status_cb },
      { STATE_LOGOUT,		self_enter_logout_cb,		self_handle_logout_cb },
      
      MN_CLIENT_SESSION_STATES_END
    };
    MNClientSessionCallbacks callbacks = {
      self_notice_cb,
      self_response_new_cb,
      self_response_free_cb,
      self_custom_handler_cb
    };
    MNClientSessionPrivate priv;
    GError *err = NULL;

    memset(&priv, 0, sizeof(priv));
    priv.mailbox = self;
    
    if (! mn_client_session_run(states,
				&callbacks,
#ifdef WITH_SSL
				selfp->ssl,
#endif
				selfp->hostname,
				selfp->port,
				selfp->username,
				selfp->password,
				&priv,
				&err))
      {
	GDK_THREADS_ENTER();
	mn_mailbox_set_error(mailbox, "%s", err->message);
	gdk_flush();
	GDK_THREADS_LEAVE();
	g_error_free(err);
      }
    
    GDK_THREADS_ENTER();
    mn_mailbox_end_check(mailbox);
    gdk_flush();
    GDK_THREADS_LEAVE();
    
    g_free(priv.tag);
    g_strfreev(priv.capabilities);
    mn_pointers_free(priv.auth_mechanisms);
  }}
#line 771 "mn-imap-mailbox.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 431 "mn-imap-mailbox.gob"
static void 
mn_imap_mailbox_notice_cb (MNClientSession * session, const char * str, MNClientSessionPrivate * priv)
#line 778 "mn-imap-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::notice_cb"
#line 431 "mn-imap-mailbox.gob"
	g_return_if_fail (session != NULL);
#line 431 "mn-imap-mailbox.gob"
	g_return_if_fail (str != NULL);
#line 431 "mn-imap-mailbox.gob"
	g_return_if_fail (priv != NULL);
#line 787 "mn-imap-mailbox.c"
{
#line 435 "mn-imap-mailbox.gob"
	
    mn_mailbox_notice(MN_MAILBOX(priv->mailbox), "%s", str);
  }}
#line 793 "mn-imap-mailbox.c"
#undef __GOB_FUNCTION__

#line 439 "mn-imap-mailbox.gob"
static MNClientSessionResponse * 
mn_imap_mailbox_response_new_cb (MNClientSession * session, const char * input, MNClientSessionPrivate * priv)
#line 799 "mn-imap-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::response_new_cb"
#line 439 "mn-imap-mailbox.gob"
	g_return_val_if_fail (session != NULL, (MNClientSessionResponse * )0);
#line 439 "mn-imap-mailbox.gob"
	g_return_val_if_fail (input != NULL, (MNClientSessionResponse * )0);
#line 439 "mn-imap-mailbox.gob"
	g_return_val_if_fail (priv != NULL, (MNClientSessionResponse * )0);
#line 808 "mn-imap-mailbox.c"
{
#line 443 "mn-imap-mailbox.gob"
	
    MNClientSessionResponse *response = NULL;

    if (! strncmp(input, "+ ", 2))
      {
	response = g_new0(MNClientSessionResponse, 1);
	response->continuation = g_strdup(input + 2);
      }
    else
      {
	char **tokens;
	
	tokens = g_strsplit(input, " ", 3);
	if (tokens[0] && tokens[1])
	  {
	    if (tokens[2] && tokens[2][0] == '[')
	      {
		char *code_start;
		char *code_end;
		
		code_start = tokens[2] + 1;
		code_end = strchr(code_start, ']');
		if (code_end)
		  {
		    response = g_new0(MNClientSessionResponse, 1);
		    response->code = g_strndup(code_start, code_end - code_start);
		    response->arguments = code_end[1] ? g_strdup(code_end + 2) : NULL;
		  }
	      }
	    else
	      {
		response = g_new0(MNClientSessionResponse, 1);
		response->arguments = g_strdup(tokens[2]);
	      }
	    
	    if (response)
	      {
		response->tag = ! strcmp(tokens[0], "*") ? NULL : g_strdup(tokens[0]);
		response->response = g_strdup(tokens[1]);
	      }
	  }
	g_strfreev(tokens);
      }
    
    return response;
  }}
#line 857 "mn-imap-mailbox.c"
#undef __GOB_FUNCTION__

#line 490 "mn-imap-mailbox.gob"
static void 
mn_imap_mailbox_response_free_cb (MNClientSession * session, MNClientSessionResponse * response, MNClientSessionPrivate * priv)
#line 863 "mn-imap-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::response_free_cb"
#line 490 "mn-imap-mailbox.gob"
	g_return_if_fail (session != NULL);
#line 490 "mn-imap-mailbox.gob"
	g_return_if_fail (response != NULL);
#line 490 "mn-imap-mailbox.gob"
	g_return_if_fail (priv != NULL);
#line 872 "mn-imap-mailbox.c"
{
#line 494 "mn-imap-mailbox.gob"
	
    g_free(response->tag);
    g_free(response->continuation);
    g_free(response->response);
    g_free(response->code);
    g_free(response->arguments);
    g_free(response);
  }}
#line 883 "mn-imap-mailbox.c"
#undef __GOB_FUNCTION__

#line 503 "mn-imap-mailbox.gob"
static int 
mn_imap_mailbox_custom_handler_cb (MNClientSession * session, MNClientSessionResponse * response, int result, MNClientSessionPrivate * priv)
#line 889 "mn-imap-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::custom_handler_cb"
#line 503 "mn-imap-mailbox.gob"
	g_return_val_if_fail (session != NULL, (int )0);
#line 503 "mn-imap-mailbox.gob"
	g_return_val_if_fail (response != NULL, (int )0);
#line 503 "mn-imap-mailbox.gob"
	g_return_val_if_fail (priv != NULL, (int )0);
#line 898 "mn-imap-mailbox.c"
{
#line 508 "mn-imap-mailbox.gob"
	
    switch (result)
      {
      case RESULT_ERROR_LOGOUT:
	self_session_set_error_from_arguments(priv, response);
	return STATE_LOGOUT;

      case RESULT_ERROR_END:
	self_session_set_error_from_arguments(priv, response);
	return MN_CLIENT_SESSION_RESULT_END;

      case RESULT_DEFAULT_HANDLER:
	if (! response->tag && IS_BYE(response))
	  return RESULT_ERROR_END;
	else
	  return MN_CLIENT_SESSION_RESULT_CONTINUE;
	
      default:
	g_return_val_if_reached(0);
      }
  }}
#line 922 "mn-imap-mailbox.c"
#undef __GOB_FUNCTION__

#line 530 "mn-imap-mailbox.gob"
static void 
mn_imap_mailbox_session_set_error_from_arguments (MNClientSessionPrivate * priv, MNClientSessionResponse * response)
#line 928 "mn-imap-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::session_set_error_from_arguments"
#line 530 "mn-imap-mailbox.gob"
	g_return_if_fail (priv != NULL);
#line 530 "mn-imap-mailbox.gob"
	g_return_if_fail (response != NULL);
#line 935 "mn-imap-mailbox.c"
{
#line 533 "mn-imap-mailbox.gob"
	
    if (response->arguments)
      mn_client_session_error(priv->session, "\"%s\"", response->arguments);
    else
      mn_client_session_error(priv->session, _("unknown server error"));
  }}
#line 944 "mn-imap-mailbox.c"
#undef __GOB_FUNCTION__

#line 540 "mn-imap-mailbox.gob"
static int 
mn_imap_mailbox_session_write (MNClientSessionPrivate * priv, const char * format, ...)
#line 950 "mn-imap-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::session_write"
#line 540 "mn-imap-mailbox.gob"
	g_return_val_if_fail (priv != NULL, (int )0);
#line 540 "mn-imap-mailbox.gob"
	g_return_val_if_fail (format != NULL, (int )0);
#line 957 "mn-imap-mailbox.c"
{
#line 544 "mn-imap-mailbox.gob"
	
    va_list args;
    char *command;

    va_start(args, format);
    command = g_strdup_vprintf(format, args);
    va_end(args);
    
    if (priv->numeric_tag == 1000)
      priv->numeric_tag = 0;
    g_free(priv->tag);
    priv->tag = g_strdup_printf("a%03i", priv->numeric_tag++);

    return mn_client_session_write(priv->session, "%s %s", priv->tag, command);
  }}
#line 975 "mn-imap-mailbox.c"
#undef __GOB_FUNCTION__

#line 560 "mn-imap-mailbox.gob"
static void 
mn_imap_mailbox_session_parse_capabilities (MNClientSessionPrivate * priv, const char * capabilities)
#line 981 "mn-imap-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::session_parse_capabilities"
#line 560 "mn-imap-mailbox.gob"
	g_return_if_fail (priv != NULL);
#line 986 "mn-imap-mailbox.c"
{
#line 563 "mn-imap-mailbox.gob"
	
    if (capabilities)
      {
	int i;
	
	priv->capabilities = g_strsplit(capabilities, " ", 0);
	
	for (i = 0; priv->capabilities[i]; i++)
	  if (! strncmp(priv->capabilities[i], "AUTH=", 5))
	    priv->auth_mechanisms = g_slist_append(priv->auth_mechanisms, g_strdup(priv->capabilities[i] + 5));
      }
    else
      priv->capabilities = g_new0(char *, 1);
  }}
#line 1003 "mn-imap-mailbox.c"
#undef __GOB_FUNCTION__

#line 578 "mn-imap-mailbox.gob"
static gboolean 
mn_imap_mailbox_session_has_capability (MNClientSessionPrivate * priv, const char * capability)
#line 1009 "mn-imap-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::session_has_capability"
#line 578 "mn-imap-mailbox.gob"
	g_return_val_if_fail (priv != NULL, (gboolean )0);
#line 578 "mn-imap-mailbox.gob"
	g_return_val_if_fail (capability != NULL, (gboolean )0);
#line 1016 "mn-imap-mailbox.c"
{
#line 581 "mn-imap-mailbox.gob"
	
    int i;

    g_return_val_if_fail(priv->capabilities != NULL, FALSE);

    for (i = 0; priv->capabilities[i]; i++)
      if (! strcmp(priv->capabilities[i], capability))
	return TRUE;
    
    return FALSE;
  }}
#line 1030 "mn-imap-mailbox.c"
#undef __GOB_FUNCTION__

#line 593 "mn-imap-mailbox.gob"
static int 
mn_imap_mailbox_session_authenticate (MNClientSessionPrivate * priv)
#line 1036 "mn-imap-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::session_authenticate"
#line 593 "mn-imap-mailbox.gob"
	g_return_val_if_fail (priv != NULL, (int )0);
#line 1041 "mn-imap-mailbox.c"
{
#line 595 "mn-imap-mailbox.gob"
	
    if (priv->mailbox->_priv->authmech)
      {
	if (*priv->mailbox->_priv->authmech != '+')
	  {
#ifdef WITH_SASL
	    return STATE_AUTHENTICATE;
#else
	    return mn_client_session_error(priv->session, _("a SASL authentication mechanism was selected but SASL support has not been compiled in"));
#endif /* WITH_SASL */
	  }
	else
	  {
	    if (! strcmp(priv->mailbox->_priv->authmech, "+LOGIN"))
	      return STATE_LOGIN;
	    else
	      return mn_client_session_error(priv->session, _("unknown authentication mechanism \"%s\""), priv->mailbox->_priv->authmech);
	  }
      }
    else
      {
#ifdef WITH_SASL
	if (priv->auth_mechanisms)
	  return STATE_AUTHENTICATE;
#endif /* WITH_SASL */
	return STATE_LOGIN;
      }
  }}
#line 1072 "mn-imap-mailbox.c"
#undef __GOB_FUNCTION__

#line 624 "mn-imap-mailbox.gob"
static int 
mn_imap_mailbox_session_authenticate_fallback (MNClientSessionPrivate * priv)
#line 1078 "mn-imap-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:IMAP:Mailbox::session_authenticate_fallback"
#line 624 "mn-imap-mailbox.gob"
	g_return_val_if_fail (priv != NULL, (int )0);
#line 1083 "mn-imap-mailbox.c"
{
#line 626 "mn-imap-mailbox.gob"
	
    if (! priv->mailbox->_priv->authmech)
      {
	mn_client_session_notice(priv->session, _("falling back to IMAP LOGIN authentication"));
	return STATE_LOGIN;
      }

    return mn_client_session_error(priv->session, _("authentication failed"));
  }}
#line 1095 "mn-imap-mailbox.c"
#undef __GOB_FUNCTION__
