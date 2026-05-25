#ifndef _HEADER_GUARD_OGLE_OBJECT_H_
#define _HEADER_GUARD_OGLE_OBJECT_H_

#include "libogle/o_common.h"

typedef int32_t (*o_object_initializer_func_t)(void* object, void* data);
typedef void (*o_object_cleanup_func_t)(void* object);

void* ogle_alloc(size_t size);
void ogle_free(void* object);
size_t ogle_object_memory_allocated();
size_t ogle_object_memory_freed();
size_t ogle_object_total_allocations();
size_t ogle_object_total_deallocations();
void* ogle_object_create(size_t object_size, o_object_initializer_func_t initializer, void* data);
void ogle_object_destroy(void* object, o_object_cleanup_func_t cleanup);

#endif // _HEADER_GUARD_OGLE_OBJECT_H_
