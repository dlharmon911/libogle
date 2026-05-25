#include "libogle/o_common.h"
#include "libogle/o_log.h"
#include "libogle/o_color.h"
#include "libogle/o_vector3.h"
#include "libogle/o_vertex.h"
#include "libogle/o_vertex_buffer.h"

static int32_t ogle_vertex_buffer_initializer_zero(o_vertex_t* vertices, int32_t count)
{
	if (!vertices)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Vertex buffer pointer is NULL");
		return -1;
	}

	for (int32_t i = 0; i < count; ++i)
	{
		ogle_vertex_zero(vertices + i);
	}

	return 0;
}

static int32_t ogle_vertex_buffer_initializer_copy(o_vertex_t* vertices, int32_t count, const o_vertex_t* data)
{
	if (!vertices)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Vertex buffer pointer is NULL");
		return -1;
	}

	if (!data)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Vertex buffer initializer data pointer is NULL");
		return -1;
	}

	for (int32_t i = 0; i < count; ++i)
	{
		vertices[i] = data[i];
	}

	return 0;
}

int32_t ogle_vertex_buffer_initializer(o_vertex_t* vertices, void* data)
{
	if (!vertices)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Vertex buffer pointer is NULL");
		return -1;
	}

	if (!data)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Vertex buffer initializer data pointer is NULL");
		return -1;
	}

	int32_t result = 0;
	int32_t count = *(int32_t*)data;

	if (count <= 0)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Vertex count must be greater than zero");
		return -1;
	}

	result = ogle_vertex_buffer_initializer_zero(vertices, count);

	return result;
}

void ogle_vertex_buffer_uninitializer(o_vertex_t* vertices)
{
	// No dynamic memory to free for vertex buffer, but this function is defined for consistency and future use
}
