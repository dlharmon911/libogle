#include "libogle/o_common.h"
#include "libogle/o_log.h"
#include "libogle/o_object.h"

typedef struct o_object_allocation_data_tag_t
{
	size_t m_total_allocations;
	size_t m_allocated;
	size_t m_total_deallocations;
	size_t m_freed;
} o_object_allocation_data_t;

typedef struct o_object_metadata_tag_t
{
	size_t m_size;
} o_object_metadata_t;

static o_object_allocation_data_t g_object_allocation_data = { 0, 0, 0, 0 };

static void* ogle_alloc(size_t size)
{
	void* memory = NULL;
	o_object_metadata_t* metadata = NULL;
	if (0 == size)
	{
		return NULL;
	}
	memory = al_malloc(sizeof(o_object_metadata_t) + size);
	if (!memory)
	{
		return NULL;
	}
	metadata = (o_object_metadata_t*)memory;
	metadata->m_size = size;
	g_object_allocation_data.m_allocated += size;
	g_object_allocation_data.m_total_allocations += 1;
	OGLE_DO_LOG(OGLE_LOG_LEVEL_INFO, "Manually allocated %zu bytes for an object", size);
	return (void*)(metadata + 1);
}

static void ogle_free(void* object)
{
	o_object_metadata_t* metadata = NULL;
	if (!object)
	{
		return;
	}
	metadata = (o_object_metadata_t*)object - 1;
	g_object_allocation_data.m_freed += metadata->m_size;
	g_object_allocation_data.m_total_deallocations += 1;
	OGLE_DO_LOG(OGLE_LOG_LEVEL_INFO, "Manually freed %zu bytes from an object", metadata->m_size);
	al_free(metadata);
}

size_t ogle_object_memory_allocated()
{
	return g_object_allocation_data.m_allocated;
}

size_t ogle_object_memory_freed()
{
	return g_object_allocation_data.m_freed;
}

size_t ogle_object_total_allocations()
{
	return g_object_allocation_data.m_total_allocations;
}

size_t ogle_object_total_deallocations()
{
	return g_object_allocation_data.m_total_deallocations;
}

void* ogle_object_create(size_t size, o_object_initializer_func_t initializer, void* data)
{
	void* object = NULL;

	if (0 == size)
	{
		return NULL;
	}

	object = ogle_alloc(size);

	if (!object)
	{
		return NULL;
	}
	
	if (initializer && initializer(object, data) < 0)
	{
		ogle_free(object);
		object = NULL;
	}
	
	return object;
}

void ogle_object_destroy(void* object, o_object_cleanup_func_t cleanup)
{
	if (!object)
	{
		return;
	}
	
	if (cleanup)
	{
		cleanup(object);
	}
	
	ogle_free(object);
}
