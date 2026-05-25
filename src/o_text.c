#include "libogle/o_common.h"
#include "libogle/o_vector2.h"
#include "libogle/o_color.h"
#include "libogle/o_math.h"
#include "libogle/o_text.h"


void ogle_text_draw_bordered_full(const ALLEGRO_FONT* font, o_vector2_t position, o_color_t color, o_color_t border, int32_t alignment, const char* text)
{
	for (float angle = 0.0f; angle < OGLE_MATH_TAU; angle += OGLE_MATH_TAU / 8.0f)
	{
		float offset_x = cosf(angle) * 2.0f;
		float offset_y = sinf(angle) * 2.0f;
		al_draw_text(font, border, position.m_x + offset_x, position.m_y + offset_y, alignment, text);
	}
	al_draw_text(font, color, position.m_x, position.m_y, alignment, text);
}

void ogle_text_draw_bordered_shadowed(const ALLEGRO_FONT* font, o_vector2_t position, o_color_t color, o_color_t border, int32_t alignment, const char* text)
{
	al_draw_text(font, border, position.m_x + 2.0f, position.m_y + 2.0f, alignment, text);
	al_draw_text(font, border, position.m_x + 1.0f, position.m_y + 1.0f, alignment, text);
	al_draw_text(font, border, position.m_x + 1.0f, position.m_y + 2.0f, alignment, text);
	al_draw_text(font, border, position.m_x + 2.0f, position.m_y + 1.0f, alignment, text);
	al_draw_text(font, color, position.m_x, position.m_y, alignment, text);
}

void ogle_text_draw_bordered_highlighted(const ALLEGRO_FONT* font, o_vector2_t position, o_color_t color, o_color_t border, int32_t alignment, const char* text)
{
	al_draw_text(font, border, position.m_x - 2.0f, position.m_y - 2.0f, alignment, text);
	al_draw_text(font, border, position.m_x - 1.0f, position.m_y - 1.0f, alignment, text);
	al_draw_text(font, border, position.m_x - 1.0f, position.m_y - 2.0f, alignment, text);
	al_draw_text(font, border, position.m_x - 2.0f, position.m_y - 1.0f, alignment, text);
	al_draw_text(font, color, position.m_x, position.m_y, alignment, text);
}

void ogle_text_draw_bordered(const ALLEGRO_FONT* font, o_vector2_t position, o_color_t color, o_color_t border, int32_t alignment, int32_t type, const char* text)
{
	switch (type)
	{
	case OGLE_TEXT_BORDER_FULL:
		ogle_text_draw_bordered_full(font, position, color, border, alignment, text);
		break;
	case OGLE_TEXT_BORDER_SHADOW:
		ogle_text_draw_bordered_shadowed(font, position, color, border, alignment, text);
		break;
	case OGLE_TEXT_BORDER_HIGHLIGHT:
		ogle_text_draw_bordered_highlighted(font, position, color, border, alignment, text);
		break;
	default:
		al_draw_text(font, color, position.m_x, position.m_y, alignment, text);
		break;
	}
}

void ogle_text_draw_bordered_args(const ALLEGRO_FONT* font, o_vector2_t position, o_color_t color, o_color_t border, int32_t alignment, int32_t type, const char* text, va_list args)
{
	char buffer[1024];
	vsnprintf(buffer, sizeof(buffer), text, args);
	ogle_text_draw_bordered(font, position, color, border, alignment, type, buffer);
}

void ogle_text_draw_bordered_f(const ALLEGRO_FONT* font, o_vector2_t position, o_color_t color, o_color_t border, int32_t alignment, int32_t type, const char* text, ...)
{
	va_list args;
	va_start(args, text);
	ogle_text_draw_bordered_args(font, position, color, border, alignment, type, text, args);
	va_end(args);
}

void ogle_text_draw(const ALLEGRO_FONT* font, o_vector2_t position, o_color_t color, int32_t alignment, const char* text)
{
	al_draw_text(font, color, position.m_x, position.m_y, alignment, text);
}

void ogle_text_draw_args(const ALLEGRO_FONT* font, o_vector2_t position, o_color_t color, int32_t alignment, const char* text, va_list args)
{
	char buffer[1024];
	vsnprintf(buffer, sizeof(buffer), text, args);
	al_draw_text(font, color, position.m_x, position.m_y, alignment, buffer);
}

void ogle_text_draw_f(const ALLEGRO_FONT* font, o_vector2_t position, o_color_t color, int32_t alignment, const char* text, ...)
{
	va_list args;
	va_start(args, text);
	ogle_text_draw_args(font, position, color, alignment, text, args);
	va_end(args);
}
