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
 * @brief   	Debug support configuration header
 * @addtogroup  base_dbg
 *********************************************************************//** @{ */
/**@defgroup    base_dbg_cfg Configuration
 * @brief       Debug support Configuration
 * @{ *//*--------------------------------------------------------------------*/

#ifndef NLIB_CONFIG_H_
#define NLIB_CONFIG_H_

/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  DEFINES  ==*/
/*==============================================================  SETTINGS  ==*/

/**@brief       Scheduler priority levels
 * @details     Possible values:
 *              - Min: 3 (three priority levels)
 *              - Max: 256
 */
#if !defined(CONFIG_PRIORITY_LEVELS)
# define CONFIG_PRIORITY_LEVELS             32u
#endif

#if !defined(CONFIG_PRIORITY_BUCKETS)
# define CONFIG_PRIORITY_BUCKETS            32u
#endif

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//** @} *//*********************************************
 * END of config.h
 ******************************************************************************/
#endif /* NLIB_CONFIG_H_ */
