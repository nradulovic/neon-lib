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
 * @addtogroup  argparse_impl
 *********************************************************************//** @{ */
/*=========================================================  INCLUDE FILES  ==*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "lib/argparse.h"
#include "base/list.h"
#include "mm/mem.h"

/*=========================================================  LOCAL MACRO's  ==*/
/*======================================================  LOCAL DATA TYPES  ==*/

struct argparse
{
	struct ndlist 				list;
	char * 						prog_name;
	char *						description;
	int							argc;
	char **						argv;
};

struct argument
{
	struct ndlist 				list;
	char *						name;
	char *						description;
	enum argparse_type			type;
};

/*=============================================  LOCAL FUNCTION PROTOTYPES  ==*/
/*=======================================================  LOCAL VARIABLES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*============================================  LOCAL FUNCTION DEFINITIONS  ==*/



static
struct argument * ndlist_to_argument(const struct ndlist * list)
{
	return (PORT_C_CONTAINER_OF(list, struct argument, list));
}

/*===========================================  GLOBAL FUNCTION DEFINITIONS  ==*/

struct argparse * argparse_create(int argc, char ** argv, const char * prog_name, const char * description)
{
	struct argparse *			argparse;
	nerror						error;

	argparse = nmem_zalloc(NMEM_GENERIC_HEAP, sizeof(struct argparse));

	if (!argparse) {
		goto ERR_ALLOC_ARGPARSE;
	}
	argparse->prog_name = nmem_alloc(NMEM_GENERIC_HEAP, strlen(prog_name));

	if (!argparse->prog_name) {
		goto ERR_ALLOC_NAME;
	}
	strcpy(argparse->prog_name, prog_name);


	if (description) {
		argparse->description = nmem_alloc(NMEM_GENERIC_HEAP, strlen(description));

		if (!argparse->description) {
			goto ERR_ALLOC_DESCRIPTION;
		}
		strcpy(argparse->description, description);
	}
	ndlist_init(&argparse->list);
	argparse->argc = argc;
	argparse->argv = argv;

	error = argparse_add_argument(argparse, "-h", "Print this help screen", ARGPARSE_NONE);

	if (error) {
		goto ERR_ALLOC_HELP;
	}

	return (argparse);

ERR_ALLOC_HELP:

	if (argparse->description) {
		nmem_free(NMEM_GENERIC_HEAP, argparse->description);
	}
ERR_ALLOC_DESCRIPTION:
	nmem_free(NMEM_GENERIC_HEAP, argparse->prog_name);
ERR_ALLOC_NAME:
	nmem_free(NMEM_GENERIC_HEAP, argparse);
ERR_ALLOC_ARGPARSE:

	return (NULL);
}



void argparse_destroy(struct argparse * argparse)
{
	struct ndlist *				current;

	current = ndlist_next(&argparse->list);

	while (current != &argparse->list) {
		struct argument *		argument;

		argument = ndlist_to_argument(current);
		current = ndlist_next(current);

		if (argument->description) {
			nmem_free(NMEM_GENERIC_HEAP, argument->description);
		}
		nmem_free(NMEM_GENERIC_HEAP, argument->name);
		nmem_free(NMEM_GENERIC_HEAP, argument);

	}

	if (argparse->description) {
		nmem_free(NMEM_GENERIC_HEAP, argparse->description);
	}
	nmem_free(NMEM_GENERIC_HEAP, argparse->prog_name);
	nmem_free(NMEM_GENERIC_HEAP, argparse);
}




nerror argparse_parse_all(struct argparse * argparse)
{
	nerror						error;

	/*
	 * TODO: This function should check if command line is well formated.
	 *       For now, only check if -h is there
	 */

	error = argparse_get_argument(argparse, "-h", NULL);

	if (!error) {
		struct argument *			argument;
		struct ndlist *				current;
		/*
		 * Option -h was given, print all information
		 */
		fprintf(stdout, "\n%s\n", argparse->prog_name);

		if (argparse->description) {
			fprintf(stdout, "\n%s\n", argparse->description);
		}
		fprintf(stdout, "\n");

		current = ndlist_next(&argparse->list);

		while (current != &argparse->list) {
			uint32_t			len;
			char 				local_buff[100];

			argument = ndlist_to_argument(current);

			memset(local_buff, 0, sizeof(local_buff));
			sprintf(local_buff, "%s", argument->name);

			switch (argument->type) {
				case ARGPARSE_INT: {
					sprintf(&local_buff[strlen(local_buff)], " N");
					break;
				}
				case ARGPARSE_STRING: {
					sprintf(&local_buff[strlen(local_buff)], " [...]");
					break;
				}
				default: {
					break;
				}
			}
			len = strlen(local_buff);

			if (len < 30) {
				memset(&local_buff[len], ' ', 30 - len);
			}

			if (argument->description) {
				sprintf(&local_buff[strlen(local_buff)], "%s", argument->description);
			}
			fprintf(stdout, "    %s\n", local_buff);
			current = ndlist_next(current);
		}
		fprintf(stdout, "\n");

		exit(0);
	}

	return (NERROR_NONE);
}



nerror argparse_add_argument(struct argparse * argparse, const char * name, const char * description, enum argparse_type type)
{
	nerror						error;

	struct argument	*			argument;

	argument = nmem_zalloc(NMEM_GENERIC_HEAP, sizeof(*argument));

	if (!argument) {
		error = NERROR_NO_MEMORY;
		goto ERR_ALLOC_ARGUMENT;
	}
	argument->name = nmem_alloc(NMEM_GENERIC_HEAP, strlen(name));

	if (!argument->name) {
		error = NERROR_NO_MEMORY;
		goto ERR_ALLOC_NAME;
	}
	strcpy(argument->name, name);

	if (description) {
		argument->description = nmem_zalloc(NMEM_GENERIC_HEAP, strlen(description));

		if (!argument->description) {
			error = NERROR_NO_MEMORY;
			goto ERR_ALLOC_DESCRIPTION;
		}
		strcpy(argument->description, description);
	}
	argument->type = type;

	ndlist_init(&argument->list);
	ndlist_add_before(&argparse->list, &argument->list);

	return (NERROR_NONE);

ERR_ALLOC_DESCRIPTION:
	nmem_free(NMEM_GENERIC_HEAP, argument->name);
ERR_ALLOC_NAME:
	nmem_free(NMEM_GENERIC_HEAP, argument);
ERR_ALLOC_ARGUMENT:

	return (error);
}



nerror argparse_get_argument(struct argparse * argparse, const char * name, void * data)
{
	struct argument *			argument;
	struct ndlist *				current;
	nerror						error;
	int							idx;
	int							name_idx;

	current = ndlist_next(&argparse->list);

	while (current != &argparse->list) {
		if (strcmp(ndlist_to_argument(current)->name, name) == 0) {
			break;
		}
		current = ndlist_next(current);
	}

	if (current == &argparse->list) {
		error = NERROR_NOT_FOUND;
		goto ERR_NOT_FOUND;
	}
	argument = ndlist_to_argument(current);

	for (name_idx = 0, idx = 0; idx < argparse->argc; idx++) {
		if (strcmp(argparse->argv[idx], name) == 0) {
			name_idx = idx;
			break;
		}
	}

	if (name_idx) {
		int 					val_idx;

		val_idx = name_idx + 1;

		if (val_idx <= argparse->argc) {
			switch (argument->type) {
				case ARGPARSE_INT: {
					int * data_ = data;

					*data_ = atoi(argparse->argv[val_idx]);
					break;
				}
				case ARGPARSE_STRING: {
					char * data_ = data;

					strcpy(data_, argparse->argv[val_idx]);

					break;
				}
				default: {
					break;
				}
			}

			return (NERROR_NONE);
		}
	}

	return (NERROR_NO_RESOURCE);

ERR_NOT_FOUND:

	return (error);
}

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//***************************************************************
 * END of main.c
 ******************************************************************************/
