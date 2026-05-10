#include "libogle/o_common.h"
#include "libogle/o_vector3.h"
#include "libogle/o_light.h"

void ogle_light_set_shader(const char* var_name, const o_light_t* light)
{
	char full_var_name[256];

	sprintf_s(full_var_name, sizeof(full_var_name), "%s.position", var_name);
	ogle_vector3_set_shader(full_var_name, light->m_position);

	sprintf_s(full_var_name, sizeof(full_var_name), "%s.ambient", var_name);
	ogle_vector3_set_shader(full_var_name, light->m_ambient);

	sprintf_s(full_var_name, sizeof(full_var_name), "%s.diffuse", var_name);
	ogle_vector3_set_shader(full_var_name, light->m_diffuse);

	sprintf_s(full_var_name, sizeof(full_var_name), "%s.specular", var_name);
	ogle_vector3_set_shader(full_var_name, light->m_specular);
}
