#include "libogle/o_common.h"
#include "libogle/o_log.h"
#include "libogle/o_math.h"
#include "libogle/o_vector3.h"
#include "libogle/o_mesh.h"

ALLEGRO_VERTEX_DECL* ogle_mesh_generate_decl()
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