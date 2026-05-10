#ifndef _HEADER_GUARD_OGLE_CAMERA_H_
#define _HEADER_GUARD_OGLE_CAMERA_H_

#include "libogle/o_common.h"
#include "libogle/o_vector2.h"
#include "libogle/o_vector3.h"
#include "libogle/o_ray.h"

typedef struct o_camera_tag_t
{
	o_vector3_t m_position;
	o_vector3_t m_look_at;
	o_vector3_t m_up;
} o_camera_t;

void ogle_camera_set_shader(const char* var_name, const o_camera_t* camera);

#endif // _HEADER_GUARD_OGLE_CAMERA_H_
