#include "libogle/o_common.h"
#include "libogle/o_color.h"
#include "libogle/o_vector3.h"
#include "libogle/o_vertex.h"

o_vertex_decl_t* ogle_vertex_decl_create()
{
	ALLEGRO_VERTEX_ELEMENT elems[] =
	{
		{ALLEGRO_PRIM_POSITION, ALLEGRO_PRIM_FLOAT_3, offsetof(o_vertex_t, m_position)},
		{ALLEGRO_PRIM_TEX_COORD_PIXEL, ALLEGRO_PRIM_FLOAT_2, offsetof(o_vertex_t, m_uv)},
		{ALLEGRO_PRIM_USER_ATTR, ALLEGRO_PRIM_FLOAT_3, offsetof(o_vertex_t, m_normal)},
		{ALLEGRO_PRIM_COLOR_ATTR, 0, offsetof(o_vertex_t, m_color)},
		{0, 0, 0}
	};

	return al_create_vertex_decl(elems, sizeof(o_vertex_t));
}

void ogle_vertex_decl_destroy(o_vertex_decl_t* decl)
{
	if (decl)
	{
		al_destroy_vertex_decl(decl);
	}
}

void ogle_vertex_zero(o_vertex_t* vertex)
{
	if (!vertex)
	{
		return;
	}

	vertex->m_position = (o_vector3_t){ 0.0f, 0.0f, 0.0f };
	vertex->m_uv = (o_vector2_t){ 0.0f, 0.0f };
	vertex->m_normal = (o_vector3_t){ 0.0f, 0.0f, 0.0f };
	vertex->m_color = (o_color_t){ 1.0f, 1.0f, 1.0f, 1.0f };
}
