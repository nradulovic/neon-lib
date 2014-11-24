/*
 * This file is part of Neon RT Kernel.
 *
 * Copyright (C) 2010 - 2014 Nenad Radulovic
 *
 * Neon RT Kernel is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Neon RT Kernel is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Neon RT Kernel.  If not, see <http://www.gnu.org/licenses/>.
 *
 * web site:    http://github.com/nradulovic
 * e-mail  :    nenad.b.radulovic@gmail.com
 *//***********************************************************************//**
 * @file
 * @author      Nenad Radulovic
 * @brief       Generic queue header
 * @defgroup    generic_queue Generic queue
 * @brief       Generic queue
 *********************************************************************//** @{ */

#ifndef NLIB_QUEUE_H_
#define NLIB_QUEUE_H_

/*=========================================================  INCLUDE FILES  ==*/

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include <common/compiler.h>

/*===============================================================  MACRO's  ==*/

#define NQUEUE_SIZEOF(elements)             (sizeof(void * [1]) * (elements))

/*-------------------------------------------------------  C++ extern base  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*============================================================  DATA TYPES  ==*/

/**@brief       Queue structure
 * @api
 */
struct nqueue
{
    void **             buffer;
    uint32_t            head;
    uint32_t            tail;
    uint32_t            empty;
    uint32_t            size;
};

typedef struct nqueue nqueue;

/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/


PORT_C_INLINE 
void nqueue_init(
    struct nqueue *             queue,
    void **                     buffer,
    size_t                      size)
{
    queue->buffer = buffer;
    queue->head   = UINT32_C(0);
    queue->tail   = UINT32_C(0);
    queue->empty  = (uint32_t)size;
    queue->size   = (uint32_t)size;
}



PORT_C_INLINE 
void nqueue_term(
    struct nqueue *             queue)
{
    queue->buffer = NULL;
    queue->head   = UINT32_C(0);
    queue->tail   = UINT32_C(0);
    queue->empty  = UINT32_C(0);
    queue->size   = UINT32_C(0);
}



PORT_C_INLINE 
void nqueue_put_head(
    struct nqueue *             queue,
    void *                      item)
{
    queue->buffer[queue->head++] = item;

    if (queue->head == queue->size) {
        queue->head = UINT32_C(0);
    }
    queue->empty--;
}



PORT_C_INLINE 
void nqueue_put_tail(
    struct nqueue *             queue,
    void *                      item)
{
    if (queue->tail == UINT32_C(0)) {
        queue->tail = queue->size;
    }
    queue->buffer[--queue->tail] = item;
    queue->empty--;
}



PORT_C_INLINE 
void * nqueue_get_tail(
    struct nqueue *             queue)
{
    void *                      tmp;

    tmp = queue->buffer[queue->tail++];

    if (queue->tail == queue->size) {
        queue->tail = UINT32_C(0);
    }
    queue->empty++;

    return (tmp);
}



PORT_C_INLINE 
size_t nqueue_size(
    const struct nqueue *       queue)
{
    return ((size_t)queue->size);
}



PORT_C_INLINE 
size_t nqueue_occupied(
    const struct nqueue *       queue)
{
    return ((size_t)(queue->size - queue->empty));
}



PORT_C_INLINE 
size_t nqueue_unoccupied(
    const struct nqueue *       queue)
{
    return ((size_t)queue->empty);
}



PORT_C_INLINE 
void ** nqueue_buffer(
    const struct nqueue *       queue)
{
    return (queue->buffer);
}



PORT_C_INLINE 
bool nqueue_is_full(
    const struct nqueue *       queue)
{
    if (queue->empty == UINT32_C(0)) {
        return (true);
    } else {
        return (false);
    }
}



PORT_C_INLINE 
bool nqueue_is_empty(
    const struct nqueue *       queue)
{
    if (queue->empty == queue->size) {
        return (true);
    } else {
        return (false);
    }
}

/*--------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of queue.h
 ******************************************************************************/
#endif /* NLIB_QUEUE_H_ */
