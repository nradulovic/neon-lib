
#include "lib/string/num_conv.h"

uint8_t bcd_to_bin(
    uint8_t                     data)
{
    uint8_t                     ret;
    
    ret = data & 0xfu;
    ret = (uint8_t)(ret + ((data >> 4u) * 10u));

    return (ret);
}

uint8_t bin_to_bcd(
    uint8_t                     data)
{
    uint8_t                     ret;

    ret = ((data / 10) & 0xfu) << 4;
    ret = (uint8_t)(ret | ((data % 10) & 0xfu) << 0);

    return (ret);
}
