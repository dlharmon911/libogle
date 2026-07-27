#ifndef _HEADER_GUARD_OGLE_SHADER_H_
#define _HEADER_GUARD_OGLE_SHADER_H_

#include "libogle/o_common.h"

typedef ALLEGRO_SHADER o_shader_t;

typedef struct o_shader_data_t
{
	const char* m_pixel_path;
	const char* m_vertex_path;
} o_shader_data_t;

typedef void o_shader_atlas_t;

int32_t ogle_shader_create(o_shader_t** shader, const o_shader_data_t* data);
void ogle_shader_destroy(o_shader_t* shader);

#endif // _HEADER_GUARD_OGLE_SHADER_H_
