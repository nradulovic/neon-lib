/*
 * checksum.c
 *
 *  Created on: Mar 18, 2016
 *      Author: nenad
 */

#include "lib/checksum.h"

uint8_t nchecksum_of(const void * data, size_t size)
{
	unsigned int				checksum_;
	unsigned int				idx;
	const uint8_t	*			data_ = data;

	for (checksum_ = 0, idx = 0; idx < size; idx++) {
		checksum_ += *data_++;
	}

	return ((uint8_t)-(int8_t)checksum_);
}
