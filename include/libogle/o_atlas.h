#ifndef _HEADER_GUARD_OGLE_ATLAS_H_
#define _HEADER_GUARD_OGLE_ATLAS_H_

#include "libogle/o_common.h"
#include "libogle/o_object.h"

void* ogle_atlas_create(size_t object_size, size_t count, o_object_initializer_func_t initializer, void* data);
void ogle_atlas_destroy(void* atlas, o_object_cleanup_func_t cleanup);
size_t ogle_atlas_get_object_size(const void* atlas);
size_t ogle_atlas_get_count(const void* atlas);
void* ogle_atlas_get_object(void* atlas, size_t index);
const void* ogle_atlas_get_const_object(const void* atlas, size_t index);

#endif // _HEADER_GUARD_OGLE_ATLAS_H_
