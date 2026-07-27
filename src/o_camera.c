#include "libogle/o_common.h"
#include "libogle/o_vector3.h"
#include "libogle/o_transform.h"
#include "libogle/o_camera.h"

void ogle_camera_set_shader(const char* var_name, const o_camera_t* camera)
{
	char full_var_name[256];

	sprintf_s(full_var_name, sizeof(full_var_name), "%s.position", var_name);
	ogle_vector3_set_shader(full_var_name, camera->m_position);

	sprintf_s(full_var_name, sizeof(full_var_name), "%s.lookat", var_name);
	ogle_vector3_set_shader(full_var_name, camera->m_lookat);

	sprintf_s(full_var_name, sizeof(full_var_name), "%s.up", var_name);
	ogle_vector3_set_shader(full_var_name, camera->m_up);
}

void ogle_camera_rotate(o_camera_t* camera, o_vector3_t axis, float angle_deg)
{
	o_vector3_t forward = ogle_vector3_sub(camera->m_lookat, camera->m_position);

	forward = ogle_vector3_rotate_axis(forward, axis, angle_deg);

	camera->m_lookat = ogle_vector3_add(camera->m_position, forward);

}

o_vector3_t ogle_camera_move(const o_camera_t* camera, o_vector3_t forward, float speed, int32_t flag)
{
	o_vector3_t right = ogle_vector3_normalize(ogle_vector3_cross(forward, camera->m_up));
	o_vector3_t true_up = ogle_vector3_normalize(ogle_vector3_cross(right, forward));
	o_vector3_t normalized_forward = ogle_vector3_normalize(forward);

	switch (flag)
	{
	case 0: // forward
		return ogle_vector3_add(camera->m_position, ogle_vector3_mul_ff(normalized_forward, speed));
	case 1: // backward
		return ogle_vector3_sub(camera->m_position, ogle_vector3_mul_ff(normalized_forward, speed));
	case 2: // strafe left
		return ogle_vector3_sub(camera->m_position, ogle_vector3_mul_ff(right, speed));
	case 3: // strafe right
		return ogle_vector3_add(camera->m_position, ogle_vector3_mul_ff(right, speed));
	case 4: // move up
		return ogle_vector3_add(camera->m_position, ogle_vector3_mul_ff(true_up, speed));
	case 5: // move down
		return ogle_vector3_sub(camera->m_position, ogle_vector3_mul_ff(true_up, speed));
	default: break;
	}

	return camera->m_position;
}
