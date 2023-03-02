#ifndef AP_HW1_H
#define AP_HW1_H
#include <iostream>
#include <vector>

using Matrix = std::vector<std::vector<double>>;

namespace algebra{

/**
 * @brief 
 * implement this function so that 
 * it will create a n x m matrix 
 * with all elements equal to zero
 * @param n 
 * @param m 
 * @return Matrix 
 */
Matrix zeros(size_t n, size_t m);


/**
 * @brief 
 * implement this function so that
 *  it will create a n x m matrix 
 * with all elements equal to one.
 * 
 * @param n 
 * @param m 
 * @param min 
 * @param max 
 * @return Matrix 
 */
Matrix ones(size_t n, size_t m);

/**
 * @brief 
 * implement this function so that
 *  it will create a n x m matrix 
 * with all elements equal to random double 
 * between min and max.
 * @param n 
 * @param m 
 * @param min 
 * @param max 
 * @return Matrix 
 */
Matrix random(size_t n, size_t m, double min, double max);


/**
 * @brief 
 * implement this function so that 
 * it will display the matrix in a 
 * beautiful way.
 * 
 * use<iomanip>library
 * @param matrix 
 */
void show(const Matrix& matrix);


/**
 * @brief 
 * mplement this function so that 
 * it multiplies the matrix into 
 * the constant scalar c.
 */
Matrix multiply(const Matrix& matrix, double c);


/**
 * @brief 
 * mplement this function 
 * so that it multiplies the 
 * matrix1 into matrix2. (this 
 * is not an element-wise multiplication)
 */
Matrix multiply(const Matrix& matrix1, const Matrix& matrix2);



}

#endif //AP_HW1_H
