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
    return {};
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
  if(matrix1.size() == 0)
  {
    return Matrix{};
  }
  else if(matrix1[0].size() != matrix2.size())
  {
    throw std::logic_error("矩阵的乘法需要m1列数要和m2的行数一致");
    return Matrix{};
  }
  size_t n = matrix1.size();
  size_t m = matrix2[0].size();
  size_t t = matrix2.size();
  Matrix res = zeros(n,m);
  for(size_t ni = 0;ni < n;++ni)
    for(size_t  mi = 0; mi < m;++mi)
      for(size_t ti = 0;ti < t;++ti)
        res[ni][mi] += matrix1[ni][ti]*matrix2[ti][mi];

  return res;

}


Matrix algebra::sum(const Matrix& matrix, double c)
{
  size_t n = matrix.size();
  if(n == 0)
  {
    return Matrix{};
  }
  size_t m = matrix[0].size();
  Matrix res = zeros(n,m);
  for(size_t ni = 0;ni < n;++ni)
    for(size_t  mi = 0; mi < m;++mi)
    {
      res[ni][mi] = matrix[ni][mi] + c;
    }

  return res;
}


Matrix algebra::sum(const Matrix& matrix1, const Matrix& matrix2)
{

  size_t n1 = matrix1.size();
  size_t n2 = matrix2.size();

  
  if(n1 != n2)
  {
    throw std::logic_error("参数错误，相加的矩阵形状要一致");
    return Matrix{};
  }
  if(n1 == 0)
  {
    return Matrix{};
  }
  size_t m1 = matrix1[0].size();
  size_t m2 = matrix2[0].size();

  if( m1!=m2)
  {
    throw std::logic_error("参数错误，相加的矩阵形状要一致");
    return Matrix{};
  }

  Matrix res = zeros(n1,m1);
  for(size_t ni = 0;ni < n1;++ni)
    for(size_t  mi = 0; mi < m1;++mi)
    {
      res[ni][mi] = matrix1[ni][mi]+matrix2[ni][mi];
    }

  return res;
}


Matrix algebra::transpose(const Matrix& matrix)
{
  size_t n = matrix.size();
  if(n == 0)
  {
    return Matrix{};
  }
  size_t m = matrix[0].size();
  Matrix res = zeros(m,n);
  for(size_t ni = 0;ni < n;++ni)
    for(size_t  mi = 0; mi < m;++mi)
    {
      res[mi][ni] = matrix[ni][mi];
    }
  return res;
}

Matrix algebra::minor(const Matrix& matrix, size_t nr, size_t mc)
{
  size_t n = matrix.size();
  if(n == 0)
  {
    return Matrix{};
  }
  size_t m = matrix[0].size();

  Matrix res = zeros(n-1,m-1);
  //创建代数余子式
  for(size_t ni = 0,rn = 0;ni < n;++ni)
  { //去掉nr行
    if(ni == nr)
      continue;
    for(size_t  mi = 0,rm = 0; mi < m;++mi)
    {
      //去掉mc列
      if(mi == mc)
        continue;
      else
        res[rn][rm++] = matrix[ni][mi];
    }
    ++rn;
  }
  return res;

}




