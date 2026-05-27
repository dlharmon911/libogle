#ifndef _HEADER_GUARD_OGLE_CONFIG_H_
#define _HEADER_GUARD_OGLE_CONFIG_H_

#include "libogle/o_common.h"

bool ogle_config_get_bool(ALLEGRO_CONFIG* config, const char* section, const char* key, bool default_value);
int8_t ogle_config_get_int8(ALLEGRO_CONFIG* config, const char* section, const char* key, int8_t default_value);
int16_t ogle_config_get_int16(ALLEGRO_CONFIG* config, const char* section, const char* key, int16_t default_value);
int32_t ogle_config_get_int32(ALLEGRO_CONFIG* config, const char* section, const char* key, int32_t default_value);
int64_t ogle_config_get_int64(ALLEGRO_CONFIG* config, const char* section, const char* key, int64_t default_value);
uint8_t ogle_config_get_uint8(ALLEGRO_CONFIG* config, const char* section, const char* key, uint8_t default_value);
uint16_t ogle_config_get_uint16(ALLEGRO_CONFIG* config, const char* section, const char* key, uint16_t default_value);
uint32_t ogle_config_get_uint32(ALLEGRO_CONFIG* config, const char* section, const char* key, uint32_t default_value);
uint64_t ogle_config_get_uint64(ALLEGRO_CONFIG* config, const char* section, const char* key, uint64_t default_value);
float ogle_config_get_float(ALLEGRO_CONFIG* config, const char* section, const char* key, float default_value);
double ogle_config_get_double(ALLEGRO_CONFIG* config, const char* section, const char* key, double default_value);
const char* ogle_config_get_string(ALLEGRO_CONFIG* config, const char* section, const char* key, const char* default_value);

bool ogle_config_get_bool_const(const ALLEGRO_CONFIG* config, const char* section, const char* key);
int8_t ogle_config_get_int8_const(const ALLEGRO_CONFIG* config, const char* section, const char* key);
int16_t ogle_config_get_int16_const(const ALLEGRO_CONFIG* config, const char* section, const char* key);
int32_t ogle_config_get_int32_const(const ALLEGRO_CONFIG* config, const char* section, const char* key);
int64_t ogle_config_get_int64_const(const ALLEGRO_CONFIG* config, const char* section, const char* key);
uint8_t ogle_config_get_uint8_const(const ALLEGRO_CONFIG* config, const char* section, const char* key);
uint16_t ogle_config_get_uint16_const(const ALLEGRO_CONFIG* config, const char* section, const char* key);
uint32_t ogle_config_get_uint32_const(const ALLEGRO_CONFIG* config, const char* section, const char* key);
uint64_t ogle_config_get_uint64_const(const ALLEGRO_CONFIG* config, const char* section, const char* key);
float ogle_config_get_float_const(const ALLEGRO_CONFIG* config, const char* section, const char* key);
double ogle_config_get_double_const(const ALLEGRO_CONFIG* config, const char* section, const char* key);
const char* ogle_config_get_string_const(const ALLEGRO_CONFIG* config, const char* section, const char* key);

bool ogle_config_set_bool(ALLEGRO_CONFIG* config, const char* section, const char* key, bool value);
bool ogle_config_set_int8(ALLEGRO_CONFIG* config, const char* section, const char* key, int8_t value);
bool ogle_config_set_int16(ALLEGRO_CONFIG* config, const char* section, const char* key, int16_t value);
bool ogle_config_set_int32(ALLEGRO_CONFIG* config, const char* section, const char* key, int32_t value);
bool ogle_config_set_int64(ALLEGRO_CONFIG* config, const char* section, const char* key, int64_t value);
bool ogle_config_set_uint8(ALLEGRO_CONFIG* config, const char* section, const char* key, uint8_t value);
bool ogle_config_set_uint16(ALLEGRO_CONFIG* config, const char* section, const char* key, uint16_t value);
bool ogle_config_set_uint32(ALLEGRO_CONFIG* config, const char* section, const char* key, uint32_t value);
bool ogle_config_set_uint64(ALLEGRO_CONFIG* config, const char* section, const char* key, uint64_t value);
bool ogle_config_set_float(ALLEGRO_CONFIG* config, const char* section, const char* key, float value);
bool ogle_config_set_double(ALLEGRO_CONFIG* config, const char* section, const char* key, double value);
bool ogle_config_set_string(ALLEGRO_CONFIG* config, const char* section, const char* key, const char* value);


#endif // _HEADER_GUARD_OGLE_CONFIG_H_
