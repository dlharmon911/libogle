#ifndef _HEADER_GUARD_OGLE_LIGHT_H_
#define _HEADER_GUARD_OGLE_LIGHT_H_

#include "libogle/o_common.h"
#include "libogle/o_vector3.h"

typedef struct o_light_tag_t
{
	o_vector3_t m_position;
	o_vector3_t m_ambient;
	o_vector3_t m_diffuse;
	o_vector3_t m_specular;
} o_light_t;

void ogle_light_set_shader(const char* var_name, const o_light_t* light);

#endif // _HEADER_GUARD_OGLE_LIGHT_H_
