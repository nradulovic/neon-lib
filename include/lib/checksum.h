/*
 * checksum.h
 *
 *  Created on: Mar 18, 2016
 *      Author: nenad
 */

#ifndef NEON_LIB_INCLUDE_LIB_CHECKSUM_H_
#define NEON_LIB_INCLUDE_LIB_CHECKSUM_H_

#include <stddef.h>
#include <stdint.h>

uint8_t nchecksum_of(const void * data, size_t size);

#endif /* NEON_LIB_INCLUDE_LIB_CHECKSUM_H_ */
