#ifndef _HEADER_GUARD_OGLE_DARRAY_H_
#define _HEADER_GUARD_OGLE_DARRAY_H_

#include "libogle/o_common.h"

void* ogle_darray_create(size_t object_size);
void ogle_darray_destroy(void** array);
void ogle_darray_clear(void* array);
size_t ogle_darray_capacity(const void* array);
size_t ogle_darray_size(const void* array);
bool ogle_darray_push_back(void** array, const void* data);
bool ogle_darray_pop_back(void** array);
bool ogle_darray_insert(void** array, size_t index, const void* data);
bool ogle_darray_remove(void** array, size_t index);
void* ogle_darray_get(void* array, size_t index);
const void* ogle_darray_get_const(const void* array, size_t index);

#endif // _HEADER_GUARD_OGLE_DARRAY_H_
