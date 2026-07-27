#ifndef _HEADER_GUARD_OGLE_MESH_H_
#define _HEADER_GUARD_OGLE_MESH_H_

#include "libogle/o_common.h"
#include "libogle/o_vector3.h"
#include "libogle/o_vertex.h"
#include "libogle/o_texture.h"

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

typedef struct o_mesh_tag_t
{
	o_vertex_buffer_t m_vertex_buffer;
	o_index_buffer_t m_index_buffer;
} o_mesh_t;

typedef struct o_mesh_data_tag_t
{
	const char* m_filename;
} o_mesh_data_t;

typedef void o_mesh_atlas_t;

int32_t ogle_mesh_create(o_mesh_t** mesh, const o_mesh_data_t* data);
void ogle_mesh_destroy(o_mesh_t* mesh);
void ogle_mesh_render(const o_mesh_t* mesh, const o_texture_t* texture);

#endif // _HEADER_GUARD_OGLE_MESH_H_
