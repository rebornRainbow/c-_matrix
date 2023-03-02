#include "../include/hw1.h"

#include <random>
#include <iomanip>
#include <stdexcept>

Matrix algebra::zeros(size_t n,size_t m)
{
  Matrix res(n,std::vector<double>(m,0));
  return res;
}


Matrix algebra::ones(size_t n, size_t m)
{
  Matrix res(n,std::vector<double>(m,1));
  return res;
}


Matrix algebra::random(size_t n, size_t m, double min, double max)
{
  if(min > max)
  {
    throw std::invalid_argument("min can't larger than max");
    // return {};
  }
  std::default_random_engine generator;
  std::uniform_real_distribution<double> distribution(min,max);
  Matrix res = zeros(n,m);
  for(size_t ni = 0;ni < n;++ni)
    for(size_t  mi = 0; mi < m;++mi)
    {
      res[ni][mi] = distribution(generator);
    }
  return res;
} 


void algebra::show(const Matrix& matrix)
{
  std::cout<<std::setiosflags(std::ios::fixed);  
 for(auto & row : matrix)
 {
    for(auto & elem:row)
    {
      std::cout << std::setw(7) << std::setprecision(3) << elem ;
    }
  std::cout<< std::endl;
 }
}


Matrix algebra::multiply(const Matrix& matrix, double c)
{
  size_t n = matrix.size();
  size_t m = matrix[0].size();
  Matrix res = zeros(n,m);
  for(size_t ni = 0;ni < n;++ni)
    for(size_t  mi = 0; mi < m;++mi)
    {
      res[ni][mi] = matrix[ni][mi] * c;
    }
  return res;
}


/**
 * @brief 
 * mplement this function 
 * so that it multiplies the 
 * matrix1 into matrix2. (this 
 * is not an element-wise multiplication)
 */
Matrix algebra::multiply(const Matrix& matrix1, const Matrix& matrix2)
{
  if(matrix1[0].size() != matrix2.size())
  {
    
  }
}