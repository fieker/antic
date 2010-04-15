/*============================================================================

    This file is part of FLINT.

    FLINT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    FLINT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FLINT; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

===============================================================================*/
/******************************************************************************

 Copyright (C) 2010 William Hart
 
******************************************************************************/

#ifndef FMPZ_MAT_H
#define FMPZ_MAT_H

#include <mpir.h>
#include "fmpz.h"

typedef struct
{
   fmpz * entries;
   ulong r;
   ulong c;
   fmpz ** rows;
} fmpz_mat_struct;

// fmpz_mat_t allows reference-like semantics for fmpz_mat_struct
typedef fmpz_mat_struct fmpz_mat_t[1];

void fmpz_mat_init(fmpz_mat_t mat, ulong rows, ulong cols);

void fmpz_mat_clear(fmpz_mat_t mat);

void fmpz_mat_print(fmpz_mat_t mat); 

void fmpz_mat_print_pretty(fmpz_mat_t mat);

void fmpz_mat_randtest(fmpz_mat_t mat, mp_bitcnt_t bits_in);

#endif





