#include "libogle/o_common.h"
#include "libogle/o_log.h"
#include "libogle/o_atlas.h"
#include "libogle/o_object.h"

typedef struct o_atlas_header_tag_t
{
	size_t m_object_size;
	size_t m_count;
	o_object_cleanup_func_t m_cleanup;
} o_atlas_header_t;

void* ogle_atlas_create(size_t object_size, const void* data, size_t data_size, size_t count, ogle_atlas_object_creator_t creator, o_object_cleanup_func_t cleanup)
{
	o_atlas_header_t* header = NULL;

	if (0 == object_size)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Object size cannot be zero.");
		return NULL;
	}

	if (NULL == data)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Data pointer is null.");
		return NULL;
	}

	if (0 == count)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Count is zero.");
		return NULL;
	}

	if (NULL == creator)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Creator function pointer is null.");
		return NULL;
	}

	if (NULL == cleanup)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Cleanup function pointer is null.");
		return NULL;
	}

	size_t total_size = sizeof(o_atlas_header_t) + (count * object_size);

	header = al_malloc(total_size);

	if (!header)
	{
		return NULL;
	}

	memset(header, 0, total_size);

	void* atlas = (void*)(header + 1);

	header->m_count = count;
	header->m_object_size = object_size;
	header->m_cleanup = cleanup;

	memset(atlas, 0, count * object_size);
	
	for (size_t i = 0; i < header->m_count; ++i)
	{
		void* object = ((char*)atlas + (i * object_size));
		void* object_data = ((char*)data + (i * data_size));

		if (creator(&object, object_data) != 0)
		{
			ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Failed to initialize object at index %zu.", i);
			ogle_atlas_destroy(atlas);
			atlas = NULL;
			break;
		}
	}

	
	return atlas;
}

void ogle_atlas_destroy(void* atlas)
{
	if (NULL == atlas)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Atlas pointer is null.");
		return;
	}

	o_atlas_header_t* header = ((o_atlas_header_t*)atlas) - 1;

	for (size_t i = 0; i < header->m_count; ++i)
	{
		void* object = ogle_atlas_get_object(atlas, i);
		header->m_cleanup(object);
	}
	
	al_free(header);
}

size_t ogle_atlas_get_count(const void* atlas)
{
	if (!atlas)
	{
		return 0;
	}

	o_atlas_header_t* header = ((o_atlas_header_t*)atlas) - 1;

	return header->m_count;
}

void* ogle_atlas_get_object(void* atlas, size_t index)
{
	if (!atlas)
	{
		return NULL;
	}
	
	o_atlas_header_t* header = ((o_atlas_header_t*)atlas) - 1;
	
	if (index >= header->m_count)
	{
		return NULL;
	}

	return (void*)((char*)atlas + sizeof(void*) * index);
}

const void* ogle_atlas_get_const_object(const void* atlas, size_t index)
{
	if (!atlas)
	{
		return NULL;
	}

	o_atlas_header_t* header = ((o_atlas_header_t*)atlas) - 1;

	if (index >= header->m_count)
	{
		return NULL;
	}

	return (const void*)((const char*)atlas + sizeof(void*) * index);
}

