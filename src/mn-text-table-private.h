/* Generated by GOB (v2.0.14)   (do not edit directly) */

#ifndef __MN_TEXT_TABLE_PRIVATE_H__
#define __MN_TEXT_TABLE_PRIVATE_H__

#include "mn-text-table.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#line 29 "mn-text-table.gob"

typedef struct
{
  GQueue	*cells;
  int		height;
} Row;

#line 22 "mn-text-table-private.h"
struct _MNTextTablePrivate {
#line 78 "mn-text-table.gob"
	GQueue * rows;
#line 81 "mn-text-table.gob"
	GArray * column_sizes;
#line 84 "mn-text-table.gob"
	Row * row;
#line 86 "mn-text-table.gob"
	gboolean dirty;
#line 87 "mn-text-table.gob"
	int width;
#line 88 "mn-text-table.gob"
	int height;
#line 36 "mn-text-table-private.h"
};

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
