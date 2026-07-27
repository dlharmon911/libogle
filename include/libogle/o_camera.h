#ifndef _HEADER_GUARD_OGLE_CAMERA_H_
#define _HEADER_GUARD_OGLE_CAMERA_H_

#include "libogle/o_common.h"
#include "libogle/o_vector2.h"
#include "libogle/o_vector3.h"
#include "libogle/o_ray.h"

enum OGLE_CAMERA_FLAG_MOVEMENT
{
	OGLE_CAMERA_FLAG_FORWARD,
	OGLE_CAMERA_FLAG_BACKWARD,
	OGLE_CAMERA_FLAG_STRAFE_LEFT,
	OGLE_CAMERA_FLAG_STRAFE_RIGHT,
	OGLE_CAMERA_FLAG_MOVE_UP,
	OGLE_CAMERA_FLAG_MOVE_DOWN
};

typedef struct o_camera_tag_t
{
	o_vector3_t m_position;
	o_vector3_t m_lookat;
	o_vector3_t m_up;
	float m_pitch;
} o_camera_t;

void ogle_camera_set_shader(const char* var_name, const o_camera_t* camera);
void ogle_camera_rotate(o_camera_t* camera, o_vector3_t axis, float angle_deg);
o_vector3_t ogle_camera_move(const o_camera_t* camera, o_vector3_t forward, float speed, int32_t flag);

#endif // _HEADER_GUARD_OGLE_CAMERA_H_
