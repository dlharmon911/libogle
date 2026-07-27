#include <float.h>
#include "libogle/o_common.h"
#include "libogle/o_log.h"
#include "libogle/o_math.h"


float ogle_math_abs_f(float a)
{
	if (a < 0.0f)
	{
		return -a;
	}

	return a;
}

float ogle_math_max_f(float a, float b)
{
	if (a > b)
	{
		return a;
	}

	return b;
}

float ogle_math_min_f(float a, float b)
{
	if (a < b)
	{
		return a;
	}

	return b;
}

float ogle_math_degree_to_radian(float degree)
{
	return degree * OGLE_MATH_DEG_TO_RAD_RATIO;
}

float ogle_math_radian_to_degree(float radian)
{
	return radian * OGLE_MATH_RAD_TO_DEG_RATIO;
}

float ogle_math_lerp_f(float a, float b, float t)
{
	return a + (b - a) * t;
}

float ogle_math_clamp_f(float value, float min, float max)
{
	if (value < min)
	{
		return min;
	}

	if (value > max)
	{
		return max;
	}

	return value;
}

bool ogle_math_is_zero_f(float a)
{
	return ogle_math_is_equal_f(a, 0.0f);
}

bool ogle_math_is_equal_f(float a, float b)
{
	return (ogle_math_abs_f(a - b) <= FLT_EPSILON);
}
