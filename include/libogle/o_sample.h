#ifndef _HEADER_GUARD_OGLE_SAMPLE_H_
#define _HEADER_GUARD_OGLE_SAMPLE_H_

#include "libogle/o_common.h"

typedef ALLEGRO_SAMPLE o_sample_t;

typedef struct o_sample_data_tag_t
{
	const char* m_filename;
} o_sample_data_t;

typedef void o_sample_atlas_t;

int32_t ogle_sample_create(o_sample_t** sample, const o_sample_data_t* data);
void ogle_sample_destroy(o_sample_t* sample);

#endif // _HEADER_GUARD_OGLE_SAMPLE_H_
