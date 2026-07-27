#ifndef _HEADER_GUARD_OGLE_MATH_H_
#define _HEADER_GUARD_OGLE_MATH_H_

#include "libogle/o_common.h"

static const float OGLE_MATH_TAU						= { (float)ALLEGRO_PI * 2.0f };
static const float OGLE_MATH_TAU_DEG					= { 360.0f };
static const float OGLE_MATH_PI						= { (float)ALLEGRO_PI };
static const float OGLE_MATH_PI_DOUBLE				= { (float)ALLEGRO_PI * 2.0f };
static const float OGLE_MATH_PI_HALF					= { (float)ALLEGRO_PI * 0.5f };
static const float OGLE_MATH_PI_THREE_HALF			= { (float)ALLEGRO_PI * 1.5f };
static const float OGLE_MATH_PI_DEG					= { 180.0f };
static const float OGLE_MATH_PI_DEG_DOUBLE			= { 360.0f };
static const float OGLE_MATH_PI_DEG_THREE_HALF		= { 270.0f };
static const float OGLE_MATH_DEG_TO_RAD_RATIO		= { (float)ALLEGRO_PI / 180.0f };
static const float OGLE_MATH_RAD_TO_DEG_RATIO		= { 180.0f / (float)ALLEGRO_PI };

float ogle_math_abs_f(float a);
float ogle_math_max_f(float a, float b);
float ogle_math_min_f(float a, float b);
float ogle_math_degree_to_radian(float degree);
float ogle_math_radian_to_degree(float radian);
float ogle_math_lerp_f(float a, float b, float t);
float ogle_math_clamp_f(float value, float min, float max);
bool ogle_math_is_zero_f(float a);
bool ogle_math_is_equal_f(float a, float b);

#endif // _HEADER_GUARD_OGLE_MATH_H_
