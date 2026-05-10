#ifndef _HEADER_GUARD_OGLE_MESH_H_
#define _HEADER_GUARD_OGLE_MESH_H_

#include "libogle/o_common.h"
#include "libogle/o_vector3.h"

typedef struct o_vertex_buffer_tag_t
{
	ALLEGRO_VERTEX_BUFFER* m_buffer;
	int32_t m_count;
} o_vertex_buffer_t;

typedef struct o_index_buffer_tag_t
{
	ALLEGRO_INDEX_BUFFER* m_buffer;
	int32_t m_count;
} o_index_buffer_t;

typedef struct o_vertex_tag_t
{
	o_vector3_t m_position;
	o_vector2_t m_uv;
	o_vector3_t m_normal;
	ALLEGRO_COLOR m_color;
} o_vertex_t;

typedef struct o_mesh_t
{
	o_vertex_buffer_t vertex_buffer;
	o_index_buffer_t index_buffer;
	int32_t m_texture;
} o_mesh_t;

typedef struct o_mesh_data_tag_t
{
	o_vertex_t* m_vertices;
	int32_t m_vertex_count;
	int32_t* m_indices;
	int32_t m_index_count;
} o_mesh_data_t;

typedef struct o_mesh_decl_data_tag_t
{
	ALLEGRO_VERTEX_DECL* m_vertex_declaration;
	o_mesh_data_t* m_mesh_data;
} o_mesh_decl_data_t;

ALLEGRO_VERTEX_DECL* ogle_mesh_generate_decl();
int32_t ogle_mesh_calculate_vertex_normals(o_mesh_data_t* mesh_data);
int32_t ogle_mesh_initializer(o_mesh_t* object, void* data);
void ogle_mesh_uninitializer(o_mesh_t* object);
void ogle_mesh_render(o_mesh_t* object, ALLEGRO_BITMAP* texture);
int32_t ogle_mesh_add_triangle(int32_t istart, int32_t* indices, int32_t i0, int32_t i1, int32_t i2);
int32_t ogle_mesh_add_quad(int32_t istart, int32_t* indices, int32_t i0, int32_t i1, int32_t i2, int32_t i3);

#endif // _HEADER_GUARD_OGLE_MESH_H_
