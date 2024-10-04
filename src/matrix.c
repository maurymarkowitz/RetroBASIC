/* matrix (implementation) for RetroBASIC
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

#include "matrix.h"

#include <math.h>

void matrix_fill(int size, double destination[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE], double fill_value)
{
  for (int i = 1; i <= size; i++)
    for (int j = 1; j <= size; j++)
      destination[i][j] = fill_value;
}

void matrix_copy(int size,
                 double destination[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE],
                 double source[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE])
{
  for (int i = 1; i <= size; i++)
    for (int j = 1; j <= size; j++)
      destination[i][j] = source[i][j];
}

void matrix_add(int size,
                double destination[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE],
                double addend1[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE],
                double addend2[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE])
{
  for (int i = 1; i <= size; i++)
    for (int j = 1; j <= size; j++)
      destination[i][j] = addend1[i][j] + addend2[i][j];
}

void matrix_sub(int size,
                double destination[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE],
                double minuend[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE],
                double subtrahend[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE])
{
  for (int i = 1; i <= size; i++)
    for (int j = 1; j <= size; j++)
      destination[j][i] = minuend[i][j] - subtrahend[i][j];
}

void matrix_mul(int size,
                double destination[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE],
                double multiplicand[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE],
                double multiplier[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE])
{
  for (int i = 1; i <= size; i++)
    for (int j = 1; j <= size; j++)
      destination[j][i] = multiplicand[i][j] * multiplier[i][j];
}

void matrix_mul_const(int size, double matrix[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE], double multiplier)
{
  for (int i = 1; i <= size; i++)
    for (int j = 1; j <= size; j++)
      matrix[j][i] *= matrix[i][j];
}

void matrix_transpose(int size, double matrix[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE])
{
  double temp[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE];
  
  // transpose the matrix into temp
  for (int i = 1; i <= size; i++)
    for (int j = 1; j <= size; j++)
      temp[j][i] = matrix[i][j];
  
  // copy it back
  for (int i = 1; i <= size; i++)
    for (int j = 1; j <= size; j++)
      matrix[i][j] = temp[i][j];
}

int martix_invert(int size, double matrix[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE], double inverse[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE]) {
  double augmented[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE * 2];
  
  // initialize the augmented matrix
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++)
      augmented[i][j] = matrix[i][j];

    for (int j = 0; j < size; j++)
      if (i == j)
        augmented[i][j + size] = 1;  // identity matrix
      else
        augmented[i][j + size] = 0;
  }
  
  // gaussian elimination
  for (int i = 0; i < size; i++) {
    // find the maximum value in this column
    double maxEl = fabs(augmented[i][i]);
    int maxRow = i;
    for (int k = i + 1; k < size; k++) {
      if (fabs(augmented[k][i]) > maxEl) {
        maxEl = fabs(augmented[k][i]);
        maxRow = k;
      }
    }
    
    // swap maximum row with current row
    for (int k = i; k < size * 2; k++) {
      double tmp = augmented[maxRow][k];
      augmented[maxRow][k] = augmented[i][k];
      augmented[i][k] = tmp;
    }
    
    // make the diagonal contain all 1s
    double diagEl = augmented[i][i];
    
    // if any of the values are 0, fail out
    if (diagEl == 0)
      return -1;
    
    // if not, divide it
    for (int k = 0; k < size * 2; k++) {
      augmented[i][k] /= diagEl;
    }
    
    // make the other rows contain 0s
    for (int k = 0; k < size; k++) {
      if (k != i) {
        double factor = augmented[k][i];
        for (int j = 0; j < size * 2; j++) {
          augmented[k][j] -= factor * augmented[i][j];
        }
      }
    }
  }
  
  // and extract the right half as the inverse matrix
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      inverse[i][j] = augmented[i][j + size];
    }
  }
  
  // we succeeded, return 0
  return 0;
}

// private function to get the cofactor of a matrix
void matrix_cofactor(int size, double matrix[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE], double cofactor[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE], int p, int q) {
  int i = 0, j = 0;
  
  // loop through the matrix and create cofactor
  for (int row = 0; row < size; row++)
    for (int col = 0; col < size; col++)
      // skip the current row and column
      if (row != p && col != q) {
        cofactor[i][j++] = matrix[row][col];
        if (j == size - 1) {
          j = 0;
          i++;
        }
      }
}

double matrix_determinant(int size, double matrix[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE]) {
  double det = 0;
  
  // simple cases for 1x1 and 2x2 matrix
  if (size == 1)
    return matrix[0][0];
  if (size == 2)
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
  
  // it's larger, so we recurse across it
  double cofactor[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE];
  for (int f = 0; f < size; f++) {
    matrix_cofactor(size, matrix, cofactor, 0, f);
    det += (f % 2 == 0 ? 1 : -1) * matrix[0][f] * matrix_determinant(size - 1, cofactor);
  }
  
  return det;
}

