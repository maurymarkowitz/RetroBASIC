/* matrix (header) for RetroBASIC
   Copyright (C) 2024 Maury Markowitz

This file is part of RetroBASIC.

RetroBASIC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

RetroBASIC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with RetroBASIC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/**
 * @file matrix.h
 * @author Maury Markowitz
 * @date 11 May 2024
 *
 * @title Dartmouth-style matrix functions
 * @brief Basic matrix math and various work methods for MAT statements
 *
 * This code includes a number of work methods for common matrix math like
 * multiplication or transposing. The key difference between these methods and
 * the many stock ones found on the 'net is that these work on 1..n as opposed
 * to a normal C array which is 0..n-1. This matches the way Dartmouth BASIC
 * organizes its arrays.
 *
 */

#ifndef matrix_h
#define matrix_h

void transpose(int size, int source[][size], int dest[][size]);

#endif /* matrix_h */
