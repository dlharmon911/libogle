#ifndef _HEADER_GUARD_OGLE_TEXT_H_
#define _HEADER_GUARD_OGLE_TEXT_H_

#include "libogle/o_common.h"
#include "libogle/o_font.h"

enum OGLE_TEXT_BORDER_FLAGS
{
	OGLE_TEXT_BORDER_NONE,
	OGLE_TEXT_BORDER_FULL,
	OGLE_TEXT_BORDER_SHADOW,
	OGLE_TEXT_BORDER_HIGHLIGHT
};

void ogle_text_draw_bordered_full(const o_font_t* font, o_vector2_t position, o_color_t color, o_color_t border, int32_t alignment, const char* text);
void ogle_text_draw_bordered_shadowed(const o_font_t* font, o_vector2_t position, o_color_t color, o_color_t border, int32_t alignment, const char* text);
void ogle_text_draw_bordered_highlighted(const o_font_t* font, o_vector2_t position, o_color_t color, o_color_t border, int32_t alignment, const char* text);

void ogle_text_draw_bordered(const o_font_t* font, o_vector2_t position, o_color_t color, o_color_t border, int32_t alignment, int32_t type, const char* text);
void ogle_text_draw_bordered_args(const o_font_t* font, o_vector2_t position, o_color_t color, o_color_t border, int32_t alignment, int32_t type, const char* text, va_list args);
void ogle_text_draw_bordered_f(const o_font_t* font, o_vector2_t position, o_color_t color, o_color_t border, int32_t alignment, int32_t type, const char* text, ...);

void ogle_text_draw(const o_font_t* font, o_vector2_t position, o_color_t color, int32_t alignment, const char* text);
void ogle_text_draw_args(const o_font_t* font, o_vector2_t position, o_color_t color, int32_t alignment, const char* text, va_list args);
void ogle_text_draw_f(const o_font_t* font, o_vector2_t position, o_color_t color, int32_t alignment, const char* text, ...);


#endif // _HEADER_GUARD_OGLE_TEXT_H_
