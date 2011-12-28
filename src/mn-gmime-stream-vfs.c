/* Generated by GOB (v2.0.10) on Wed Oct  6 19:29:53 2004
   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 10

#define selfp (self->_priv)

#include <string.h> /* memset() */

#include "mn-gmime-stream-vfs.h"

#include "mn-gmime-stream-vfs-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 26 "mn-gmime-stream-vfs.gob"

#include "config.h"
#include <glib/gi18n-lib.h>

#define VFS_CALL(stream, expr, fail_format, fail_retval)		\
  {									\
    GnomeVFSResult result;						\
									\
    result = expr;							\
    if (result != GNOME_VFS_OK)						\
      {									\
	(stream)->_priv->eof = TRUE;					\
	if (result != GNOME_VFS_ERROR_EOF)				\
	  {								\
	    g_warning((fail_format),					\
		      (stream)->_priv->uri,				\
		      gnome_vfs_result_to_string(result));		\
	    return (fail_retval);					\
	  }								\
      }									\
  }

#define VFS_READ(stream, buffer, bytes, bytes_read, fail_retval) \
  VFS_CALL((stream), gnome_vfs_read((stream)->_priv->handle, (buffer), (bytes), (bytes_read)), _("unable to read %s: %s"), (fail_retval))
#define VFS_WRITE(stream, buffer, bytes, bytes_written, fail_retval) \
  VFS_CALL((stream), gnome_vfs_write((stream)->_priv->handle, (buffer), (bytes), (bytes_written)), _("unable to write to %s: %s"), (fail_retval))
#define VFS_SEEK(stream, whence, offset, fail_retval) \
  VFS_CALL((stream), gnome_vfs_seek((stream)->_priv->handle, (whence), (offset)), _("unable to seek in %s: %s"), (fail_retval))
#define VFS_TELL(stream, offset_return, fail_retval) \
  VFS_CALL((stream), gnome_vfs_tell((stream)->_priv->handle, (offset_return)), _("unable to tell position of %s: %s"), (fail_retval))
#define VFS_CLOSE(stream, fail_retval) \
  VFS_CALL((stream), gnome_vfs_close((stream)->_priv->handle), _("unable to close %s: %s"), (fail_retval))

#line 61 "mn-gmime-stream-vfs.c"
/* self casting macros */
#define SELF(x) MN_GMIME_STREAM_VFS(x)
#define SELF_CONST(x) MN_GMIME_STREAM_VFS_CONST(x)
#define IS_SELF(x) MN_IS_GMIME_STREAM_VFS(x)
#define TYPE_SELF MN_TYPE_GMIME_STREAM_VFS
#define SELF_CLASS(x) MN_GMIME_STREAM_VFS_CLASS(x)

#define SELF_GET_CLASS(x) MN_GMIME_STREAM_VFS_GET_CLASS(x)

/* self typedefs */
typedef MNGMimeStreamVFS Self;
typedef MNGMimeStreamVFSClass SelfClass;

/* here are local prototypes */
static void mn_gmime_stream_vfs_init (MNGMimeStreamVFS * o) G_GNUC_UNUSED;
static void mn_gmime_stream_vfs_class_init (MNGMimeStreamVFSClass * c) G_GNUC_UNUSED;
static ssize_t ___1_mn_gmime_stream_vfs_read (GMimeStream * stream, char * buf, size_t len) G_GNUC_UNUSED;
static ssize_t ___2_mn_gmime_stream_vfs_write (GMimeStream * stream, const char * buf, size_t len) G_GNUC_UNUSED;
static int ___3_mn_gmime_stream_vfs_flush (GMimeStream * stream) G_GNUC_UNUSED;
static int ___4_mn_gmime_stream_vfs_close (GMimeStream * stream) G_GNUC_UNUSED;
static gboolean ___5_mn_gmime_stream_vfs_eos (GMimeStream * stream) G_GNUC_UNUSED;
static int ___6_mn_gmime_stream_vfs_reset (GMimeStream * stream) G_GNUC_UNUSED;
static off_t ___7_mn_gmime_stream_vfs_seek (GMimeStream * stream, off_t offset, GMimeSeekWhence whence) G_GNUC_UNUSED;
static off_t ___8_mn_gmime_stream_vfs_tell (GMimeStream * stream) G_GNUC_UNUSED;
static ssize_t ___9_mn_gmime_stream_vfs_length (GMimeStream * stream) G_GNUC_UNUSED;
static GMimeStream * ___a_mn_gmime_stream_vfs_substream (GMimeStream * stream, off_t start, off_t end) G_GNUC_UNUSED;

/* pointer to the class of our parent */
static GMimeStreamClass *parent_class = NULL;

/* Short form macros */
#define self_new mn_gmime_stream_vfs_new
GType
mn_gmime_stream_vfs_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (MNGMimeStreamVFSClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) mn_gmime_stream_vfs_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (MNGMimeStreamVFS),
			0 /* n_preallocs */,
			(GInstanceInitFunc) mn_gmime_stream_vfs_init,
			NULL
		};

		type = g_type_register_static (GMIME_TYPE_STREAM, "MNGMimeStreamVFS", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((MNGMimeStreamVFS *)g_object_new(mn_gmime_stream_vfs_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static MNGMimeStreamVFS * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static MNGMimeStreamVFS *
GET_NEW_VARG (const char *first, ...)
{
	MNGMimeStreamVFS *ret;
	va_list ap;
	va_start (ap, first);
	ret = (MNGMimeStreamVFS *)g_object_new_valist (mn_gmime_stream_vfs_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "MN:GMime:Stream:VFS::finalize"
	MNGMimeStreamVFS *self G_GNUC_UNUSED = MN_GMIME_STREAM_VFS (obj_self);
	gpointer priv G_GNUC_UNUSED = self->_priv;
	if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(obj_self);
#line 63 "mn-gmime-stream-vfs.gob"
	if(self->_priv->uri) { g_free ((gpointer) self->_priv->uri); self->_priv->uri = NULL; }
#line 147 "mn-gmime-stream-vfs.c"
}
#undef __GOB_FUNCTION__

static void 
mn_gmime_stream_vfs_init (MNGMimeStreamVFS * o G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:GMime:Stream:VFS::init"
	o->_priv = G_TYPE_INSTANCE_GET_PRIVATE(o,TYPE_SELF,MNGMimeStreamVFSPrivate);
}
#undef __GOB_FUNCTION__
static void 
mn_gmime_stream_vfs_class_init (MNGMimeStreamVFSClass * c G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:GMime:Stream:VFS::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) c;

	g_type_class_add_private(c,sizeof(MNGMimeStreamVFSPrivate));
	GMimeStreamClass *gmime_stream_class = (GMimeStreamClass *)c;

	parent_class = g_type_class_ref (GMIME_TYPE_STREAM);

#line 66 "mn-gmime-stream-vfs.gob"
	gmime_stream_class->read = ___1_mn_gmime_stream_vfs_read;
#line 88 "mn-gmime-stream-vfs.gob"
	gmime_stream_class->write = ___2_mn_gmime_stream_vfs_write;
#line 110 "mn-gmime-stream-vfs.gob"
	gmime_stream_class->flush = ___3_mn_gmime_stream_vfs_flush;
#line 117 "mn-gmime-stream-vfs.gob"
	gmime_stream_class->close = ___4_mn_gmime_stream_vfs_close;
#line 127 "mn-gmime-stream-vfs.gob"
	gmime_stream_class->eos = ___5_mn_gmime_stream_vfs_eos;
#line 138 "mn-gmime-stream-vfs.gob"
	gmime_stream_class->reset = ___6_mn_gmime_stream_vfs_reset;
#line 152 "mn-gmime-stream-vfs.gob"
	gmime_stream_class->seek = ___7_mn_gmime_stream_vfs_seek;
#line 199 "mn-gmime-stream-vfs.gob"
	gmime_stream_class->tell = ___8_mn_gmime_stream_vfs_tell;
#line 205 "mn-gmime-stream-vfs.gob"
	gmime_stream_class->length = ___9_mn_gmime_stream_vfs_length;
#line 224 "mn-gmime-stream-vfs.gob"
	gmime_stream_class->substream = ___a_mn_gmime_stream_vfs_substream;
#line 189 "mn-gmime-stream-vfs.c"
	g_object_class->finalize = ___finalize;
}
#undef __GOB_FUNCTION__



#line 66 "mn-gmime-stream-vfs.gob"
static ssize_t 
___1_mn_gmime_stream_vfs_read (GMimeStream * stream G_GNUC_UNUSED, char * buf, size_t len)
#line 199 "mn-gmime-stream-vfs.c"
#define PARENT_HANDLER(___stream,___buf,___len) \
	((GMIME_STREAM_CLASS(parent_class)->read)? \
		(* GMIME_STREAM_CLASS(parent_class)->read)(___stream,___buf,___len): \
		((ssize_t )0))
{
#define __GOB_FUNCTION__ "MN:GMime:Stream:VFS::read"
#line 66 "mn-gmime-stream-vfs.gob"
	g_return_val_if_fail (stream != NULL, (ssize_t )0);
#line 66 "mn-gmime-stream-vfs.gob"
	g_return_val_if_fail (GMIME_IS_STREAM (stream), (ssize_t )0);
#line 66 "mn-gmime-stream-vfs.gob"
	g_return_val_if_fail (buf != NULL, (ssize_t )0);
#line 212 "mn-gmime-stream-vfs.c"
{
#line 70 "mn-gmime-stream-vfs.gob"
	
    Self *self = SELF(stream);
    GnomeVFSFileSize bytes_read;

    if (stream->bound_end != -1 && stream->position >= stream->bound_end)
      return -1;
    if (stream->bound_end != -1)
      len = MIN(stream->bound_end - stream->position, (off_t) len);

    /* make sure we are at the right position */
    VFS_SEEK(self, GNOME_VFS_SEEK_START, stream->position, -1);

    VFS_READ(self, buf, len, &bytes_read, -1);
    stream->position += bytes_read;
    
    return bytes_read;
  }}
#line 232 "mn-gmime-stream-vfs.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 88 "mn-gmime-stream-vfs.gob"
static ssize_t 
___2_mn_gmime_stream_vfs_write (GMimeStream * stream G_GNUC_UNUSED, const char * buf, size_t len)
#line 239 "mn-gmime-stream-vfs.c"
#define PARENT_HANDLER(___stream,___buf,___len) \
	((GMIME_STREAM_CLASS(parent_class)->write)? \
		(* GMIME_STREAM_CLASS(parent_class)->write)(___stream,___buf,___len): \
		((ssize_t )0))
{
#define __GOB_FUNCTION__ "MN:GMime:Stream:VFS::write"
#line 88 "mn-gmime-stream-vfs.gob"
	g_return_val_if_fail (stream != NULL, (ssize_t )0);
#line 88 "mn-gmime-stream-vfs.gob"
	g_return_val_if_fail (GMIME_IS_STREAM (stream), (ssize_t )0);
#line 88 "mn-gmime-stream-vfs.gob"
	g_return_val_if_fail (buf != NULL, (ssize_t )0);
#line 252 "mn-gmime-stream-vfs.c"
{
#line 92 "mn-gmime-stream-vfs.gob"
	
    Self *self = SELF(stream);
    GnomeVFSFileSize bytes_written;

    if (stream->bound_end != -1 && stream->position >= stream->bound_end)
      return -1;
    if (stream->bound_end != -1)
      len = MIN(stream->bound_end - stream->position, (off_t) len);

    /* make sure we are at the right position */
    VFS_SEEK(self, GNOME_VFS_SEEK_START, stream->position, -1);

    VFS_WRITE(self, buf, len, &bytes_written, -1);
    stream->position += bytes_written;

    return bytes_written;
  }}
#line 272 "mn-gmime-stream-vfs.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 110 "mn-gmime-stream-vfs.gob"
static int 
___3_mn_gmime_stream_vfs_flush (GMimeStream * stream G_GNUC_UNUSED)
#line 279 "mn-gmime-stream-vfs.c"
#define PARENT_HANDLER(___stream) \
	((GMIME_STREAM_CLASS(parent_class)->flush)? \
		(* GMIME_STREAM_CLASS(parent_class)->flush)(___stream): \
		((int )0))
{
#define __GOB_FUNCTION__ "MN:GMime:Stream:VFS::flush"
#line 110 "mn-gmime-stream-vfs.gob"
	g_return_val_if_fail (stream != NULL, (int )0);
#line 110 "mn-gmime-stream-vfs.gob"
	g_return_val_if_fail (GMIME_IS_STREAM (stream), (int )0);
#line 290 "mn-gmime-stream-vfs.c"
{
#line 112 "mn-gmime-stream-vfs.gob"
	
    /* nop */
    return 0;			/* success */
  }}
#line 297 "mn-gmime-stream-vfs.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 117 "mn-gmime-stream-vfs.gob"
static int 
___4_mn_gmime_stream_vfs_close (GMimeStream * stream G_GNUC_UNUSED)
#line 304 "mn-gmime-stream-vfs.c"
#define PARENT_HANDLER(___stream) \
	((GMIME_STREAM_CLASS(parent_class)->close)? \
		(* GMIME_STREAM_CLASS(parent_class)->close)(___stream): \
		((int )0))
{
#define __GOB_FUNCTION__ "MN:GMime:Stream:VFS::close"
#line 117 "mn-gmime-stream-vfs.gob"
	g_return_val_if_fail (stream != NULL, (int )0);
#line 117 "mn-gmime-stream-vfs.gob"
	g_return_val_if_fail (GMIME_IS_STREAM (stream), (int )0);
#line 315 "mn-gmime-stream-vfs.c"
{
#line 119 "mn-gmime-stream-vfs.gob"
	
    Self *self = SELF(stream);

    VFS_CLOSE(self, -1);

    return 0;			/* success */
  }}
#line 325 "mn-gmime-stream-vfs.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 127 "mn-gmime-stream-vfs.gob"
static gboolean 
___5_mn_gmime_stream_vfs_eos (GMimeStream * stream G_GNUC_UNUSED)
#line 332 "mn-gmime-stream-vfs.c"
#define PARENT_HANDLER(___stream) \
	((GMIME_STREAM_CLASS(parent_class)->eos)? \
		(* GMIME_STREAM_CLASS(parent_class)->eos)(___stream): \
		((gboolean )0))
{
#define __GOB_FUNCTION__ "MN:GMime:Stream:VFS::eos"
#line 127 "mn-gmime-stream-vfs.gob"
	g_return_val_if_fail (stream != NULL, (gboolean )0);
#line 127 "mn-gmime-stream-vfs.gob"
	g_return_val_if_fail (GMIME_IS_STREAM (stream), (gboolean )0);
#line 343 "mn-gmime-stream-vfs.c"
{
#line 129 "mn-gmime-stream-vfs.gob"
	
    Self *self = SELF(stream);

    if (stream->bound_end == -1)
      return selfp->eof;
    else
      return stream->position >= stream->bound_end;
  }}
#line 354 "mn-gmime-stream-vfs.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 138 "mn-gmime-stream-vfs.gob"
static int 
___6_mn_gmime_stream_vfs_reset (GMimeStream * stream G_GNUC_UNUSED)
#line 361 "mn-gmime-stream-vfs.c"
#define PARENT_HANDLER(___stream) \
	((GMIME_STREAM_CLASS(parent_class)->reset)? \
		(* GMIME_STREAM_CLASS(parent_class)->reset)(___stream): \
		((int )0))
{
#define __GOB_FUNCTION__ "MN:GMime:Stream:VFS::reset"
#line 138 "mn-gmime-stream-vfs.gob"
	g_return_val_if_fail (stream != NULL, (int )0);
#line 138 "mn-gmime-stream-vfs.gob"
	g_return_val_if_fail (GMIME_IS_STREAM (stream), (int )0);
#line 372 "mn-gmime-stream-vfs.c"
{
#line 140 "mn-gmime-stream-vfs.gob"
	
    Self *self = SELF(stream);

    if (stream->position == stream->bound_start)
      return 0;

    VFS_SEEK(self, GNOME_VFS_SEEK_START, stream->bound_start, -1);
    stream->position = stream->bound_start;

    return 0;
  }}
#line 386 "mn-gmime-stream-vfs.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 152 "mn-gmime-stream-vfs.gob"
static off_t 
___7_mn_gmime_stream_vfs_seek (GMimeStream * stream G_GNUC_UNUSED, off_t offset, GMimeSeekWhence whence)
#line 393 "mn-gmime-stream-vfs.c"
#define PARENT_HANDLER(___stream,___offset,___whence) \
	((GMIME_STREAM_CLASS(parent_class)->seek)? \
		(* GMIME_STREAM_CLASS(parent_class)->seek)(___stream,___offset,___whence): \
		((off_t )0))
{
#define __GOB_FUNCTION__ "MN:GMime:Stream:VFS::seek"
#line 152 "mn-gmime-stream-vfs.gob"
	g_return_val_if_fail (stream != NULL, (off_t )0);
#line 152 "mn-gmime-stream-vfs.gob"
	g_return_val_if_fail (GMIME_IS_STREAM (stream), (off_t )0);
#line 404 "mn-gmime-stream-vfs.c"
{
#line 156 "mn-gmime-stream-vfs.gob"
	
    Self *self = SELF(stream);
    off_t real = stream->position;

    switch (whence)
      {
      case GMIME_STREAM_SEEK_SET:
	real = offset;
	break;

      case GMIME_STREAM_SEEK_CUR:
	real = stream->position + offset;
	break;

      case GMIME_STREAM_SEEK_END:
	if (stream->bound_end == -1)
	  {
	    GnomeVFSFileSize current_position;

	    VFS_SEEK(self, GNOME_VFS_SEEK_END, offset, -1);
	    VFS_TELL(self, &current_position, -1);

	    real = current_position;
	    if (real < stream->bound_start)
	      real = stream->bound_start;
	    stream->position = real;
	    
	    return real;
	  }
	real = stream->bound_end + offset;
	break;
      }
    
    if (stream->bound_end != -1)
      real = MIN(real, stream->bound_end);
    real = MAX(real, stream->bound_start);

    VFS_SEEK(self, GNOME_VFS_SEEK_START, real, -1);
    stream->position = real;

    return real;
  }}
#line 449 "mn-gmime-stream-vfs.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 199 "mn-gmime-stream-vfs.gob"
static off_t 
___8_mn_gmime_stream_vfs_tell (GMimeStream * stream G_GNUC_UNUSED)
#line 456 "mn-gmime-stream-vfs.c"
#define PARENT_HANDLER(___stream) \
	((GMIME_STREAM_CLASS(parent_class)->tell)? \
		(* GMIME_STREAM_CLASS(parent_class)->tell)(___stream): \
		((off_t )0))
{
#define __GOB_FUNCTION__ "MN:GMime:Stream:VFS::tell"
#line 199 "mn-gmime-stream-vfs.gob"
	g_return_val_if_fail (stream != NULL, (off_t )0);
#line 199 "mn-gmime-stream-vfs.gob"
	g_return_val_if_fail (GMIME_IS_STREAM (stream), (off_t )0);
#line 467 "mn-gmime-stream-vfs.c"
{
#line 201 "mn-gmime-stream-vfs.gob"
	
    return stream->position;
  }}
#line 473 "mn-gmime-stream-vfs.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 205 "mn-gmime-stream-vfs.gob"
static ssize_t 
___9_mn_gmime_stream_vfs_length (GMimeStream * stream G_GNUC_UNUSED)
#line 480 "mn-gmime-stream-vfs.c"
#define PARENT_HANDLER(___stream) \
	((GMIME_STREAM_CLASS(parent_class)->length)? \
		(* GMIME_STREAM_CLASS(parent_class)->length)(___stream): \
		((ssize_t )0))
{
#define __GOB_FUNCTION__ "MN:GMime:Stream:VFS::length"
#line 205 "mn-gmime-stream-vfs.gob"
	g_return_val_if_fail (stream != NULL, (ssize_t )0);
#line 205 "mn-gmime-stream-vfs.gob"
	g_return_val_if_fail (GMIME_IS_STREAM (stream), (ssize_t )0);
#line 491 "mn-gmime-stream-vfs.c"
{
#line 207 "mn-gmime-stream-vfs.gob"
	
    Self *self = SELF(stream);
    GnomeVFSFileSize bound_end;

    if (stream->bound_start != -1 && stream->bound_end != -1)
      return stream->bound_end - stream->bound_start;

    VFS_SEEK(self, GNOME_VFS_SEEK_END, 0, -1);
    VFS_TELL(self, &bound_end, -1);
    VFS_SEEK(self, GNOME_VFS_SEEK_START, stream->position, -1);
    
    if (bound_end < stream->bound_start)
      return -1;
    
    return bound_end - stream->bound_start;
  }}
#line 510 "mn-gmime-stream-vfs.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 224 "mn-gmime-stream-vfs.gob"
static GMimeStream * 
___a_mn_gmime_stream_vfs_substream (GMimeStream * stream G_GNUC_UNUSED, off_t start, off_t end)
#line 517 "mn-gmime-stream-vfs.c"
#define PARENT_HANDLER(___stream,___start,___end) \
	((GMIME_STREAM_CLASS(parent_class)->substream)? \
		(* GMIME_STREAM_CLASS(parent_class)->substream)(___stream,___start,___end): \
		((GMimeStream * )0))
{
#define __GOB_FUNCTION__ "MN:GMime:Stream:VFS::substream"
#line 224 "mn-gmime-stream-vfs.gob"
	g_return_val_if_fail (stream != NULL, (GMimeStream * )0);
#line 224 "mn-gmime-stream-vfs.gob"
	g_return_val_if_fail (GMIME_IS_STREAM (stream), (GMimeStream * )0);
#line 528 "mn-gmime-stream-vfs.c"
{
#line 226 "mn-gmime-stream-vfs.gob"
	
    Self *self;

    self = GET_NEW;
    selfp->handle = SELF(stream)->_priv->handle;

    g_mime_stream_construct(GMIME_STREAM(self), start, end);

    return GMIME_STREAM(self);
  }}
#line 541 "mn-gmime-stream-vfs.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 237 "mn-gmime-stream-vfs.gob"
GMimeStream * 
mn_gmime_stream_vfs_new (GnomeVFSHandle * handle, const char * uri)
#line 548 "mn-gmime-stream-vfs.c"
{
#define __GOB_FUNCTION__ "MN:GMime:Stream:VFS::new"
#line 237 "mn-gmime-stream-vfs.gob"
	g_return_val_if_fail (handle != NULL, (GMimeStream * )0);
#line 237 "mn-gmime-stream-vfs.gob"
	g_return_val_if_fail (uri != NULL, (GMimeStream * )0);
#line 555 "mn-gmime-stream-vfs.c"
{
#line 239 "mn-gmime-stream-vfs.gob"
	
    Self *self;
    GMimeStream *stream;
    GnomeVFSFileSize current_position;

    self = GET_NEW;
    selfp->handle = handle;
    selfp->uri = g_strdup(uri);
    
    if (gnome_vfs_tell(selfp->handle, &current_position) != GNOME_VFS_OK)
      current_position = 0;
    
    stream = GMIME_STREAM(self);
    g_mime_stream_construct(stream, current_position, -1);
    
    /* check for EOF */
    if (g_mime_stream_length(stream) <= 0)
      selfp->eof = TRUE;

    return stream;
  }}
#line 579 "mn-gmime-stream-vfs.c"
#undef __GOB_FUNCTION__
