#ifndef _HEADER_GUARD_OGLE_FONT_H_
#define _HEADER_GUARD_OGLE_FONT_H_

#include "libogle/o_common.h"

enum OGLE_FONT_TYPES
{
	OGLE_FONT_TYPE_BUILTIN,
	OGLE_FONT_TYPE_TTF,
	OGLE_FONT_TYPE_BITMAP,
	OGLE_FONT_TYPE_COUNT
};

typedef ALLEGRO_FONT o_font_t;

typedef struct o_font_data_tag_t
{
	const char* m_filename;
	int32_t m_size;
	int32_t m_flags;
	int32_t m_type;
} o_font_data_t;

typedef void o_font_atlas_t;

int32_t ogle_font_create(o_font_t** font, const o_font_data_t* data);
void ogle_font_destroy(o_font_t* font);

#endif // _HEADER_GUARD_OGLE_FONT_H_
