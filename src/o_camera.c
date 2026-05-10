#include "libogle/o_common.h"
#include "libogle/o_vector3.h"
#include "libogle/o_transform.h"
#include "libogle/o_camera.h"

void ogle_camera_set_shader(const char* var_name, const o_camera_t* camera)
{
	char full_var_name[256];

	sprintf_s(full_var_name, sizeof(full_var_name), "%s.position", var_name);
	ogle_vector3_set_shader(full_var_name, camera->m_position);

	sprintf_s(full_var_name, sizeof(full_var_name), "%s.look_at", var_name);
	ogle_vector3_set_shader(full_var_name, camera->m_look_at);

	sprintf_s(full_var_name, sizeof(full_var_name), "%s.up", var_name);
	ogle_vector3_set_shader(full_var_name, camera->m_up);
}

