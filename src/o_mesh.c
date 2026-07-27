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