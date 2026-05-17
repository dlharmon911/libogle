#ifndef _HEADER_GUARD_OGLE_VERTEX_H_
#define _HEADER_GUARD_OGLE_VERTEX_H_

#include "libogle/o_common.h"
#include "libogle/o_vector3.h"

typedef struct o_vertex_tag_t
{
	o_vector3_t m_position;
	o_vector2_t m_uv;
	o_vector3_t m_normal;
	ALLEGRO_COLOR m_color;
} o_vertex_t;

typedef ALLEGRO_VERTEX_DECL o_vertex_decl_t;

o_vertex_decl_t* ogle_vertex_decl_create();
void ogle_vertex_decl_destroy(o_vertex_decl_t* decl);
void ogle_vertex_zero(o_vertex_t* vertex);

#endif // _HEADER_GUARD_OGLE_VERTEX_H_
