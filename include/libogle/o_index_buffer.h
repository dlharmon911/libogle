#ifndef _HEADER_GUARD_OGLE_INDEX_BUFFER_H_
#define _HEADER_GUARD_OGLE_INDEX_BUFFER_H_

#include "libogle/o_common.h"

int32_t ogle_index_buffer_initializer(int32_t* indices, void* data);
void ogle_index_buffer_uninitializer(int32_t* indices);

#endif // _HEADER_GUARD_OGLE_INDEX_BUFFER_H_
