/*
 * This file is part of eSolid.
 *
 * Copyright (C) 2010 - 2013 Nenad Radulovic
 *
 * eSolid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * eSolid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with eSolid.  If not, see <http://www.gnu.org/licenses/>.
 *
 * web site:    http://github.com/nradulovic
 * e-mail  :    nenad.b.radulovic@gmail.com
 *//***********************************************************************//**
 * @file
 * @author  	Nenad Radulovic
 * @brief       Base module header
 * @defgroup    base Base
 * @brief       Debugging support
 *********************************************************************//** @{ */
/**@defgroup    base_intf Interface
 * @brief       Base API
 * @{ *//*--------------------------------------------------------------------*/

#ifndef NMODULE_H_
#define NMODULE_H_

/*=========================================================  INCLUDE FILES  ==*/

#include "plat/compiler.h"
#include "lib/error.h"

/*===============================================================  MACRO's  ==*/

/**@brief       Declare a module information
 * @param       name
 *              Module name : string
 * @param       description
 *              Module description : string
 * @param       author
 *              Module author : string
 * @api
 */
#define NMODULE_INFO_CREATE(description, author)                                \
    PORT_C_ROM struct PORT_C_UNUSED nmodule_info g_module_info =                \
    {                                                                           \
        description,                                                            \
        author,                                                                 \
        PORT_C_FILE                                                             \
    }

/*------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*============================================================  DATA TYPES  ==*/

/**@brief       Defines module information structure
 * @api
 */
struct nmodule_info
{
    const PORT_C_ROM char * const PORT_C_ROM_VAR desc;      
                                        /**<@brief Module description         */
    const PORT_C_ROM char * const PORT_C_ROM_VAR auth;
                                        /**<@brief Module author              */
    const PORT_C_ROM char * const PORT_C_ROM_VAR file;
                                        /**<@brief Module source file         */
};

/*======================================================  GLOBAL VARIABLES  ==*/

extern PORT_C_UNUSED const PORT_C_ROM struct nmodule_info g_unnamed_module;

/*===================================================  FUNCTION PROTOTYPES  ==*/
/*--------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//** @} *//*********************************************
 * END of base.h
 ******************************************************************************/
#endif /* NMODULE_H_ */
