/* 
 * File:   num_conv.h
 * Author: nenad
 *
 * Created on 01 December 2014, 23:56
 */

#ifndef NUM_CONV_H
#define NUM_CONV_H

#include <stdint.h>

#ifdef  __cplusplus
extern "C" {
#endif


uint8_t bcd_to_bin(
    uint8_t                     data);



uint8_t bcd_from_bin(
    uint8_t                     data);



uint32_t ascii_hex_to_bin(char hex);



char ascii_hex_from_bin(uint32_t bin);


#ifdef  __cplusplus
}
#endif

#endif  /* NUM_CONV_H */

