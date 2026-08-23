#include "libogle/o_common.h"
#include "libogle/o_darray.h"

#define OGLE_DARRAY_INITIAL_CAPACITY 4
#define OGLE_DARRAY_GROWTH_FACTOR 2

typedef struct ogle_darray_header_t
{
	size_t m_size;
	size_t m_capacity;
	size_t m_object_size;
} ogle_darray_header_t;

static ogle_darray_header_t* _ogle_darray_create_header(size_t object_size)
{
	if (object_size == 0)
	{
		return NULL;
	}

	ogle_darray_header_t* header = (ogle_darray_header_t*)al_malloc(sizeof(ogle_darray_header_t) + object_size * OGLE_DARRAY_INITIAL_CAPACITY);
	
	if (!header)
	{
		return NULL;
	}
	
	header->m_size = 0;
	header->m_capacity = OGLE_DARRAY_INITIAL_CAPACITY;
	header->m_object_size = object_size;
	
	return header;
}

static const ogle_darray_header_t* _ogle_darray_get_header_const(const void* array)
{
	return (const ogle_darray_header_t*)((const uint8_t*)array - sizeof(ogle_darray_header_t));
}

static ogle_darray_header_t* _ogle_darray_get_header(void* array)
{
	return (ogle_darray_header_t*)((uint8_t*)array - sizeof(ogle_darray_header_t));
}

static const void* _ogle_darray_get_array_const(const ogle_darray_header_t* header)
{
	return (const void*)((const uint8_t*)header + sizeof(ogle_darray_header_t));
}

static void* _ogle_darray_get_array(ogle_darray_header_t* header)
{
	return (void*)((uint8_t*)header + sizeof(ogle_darray_header_t));
}

static void _ogle_darray_destroy_header(ogle_darray_header_t* header)
{
	if (header)
	{
		al_free(header);
	}
}

static ogle_darray_header_t* _ogle_darray_push_back(ogle_darray_header_t* header, const void* data)
{
	if (!header || !data)
	{
		return NULL;
	}

	if (header->m_size >= header->m_capacity)
	{
		size_t new_capacity = header->m_capacity * OGLE_DARRAY_GROWTH_FACTOR;
		size_t new_size = sizeof(ogle_darray_header_t) + header->m_object_size * new_capacity;
		
		ogle_darray_header_t* new_header = (ogle_darray_header_t*)al_realloc(header, new_size);
		
		if (!new_header)
		{
			return NULL;
		}
		
		new_header->m_capacity = new_capacity;
		header = new_header;
	}

	memcpy((uint8_t*)_ogle_darray_get_array(header) + header->m_size * header->m_object_size, data, header->m_object_size);
	++header->m_size;

	return header;
}

static ogle_darray_header_t* _ogle_darray_pop_back(ogle_darray_header_t* header)
{
	if (!header || header->m_size == 0)
	{
		return NULL;
	}
	--header->m_size;
	return header;
}

void* ogle_darray_create(size_t object_size)
{
	ogle_darray_header_t* header = _ogle_darray_create_header(object_size);

	if (!header)
	{
		return NULL;
	}

	return _ogle_darray_get_array(header);
}

void ogle_darray_destroy(void** array)
{
	if (!array || !*array)
	{
		return;
	}
	ogle_darray_header_t* header = _ogle_darray_get_header(*array);
	_ogle_darray_destroy_header(header);
	*array = NULL;
}

void ogle_darray_clear(void* array)
{
	if (!array)
	{
		return;
	}
	ogle_darray_header_t* header = _ogle_darray_get_header(array);
	header->m_size = 0;
}

size_t ogle_darray_capacity(const void* array)
{
	if (!array)
	{
		return 0;
	}
	
	const ogle_darray_header_t* header = _ogle_darray_get_header_const(array);
	
	if (!header)
	{
		return 0;
	}

	return header->m_capacity;
}

size_t ogle_darray_size(const void* array)
{
	if (!array)
	{
		return 0;
	}

	const ogle_darray_header_t* header = _ogle_darray_get_header_const(array);

	if (!header)
	{
		return 0;
	}

	return header->m_size;
}

bool ogle_darray_push_back(void** array, const void* data)
{
	if (!array || !*array || !data)
	{
		return false;
	}

	ogle_darray_header_t* header = _ogle_darray_get_header(*array);
	
	header = _ogle_darray_push_back(header, data);
	
	if (!header)
	{
		return false;
	}
	
	*array = _ogle_darray_get_array(header);
	return true;
}

bool ogle_darray_pop_back(void** array)
{
	if (!array || !*array)
	{
		return false;
	}

	ogle_darray_header_t* header = _ogle_darray_get_header(*array);
	
	header = _ogle_darray_pop_back(header);
	
	if (!header)
	{
		return false;
	}
	
	*array = _ogle_darray_get_array(header);
	return true;
}

bool ogle_darray_insert(void** array, size_t index, const void* data)
{
	if (!array || !*array || !data)
	{
		return false;
	}
	ogle_darray_header_t* header = _ogle_darray_get_header(*array);
	if (index > header->m_size)
	{
		return false;
	}
	header = _ogle_darray_push_back(header, data);

	if (!header)
	{
		return false;
	}
	void* array_data = _ogle_darray_get_array(header);
	size_t object_size = header->m_object_size;
	memmove((uint8_t*)array_data + (index + 1) * object_size, (uint8_t*)array_data + index * object_size, (header->m_size - index - 1) * object_size);
	memcpy((uint8_t*)array_data + index * object_size, data, object_size);
	*array = array_data;
	return true;
}

bool ogle_darray_remove(void** array, size_t index)
{
	if (!array || !*array)
	{
		return false;
	}
	ogle_darray_header_t* header = _ogle_darray_get_header(*array);
	if (index >= header->m_size)
	{
		return false;
	}
	void* array_data = _ogle_darray_get_array(header);
	size_t object_size = header->m_object_size;
	memmove((uint8_t*)array_data + index * object_size, (uint8_t*)array_data + (index + 1) * object_size, (header->m_size - index - 1) * object_size);
	header = _ogle_darray_pop_back(header);
	if (!header)
	{
		return false;
	}
	*array = _ogle_darray_get_array(header);
	return true;
}

void* ogle_darray_get(void* array, size_t index)
{
	if (!array)
	{
		return NULL;
	}

	ogle_darray_header_t* header = _ogle_darray_get_header(array);

	if (index >= header->m_size)
	{
		return NULL;
	}

	return (uint8_t*)_ogle_darray_get_array(header) + index * header->m_object_size;
}

const void* ogle_darray_get_const(const void* array, size_t index)
{
	if (!array)
	{
		return NULL;
	}

	const ogle_darray_header_t* header = _ogle_darray_get_header_const(array);

	if (index >= header->m_size)
	{
		return NULL;
	}

	return (const uint8_t*)_ogle_darray_get_array_const(header) + index * header->m_object_size;
}
