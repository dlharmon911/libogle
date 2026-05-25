#ifndef _HEADER_GUARD_OGLE_VERTEX_BUFFER_H_
#define _HEADER_GUARD_OGLE_VERTEX_BUFFER_H_

#include "libogle/o_common.h"
#include "libogle/o_vertex.h"

int32_t ogle_vertex_buffer_initializer(o_vertex_t* vertices, void* data);
void ogle_vertex_buffer_uninitializer(o_vertex_t* vertices);

#endif // _HEADER_GUARD_OGLE_VERTEX_BUFFER_H_
