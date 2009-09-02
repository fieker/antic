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
/****************************************************************************

   Copyright (C) 2009 William Hart

*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <mpir.h>
#include "flint.h"
#include "ulong_extras.h"

int main(void)
{
   int result;
   printf("mod2_preinv....");
   fflush(stdout);

   for (ulong i = 0; i < 1000000UL; i++)
   {
      mp_limb_t d, dinv, n, r1, r2, norm;

      d = n_randtest_not_zero();
      n = n_randtest();
      
      dinv = n_preinvert_limb(d);

      r1 = n_mod2_preinv(n, d, dinv);
      r2 = n%d;

      result = (r1 == r2);

      if (!result)
      {
         printf("FAIL\n");
         printf("n = %lu, d = %lu, dinv = %lu\n", n, d, dinv); 
         printf("r1 = %lu, r2 = %lu\n", r1, r2);
         abort();
      }
   }

   printf("PASS\n");
   return 0;
}