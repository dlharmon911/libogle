#ifndef _HEADER_GUARD_OGLE_INPUT_H_
#define _HEADER_GUARD_OGLE_INPUT_H_

#include "libogle/o_common.h"
#include "libogle/o_vector2.h"

#define OGLE_INPUT_KEYBOARD_MAX_BUTTONS ALLEGRO_KEY_MAX
#define OGLE_INPUT_MOUSE_MAX_BUTTONS 5

enum OGLE_INPUT_BUTTON_FLAGS
{
	OGLE_INPUT_BUTTON_FLAG_CHANGED = 1 << 0,
	OGLE_INPUT_BUTTON_FLAG_PRESSED = 1 << 1
};

enum OGLE_INPUT_TYPE
{
	OGLE_INPUT_TYPE_KEYBOARD,
	OGLE_INPUT_TYPE_MOUSE,
	OGLE_INPUT_TYPE_COUNT
};

typedef struct o_input_keyboard_t
{
	uint8_t m_button[OGLE_INPUT_KEYBOARD_MAX_BUTTONS];
	bool m_changed;
} o_input_keyboard_t;

typedef struct o_input_mouse_t
{
	uint8_t m_button[OGLE_INPUT_MOUSE_MAX_BUTTONS];
	o_vector2_t m_position;
	o_vector2_t m_delta;
	float m_wheel;
	bool m_changed;
} o_input_mouse_t;

typedef struct o_input_t o_input_t;

int32_t ogle_input_initializer(o_input_t* input, void * data);
void ogle_input_uninitializer(o_input_t* input);
size_t ogle_input_size();
bool ogle_input_keyboard_button_is_pressed(const o_input_keyboard_t* keyboard, int32_t index);
bool ogle_input_keyboard_button_was_pressed(const o_input_keyboard_t* keyboard, int32_t index);
bool ogle_input_keyboard_button_was_released(const o_input_keyboard_t* keyboard, int32_t index);
bool ogle_input_keyboard_button_was_changed(const o_input_keyboard_t* keyboard, int32_t index);
bool ogle_input_keyboard_was_changed(const o_input_keyboard_t* keyboard);
void ogle_input_keyboard_reset(o_input_keyboard_t* keyboard);
bool ogle_input_mouse_button_is_pressed(const o_input_mouse_t* mouse, int32_t index);
bool ogle_input_mouse_button_was_pressed(const o_input_mouse_t* mouse, int32_t index);
bool ogle_input_mouse_button_was_released(const o_input_mouse_t* mouse, int32_t index);
bool ogle_input_mouse_button_was_changed(const o_input_mouse_t* mouse, int32_t index);
bool ogle_input_mouse_was_changed(const o_input_mouse_t* mouse);
void ogle_input_mouse_reset(o_input_mouse_t* mouse);
o_vector2_t ogle_input_mouse_get_position(const o_input_mouse_t* mouse);
o_vector2_t ogle_input_mouse_get_delta(const o_input_mouse_t* mouse);
float ogle_input_mouse_get_wheel(const o_input_mouse_t* mouse);
bool ogle_input_is_pressed(const o_input_t* input, int32_t type, int32_t index);
bool ogle_input_was_pressed(const o_input_t* input, int32_t type, int32_t index);
bool ogle_input_was_changed(const o_input_t* input, int32_t type, int32_t index);
void ogle_input_reset(o_input_t* input);
void* ogle_input_get_type(const o_input_t* input, int32_t type);


#endif // _HEADER_GUARD_OGLE_INPUT_H_
