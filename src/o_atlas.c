#include "libogle/o_common.h"
#include "libogle/o_object.h"

typedef struct o_atlas_header_tag_t
{
	size_t object_size;
	size_t count;
} o_atlas_header_t;

void* ogle_atlas_create(size_t object_size, size_t count, o_object_initializer_func_t initializer, void* data)
{
	o_atlas_header_t* header = NULL;

	if (0 == object_size || 0 == count)
	{
		return NULL;
	}

	header = al_malloc(sizeof(o_atlas_header_t) + object_size * count);

	if (!header)
	{
		return NULL;
	}

	void* atlas = (void*)(header + 1);
	
	if (initializer && initializer(atlas, data) < 0)
	{
		al_free(header);
		atlas = NULL;
	}
	
	return atlas;
}

void ogle_atlas_destroy(void* atlas, o_object_cleanup_func_t cleanup)
{
	if (!atlas)
	{
		return;
	}

	if (cleanup)
	{
		cleanup(atlas);
	}

	o_atlas_header_t* header = ((o_atlas_header_t*)atlas) - 1;
	
	al_free(header);
}

size_t ogle_atlas_get_object_size(const void* atlas)
{
	if (!atlas)
	{
		return 0;
	}

	o_atlas_header_t* header = ((o_atlas_header_t*)atlas) - 1;

	return header->object_size;
}

size_t ogle_atlas_get_count(const void* atlas)
{
	if (!atlas)
	{
		return 0;
	}

	o_atlas_header_t* header = ((o_atlas_header_t*)atlas) - 1;

	return header->count;
}

void* ogle_atlas_get_object(void* atlas, size_t index)
{
	if (!atlas)
	{
		return NULL;
	}
	
	o_atlas_header_t* header = ((o_atlas_header_t*)atlas) - 1;
	
	if (index >= header->count)
	{
		return NULL;
	}

	return (void*)((char*)atlas + header->object_size * index);
}

const void* ogle_atlas_get_const_object(const void* atlas, size_t index)
{
	if (!atlas)
	{
		return NULL;
	}

	o_atlas_header_t* header = ((o_atlas_header_t*)atlas) - 1;

	if (index >= header->count)
	{
		return NULL;
	}

	return (const void*)((const char*)atlas + header->object_size * index);
}
