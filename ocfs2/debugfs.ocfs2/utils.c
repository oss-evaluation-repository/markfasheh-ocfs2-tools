/*
 * utils.c
 *
 * utility functions
 *
 * Copyright (C) 2004 Oracle.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 021110-1307, USA.
 *
 * Authors: Sunil Mushran
 */

#include <main.h>
#include <commands.h>
#include <dump.h>
#include <readfs.h>
#include <utils.h>

/*
 * add_extent_rec()
 *
 */
void add_extent_rec (GArray *arr, ocfs2_extent_rec *rec)
{
	ocfs2_extent_rec *new;

	if (!arr)
		return ;

	if (!(new = malloc(sizeof(ocfs2_extent_rec))))
		DBGFS_FATAL();

	memcpy(new, rec, sizeof(ocfs2_extent_rec));
	g_array_append_vals(arr, new, 1);

	return ;
}				/* add_extent_rec */