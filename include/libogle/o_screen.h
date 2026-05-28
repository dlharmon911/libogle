#ifndef _HEADER_GUARD_OGLE_SCREEN_H_
#define _HEADER_GUARD_OGLE_SCREEN_H_

#include "libogle/o_common.h"
#include "libogle/o_input.h"

typedef int32_t(*o_screen_initialize_func)(void* screen_data, void* data);
typedef void(*o_screen_uninitialize_func)(void* screen_data);
typedef void(*o_screen_render_func)(void* screen_data, void* data);
typedef int32_t (*o_screen_update_func)(const o_input_t* input, void* screen_data, void* data);

typedef struct o_screen_tag_t
{
	o_screen_initialize_func m_initialize;
	o_screen_uninitialize_func m_uninitialize;
	o_screen_render_func m_render;
	o_screen_update_func m_update;
} o_screen_t;

#endif // _HEADER_GUARD_OGLE_SCREEN_H_
