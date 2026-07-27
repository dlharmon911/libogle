#include "libogle/o_common.h"
#include "libogle/o_log.h"
#include "libogle/o_index_buffer.h"

static int32_t ogle_index_buffer_initializer_zero(int32_t* indices, int32_t count)
{
	if (!indices)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Index buffer pointer is NULL");
		return -1;
	}

	for (int32_t i = 0; i < count; ++i)
	{
		*(indices + i) = 0;
	}

	return 0;
}

static int32_t ogle_index_buffer_initializer_copy(int32_t* indices, int32_t count, const int32_t* data)
{
	if (!indices)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Index buffer pointer is NULL");
		return -1;
	}

	if (!data)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Index buffer initializer data pointer is NULL");
		return -1;
	}

	for (int32_t i = 0; i < count; ++i)
	{
		indices[i] = data[i];
	}

	return 0;
}

int32_t ogle_index_buffer_initializer(int32_t* indices, void* data)
{
	if (!indices)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Index buffer pointer is NULL");
		return -1;
	}

	if (!data)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Index buffer initializer data pointer is NULL");
		return -1;
	}

	int32_t result = 0;
	int32_t count = *(int32_t*)data;

	if (count <= 0)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Index count must be greater than zero");
		return -1;
	}

	result = ogle_index_buffer_initializer_zero(indices, count);

	return result;
}

void ogle_index_buffer_uninitializer(int32_t* indices)
{
	// No dynamic memory to free for index buffer, but this function is defined for consistency and future use
}