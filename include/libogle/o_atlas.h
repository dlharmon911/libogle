#ifndef _HEADER_GUARD_OGLE_ATLAS_H_
#define _HEADER_GUARD_OGLE_ATLAS_H_

#include "libogle/o_common.h"
#include "libogle/o_object.h"
#include "libogle/o_shader.h"
#include "libogle/o_mesh.h"

typedef int32_t (*ogle_atlas_object_creator_t)(void** object, void* data);

void* ogle_atlas_create(size_t object_size, const void* data, size_t data_size, size_t count, ogle_atlas_object_creator_t creator, o_object_cleanup_func_t cleanup);
void ogle_atlas_destroy(void* atlas);
size_t ogle_atlas_get_count(const void* atlas);
void* ogle_atlas_get_object(void* atlas, size_t index);
const void* ogle_atlas_get_const_object(const void* atlas, size_t index);

#endif // _HEADER_GUARD_OGLE_ATLAS_H_
