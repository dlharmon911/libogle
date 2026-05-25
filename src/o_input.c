#include "libogle/o_common.h"
#include "libogle/o_log.h"
#include "libogle/o_vector2.h"
#include "libogle/o_input.h"

typedef struct o_input_t
{
	o_input_keyboard_t m_keyboard;
	o_input_mouse_t m_mouse;
} o_input_t;

static void o_input_keyboard_zero(o_input_keyboard_t* keyboard)
{
	int32_t i;
	
	for (i = 0; i < OGLE_INPUT_KEYBOARD_MAX_BUTTONS; ++i)
	{
		keyboard->m_button[i] = 0;
	}

	keyboard->m_changed = false;
}

static void o_input_mouse_zero(o_input_mouse_t* mouse)
{
	int32_t i;
	for (i = 0; i < OGLE_INPUT_MOUSE_MAX_BUTTONS; ++i)
	{
		mouse->m_button[i] = 0;
	}

	mouse->m_position = ogle_vector2_zero();
	mouse->m_delta = ogle_vector2_zero();
	mouse->m_wheel = 0.0f;
	mouse->m_changed = false;
}

static void ogle_input_zero(o_input_t* input)
{
	o_input_keyboard_zero(&input->m_keyboard);
	o_input_mouse_zero(&input->m_mouse);
}

int32_t ogle_input_initializer(o_input_t* input, void* data)
{
	if (input == NULL)
	{
		return -1;
	}

	OGLE_DO_LOG(OGLE_LOG_LEVEL_INFO, "Initializing input");

	ogle_input_zero(input);

	return 0;
}

void ogle_input_uninitializer(o_input_t* input)
{
	OGLE_DO_LOG(OGLE_LOG_LEVEL_INFO, "Uninitializing input");
}

size_t ogle_input_size()
{
	return sizeof(o_input_t);
}

bool ogle_input_keyboard_button_is_pressed(const o_input_keyboard_t* keyboard, int32_t index)
{
	if (keyboard == NULL || index < 0 || index >= OGLE_INPUT_KEYBOARD_MAX_BUTTONS)
	{
		return false;
	}

	return (keyboard->m_button[index] & OGLE_INPUT_BUTTON_FLAG_PRESSED) != 0;
}

bool ogle_input_keyboard_button_was_pressed(const o_input_keyboard_t* keyboard, int32_t index)
{
	if (keyboard == NULL || index < 0 || index >= OGLE_INPUT_KEYBOARD_MAX_BUTTONS)
	{
		return false;
	}

	return (keyboard->m_button[index] & OGLE_INPUT_BUTTON_FLAG_CHANGED) != 0 &&
		(keyboard->m_button[index] & OGLE_INPUT_BUTTON_FLAG_PRESSED) != 0;
}

bool ogle_input_keyboard_button_was_changed(const o_input_keyboard_t* keyboard, int32_t index)
{
	if (keyboard == NULL || index < 0 || index >= OGLE_INPUT_KEYBOARD_MAX_BUTTONS)
	{
		return false;
	}

	return (keyboard->m_button[index] & OGLE_INPUT_BUTTON_FLAG_CHANGED) != 0;
}

bool ogle_input_keyboard_was_changed(const o_input_keyboard_t* keyboard)
{
	if (keyboard == NULL)
	{
		return false;
	}

	return keyboard->m_changed;
}

void ogle_input_keyboard_reset(o_input_keyboard_t* keyboard)
{
	for (int32_t i = 0; i < OGLE_INPUT_KEYBOARD_MAX_BUTTONS; ++i)
	{
		keyboard->m_button[i] &= ~OGLE_INPUT_BUTTON_FLAG_CHANGED;
	}

	keyboard->m_changed = false;
}

bool ogle_input_mouse_button_is_pressed(const o_input_mouse_t* mouse, int32_t index)
{
	if (mouse == NULL || index < 0 || index >= OGLE_INPUT_MOUSE_MAX_BUTTONS)
	{
		return false;
	}

	return (mouse->m_button[index] & OGLE_INPUT_BUTTON_FLAG_PRESSED) != 0;
}

bool ogle_input_mouse_button_was_pressed(const o_input_mouse_t* mouse, int32_t index)
{
	if (mouse == NULL || index < 0 || index >= OGLE_INPUT_MOUSE_MAX_BUTTONS)
	{
		return false;
	}

	return (mouse->m_button[index] & OGLE_INPUT_BUTTON_FLAG_CHANGED) != 0 &&
		(mouse->m_button[index] & OGLE_INPUT_BUTTON_FLAG_PRESSED) != 0;
}

bool ogle_input_mouse_button_was_changed(const o_input_mouse_t* mouse, int32_t index)
{
	if (mouse == NULL || index < 0 || index >= OGLE_INPUT_MOUSE_MAX_BUTTONS)
	{
		return false;
	}

	return (mouse->m_button[index] & OGLE_INPUT_BUTTON_FLAG_CHANGED) != 0;
}

bool ogle_input_mouse_was_changed(const o_input_mouse_t* mouse)
{
	if (mouse == NULL)
	{
		return false;
	}

	return mouse->m_changed;
}

void ogle_input_mouse_reset(o_input_mouse_t* mouse)
{
	for (int32_t i = 0; i < OGLE_INPUT_MOUSE_MAX_BUTTONS; ++i)
	{
		mouse->m_button[i] &= ~OGLE_INPUT_BUTTON_FLAG_CHANGED;
	}

	mouse->m_changed = false;
}

o_vector2_t ogle_input_mouse_get_position(const o_input_mouse_t* mouse)
{
	if (mouse == NULL)
	{
		return ogle_vector2_zero();
	}
	
	return mouse->m_position;
}

o_vector2_t ogle_input_mouse_get_delta(const o_input_mouse_t* mouse)
{
	if (mouse == NULL)
	{
		return ogle_vector2_zero();
	}

	return mouse->m_delta;
}

float ogle_input_mouse_get_wheel(const o_input_mouse_t* mouse)
{
	if (mouse == NULL)
	{
		return 0.0f;
	}

	return mouse->m_wheel;
}

bool ogle_input_is_pressed(const o_input_t* input, int32_t type, int32_t index)
{
	if (input == NULL)
	{
		return false;
	}

	switch (type)
	{
	case OGLE_INPUT_TYPE_KEYBOARD:
		return ogle_input_keyboard_button_is_pressed(&input->m_keyboard, index);
	case OGLE_INPUT_TYPE_MOUSE:
		return ogle_input_mouse_button_is_pressed(&input->m_mouse, index);
	default:
		return false;
	}
}

bool ogle_input_was_pressed(const o_input_t* input, int32_t type, int32_t index)
{
	if (input == NULL)
	{
		return false;
	}	switch (type)
	{
	case OGLE_INPUT_TYPE_KEYBOARD:
		return ogle_input_keyboard_button_was_pressed(&input->m_keyboard, index);
	case OGLE_INPUT_TYPE_MOUSE:
		return ogle_input_mouse_button_was_pressed(&input->m_mouse, index);
	default:
		return false;
	}
}

bool ogle_input_was_changed(const o_input_t* input, int32_t type, int32_t index)
{
	if (input == NULL)
	{
		return false;
	}

	switch (type)
	{
	case OGLE_INPUT_TYPE_KEYBOARD:
		return ogle_input_keyboard_button_was_changed(&input->m_keyboard, index);
	case OGLE_INPUT_TYPE_MOUSE:
		return ogle_input_mouse_button_was_changed(&input->m_mouse, index);
	default:
		return false;
	}
}

void ogle_input_reset(o_input_t* input)
{
	if (input == NULL)
	{
		return;
	}

	ogle_input_keyboard_reset(&input->m_keyboard);
	ogle_input_mouse_reset(&input->m_mouse);
}

void* ogle_input_get_type(const o_input_t* input, int32_t type)
{
	if (input == NULL)
	{
		return NULL;
	}

	switch (type)
	{
	case OGLE_INPUT_TYPE_KEYBOARD:
		return (void*)&input->m_keyboard;
	case OGLE_INPUT_TYPE_MOUSE:
		return (void*)&input->m_mouse;
	default:
		return NULL;
	}
}
