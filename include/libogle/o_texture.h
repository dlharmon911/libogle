#ifndef _HEADER_GUARD_OGLE_TEXTURE_H_
#define _HEADER_GUARD_OGLE_TEXTURE_H_

#include "libogle/o_common.h"

typedef ALLEGRO_BITMAP o_texture_t;

typedef struct o_texture_data_tag_t
{
	const char* m_filename;
	bool m_apply_mask;
} o_texture_data_t;

typedef void o_texture_atlas_t;

int32_t ogle_texture_create(o_texture_t** texture, const o_texture_data_t* data);
void ogle_texture_destroy(o_texture_t* texture);

#endif // _HEADER_GUARD_OGLE_TEXTURE_H_
