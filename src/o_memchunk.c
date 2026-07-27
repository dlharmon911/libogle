#include "libogle/o_common.h"
#include "libogle/o_log.h"
#include "libogle/o_file.h"
#include "libogle/o_object.h"
#include "libogle/o_memchunk.h"

int32_t ogle_memchunk_create(size_t size, o_memchunk_t* memchunk)
{
	if (!memchunk)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "ogle_memchunk_create: memchunk is NULL");
		return -1;
	}
	memchunk->m_data = (const char*)ogle_malloc(size);
	if (!memchunk->m_data)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "ogle_memchunk_create: failed to allocate memory for memchunk");
		return -1;
	}
	memchunk->m_length = size;
	return 0;
}

int32_t ogle_memchunk_load(ALLEGRO_FILE* file, o_memchunk_t* memchunk)
{
	if (!file)
	{
		return -1;
	}

	if (!memchunk)
	{
		return -1;
	}

	size_t size = ogle_file_size(file);

	if (size == 0)
	{
		return -1;
	}

	char* buffer = (char*)ogle_malloc(size);

	if (!buffer)
	{
		return -1;
	}

	size_t read_size = al_fread(file, buffer, size);

	if (read_size != size)
	{
		ogle_free(buffer);
		return -1;
	}

	memchunk->m_data = buffer;
	memchunk->m_length = size;

	return 0;
}

void ogle_memchunk_clean(o_memchunk_t* memchunk)
{
	if (!memchunk)
	{
		return;
	}

	if (memchunk->m_data)
	{
		ogle_free((void*)memchunk->m_data);
		memchunk->m_data = NULL;
	}

	memchunk->m_length = 0;
}
