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
 * @brief       Bit and logic operations implementation
 * @addtogroup  lib_bits
 *********************************************************************//** @{ */
/**@defgroup    lib_bits_impl Implementation
 * @brief       Bit and logic operations implementation
 * @{ *//*--------------------------------------------------------------------*/

/*=========================================================  INCLUDE FILES  ==*/

#include "lib/bits.h"

/*=========================================================  LOCAL MACRO's  ==*/
/*======================================================  LOCAL DATA TYPES  ==*/
/*=============================================  LOCAL FUNCTION PROTOTYPES  ==*/
/*=======================================================  LOCAL VARIABLES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*============================================  LOCAL FUNCTION DEFINITIONS  ==*/
/*===========================================  GLOBAL FUNCTION DEFINITIONS  ==*/

uint32_t n_log2_int(uint32_t v)
{
	static const unsigned char 	log_table_256[256] =
	{
		#define LT(n) n, n, n, n, n, n, n, n, n, n, n, n, n, n, n, n
	    (unsigned char)-1, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
	    LT(4), LT(5), LT(5), LT(6), LT(6), LT(6), LT(6),
	    LT(7), LT(7), LT(7), LT(7), LT(7), LT(7), LT(7), LT(7)
	};
	unsigned int				r;
	register unsigned int 		t;
	register unsigned int		tt;

	if ((tt = v) >> 16) {
	  r = ((t = tt) >> 8u) ? 24u + log_table_256[t] : 16u + log_table_256[tt];
	} else {
	  r = ((t = v)  >> 8u) ? 8u  + log_table_256[t] :      log_table_256[v];
	}

	return (r);
}


/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//** @} *//*********************************************
 * END of bits.c
 ******************************************************************************/
