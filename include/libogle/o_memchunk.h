#ifndef _HEADER_GUARD_OGLE_MEMCHUNK_H_
#define _HEADER_GUARD_OGLE_MEMCHUNK_H_

#include "libogle/o_common.h"

typedef struct o_memchunk_tag_t o_memchunk_t;

struct o_memchunk_tag_t
{
	const char* m_data;
	size_t m_length;
};

int32_t ogle_memchunk_create(size_t size, o_memchunk_t* memchunk);
int32_t ogle_memchunk_load(ALLEGRO_FILE* file, o_memchunk_t* memchunk);
void ogle_memchunk_clean(o_memchunk_t* memchunk);

#endif // _HEADER_GUARD_OGLE_MEMCHUNK_H_
