
#include "lib/num_conv.h"

uint8_t bcd_to_bin(
    uint8_t                     data)
{
    uint8_t                     retval;
    
    retval  =   data & 0xfu;
    retval += ((data >> 4u) & 0xfu) * 10u;

    return (retval);
}

uint8_t bin_to_bcd(
    uint8_t                     data)
{
    uint8_t                     retval;

    retval  = ((data / 10) & 0xfu) << 4;
    retval |= ((data % 10) & 0xfu) << 0;

    return (retval);
}
