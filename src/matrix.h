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
 * organizes its arrays. Items are allowed in the 0 indexes, but are ignored
 * in this code, which, like Dartmouth, can result in odd output when not
 * expected.
 *
 */

#ifndef matrix_h
#define matrix_h

/**
 * Dartmouth can have a maximum matrix size of 32k, so we'll allow 200x200 in this code.
*/
#define MATRIX_MAX_SIZE 200

/**
 * Fills the source matrix with a given double value. Used for ZER and CON.
 *
 * @param matrix the matrix to fill.
 * @param fill_value the value to fill it with.
*/
void matrix_fill(int size,
                 double destination[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE],
                 double fill_value);

/**
 * Copies the values in the source matrix to the destination matrix.
 *
 * @param size the actual dimensions of the source array.
 * @param destination the destination matrix the values will be copied into.
 * @param source the source matrix.
*/
void matrix_copy(int size,
                 double destination[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE],
                 double source[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE]);

/**
 * Adds the values in one array to the values already in another.
 *
 * @param size the actual dimensions of the resulting array.
 * @param matrix the destination matrix.
 * @param addend the source matrix the addition values will be taken from.
*/
void matrix_add(int size,
                double destination[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE],
                double addend1[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE],
                double addend2[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE]);

/**
 * Subtracts the values in one array from the values already in another.
 *
 * @param size the actual dimensions of the resulting array.
 * @param matrix the destination matrix.
 * @param subtrahend the source matrix the subtraction values will be taken from.
*/
void matrix_sub(int size,
                double destination[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE],
                double minuend[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE],
                double subtrahend[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE]);

/**
 * Multiplies the values in one array by the values in another.
 *
 * @param size the actual dimensions of the resulting array.
 * @param matrix the destination matrix.
 * @param multiplier the source matrix the multiplier values will be taken from.
*/
void matrix_mul(int size,
                double destination[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE],
                double multiplicand[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE],
                double multiplier[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE]);

/**
 * Multiplies the values in a matrix by a double value.
 *
 * @param size the actual dimensions of the resulting array.
 * @param matrix the destination matrix.
 * @param multiplier the multiplier value.
*/
void matrix_mul_const(int size,
                      double matrix[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE],
                      double multiplier);

/**
 * Transposes a matrix.
 *
 * @param size the actual dimensions of the resulting array.
 * @param matrix the destination matrix.
*/
void transpose(int size,
               int source[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE]);

/**
 * Inverts a matrix.
 *
 * Unlike the other functions in this library, inverting an array is almost always then used to
 * modify the original array, so when this function is used the original will generally need
 * to be left in the original form.
 *
 * Additionally, this function can fail, so it returns an integer value.
 *
 * @param size the actual dimensions of the resulting array.
 * @param matrix the matrix to invert matrix.
 * @param inverse the resulting inverted matrix.
 * @return 0 for success, non-zero for failure (currently only -1 is used).
*/
int martix_invert(int size,
                  double matrix[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE],
                  double inverse[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE]);

/**
 * Calculates the determinant of a matrix.
 *
 * @param size the actual dimensions of the resulting array.
 * @param matrix the matrix to calculate the determinant of.
 * @return the determinant.
*/
double matrix_determinant(int size,
                          double matrix[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE]);
    
#endif /* matrix_h */
