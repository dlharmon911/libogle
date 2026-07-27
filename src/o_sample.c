#include "libogle/o_common.h"
#include "libogle/o_log.h"
#include "libogle/o_sample.h"

int32_t ogle_sample_create(o_sample_t** sample, const o_sample_data_t* data)
{
	if (NULL == sample)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Texture pointer is null.");
		return -1;
	}

	if (NULL == data)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Texture data pointer is null.");
		return -1;
	}

	if (NULL == data->m_filename)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Sample filename is null.");
		return -1;
	}

	*sample = al_load_sample(data->m_filename);

	if (NULL == *sample)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Failed to load sample from filename: %s", data->m_filename);
		return -1;
	}

	return 0;
}



void ogle_sample_destroy(o_sample_t* sample)
{
	if (sample)
	{
		al_destroy_sample(sample);
	}
}