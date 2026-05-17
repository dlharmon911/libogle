#include "libogle/o_common.h"
#include "libogle/o_log.h"
#include "libogle/o_math.h"
#include "libogle/o_vector3.h"
#include "libogle/o_mesh.h"
#include "libogle/o_vertex.h"

static o_vector3_t _ogle_mesh_calculate_face_normal(o_vector3_t v1, o_vector3_t v2, o_vector3_t v3)
{
	o_vector3_t edge1 = ogle_vector3_sub(v2, v1);
	o_vector3_t edge2 = ogle_vector3_sub(v3, v1);
	o_vector3_t normal = ogle_vector3_cross(edge1, edge2);

	return ogle_vector3_normalize(normal);
}

int32_t ogle_mesh_calculate_vertex_normals(o_mesh_data_t* mesh_data)
{
	if (!mesh_data || !mesh_data->m_vertices || !mesh_data->m_indices)
	{
		return -1;
	}

	o_vector3_t normal = { 0 };
	int32_t count = 0;

	for (int32_t v = 0; v < mesh_data->m_vertex_count; ++v)
	{
		normal = (mesh_data->m_vertices + v)->m_normal;
		count = 0;

		for (int32_t i = 0; i < mesh_data->m_index_count; i += 3)
		{
			int32_t i1 = mesh_data->m_indices[i];
			int32_t i2 = mesh_data->m_indices[i + 1];
			int32_t i3 = mesh_data->m_indices[i + 2];

			if (i1 == v || i2 == v || i3 == v)
			{
				o_vector3_t v1 = (mesh_data->m_vertices + i1)->m_position;
				o_vector3_t v2 = (mesh_data->m_vertices + i2)->m_position;
				o_vector3_t v3 = (mesh_data->m_vertices + i3)->m_position;

				normal = ogle_vector3_add(normal, _ogle_mesh_calculate_face_normal(v1, v2, v3));
				count++;
			}
		}

		if (count > 0)
		{
			normal = ogle_vector3_div_ff(normal, (float)count);
			normal = ogle_vector3_normalize(normal);

			(mesh_data->m_vertices + v)->m_normal = normal;
		}
	}

	return 0;
}

static int32_t _ogle_mesh_initializer(o_mesh_t* mesh, void* data)
{
	if (!mesh || !data)
	{
		return -1;
	}

	o_mesh_decl_data_t* decl_mesh_data = data;
	const o_mesh_data_t* mesh_data = decl_mesh_data->m_mesh_data;
	ALLEGRO_VERTEX_DECL* vertex_decl = decl_mesh_data->m_vertex_declaration;

	mesh->vertex_buffer.m_buffer = al_create_vertex_buffer(vertex_decl, mesh_data->m_vertices, mesh_data->m_vertex_count, ALLEGRO_PRIM_BUFFER_STATIC);
	if (!mesh->vertex_buffer.m_buffer)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Failed to create vertex buffer for board tile mesh");
		return -1;
	}
	mesh->vertex_buffer.m_count = mesh_data->m_vertex_count;

	mesh->index_buffer.m_buffer = al_create_index_buffer(sizeof(int32_t), mesh_data->m_indices, mesh_data->m_index_count, ALLEGRO_PRIM_BUFFER_STATIC);
	if (!mesh->index_buffer.m_buffer)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Failed to create index buffer for board tile mesh");
		return -1;
	}
	mesh->index_buffer.m_count = mesh_data->m_index_count;

	return 0;
}

static void _ogle_mesh_zero(o_mesh_t* mesh)
{
	if (!mesh)
	{
		return;
	}
	mesh->vertex_buffer.m_buffer = NULL;
	mesh->vertex_buffer.m_count = 0;
	mesh->index_buffer.m_buffer = NULL;
	mesh->index_buffer.m_count = 0;
	mesh->m_texture = -1;
}

int32_t ogle_mesh_initializer(o_mesh_t* mesh, void* data)
{
	if (!mesh || !data)
	{
		return -1;
	}

	_ogle_mesh_zero(mesh);

	int32_t result = _ogle_mesh_initializer(mesh, data);

	if (result < 0)
	{
		ogle_mesh_uninitializer(mesh);
	}

	return result;
}

void ogle_mesh_uninitializer(o_mesh_t* mesh)
{
	if (!mesh)
	{
		return;
	}

	if (mesh->vertex_buffer.m_buffer)
	{
		al_destroy_vertex_buffer(mesh->vertex_buffer.m_buffer);
		mesh->vertex_buffer.m_buffer = NULL;
	}

	if (mesh->index_buffer.m_buffer)
	{
		al_destroy_index_buffer(mesh->index_buffer.m_buffer);
		mesh->index_buffer.m_buffer = NULL;
	}
}


void ogle_mesh_render(o_mesh_t* object, ALLEGRO_BITMAP* texture)
{
	if (!object)
	{
		return;
	}

	al_draw_indexed_buffer(
		object->vertex_buffer.m_buffer,
		texture,
		object->index_buffer.m_buffer,
		0, object->index_buffer.m_count,
		ALLEGRO_PRIM_TRIANGLE_LIST);
}

int32_t ogle_mesh_add_triangle(int32_t istart, int32_t* indices, int32_t i0, int32_t i1, int32_t i2)
{
	indices[istart] = i0;
	indices[istart + 1] = i1;
	indices[istart + 2] = i2;
	return istart + 3;
}

int32_t ogle_mesh_add_quad(int32_t istart, int32_t* indices, int32_t i0, int32_t i1, int32_t i2, int32_t i3)
{
	istart = ogle_mesh_add_triangle(istart, indices, i0, i1, i2);
	istart = ogle_mesh_add_triangle(istart, indices, i2, i1, i3);

	return istart;
}

void ogle_mesh_data_zero(o_mesh_data_t* mesh_data)
{
	if (!mesh_data)
	{
		return;
	}

	mesh_data->m_vertices = NULL;
	mesh_data->m_vertex_count = 0;
	mesh_data->m_indices = NULL;
	mesh_data->m_index_count = 0;
}


typedef int32_t (*_ogle_mesh_data_loader_func)(ALLEGRO_FILE* file, o_mesh_data_t* object);

int32_t _ogle_mesh_data_loader_obj(ALLEGRO_FILE* file, o_mesh_data_t* object);

static int32_t _ogle_mesh_data_loader(o_mesh_data_t* object, const o_mesh_data_loader_data_t* loader_data)
{
	const _ogle_mesh_data_loader_func loaders[OGLE_MESH_DATA_FILE_FORMAT_COUNT] =
	{
		_ogle_mesh_data_loader_obj
	};

	if (!object || !loader_data)
	{
		return -1;
	}

	if (loader_data->m_type < 0 || loader_data->m_type >= OGLE_MESH_DATA_FILE_FORMAT_COUNT)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Invalid mesh data file format type: %d", loader_data->m_type);
		return -1;
	}

	ALLEGRO_FILE* file = al_fopen(loader_data->m_filename, "rb");

	if (!file)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Failed to open mesh data file: %s", loader_data->m_filename);
		return -1;
	}

	int32_t result = loaders[loader_data->m_type](file, object);

	al_fclose(file);

	return result;
}

int32_t ogle_mesh_data_loader(o_mesh_data_t* object, void* data)
{
	const o_mesh_data_loader_data_t* loader_data = (o_mesh_data_loader_data_t*)data;

	ogle_mesh_data_zero(object);

	if (_ogle_mesh_data_loader(object, loader_data) < 0)
	{
		ogle_mesh_data_uninitializer(object);
		return -1;
	}

	return 0;
}

static int32_t _ogle_mesh_data_initializer(o_mesh_data_t* object, const o_mesh_data_init_data_t* init_data)
{
	if (!object || !init_data)
	{
		return -1;
	}

	int32_t vertex_count = init_data->m_vertex_count;
	int32_t index_count = init_data->m_index_count;

	object->m_vertices = (o_vertex_t*)al_malloc(sizeof(o_vertex_t) * vertex_count);
	if (!object->m_vertices)
	{
		return -1;
	}
	object->m_vertex_count = vertex_count;

	object->m_indices = (int32_t*)al_malloc(sizeof(int32_t) * index_count);
	if (!object->m_indices)
	{
		return -1;
	}
	object->m_index_count = index_count;

	for (int32_t i = 0; i < vertex_count; ++i)
	{
		ogle_vertex_zero(object->m_vertices + i);
	}

	for (int32_t i = 0; i < index_count; ++i)
	{
		object->m_indices[i] = 0;
	}

	return 0;
}

int32_t ogle_mesh_data_initializer(o_mesh_data_t* object, void* data)
{
	const o_mesh_data_init_data_t* init_data = (o_mesh_data_init_data_t*)data;

	ogle_mesh_data_zero(object);

	if (_ogle_mesh_data_initializer(object, init_data) < 0)
	{
		ogle_mesh_data_uninitializer(object);
		return -1;
	}

	return 0;
}

void ogle_mesh_data_uninitializer(o_mesh_data_t* object)
{
	if (!object)
	{
		return;
	}

	if (object->m_vertices)
	{
		al_free(object->m_vertices);
		object->m_vertices = NULL;
		object->m_vertex_count = 0;
	}

	if (object->m_indices)
	{
		al_free(object->m_indices);
		object->m_indices = NULL;
		object->m_index_count = 0;
	}
}