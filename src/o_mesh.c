#include "libogle/o_common.h"
#include "libogle/o_log.h"
#include "libogle/o_math.h"
#include "libogle/o_vector3.h"
#include "libogle/o_vertex.h"
#include "libogle/o_object.h"
#include "libogle/o_index_buffer.h"
#include "libogle/o_vertex_buffer.h"
#include "libogle/o_mesh.h"

int32_t ogle_mesh_create(o_mesh_t** mesh, const o_mesh_data_t* data)
{
	(void)mesh;
	(void)data;

	return 0;
}

void ogle_mesh_destroy(o_mesh_t* mesh)
{
	if (NULL == mesh)
	{
		return;
	}

	if (NULL != mesh->m_vertex_buffer.m_buffer)
	{
		al_destroy_vertex_buffer(mesh->m_vertex_buffer.m_buffer);
		mesh->m_vertex_buffer.m_buffer = NULL;
	}

	if (NULL != mesh->m_index_buffer.m_buffer)
	{
		al_destroy_index_buffer(mesh->m_index_buffer.m_buffer);
		mesh->m_index_buffer.m_buffer = NULL;
	}
}

void ogle_mesh_render(const o_mesh_t* mesh, const o_texture_t* texture)
{
	if (!mesh)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Mesh pointer is NULL");
		return;
	}

	al_draw_indexed_buffer(
		mesh->m_vertex_buffer.m_buffer,
		(ALLEGRO_BITMAP*)texture,
		mesh->m_index_buffer.m_buffer,
		0, mesh->m_index_buffer.m_count,
		ALLEGRO_PRIM_TRIANGLE_LIST);
}

/*******************************************/

static o_vector3_t _ogle_mesh_calculate_face_normal(o_vector3_t v1, o_vector3_t v2, o_vector3_t v3)
{
	o_vector3_t edge1 = ogle_vector3_sub(v2, v1);
	o_vector3_t edge2 = ogle_vector3_sub(v3, v1);
	o_vector3_t normal = ogle_vector3_cross(edge1, edge2);

	return ogle_vector3_normalize(normal);
}

int32_t ogle_mesh_calculate_vertex_normals(o_mesh_vertex_info_t* mesh_data)
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
	if (!mesh)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Mesh pointer is NULL");
		return -1;
	}

	if (!data)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Mesh data pointer is NULL");
		return -1;
	}

	ogle_do_log(OGLE_LOG_LEVEL_INFO, "Initializing mesh");

	o_mesh_decl_data_t* decl_mesh_data = data;
	const o_mesh_vertex_info_t* mesh_data = decl_mesh_data->m_mesh_data;
	ALLEGRO_VERTEX_DECL* vertex_decl = decl_mesh_data->m_vertex_declaration;

	mesh->m_vertex_buffer.m_buffer = al_create_vertex_buffer(vertex_decl, mesh_data->m_vertices, mesh_data->m_vertex_count, ALLEGRO_PRIM_BUFFER_STATIC);
	if (!mesh->m_vertex_buffer.m_buffer)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Failed to create vertex buffer for mesh");
		return -1;
	}
	mesh->m_vertex_buffer.m_count = mesh_data->m_vertex_count;

	mesh->m_index_buffer.m_buffer = al_create_index_buffer(sizeof(int32_t), mesh_data->m_indices, mesh_data->m_index_count, ALLEGRO_PRIM_BUFFER_STATIC);
	if (!mesh->m_index_buffer.m_buffer)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Failed to create index buffer for mesh");
		return -1;
	}
	mesh->m_index_buffer.m_count = mesh_data->m_index_count;

	return 0;
}

static void _ogle_mesh_zero(o_mesh_t* mesh)
{
	if (!mesh)
	{
		return;
	}
	mesh->m_vertex_buffer.m_buffer = NULL;
	mesh->m_vertex_buffer.m_count = 0;
	mesh->m_index_buffer.m_buffer = NULL;
	mesh->m_index_buffer.m_count = 0;
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
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Mesh pointer is NULL");
		return;
	}

	ogle_do_log(OGLE_LOG_LEVEL_INFO, "Uninitializing mesh");

	if (mesh->m_vertex_buffer.m_buffer)
	{
		al_destroy_vertex_buffer(mesh->m_vertex_buffer.m_buffer);
		mesh->m_vertex_buffer.m_buffer = NULL;
	}

	if (mesh->m_index_buffer.m_buffer)
	{
		al_destroy_index_buffer(mesh->m_index_buffer.m_buffer);
		mesh->m_index_buffer.m_buffer = NULL;
	}
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

void ogle_mesh_data_zero(o_mesh_vertex_info_t* mesh_data)
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

static int32_t _ogle_mesh_data_initializer(o_mesh_vertex_info_t* object, const o_mesh_data_init_data_t* init_data)
{
	if (!object || !init_data)
	{
		return -1;
	}

	object->m_vertex_count = init_data->m_vertex_count;

	object->m_vertices = ogle_object_create(sizeof(o_vertex_t) * object->m_vertex_count, ogle_vertex_buffer_initializer, &object->m_vertex_count);
	if (!object->m_vertices)
	{
		object->m_vertex_count = 0;
		return -1;
	}

	object->m_index_count = init_data->m_index_count;
	object->m_indices = ogle_object_create(sizeof(int32_t) * object->m_index_count, ogle_index_buffer_initializer, &object->m_index_count);
	if (!object->m_indices)
	{
		object->m_index_count = 0;
		return -1;
	}

	return 0;
}

int32_t ogle_mesh_data_initializer(o_mesh_vertex_info_t* object, void* data)
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

void ogle_mesh_data_uninitializer(o_mesh_vertex_info_t* object)
{
	if (!object)
	{
		return;
	}

	if (object->m_vertices)
	{
		ogle_object_destroy(object->m_vertices, ogle_vertex_buffer_uninitializer);
		object->m_vertices = NULL;
		object->m_vertex_count = 0;
	}

	if (object->m_indices)
	{
		ogle_object_destroy(object->m_indices, ogle_index_buffer_uninitializer);
		object->m_indices = NULL;
		object->m_index_count = 0;
	}
}

