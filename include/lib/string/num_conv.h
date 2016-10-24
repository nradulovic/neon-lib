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



/**@brief       Convert a lower case HEX character to a binary value
 * @details     If a non-HEX character is given the function will return -1 
 *              casted to uint32_t type.
 * @note        The function works only on lower case HEX characters. Use 
 *              tolower() standard C function for upper case HEX characters.
 * @api
 */
uint32_t ascii_hex_to_bin(char hex);



/**@brief       Convert a binary number [0-15] to a lower case HEX character
 * @details     If a number greater than 15 is given the function will return 
 *              zero.
 * @api
 */
char ascii_hex_from_bin(uint32_t bin);


#ifdef  __cplusplus
}
#endif

#endif  /* NUM_CONV_H */

