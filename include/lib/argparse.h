/*
 * This file is part of Neon.
 *
 * Copyright (C) 2010 - 2016 Nenad Radulovic
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
 * @brief       Argument parsing for main() function
 * @addtogroup  argparse_intf
 *********************************************************************//** @{ */

#ifndef NEON_LIB_INCLUDE_LIB_ARGPARSE_H_
#define NEON_LIB_INCLUDE_LIB_ARGPARSE_H_

/*=========================================================  INCLUDE FILES  ==*/

#include "base/error.h"

/*===============================================================  MACRO's  ==*/
/*------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*============================================================  DATA TYPES  ==*/

struct argparse;

struct argparse_argument;

enum argparse_type
{
	ARGPARSE_NONE,
	ARGPARSE_INT,
	ARGPARSE_STRING
};

/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/

struct argparse * argparse_create(int argc, char ** argv, const char * prog_name, const char * description);

void argparse_destroy(struct argparse * argparse);

nerror argparse_parse_all(struct argparse * argparse);

nerror argparse_add_argument(struct argparse * argparse, const char * name, const char * description, enum argparse_type type);

nerror argparse_get_argument(struct argparse * argparse, const char * name, void * data);

/*--------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of argparse.h
 ******************************************************************************/
#endif /* NEON_LIB_INCLUDE_LIB_ARGPARSE_H_ */

