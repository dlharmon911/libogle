#ifndef _HEADER_GUARD_OGLE_MESH_H_
#define _HEADER_GUARD_OGLE_MESH_H_

#include "libogle/o_common.h"
#include "libogle/o_vector3.h"
#include "libogle/o_vertex.h"

enum OGLE_MESH_DATA_FILE_FORMATS
{
	OGLE_MESH_DATA_FILE_FORMAT_OBJ,
	OGLE_MESH_DATA_FILE_FORMAT_COUNT
};

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

typedef struct o_mesh_data_init_data_tag_t
{
	int32_t m_vertex_count;
	int32_t m_index_count;
} o_mesh_data_init_data_t;

typedef struct o_mesh_data_loader_data_tag_t
{
	const char* m_filename;
	int32_t m_type;
} o_mesh_data_loader_data_t;

int32_t ogle_mesh_calculate_vertex_normals(o_mesh_data_t* mesh_data);
int32_t ogle_mesh_initializer(o_mesh_t* object, void* data);
void ogle_mesh_uninitializer(o_mesh_t* object);
void ogle_mesh_render(o_mesh_t* object, ALLEGRO_BITMAP* texture);
int32_t ogle_mesh_add_triangle(int32_t istart, int32_t* indices, int32_t i0, int32_t i1, int32_t i2);
int32_t ogle_mesh_add_quad(int32_t istart, int32_t* indices, int32_t i0, int32_t i1, int32_t i2, int32_t i3);
int32_t ogle_mesh_data_save_h(const char* filename, const char* name, const o_mesh_data_t* mesh_data);
int32_t ogle_mesh_data_save_obj(const char* filename, const char* name, const o_mesh_data_t* mesh_data);
void ogle_mesh_data_zero(o_mesh_data_t* mesh_data);
int32_t ogle_mesh_data_loader(o_mesh_data_t* object, void* data);
int32_t ogle_mesh_data_initializer(o_mesh_data_t* object, void* data);
void ogle_mesh_data_uninitializer(o_mesh_data_t* object);


#endif // _HEADER_GUARD_OGLE_MESH_H_
