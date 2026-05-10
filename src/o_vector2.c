#include "libogle/o_common.h"
#include "libogle/o_log.h"
#include "libogle/o_math.h"
#include "libogle/o_vector2.h"

o_vector2_t ogle_vector2_zero(void)
{
	return (o_vector2_t) { 0.0f, 0.0f };
}

o_vector2_t ogle_vector2_ff(float f)
{
	return (o_vector2_t) { f, f };
}

o_vector2_t ogle_vector2_f(float x, float y)
{
	return (o_vector2_t) { x, y };
}

o_vector2_t ogle_vector2(o_vector2_t other)
{
	return other;
}

float ogle_vector2_x(o_vector2_t vector)
{
	return vector.m_x;
}

float ogle_vector2_y(o_vector2_t vector)
{
	return vector.m_y;
}

float ogle_vector2_squared_length(o_vector2_t vector)
{
	return vector.m_x * vector.m_x + vector.m_y * vector.m_y;
}

float ogle_vector2_length(o_vector2_t vector)
{
	return sqrtf(ogle_vector2_squared_length(vector));
}

float ogle_vector2_distance(o_vector2_t vector1, o_vector2_t vector2)
{
	return ogle_vector2_length(ogle_vector2_sub(vector1, vector2));
}

float ogle_vector2_dot(o_vector2_t vector1, o_vector2_t vector2)
{
	return vector1.m_x * vector2.m_x + vector1.m_y * vector2.m_y;
}

o_vector2_t ogle_vector2_add_ff(o_vector2_t vector, float f)
{
	return (o_vector2_t) { vector.m_x + f, vector.m_y + f };
}

o_vector2_t ogle_vector2_add_f(o_vector2_t vector, float x, float y)
{
	return (o_vector2_t) { vector.m_x + x, vector.m_y + y };
}

o_vector2_t ogle_vector2_add(o_vector2_t vector1, o_vector2_t vector2)
{
	return (o_vector2_t) { vector1.m_x + vector2.m_x, vector1.m_y + vector2.m_y };
}

o_vector2_t ogle_vector2_sub_ff(o_vector2_t vector, float f)
{
	return (o_vector2_t) { vector.m_x - f, vector.m_y - f };
}

o_vector2_t ogle_vector2_sub_f(o_vector2_t vector, float x, float y)
{
	return (o_vector2_t) { vector.m_x - x, vector.m_y - y };
}

o_vector2_t ogle_vector2_sub(o_vector2_t vector1, o_vector2_t vector2)
{
	return (o_vector2_t) { vector1.m_x - vector2.m_x, vector1.m_y - vector2.m_y };
}

o_vector2_t ogle_vector2_mul_ff(o_vector2_t vector, float f)
{
	return (o_vector2_t) { vector.m_x* f, vector.m_y* f };
}

o_vector2_t ogle_vector2_mul_f(o_vector2_t vector, float x, float y)
{
	return (o_vector2_t) { vector.m_x* x, vector.m_y* y };
}

o_vector2_t ogle_vector2_mul(o_vector2_t vector1, o_vector2_t vector2)
{
	return (o_vector2_t) { vector1.m_x* vector2.m_x, vector1.m_y* vector2.m_y };
}

o_vector2_t ogle_vector2_div_ff(o_vector2_t vector, float f)
{
	if (ogle_math_is_zero_f(f))
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_WARNING, "Attempted to divide vector by zero.\n");
		return vector;
	}

	return (o_vector2_t) { vector.m_x / f, vector.m_y / f };
}

o_vector2_t ogle_vector2_div_f(o_vector2_t vector, float x, float y)
{
	if (ogle_math_is_zero_f(x) || ogle_math_is_zero_f(y))
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_WARNING, "Attempted to divide vector by zero.\n");
		return vector;
	}

	return (o_vector2_t) { vector.m_x / x, vector.m_y / y };
}

o_vector2_t ogle_vector2_div(o_vector2_t vector1, o_vector2_t vector2)
{
	if (ogle_math_is_zero_f(vector2.m_x) || ogle_math_is_zero_f(vector2.m_y))
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_WARNING, "Attempted to divide vector by zero.\n");
		return vector1;
	}

	return (o_vector2_t) { vector1.m_x / vector2.m_x, vector1.m_y / vector2.m_y };
}

bool ogle_vector2_equal(o_vector2_t vector1, o_vector2_t vector2)
{
	return ogle_math_is_equal_f(vector1.m_x, vector2.m_x) && ogle_math_is_equal_f(vector1.m_y, vector2.m_y);
}

o_vector2_t ogle_vector2_normalize(o_vector2_t vector)
{
	float length = ogle_vector2_length(vector);

	if (ogle_math_is_zero_f(length))
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_WARNING, "Attempted to normalize a zero-length vector.\n");
		return vector;
	}

	return ogle_vector2_div_ff(vector, length);
}

o_vector2_t ogle_vector2_lerp(o_vector2_t vector1, o_vector2_t vector2, float t)
{
	return (o_vector2_t) { ogle_math_lerp_f(vector1.m_x, vector2.m_x, t), ogle_math_lerp_f(vector1.m_y, vector2.m_y, t) };
}

o_vector2_t ogle_vector2_clamp(o_vector2_t vector, o_vector2_t min, o_vector2_t max)
{
	return (o_vector2_t) { ogle_math_clamp_f(vector.m_x, min.m_x, max.m_x), ogle_math_clamp_f(vector.m_y, min.m_y, max.m_y) };
}

o_vector2_t ogle_vector2_rotate(o_vector2_t vector, float angle)
{
	float cos_angle = cosf(angle);
	float sin_angle = sinf(angle);

	return (o_vector2_t) { vector.m_x* cos_angle - vector.m_y * sin_angle, vector.m_x* sin_angle + vector.m_y * cos_angle };
}

o_vector2_t ogle_vector2_perpendicular(o_vector2_t vector)
{
	return (o_vector2_t) { -vector.m_y, vector.m_x };
}

o_vector2_t ogle_vector2_difference(o_vector2_t vector, o_vector2_t other)
{
	return ogle_vector2_abs(ogle_vector2_sub(vector, other));
}

o_vector2_t ogle_vector2_abs(o_vector2_t vector)
{
	return (o_vector2_t) { fabsf(vector.m_x), fabsf(vector.m_y) };
}

ALLEGRO_PRIM_STORAGE ogle_vector2_storage_type(void)
{
	return ALLEGRO_PRIM_FLOAT_2;
}

void ogle_vector2_set_shader(const char* var_name, o_vector2_t vector)
{
	const ALLEGRO_SHADER* shader = al_get_current_shader();

	if (!shader)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_WARNING, "No shader is currently active. Cannot set shader variable '%s'.\n", var_name);
		return;
	}

	if (!var_name)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Variable name is NULL.\n");
		return;
	}

	al_set_shader_float_vector(var_name, 2, &vector.m_x, 1);
}
