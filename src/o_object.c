#include "libogle/o_common.h"
#include "libogle/o_object.h"


void* ogle_object_create(size_t size, o_object_initializer_func_t initializer, void* data)
{
	void* object = NULL;

	if (0 == size)
	{
		return NULL;
	}

	object = al_malloc(size);

	if (!object)
	{
		return NULL;
	}
	
	if (initializer && initializer(object, data) < 0)
	{
		al_free(object);
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
	
	al_free(object);
}
