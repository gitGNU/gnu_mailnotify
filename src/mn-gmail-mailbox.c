/* Generated by GOB (v2.0.9) on Thu Aug 19 00:41:31 2004
   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 9

#define selfp (self->_priv)

#include "mn-gmail-mailbox.h"

#include "mn-gmail-mailbox-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 22 "mn-gmail-mailbox.gob"

#include "config.h"
#include <string.h>
#include <stdlib.h>
#include <glib/gi18n-lib.h>
#include <libgnomevfs/gnome-vfs-utils.h>
#include <libsoup/soup.h>
#include "mn-mailbox-private.h"
#include "mn-uri.h"
#include "mn-util.h"
#include "mn-stock.h"
#include "mn-soup.h"

#line 39 "mn-gmail-mailbox.c"
/* self casting macros */
#define SELF(x) MN_GMAIL_MAILBOX(x)
#define SELF_CONST(x) MN_GMAIL_MAILBOX_CONST(x)
#define IS_SELF(x) MN_IS_GMAIL_MAILBOX(x)
#define TYPE_SELF MN_TYPE_GMAIL_MAILBOX
#define SELF_CLASS(x) MN_GMAIL_MAILBOX_CLASS(x)

#define SELF_GET_CLASS(x) MN_GMAIL_MAILBOX_GET_CLASS(x)

/* self typedefs */
typedef MNGmailMailbox Self;
typedef MNGmailMailboxClass SelfClass;

/* here are local prototypes */
static void mn_gmail_mailbox_init (MNGmailMailbox * o) G_GNUC_UNUSED;
static void mn_gmail_mailbox_class_init (MNGmailMailboxClass * class) G_GNUC_UNUSED;
static GObject * ___2_mn_gmail_mailbox_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_params) G_GNUC_UNUSED;
static void ___3_mn_gmail_mailbox_finalize (GObject * object) G_GNUC_UNUSED;
static gboolean ___4_mn_gmail_mailbox_impl_is (MNMailbox * dummy, const char * uri) G_GNUC_UNUSED;
static void ___5_mn_gmail_mailbox_impl_check (MNMailbox * mailbox) G_GNUC_UNUSED;
static void mn_gmail_mailbox_get (MNGmailMailbox * self, const char * uri, SoupCallbackFn callback) G_GNUC_UNUSED;
static char * mn_gmail_mailbox_get_token (const char * str, const char * pre, const char * post, gboolean include_pre, gboolean include_post) G_GNUC_UNUSED;
static void mn_gmail_mailbox_login (MNGmailMailbox * self) G_GNUC_UNUSED;
static void mn_gmail_mailbox_login_cb1 (SoupMessage * message, gpointer user_data) G_GNUC_UNUSED;
static void mn_gmail_mailbox_login_cb2 (SoupMessage * message, gpointer user_data) G_GNUC_UNUSED;
static void mn_gmail_mailbox_login_cb3 (SoupMessage * message, gpointer user_data) G_GNUC_UNUSED;
static void mn_gmail_mailbox_update_cookies (MNGmailMailbox * self, SoupMessage * message) G_GNUC_UNUSED;
static char * mn_gmail_mailbox_build_cookie (MNGmailMailbox * self) G_GNUC_UNUSED;
static void mn_gmail_mailbox_build_cookie_cb (gpointer key, gpointer value, gpointer user_data) G_GNUC_UNUSED;
static void mn_gmail_mailbox_check_internal (MNGmailMailbox * self) G_GNUC_UNUSED;
static void mn_gmail_mailbox_check_internal_cb (SoupMessage * message, gpointer user_data) G_GNUC_UNUSED;
static int mn_gmail_mailbox_get_unread_count (SoupMessage * message) G_GNUC_UNUSED;

/* pointer to the class of our parent */
static MNMailboxClass *parent_class = NULL;

/* Short form macros */
#define self_get mn_gmail_mailbox_get
#define self_get_token mn_gmail_mailbox_get_token
#define self_login mn_gmail_mailbox_login
#define self_login_cb1 mn_gmail_mailbox_login_cb1
#define self_login_cb2 mn_gmail_mailbox_login_cb2
#define self_login_cb3 mn_gmail_mailbox_login_cb3
#define self_update_cookies mn_gmail_mailbox_update_cookies
#define self_build_cookie mn_gmail_mailbox_build_cookie
#define self_build_cookie_cb mn_gmail_mailbox_build_cookie_cb
#define self_check_internal mn_gmail_mailbox_check_internal
#define self_check_internal_cb mn_gmail_mailbox_check_internal_cb
#define self_get_unread_count mn_gmail_mailbox_get_unread_count
GType
mn_gmail_mailbox_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (MNGmailMailboxClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) mn_gmail_mailbox_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (MNGmailMailbox),
			0 /* n_preallocs */,
			(GInstanceInitFunc) mn_gmail_mailbox_init,
			NULL
		};

		type = g_type_register_static (MN_TYPE_MAILBOX, "MNGmailMailbox", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((MNGmailMailbox *)g_object_new(mn_gmail_mailbox_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static MNGmailMailbox * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static MNGmailMailbox *
GET_NEW_VARG (const char *first, ...)
{
	MNGmailMailbox *ret;
	va_list ap;
	va_start (ap, first);
	ret = (MNGmailMailbox *)g_object_new_valist (mn_gmail_mailbox_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox::finalize"
	MNGmailMailbox *self  G_GNUC_UNUSED = MN_GMAIL_MAILBOX (obj_self);
	gpointer priv = self->_priv;
#line 70 "mn-gmail-mailbox.gob"
	___3_mn_gmail_mailbox_finalize(obj_self);
#line 140 "mn-gmail-mailbox.c"
#line 38 "mn-gmail-mailbox.gob"
	if(self->_priv->username) { ((*(void (*)(void *))g_free)) (self->_priv->username); self->_priv->username = NULL; }
#line 143 "mn-gmail-mailbox.c"
#line 39 "mn-gmail-mailbox.gob"
	if(self->_priv->password) { ((*(void (*)(void *))g_free)) (self->_priv->password); self->_priv->password = NULL; }
#line 146 "mn-gmail-mailbox.c"
#line 40 "mn-gmail-mailbox.gob"
	if(self->_priv->cookies) { ((*(void (*)(void *))g_hash_table_destroy)) (self->_priv->cookies); self->_priv->cookies = NULL; }
#line 149 "mn-gmail-mailbox.c"
	g_free (priv);
}
#undef __GOB_FUNCTION__

static void 
mn_gmail_mailbox_init (MNGmailMailbox * o G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox::init"
	o->_priv = g_new0 (MNGmailMailboxPrivate, 1);
}
#undef __GOB_FUNCTION__
#line 43 "mn-gmail-mailbox.gob"
static void 
mn_gmail_mailbox_class_init (MNGmailMailboxClass * class G_GNUC_UNUSED)
#line 164 "mn-gmail-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) class;
	MNMailboxClass *mn_mailbox_class = (MNMailboxClass *)class;

	parent_class = g_type_class_ref (MN_TYPE_MAILBOX);

#line 49 "mn-gmail-mailbox.gob"
	g_object_class->constructor = ___2_mn_gmail_mailbox_constructor;
#line 70 "mn-gmail-mailbox.gob"
	g_object_class->finalize = ___finalize;
#line 77 "mn-gmail-mailbox.gob"
	mn_mailbox_class->impl_is = ___4_mn_gmail_mailbox_impl_is;
#line 90 "mn-gmail-mailbox.gob"
	mn_mailbox_class->impl_check = ___5_mn_gmail_mailbox_impl_check;
#line 180 "mn-gmail-mailbox.c"
 {
#line 44 "mn-gmail-mailbox.gob"

    MN_MAILBOX_CLASS(class)->stock_id = MN_STOCK_GMAIL;
    MN_MAILBOX_CLASS(class)->format = "Gmail";
  
#line 187 "mn-gmail-mailbox.c"
 }
}
#undef __GOB_FUNCTION__



#line 49 "mn-gmail-mailbox.gob"
static GObject * 
___2_mn_gmail_mailbox_constructor (GType type G_GNUC_UNUSED, guint n_construct_properties, GObjectConstructParam * construct_params)
#line 197 "mn-gmail-mailbox.c"
#define PARENT_HANDLER(___type,___n_construct_properties,___construct_params) \
	((G_OBJECT_CLASS(parent_class)->constructor)? \
		(* G_OBJECT_CLASS(parent_class)->constructor)(___type,___n_construct_properties,___construct_params): \
		((GObject * )0))
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox::constructor"
{
#line 51 "mn-gmail-mailbox.gob"
	
    GObject *object;
    MNMailbox *mailbox;
    Self *self;

    object = PARENT_HANDLER(type, n_construct_properties, construct_params);
    mailbox = MN_MAILBOX(object);
    self = SELF(object);
    
    mn_soup_use();

    if (! mn_uri_parse_gmail(mn_mailbox_get_uri(mailbox),
			     &selfp->username,
			     &selfp->password))
      mn_mailbox_set_init_error(mailbox, _("unable to parse Gmail URI"));
    
    return object;
  }}
#line 224 "mn-gmail-mailbox.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 70 "mn-gmail-mailbox.gob"
static void 
___3_mn_gmail_mailbox_finalize (GObject * object G_GNUC_UNUSED)
#line 231 "mn-gmail-mailbox.c"
#define PARENT_HANDLER(___object) \
	{ if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(___object); }
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox::finalize"
{
#line 72 "mn-gmail-mailbox.gob"
	
    mn_soup_unuse();
    PARENT_HANDLER(object);
  }}
#line 243 "mn-gmail-mailbox.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 77 "mn-gmail-mailbox.gob"
static gboolean 
___4_mn_gmail_mailbox_impl_is (MNMailbox * dummy G_GNUC_UNUSED, const char * uri)
#line 250 "mn-gmail-mailbox.c"
#define PARENT_HANDLER(___dummy,___uri) \
	((MN_MAILBOX_CLASS(parent_class)->impl_is)? \
		(* MN_MAILBOX_CLASS(parent_class)->impl_is)(___dummy,___uri): \
		((gboolean )0))
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox::impl_is"
#line 77 "mn-gmail-mailbox.gob"
	g_return_val_if_fail (uri != NULL, (gboolean )0);
#line 259 "mn-gmail-mailbox.c"
{
#line 79 "mn-gmail-mailbox.gob"
	
    char *scheme;
    gboolean is;
    
    scheme = gnome_vfs_get_uri_scheme(uri);
    is = scheme && ! strcmp(scheme, "gmail");
    g_free(scheme);
    
    return is;
  }}
#line 272 "mn-gmail-mailbox.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 90 "mn-gmail-mailbox.gob"
static void 
___5_mn_gmail_mailbox_impl_check (MNMailbox * mailbox G_GNUC_UNUSED)
#line 279 "mn-gmail-mailbox.c"
#define PARENT_HANDLER(___mailbox) \
	{ if(MN_MAILBOX_CLASS(parent_class)->impl_check) \
		(* MN_MAILBOX_CLASS(parent_class)->impl_check)(___mailbox); }
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox::impl_check"
#line 90 "mn-gmail-mailbox.gob"
	g_return_if_fail (mailbox != NULL);
#line 90 "mn-gmail-mailbox.gob"
	g_return_if_fail (MN_IS_MAILBOX (mailbox));
#line 289 "mn-gmail-mailbox.c"
{
#line 92 "mn-gmail-mailbox.gob"
	
    Self *self = SELF(mailbox);

    if (selfp->logged_in)
      self_check_internal(self);
    else
      self_login(self);
  }}
#line 300 "mn-gmail-mailbox.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 101 "mn-gmail-mailbox.gob"
static void 
mn_gmail_mailbox_get (MNGmailMailbox * self, const char * uri, SoupCallbackFn callback)
#line 307 "mn-gmail-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox::get"
#line 101 "mn-gmail-mailbox.gob"
	g_return_if_fail (self != NULL);
#line 101 "mn-gmail-mailbox.gob"
	g_return_if_fail (MN_IS_GMAIL_MAILBOX (self));
#line 101 "mn-gmail-mailbox.gob"
	g_return_if_fail (uri != NULL);
#line 101 "mn-gmail-mailbox.gob"
	g_return_if_fail (callback != NULL);
#line 318 "mn-gmail-mailbox.c"
{
#line 105 "mn-gmail-mailbox.gob"
	
    SoupContext *context;
    SoupMessage *message;
    char *cookie;

    context = soup_context_get(uri);
    message = soup_message_new(context, SOUP_METHOD_GET);
    soup_context_unref(context);

    soup_message_add_header(message->request_headers, "User-Agent", "Mail Notification");
    cookie = self_build_cookie(self);
    if (cookie)
      {
	soup_message_add_header(message->request_headers, "Cookie", cookie);
	g_free(cookie);
      }
    
    soup_message_queue(message, callback, self);
    /* message will be freed by libsoup after invoking the callback */
  }}
#line 341 "mn-gmail-mailbox.c"
#undef __GOB_FUNCTION__

/**
 * mn_gmail_mailbox_get_token:
 * @str: the string to search
 * @pre: the start of the token
 * @post: the end of the token
 * @include_pre: whether to include @pre in the result or not
 * @include_post: whether to include @post in the result or not
 *
 * Gets the first token of @str included between @pre and @post.
 *
 * Return value: a newly allocated string containing the token or
 *               NULL if not found.
 **/
#line 139 "mn-gmail-mailbox.gob"
static char * 
mn_gmail_mailbox_get_token (const char * str, const char * pre, const char * post, gboolean include_pre, gboolean include_post)
#line 360 "mn-gmail-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox::get_token"
#line 139 "mn-gmail-mailbox.gob"
	g_return_val_if_fail (str != NULL, (char * )0);
#line 139 "mn-gmail-mailbox.gob"
	g_return_val_if_fail (pre != NULL, (char * )0);
#line 139 "mn-gmail-mailbox.gob"
	g_return_val_if_fail (post != NULL, (char * )0);
#line 369 "mn-gmail-mailbox.c"
{
#line 145 "mn-gmail-mailbox.gob"
	
    char *token = NULL;
    char *pre_loc;
    
    pre_loc = strstr(str, pre);
    if (pre_loc)
      {
	char *after_pre_loc;
	char *post_loc;
	
	after_pre_loc = pre_loc + strlen(pre);
	post_loc = strstr(after_pre_loc, post);
	if (post_loc)
	  {
	    char *start = include_pre ? pre_loc : after_pre_loc;
	    char *end = include_post ? post_loc + strlen(post) : post_loc;
	    
	    token = g_strndup(start, end - start);
	  }
      }
    
    return token;
  }}
#line 395 "mn-gmail-mailbox.c"
#undef __GOB_FUNCTION__

#line 169 "mn-gmail-mailbox.gob"
static void 
mn_gmail_mailbox_login (MNGmailMailbox * self)
#line 401 "mn-gmail-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox::login"
#line 169 "mn-gmail-mailbox.gob"
	g_return_if_fail (self != NULL);
#line 169 "mn-gmail-mailbox.gob"
	g_return_if_fail (MN_IS_GMAIL_MAILBOX (self));
#line 408 "mn-gmail-mailbox.c"
{
#line 171 "mn-gmail-mailbox.gob"
	
    char *uri;
    char *escaped_username;
    char *escaped_password;

    g_return_if_fail(selfp->logged_in == FALSE);

    if (selfp->cookies)
      g_hash_table_destroy(selfp->cookies);
    selfp->cookies = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
	
    mn_mailbox_notice(MN_MAILBOX(self), _("logging in"));

    escaped_username = gnome_vfs_escape_string(selfp->username);
    escaped_password = gnome_vfs_escape_string(selfp->password);
    uri = g_strdup_printf("https://www.google.com/accounts/ServiceLoginBoxAuth?service=mail&continue=http://gmail.google.com/gmail&Email=%s&Passwd=%s", escaped_username, escaped_password);
    g_free(escaped_username);
    g_free(escaped_password);

    self_get(self, uri, self_login_cb1);
    g_free(uri);
  }}
#line 433 "mn-gmail-mailbox.c"
#undef __GOB_FUNCTION__

#line 194 "mn-gmail-mailbox.gob"
static void 
mn_gmail_mailbox_login_cb1 (SoupMessage * message, gpointer user_data)
#line 439 "mn-gmail-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox::login_cb1"
#line 194 "mn-gmail-mailbox.gob"
	g_return_if_fail (message != NULL);
#line 194 "mn-gmail-mailbox.gob"
	g_return_if_fail (user_data != NULL);
#line 446 "mn-gmail-mailbox.c"
{
#line 197 "mn-gmail-mailbox.gob"
	
    Self *self = user_data;

    if (SOUP_MESSAGE_IS_ERROR(message))
      mn_mailbox_set_error(MN_MAILBOX(self), _("unable to transfer data: %s"), message->errorphrase);
    else
      {
	char *body;
	char *next_location;

	self_update_cookies(self, message);

	body = g_strndup(message->response.body, message->response.length);
	next_location = self_get_token(body, "top.location = \"", "\"", FALSE, FALSE);
	g_free(body);

	if (next_location)
	  {
	    char *uri;

	    uri = g_strdup_printf("https://www.google.com/accounts/%s", next_location);
	    g_free(next_location);

	    self_get(self, uri, self_login_cb2);
	    g_free(uri);

	    return;
	  }

	mn_mailbox_set_error(MN_MAILBOX(self), _("login failed"));
      }
    
    /* if this point is reached, an error occurred */
    mn_mailbox_end_check(MN_MAILBOX(self));
  }}
#line 484 "mn-gmail-mailbox.c"
#undef __GOB_FUNCTION__

#line 233 "mn-gmail-mailbox.gob"
static void 
mn_gmail_mailbox_login_cb2 (SoupMessage * message, gpointer user_data)
#line 490 "mn-gmail-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox::login_cb2"
#line 233 "mn-gmail-mailbox.gob"
	g_return_if_fail (message != NULL);
#line 233 "mn-gmail-mailbox.gob"
	g_return_if_fail (user_data != NULL);
#line 497 "mn-gmail-mailbox.c"
{
#line 236 "mn-gmail-mailbox.gob"
	
    Self *self = user_data;

    if (SOUP_MESSAGE_IS_ERROR(message))
      mn_mailbox_set_error(MN_MAILBOX(self), _("unable to transfer data: %s"), message->errorphrase);
    else
      {
	char *body;
	char *next_location;

	self_update_cookies(self, message);
	
	body = g_strndup(message->response.body, message->response.length);
	next_location = self_get_token(body, "location.replace(\"", "\")", FALSE, FALSE);
	g_free(body);

	if (next_location)
	  {
	    self_get(self, next_location, self_login_cb3);
	    g_free(next_location);
	    return;
	  }

	mn_mailbox_set_error(MN_MAILBOX(self), _("login failed"));
      }

    /* if this point is reached, an error occurred */
    mn_mailbox_end_check(MN_MAILBOX(self));
  }}
#line 529 "mn-gmail-mailbox.c"
#undef __GOB_FUNCTION__

#line 266 "mn-gmail-mailbox.gob"
static void 
mn_gmail_mailbox_login_cb3 (SoupMessage * message, gpointer user_data)
#line 535 "mn-gmail-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox::login_cb3"
#line 266 "mn-gmail-mailbox.gob"
	g_return_if_fail (message != NULL);
#line 266 "mn-gmail-mailbox.gob"
	g_return_if_fail (user_data != NULL);
#line 542 "mn-gmail-mailbox.c"
{
#line 269 "mn-gmail-mailbox.gob"
	
    Self *self = user_data;

    if (SOUP_MESSAGE_IS_ERROR(message))
      mn_mailbox_set_error(MN_MAILBOX(self), _("unable to transfer data: %s"), message->errorphrase);
    else
      {
	char *body;
	char *token;

	self_update_cookies(self, message);

	body = g_strndup(message->response.body, message->response.length);
	token = strstr(body, "frame name=js src=/gmail");
	
	if (token)
	  {
	    selfp->logged_in = TRUE;
	    mn_mailbox_notice(MN_MAILBOX(self), _("successfully logged in"));
	    self_check_internal(self);
	    
	    return;
	  }

	mn_mailbox_set_error(MN_MAILBOX(self), _("login failed"));
      }

    /* if this point is reached, an error occurred */
    mn_mailbox_end_check(MN_MAILBOX(self));
  }}
#line 575 "mn-gmail-mailbox.c"
#undef __GOB_FUNCTION__

#line 300 "mn-gmail-mailbox.gob"
static void 
mn_gmail_mailbox_update_cookies (MNGmailMailbox * self, SoupMessage * message)
#line 581 "mn-gmail-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox::update_cookies"
#line 300 "mn-gmail-mailbox.gob"
	g_return_if_fail (self != NULL);
#line 300 "mn-gmail-mailbox.gob"
	g_return_if_fail (MN_IS_GMAIL_MAILBOX (self));
#line 300 "mn-gmail-mailbox.gob"
	g_return_if_fail (message != NULL);
#line 590 "mn-gmail-mailbox.c"
{
#line 302 "mn-gmail-mailbox.gob"
	
    const GSList *set_cookie_headers;
    const GSList *l;
    
    set_cookie_headers = soup_message_get_header_list(message->response_headers, "Set-Cookie");
    MN_LIST_FOREACH(l, set_cookie_headers)
      {
	const char *value = l->data;
	char *equal;

	equal = strchr(value, '=');
	if (equal && equal - value > 0)
	  {
	    char *end;
	    char *cookie_name;
	    char *cookie_value;

	    end = strchr(equal, ';');

	    cookie_name = g_strndup(value, equal - value);
	    cookie_value = end
	      ? g_strndup(equal + 1, end - equal - 1)
	      : g_strdup(equal + 1);

	    g_hash_table_insert(selfp->cookies, cookie_name, cookie_value);
	  }
      }
  }}
#line 621 "mn-gmail-mailbox.c"
#undef __GOB_FUNCTION__

#line 331 "mn-gmail-mailbox.gob"
static char * 
mn_gmail_mailbox_build_cookie (MNGmailMailbox * self)
#line 627 "mn-gmail-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox::build_cookie"
#line 331 "mn-gmail-mailbox.gob"
	g_return_val_if_fail (self != NULL, (char * )0);
#line 331 "mn-gmail-mailbox.gob"
	g_return_val_if_fail (MN_IS_GMAIL_MAILBOX (self), (char * )0);
#line 634 "mn-gmail-mailbox.c"
{
#line 333 "mn-gmail-mailbox.gob"
	
    GString *cookie;
    char *str;

    cookie = g_string_new(NULL);
    g_hash_table_foreach(selfp->cookies, self_build_cookie_cb, cookie);

    if (*cookie->str)
      str = g_string_free(cookie, FALSE);
    else
      {
	str = NULL;
	g_string_free(cookie, TRUE);
      }

    return str;
  }}
#line 654 "mn-gmail-mailbox.c"
#undef __GOB_FUNCTION__

#line 351 "mn-gmail-mailbox.gob"
static void 
mn_gmail_mailbox_build_cookie_cb (gpointer key, gpointer value, gpointer user_data)
#line 660 "mn-gmail-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox::build_cookie_cb"
{
#line 353 "mn-gmail-mailbox.gob"
	
    GString *cookie = user_data;

    if (*cookie->str)
      g_string_append(cookie, "; ");

    g_string_append_printf(cookie, "%s=%s", (const char *) key, (const char *) value);
  }}
#line 673 "mn-gmail-mailbox.c"
#undef __GOB_FUNCTION__

#line 362 "mn-gmail-mailbox.gob"
static void 
mn_gmail_mailbox_check_internal (MNGmailMailbox * self)
#line 679 "mn-gmail-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox::check_internal"
#line 362 "mn-gmail-mailbox.gob"
	g_return_if_fail (self != NULL);
#line 362 "mn-gmail-mailbox.gob"
	g_return_if_fail (MN_IS_GMAIL_MAILBOX (self));
#line 686 "mn-gmail-mailbox.c"
{
#line 364 "mn-gmail-mailbox.gob"
	
    mn_mailbox_notice(MN_MAILBOX(self), _("searching for unread mail"));

    self_get(self, "https://gmail.google.com/gmail?search=adv&as_subset=unread&view=tl&start=0", self_check_internal_cb);
  }}
#line 694 "mn-gmail-mailbox.c"
#undef __GOB_FUNCTION__

#line 370 "mn-gmail-mailbox.gob"
static void 
mn_gmail_mailbox_check_internal_cb (SoupMessage * message, gpointer user_data)
#line 700 "mn-gmail-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox::check_internal_cb"
#line 370 "mn-gmail-mailbox.gob"
	g_return_if_fail (message != NULL);
#line 705 "mn-gmail-mailbox.c"
{
#line 373 "mn-gmail-mailbox.gob"
	
    Self *self = user_data;

    if (SOUP_MESSAGE_IS_ERROR(message))
      mn_mailbox_set_error(MN_MAILBOX(self), _("unable to transfer data: %s"), message->errorphrase);
    else
      {
	int count;
	
	count = self_get_unread_count(message);
	if (count == -1)
	  mn_mailbox_set_error(MN_MAILBOX(self), _("unable to parse Gmail data"));
	else
	  mn_mailbox_set_has_new(MN_MAILBOX(self), count != 0);
    }

    mn_mailbox_end_check(MN_MAILBOX(self));
  }}
#line 726 "mn-gmail-mailbox.c"
#undef __GOB_FUNCTION__

#line 392 "mn-gmail-mailbox.gob"
static int 
mn_gmail_mailbox_get_unread_count (SoupMessage * message)
#line 732 "mn-gmail-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox::get_unread_count"
#line 392 "mn-gmail-mailbox.gob"
	g_return_val_if_fail (message != NULL, (int )0);
#line 737 "mn-gmail-mailbox.c"
{
#line 394 "mn-gmail-mailbox.gob"
	
    int count = -1;
    char *body;
    char *results;
  
    body = g_strndup(message->response.body, message->response.length);
    
    results = strstr(body, "Search results for: is:unread\",\"");
    if (results)
      {
	char *count_str;
	
	count_str = self_get_token(results + 32, "\",", "]", FALSE, FALSE);
	if (count_str)
	  {
	    if (mn_str_isnumeric(count_str))
	      count = atoi(count_str);
	    g_free(count_str);
	  }
      }
  
    g_free(body);
    
    return count;
  }}
#line 765 "mn-gmail-mailbox.c"
#undef __GOB_FUNCTION__