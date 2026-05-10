#ifndef _HEADER_GUARD_OGLE_OBJECT_H_
#define _HEADER_GUARD_OGLE_OBJECT_H_

#include "libogle/o_common.h"

typedef int32_t (*o_object_initializer_func_t)(void* object, void* data);
typedef void (*o_object_cleanup_func_t)(void* object);

void* ogle_object_create(size_t object_size, o_object_initializer_func_t initializer, void* data);
void ogle_object_destroy(void* object, o_object_cleanup_func_t cleanup);

#endif // _HEADER_GUARD_OGLE_OBJECT_H_
