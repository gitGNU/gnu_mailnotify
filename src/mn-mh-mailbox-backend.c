/* Generated by GOB (v2.0.14)   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 14

#define selfp (self->_priv)

#include <string.h> /* memset() */

#include "mn-mh-mailbox-backend.h"

#include "mn-mh-mailbox-backend-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 26 "mn-mh-mailbox-backend.gob"

#include "config.h"
#include <glib/gi18n.h>
#include <eel/eel.h>
#include "mn-mailbox-private.h"
#include "mn-reentrant-mailbox-private.h"
#include "mn-vfs-mailbox-backend-private.h"
#include "mn-vfs.h"
#include "mn-util.h"
#include "mn-message-mime.h"

#define SEQUENCES_FILE			".mh_sequences"

#line 40 "mn-mh-mailbox-backend.c"
/* self casting macros */
#define SELF(x) MN_MH_MAILBOX_BACKEND(x)
#define SELF_CONST(x) MN_MH_MAILBOX_BACKEND_CONST(x)
#define IS_SELF(x) MN_IS_MH_MAILBOX_BACKEND(x)
#define TYPE_SELF MN_TYPE_MH_MAILBOX_BACKEND
#define SELF_CLASS(x) MN_MH_MAILBOX_BACKEND_CLASS(x)

#define SELF_GET_CLASS(x) MN_MH_MAILBOX_BACKEND_GET_CLASS(x)

/* self typedefs */
typedef MNMHMailboxBackend Self;
typedef MNMHMailboxBackendClass SelfClass;

/* here are local prototypes */
static void mn_mh_mailbox_backend_init (MNMHMailboxBackend * o) G_GNUC_UNUSED;
static void mn_mh_mailbox_backend_class_init (MNMHMailboxBackendClass * class) G_GNUC_UNUSED;
static void ___2_mn_mh_mailbox_backend_monitor_cb (MNVFSMailboxBackend * backend, const char * info_uri, GnomeVFSMonitorEventType event_type) G_GNUC_UNUSED;
static gboolean ___3_mn_mh_mailbox_backend_is (MNVFSMailboxBackend * dummy, MNVFSMailboxBackendClass * class, MNVFSMailbox * mailbox) G_GNUC_UNUSED;
static void ___4_mn_mh_mailbox_backend_check (MNVFSMailboxBackend * backend, unsigned long check_id) G_GNUC_UNUSED;

/* pointer to the class of our parent */
static MNVFSMailboxBackendClass *parent_class = NULL;

GType
mn_mh_mailbox_backend_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (MNMHMailboxBackendClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) mn_mh_mailbox_backend_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (MNMHMailboxBackend),
			0 /* n_preallocs */,
			(GInstanceInitFunc) mn_mh_mailbox_backend_init,
			NULL
		};

		type = g_type_register_static (MN_TYPE_VFS_MAILBOX_BACKEND, "MNMHMailboxBackend", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((MNMHMailboxBackend *)g_object_new(mn_mh_mailbox_backend_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static MNMHMailboxBackend * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static MNMHMailboxBackend *
GET_NEW_VARG (const char *first, ...)
{
	MNMHMailboxBackend *ret;
	va_list ap;
	va_start (ap, first);
	ret = (MNMHMailboxBackend *)g_object_new_valist (mn_mh_mailbox_backend_get_type (), first, ap);
	va_end (ap);
	return ret;
}

static void 
mn_mh_mailbox_backend_init (MNMHMailboxBackend * o G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:MH:Mailbox:Backend::init"
}
#undef __GOB_FUNCTION__
#line 42 "mn-mh-mailbox-backend.gob"
static void 
mn_mh_mailbox_backend_class_init (MNMHMailboxBackendClass * class G_GNUC_UNUSED)
#line 115 "mn-mh-mailbox-backend.c"
{
#define __GOB_FUNCTION__ "MN:MH:Mailbox:Backend::class_init"
	MNVFSMailboxBackendClass *mn_vfs_mailbox_backend_class = (MNVFSMailboxBackendClass *)class;

	parent_class = g_type_class_ref (MN_TYPE_VFS_MAILBOX_BACKEND);

#line 47 "mn-mh-mailbox-backend.gob"
	mn_vfs_mailbox_backend_class->monitor_cb = ___2_mn_mh_mailbox_backend_monitor_cb;
#line 69 "mn-mh-mailbox-backend.gob"
	mn_vfs_mailbox_backend_class->is = ___3_mn_mh_mailbox_backend_is;
#line 84 "mn-mh-mailbox-backend.gob"
	mn_vfs_mailbox_backend_class->check = ___4_mn_mh_mailbox_backend_check;
#line 128 "mn-mh-mailbox-backend.c"
 {
#line 43 "mn-mh-mailbox-backend.gob"

    MN_VFS_MAILBOX_BACKEND_CLASS(class)->format = "MH";
  
#line 134 "mn-mh-mailbox-backend.c"
 }
}
#undef __GOB_FUNCTION__



#line 47 "mn-mh-mailbox-backend.gob"
static void 
___2_mn_mh_mailbox_backend_monitor_cb (MNVFSMailboxBackend * backend G_GNUC_UNUSED, const char * info_uri, GnomeVFSMonitorEventType event_type)
#line 144 "mn-mh-mailbox-backend.c"
#define PARENT_HANDLER(___backend,___info_uri,___event_type) \
	{ if(MN_VFS_MAILBOX_BACKEND_CLASS(parent_class)->monitor_cb) \
		(* MN_VFS_MAILBOX_BACKEND_CLASS(parent_class)->monitor_cb)(___backend,___info_uri,___event_type); }
{
#define __GOB_FUNCTION__ "MN:MH:Mailbox:Backend::monitor_cb"
{
#line 51 "mn-mh-mailbox-backend.gob"
	
    if (event_type == GNOME_VFS_MONITOR_EVENT_CHANGED
	|| event_type == GNOME_VFS_MONITOR_EVENT_DELETED
	|| event_type == GNOME_VFS_MONITOR_EVENT_CREATED)
      {
	char *filename;

	filename = eel_uri_get_basename(info_uri);
	if (filename)
	  {
	    if (! strcmp(filename, SEQUENCES_FILE) || mn_str_isnumeric(filename))
	      mn_reentrant_mailbox_queue_check(MN_REENTRANT_MAILBOX(backend->mailbox));

	    g_free(filename);
	  }
      }
  }}
#line 169 "mn-mh-mailbox-backend.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 69 "mn-mh-mailbox-backend.gob"
static gboolean 
___3_mn_mh_mailbox_backend_is (MNVFSMailboxBackend * dummy G_GNUC_UNUSED, MNVFSMailboxBackendClass * class, MNVFSMailbox * mailbox)
#line 176 "mn-mh-mailbox-backend.c"
#define PARENT_HANDLER(___dummy,___class,___mailbox) \
	((MN_VFS_MAILBOX_BACKEND_CLASS(parent_class)->is)? \
		(* MN_VFS_MAILBOX_BACKEND_CLASS(parent_class)->is)(___dummy,___class,___mailbox): \
		((gboolean )0))
{
#define __GOB_FUNCTION__ "MN:MH:Mailbox:Backend::is"
{
#line 73 "mn-mh-mailbox-backend.gob"
	
    GnomeVFSURI *sequences_uri;
    gboolean is;

    sequences_uri = gnome_vfs_uri_append_file_name(mailbox->vfs_uri, SEQUENCES_FILE);
    is = mn_vfs_test(sequences_uri, G_FILE_TEST_IS_REGULAR);
    gnome_vfs_uri_unref(sequences_uri);

    return is;
  }}
#line 195 "mn-mh-mailbox-backend.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 84 "mn-mh-mailbox-backend.gob"
static void 
___4_mn_mh_mailbox_backend_check (MNVFSMailboxBackend * backend G_GNUC_UNUSED, unsigned long check_id)
#line 202 "mn-mh-mailbox-backend.c"
#define PARENT_HANDLER(___backend,___check_id) \
	{ if(MN_VFS_MAILBOX_BACKEND_CLASS(parent_class)->check) \
		(* MN_VFS_MAILBOX_BACKEND_CLASS(parent_class)->check)(___backend,___check_id); }
{
#define __GOB_FUNCTION__ "MN:MH:Mailbox:Backend::check"
{
#line 86 "mn-mh-mailbox-backend.gob"
	
    GnomeVFSURI *sequences_uri;
    GnomeVFSResult result;
    GnomeVFSHandle *handle;

    mn_vfs_mailbox_backend_monitor(backend, check_id, backend->mailbox->uri, GNOME_VFS_MONITOR_DIRECTORY);

    sequences_uri = gnome_vfs_uri_append_file_name(backend->mailbox->vfs_uri, SEQUENCES_FILE);
    result = gnome_vfs_open_uri(&handle, sequences_uri, GNOME_VFS_OPEN_READ);
    gnome_vfs_uri_unref(sequences_uri);

    if (result == GNOME_VFS_OK)
      {
	MNVFSReadLineContext *context = NULL;
	const char *line;
	GSList *messages = NULL;
	GnomeVFSResult close_result;

	while ((result = mn_vfs_read_line(&context, handle, &line)) == GNOME_VFS_OK)
	  if (g_str_has_prefix(line, "unseen: "))
	    {
	      int first;
	      char **elements;
	      int i;

	      elements = g_strsplit(line + 8, " ", 0);
	      for (i = 0; elements[i]; i++)
		{
		  int last;
		  int n;

		  n = sscanf(elements[i], "%d-%d", &first, &last);
		  if (n >= 1)
		    {
		      int j;

		      if (n == 1)
			last = first;

		      for (j = first; j <= last; j++)
			{
			  char *filename;
			  GnomeVFSURI *message_uri;
			  MNMessage *message;

			  if (mn_reentrant_mailbox_check_aborted(MN_REENTRANT_MAILBOX(backend->mailbox), check_id))
			    {
			      g_strfreev(elements);
			      goto loop_end;
			    }

			  filename = g_strdup_printf("%i", j);
			  message_uri = gnome_vfs_uri_append_file_name(backend->mailbox->vfs_uri, filename);
			  g_free(filename);

			  /*
			   * We set handle_status to FALSE, since
			   * messages in the unseen sequence are by
			   * definition unseen (that is, new).
			   */

			  message = mn_message_new_from_uri(MN_MAILBOX(backend->mailbox),
							    message_uri,
							    MN_MESSAGE_NEW,
							    FALSE);
			  gnome_vfs_uri_unref(message_uri);

			  if (message)
			    messages = g_slist_prepend(messages, message);
			}
		    }
		}
	      g_strfreev(elements);
	    }

      loop_end:
	mn_vfs_read_line_context_free(context);
	close_result = gnome_vfs_close(handle);

	GDK_THREADS_ENTER();

	if (! mn_reentrant_mailbox_check_aborted_unlocked(MN_REENTRANT_MAILBOX(backend->mailbox), check_id))
	  {
	    if (result == GNOME_VFS_ERROR_EOF || result == GNOME_VFS_OK)
	      {
		if (close_result == GNOME_VFS_OK)
		  mn_mailbox_set_messages(MN_MAILBOX(backend->mailbox), messages);
		else
		  mn_mailbox_set_error(MN_MAILBOX(backend->mailbox), _("unable to close %s: %s"), SEQUENCES_FILE, gnome_vfs_result_to_string(close_result));
	      }
	    else
	      mn_mailbox_set_error(MN_MAILBOX(backend->mailbox), _("error while reading %s: %s"), SEQUENCES_FILE, gnome_vfs_result_to_string(result));
	  }

	mn_g_object_slist_free(messages);

	gdk_flush();
	GDK_THREADS_LEAVE();
      }
    else
      {
	GDK_THREADS_ENTER();

	if (! mn_reentrant_mailbox_check_aborted_unlocked(MN_REENTRANT_MAILBOX(backend->mailbox), check_id))
	  mn_mailbox_set_error(MN_MAILBOX(backend->mailbox), _("unable to open %s: %s"), SEQUENCES_FILE, gnome_vfs_result_to_string(result));

	gdk_flush();
	GDK_THREADS_LEAVE();
      }
  }}
#line 320 "mn-mh-mailbox-backend.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER
