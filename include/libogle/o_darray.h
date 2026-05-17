#ifndef _HEADER_GUARD_OGLE_DARRAY_H_
#define _HEADER_GUARD_OGLE_DARRAY_H_

#include "libogle/o_common.h"

void* ogle_darray_create(size_t object_size);
void ogle_darray_destroy(void** array);
size_t ogle_darray_size(const void* array);
void ogle_darray_push_back(void** array, void* data);
void ogle_darray_pop_back(void** array);

#endif // _HEADER_GUARD_OGLE_DARRAY_H_
