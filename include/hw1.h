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




/**
 * @brief 
 * implement this function so that 
 * it adds the constant number c to 
 * every element of matrix.
 * @param matrix 
 * @param c 
 * @return Matrix 
 */
Matrix sum(const Matrix& matrix, double c);



/**
 * @brief 
 * implement this function so that it 
 * adds 2 matrices to each other.
 * @param matrix1 
 * @param matrix2 
 * @return Matrix 
 */
Matrix sum(const Matrix& matrix1, const Matrix& matrix2);



/**
 * @brief 
 * transpose implement this function so 
 * that it will generate the transpose 
 * matrix of the input matrix.
 * @param matrix 
 * @return Matrix 
 */
Matrix transpose(const Matrix& matrix);



/**
 * @brief 
 * minor implement this function so that 
 * it will create the minor of the input 
 * matrix with respect to nth row and 
 * mth column.
 * @param matrix 
 * @param n 
 * @param m 
 * @return Matrix 
 */
Matrix minor(const Matrix& matrix, size_t n, size_t m);



/**
 * @brief 
 * determinant implement this function so
 *  that it calculates the determinant of
 *  the input matrix.
 * @param matrix 
 * @return double 
 */
double determinant(const Matrix& matrix);


}
#endif //AP_HW1_H
