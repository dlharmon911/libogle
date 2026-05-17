#include "libogle/o_common.h"
#include "libogle/o_utilities.h"

void ogle_utilities_swap_bytes(void* data, size_t size)
{
    uint8_t* bytes = (uint8_t*)data;
    for (size_t i = 0; i < size / 2; ++i)
    {
        uint8_t temp = bytes[i];
        bytes[i] = bytes[size - 1 - i];
        bytes[size - 1 - i] = temp;
    }
}
