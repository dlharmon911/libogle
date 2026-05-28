#include "libogle/o_common.h"
#include "libogle/o_string.h"
#include "libogle/o_log.h"
#include "libogle/o_config.h"

bool ogle_config_get_bool(ALLEGRO_CONFIG* config, const char* section, const char* key, bool default_value)
{
	if (!config || !section || !key) 
	{
		return default_value;
	}

	const char* value_str = al_get_config_value(config, section, key);

	if (!value_str)
	{
		return default_value;
	}

	return ogle_string_to_bool(value_str);
}

int8_t ogle_config_get_int8(ALLEGRO_CONFIG* config, const char* section, const char* key, int8_t default_value)
{
	if (!config || !section || !key)
	{
		return default_value;
	}
	const char* value_str = al_get_config_value(config, section, key);
	if (!value_str)
	{
		return default_value;
	}
	return ogle_string_to_int8(value_str);
}

int16_t ogle_config_get_int16(ALLEGRO_CONFIG* config, const char* section, const char* key, int16_t default_value)
{
	if (!config || !section || !key)
	{
		return default_value;
	}
	const char* value_str = al_get_config_value(config, section, key);
	if (!value_str)
	{
		return default_value;
	}
	return ogle_string_to_int16(value_str);
}

int32_t ogle_config_get_int32(ALLEGRO_CONFIG* config, const char* section, const char* key, int32_t default_value)
{
	if (!config || !section || !key)
	{
		return default_value;
	}
	const char* value_str = al_get_config_value(config, section, key);
	if (!value_str)
	{
		return default_value;
	}
	return ogle_string_to_int32(value_str);
}

int64_t ogle_config_get_int64(ALLEGRO_CONFIG* config, const char* section, const char* key, int64_t default_value)
{
	if (!config || !section || !key)
	{
		return default_value;
	}
	const char* value_str = al_get_config_value(config, section, key);
	if (!value_str)
	{
		return default_value;
	}
	return ogle_string_to_int64(value_str);
}

uint8_t ogle_config_get_uint8(ALLEGRO_CONFIG* config, const char* section, const char* key, uint8_t default_value)
{
	if (!config || !section || !key)
	{
		return default_value;
	}
	const char* value_str = al_get_config_value(config, section, key);
	if (!value_str)
	{
		return default_value;
	}
	return ogle_string_to_uint8(value_str);
}

uint16_t ogle_config_get_uint16(ALLEGRO_CONFIG* config, const char* section, const char* key, uint16_t default_value)
{
	if (!config || !section || !key)
	{
		return default_value;
	}
	const char* value_str = al_get_config_value(config, section, key);
	if (!value_str)
	{
		return default_value;
	}
	return ogle_string_to_uint16(value_str);
}

uint32_t ogle_config_get_uint32(ALLEGRO_CONFIG* config, const char* section, const char* key, uint32_t default_value)
{
	if (!config || !section || !key)
	{
		return default_value;
	}
	const char* value_str = al_get_config_value(config, section, key);
	if (!value_str)
	{
		return default_value;
	}
	return ogle_string_to_uint32(value_str);
}

uint64_t ogle_config_get_uint64(ALLEGRO_CONFIG* config, const char* section, const char* key, uint64_t default_value)
{
	if (!config || !section || !key)
	{
		return default_value;
	}
	const char* value_str = al_get_config_value(config, section, key);
	if (!value_str)
	{
		return default_value;
	}
	return ogle_string_to_uint64(value_str);
}

float ogle_config_get_float(ALLEGRO_CONFIG* config, const char* section, const char* key, float default_value)
{
	if (!config || !section || !key)
	{
		return default_value;
	}
	const char* value_str = al_get_config_value(config, section, key);
	if (!value_str)
	{
		return default_value;
	}
	return ogle_string_to_float(value_str);
}

double ogle_config_get_double(ALLEGRO_CONFIG* config, const char* section, const char* key, double default_value)
{
	if (!config || !section || !key)
	{
		return default_value;
	}
	const char* value_str = al_get_config_value(config, section, key);
	if (!value_str)
	{
		return default_value;
	}
	return ogle_string_to_double(value_str);
}

const char* ogle_config_get_string(ALLEGRO_CONFIG* config, const char* section, const char* key, const char* default_value)
{
	if (!config || !section || !key)
	{
		return default_value;
	}
	
	const char* value_str = al_get_config_value(config, section, key);
	
	if (!value_str)
	{
		return default_value;
	}

	return value_str;
}

bool ogle_config_get_bool_const(const ALLEGRO_CONFIG* config, const char* section, const char* key)
{
	if (!config || !section || !key)
	{
		return false;
	}
	const char* value_str = al_get_config_value(config, section, key);

	if (!value_str)
	{
		return false;
	}
	
	return ogle_string_to_bool(value_str);
}

int8_t ogle_config_get_int8_const(const ALLEGRO_CONFIG* config, const char* section, const char* key)
{
	if (!config || !section || !key)
	{
		return 0;
	}
	const char* value_str = al_get_config_value(config, section, key);
	if (!value_str)
	{
		return 0;
	}
	return ogle_string_to_int8(value_str);
}
int16_t ogle_config_get_int16_const(const ALLEGRO_CONFIG* config, const char* section, const char* key)
{
	if (!config || !section || !key)
	{
		return 0;
	}
	const char* value_str = al_get_config_value(config, section, key);
	if (!value_str)
	{
		return 0;
	}
	return ogle_string_to_int16(value_str);
}

int32_t ogle_config_get_int32_const(const ALLEGRO_CONFIG* config, const char* section, const char* key)
{
	if (!config || !section || !key)
	{
		return 0;
	}
	const char* value_str = al_get_config_value(config, section, key);
	if (!value_str)
	{
		return 0;
	}
	return ogle_string_to_int32(value_str);
}

int64_t ogle_config_get_int64_const(const ALLEGRO_CONFIG* config, const char* section, const char* key)
{
	if (!config || !section || !key)
	{
		return 0;
	}
	const char* value_str = al_get_config_value(config, section, key);
	if (!value_str)
	{
		return 0;
	}
	return ogle_string_to_int64(value_str);
}

uint8_t ogle_config_get_uint8_const(const ALLEGRO_CONFIG* config, const char* section, const char* key)
{
	if (!config || !section || !key)
	{
		return 0;
	}
	const char* value_str = al_get_config_value(config, section, key);
	if (!value_str)
	{
		return 0;
	}
	return ogle_string_to_uint8(value_str);
}

uint16_t ogle_config_get_uint16_const(const ALLEGRO_CONFIG* config, const char* section, const char* key)
{
	if (!config || !section || !key)
	{
		return 0;
	}
	const char* value_str = al_get_config_value(config, section, key);
	if (!value_str)
	{
		return 0;
	}
	return ogle_string_to_uint16(value_str);
}

uint32_t ogle_config_get_uint32_const(const ALLEGRO_CONFIG* config, const char* section, const char* key)
{
	if (!config || !section || !key)
	{
		return 0;
	}
	const char* value_str = al_get_config_value(config, section, key);
	if (!value_str)
	{
		return 0;
	}
	return ogle_string_to_uint32(value_str);
}

uint64_t ogle_config_get_uint64_const(const ALLEGRO_CONFIG* config, const char* section, const char* key)
{
	if (!config || !section || !key)
	{
		return 0;
	}
	const char* value_str = al_get_config_value(config, section, key);
	if (!value_str)
	{
		return 0;
	}
	return ogle_string_to_uint64(value_str);
}

float ogle_config_get_float_const(const ALLEGRO_CONFIG* config, const char* section, const char* key)
{
	if (!config || !section || !key)
	{
		return 0;
	}
	const char* value_str = al_get_config_value(config, section, key);
	if (!value_str)
	{
		return 0;
	}
	return ogle_string_to_float(value_str);
}

double ogle_config_get_double_const(const ALLEGRO_CONFIG* config, const char* section, const char* key)
{
	if (!config || !section || !key)
	{
		return 0;
	}
	const char* value_str = al_get_config_value(config, section, key);
	if (!value_str)
	{
		return 0;
	}
	return ogle_string_to_double(value_str);
}

const char* ogle_config_get_string_const(const ALLEGRO_CONFIG* config, const char* section, const char* key)
{
	if (!config || !section || !key)
	{
		return NULL;
	}

	const char* value_str = al_get_config_value(config, section, key);

	if (!value_str)
	{
		return NULL;
	}

	return value_str;
}

bool ogle_config_set_bool(ALLEGRO_CONFIG* config, const char* section, const char* key, bool value)
{
	char value_str[6] = { 0 };
	if (ogle_string_from_bool(value_str, sizeof(value_str), value))
	{
		al_set_config_value(config, section, key, value_str);
		return true;
	}

	return false;
}

bool ogle_config_set_int8(ALLEGRO_CONFIG* config, const char* section, const char* key, int8_t value)
{
	char value_str[12] = { 0 };
	if (ogle_string_from_int8(value_str, sizeof(value_str), value))
	{
		al_set_config_value(config, section, key, value_str);
		return true;
	}
	return false;
}

bool ogle_config_set_int16(ALLEGRO_CONFIG* config, const char* section, const char* key, int16_t value)
{
	char value_str[12] = { 0 };
	if (ogle_string_from_int16(value_str, sizeof(value_str), value))
	{
		al_set_config_value(config, section, key, value_str);
		return true;
	}
	return false;
}

bool ogle_config_set_int32(ALLEGRO_CONFIG* config, const char* section, const char* key, int32_t value)
{
	char value_str[12] = { 0 };
	if (ogle_string_from_int32(value_str, sizeof(value_str), value))
	{
		al_set_config_value(config, section, key, value_str);
		return true;
	}
	return false;
}

bool ogle_config_set_int64(ALLEGRO_CONFIG* config, const char* section, const char* key, int64_t value)
{
	char value_str[21] = { 0 };
	if (ogle_string_from_int64(value_str, sizeof(value_str), value))
	{
		al_set_config_value(config, section, key, value_str);
		return true;
	}
	return false;
}

bool ogle_config_set_uint8(ALLEGRO_CONFIG* config, const char* section, const char* key, uint8_t value)
{
	char value_str[12] = { 0 };
	if (ogle_string_from_uint8(value_str, sizeof(value_str), value))
	{
		al_set_config_value(config, section, key, value_str);
		return true;
	}
	return false;
}

bool ogle_config_set_uint16(ALLEGRO_CONFIG* config, const char* section, const char* key, uint16_t value)
{
	char value_str[12] = { 0 };
	if (ogle_string_from_uint16(value_str, sizeof(value_str), value))
	{
		al_set_config_value(config, section, key, value_str);
		return true;
	}
	return false;
}

bool ogle_config_set_uint32(ALLEGRO_CONFIG* config, const char* section, const char* key, uint32_t value)
{
	char value_str[12] = { 0 };
	if (ogle_string_from_uint32(value_str, sizeof(value_str), value))
	{
		al_set_config_value(config, section, key, value_str);
		return true;
	}
	return false;
}

bool ogle_config_set_uint64(ALLEGRO_CONFIG* config, const char* section, const char* key, uint64_t value)
{
	char value_str[21] = { 0 };
	if (ogle_string_from_uint64(value_str, sizeof(value_str), value))
	{
		al_set_config_value(config, section, key, value_str);
		return true;
	}
	return false;
}

bool ogle_config_set_float(ALLEGRO_CONFIG* config, const char* section, const char* key, float value)
{
	char value_str[32] = { 0 };
	if (ogle_string_from_float(value_str, sizeof(value_str), value))
	{
		al_set_config_value(config, section, key, value_str);
		return true;
	}
	return false;
}

bool ogle_config_set_double(ALLEGRO_CONFIG* config, const char* section, const char* key, double value)
{
	char value_str[32] = { 0 };
	if (ogle_string_from_double(value_str, sizeof(value_str), value))
	{
		al_set_config_value(config, section, key, value_str);
		return true;
	}
	return false;
}

bool ogle_config_set_string(ALLEGRO_CONFIG* config, const char* section, const char* key, const char* value)
{
	if (!config || !section || !key || !value)
	{
		return false;
	}

	al_set_config_value(config, section, key, value);
	return true;
}