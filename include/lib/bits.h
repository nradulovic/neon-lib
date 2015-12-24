/*
 * This file is part of Neon.
 *
 * Copyright (C) 2010 - 2015 Nenad Radulovic
 *
 * Neon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Neon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Neon.  If not, see <http://www.gnu.org/licenses/>.
 *
 * web site:    http://github.com/nradulovic
 * e-mail  :    nenad.b.radulovic@gmail.com
 *//***********************************************************************//**
 * @file
 * @author      Nenad Radulovic
 * @brief       Bit and logic operations
 * @addtogroup  lib_intf
 *********************************************************************//** @{ */
/**@defgroup    lib_bits Bit and logic operations
 * @brief       Bit and logic operations
 * @{ *//*--------------------------------------------------------------------*/

#ifndef NEON_LIB_INCLUDE_LIB_BITS_H_
#define NEON_LIB_INCLUDE_LIB_BITS_H_

/*=========================================================  INCLUDE FILES  ==*/

#include <stdint.h>

/*===============================================================  MACRO's  ==*/
/*------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*============================================================  DATA TYPES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/


/**@brief		Compute logarithm base 2 of v value
 * @param 		v
 * @return		Log2(v)
 * @details		If v equals zero the returned value will be 255.
 */
uint32_t n_log2_int(uint32_t v);

/*--------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//** @} *//*********************************************
 * END of bits.h
 ******************************************************************************/
#endif /* NEON_LIB_INCLUDE_LIB_BITS_H_ */
