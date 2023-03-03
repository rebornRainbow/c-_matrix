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

//求代数余子式
double algebra::determinant(const Matrix& matrix)
{
  
  //使用递归的方式
  if(matrix.size() == 1&&matrix[0].size()==1)
  {
    return matrix[0][0];
  }else if(matrix.size() == 0)
  {
    return 1;
  }

  if(matrix.size() != matrix[0].size())
  {
    throw std::logic_error("必须是方阵才可以做行列式");
    return 0;
  }



  size_t m = matrix[0].size();
  //等于某行的代数余子和
  double res = 0;
  for(size_t i = 0;i < m;++i)
  {
    double tem = matrix[0][i]*determinant(minor(matrix,0,i));
    if((0+i)%2)
    {
      tem *= -1;
    }
    res += tem;
  }
  return res;
}



Matrix algebra::inverse(const Matrix& matrix)
{
  size_t n = matrix.size();
  if(n == 0)
  {
    return Matrix{};
  }
  size_t m = matrix[0].size();

  if(n!=m)
  {
    throw std::logic_error("必须是方阵才可以求逆，基础线代中");
    return Matrix{};
  }
  double A_de = determinant(matrix);
  if(A_de  == 0)
  {
    throw std::logic_error("奇异矩阵无法求逆");
    return Matrix{};
  }

  Matrix A_star = zeros(n,m);

  //求伴随矩阵-先求伴随矩阵
  for(size_t ni = 0;ni < n;++ni)
    for(size_t  mi = 0; mi < m;++mi)
    {
      double tem = determinant(minor(matrix,ni,mi));
      if((ni+mi)%2)
        tem *= -1;
      A_star[ni][mi] = tem;
    }

  
  // 将伴随矩阵求求转置
  A_star = transpose(A_star);

  

  //通过伴随矩阵得到矩阵的逆
  return multiply(A_star, 1.0/A_de);;
}



Matrix algebra::concatenate(const Matrix& matrix1, const Matrix& matrix2, int axis)
{
  //按照axis指定的维度拼接矩阵
  size_t n1 = matrix1.size();
  size_t n2 = matrix2.size();
  if(n1 == 0)
  {
    return matrix2;
  }else if(n2 == 0)
  {
    return matrix1;
  }
  size_t m1 = matrix1[0].size();
  size_t m2 = matrix2[0].size();

  if(axis == 0)
  {
    if(m1 != m2)
    {
      throw std::logic_error("维度错误");
      return Matrix{};
    }
    Matrix res = zeros(n1+n2,m1);
    size_t ni = 0;
    for(;ni < n1;++ni)
      for(size_t  mi = 0; mi < m1;++mi)
      {
        res[ni][mi] = matrix1[ni][mi];
      }
    for(size_t n2i = 0;ni < n1+n2;++ni,++n2i)
      for(size_t  mi = 0; mi < m1;++mi)
      {
        res[ni][mi] = matrix2[n2i][mi];
      }
    return res;
  }else if(axis == 1)
  {
    if(n1 != n2)
    {
      throw std::logic_error("维度错误");
      return Matrix{};
    }
    Matrix res = zeros(n1,m1+m2);

    for(size_t ni = 0;ni < n1;++ni)
      for(size_t  mi = 0; mi < m1;++mi)
      {
        res[ni][mi] = matrix1[ni][mi];
      }
    
    for(size_t ni = 0;ni < n2;++ni)
      for(size_t  mi = 0; mi < m2;++mi)
      {
        res[ni][mi+m1] = matrix2[ni][mi];
      }
    return res;
  }

  return Matrix{};


}


Matrix algebra::ero_swap(const Matrix& matrix_t, size_t r1, size_t r2)
{
  Matrix matrix = matrix_t;
  size_t n = matrix.size();
  if(n == 0)
    return Matrix{};
  size_t m = matrix[0].size();
  std::vector<double> tem(m,0);
  if(!(r1 >= 0&&r1 < n)||!(r2 >= 0&&r2 < n) )
  {
    throw std::logic_error("指定行不在范围内错误");
    return Matrix{};
  }

  for(size_t mi = 0;mi < m;++mi)
  {
    tem[mi] = matrix[r1][mi];
  }
  for(size_t mi = 0;mi < m;++mi)
  {
    matrix[r1][mi] = matrix[r2][mi];
  }
  for(size_t mi = 0;mi < m;++mi)
  {
    matrix[r2][mi] = tem[mi];
  }
  return matrix;
}



Matrix algebra::ero_multiply(const Matrix& matrix_t, size_t r, double c)
{
  Matrix matrix = matrix_t;
  size_t n = matrix.size();
  if(n == 0)
    return Matrix{};
  size_t m = matrix[0].size();
  if(!(r >= 0&&r < n) )
  {
    throw std::logic_error("指定行不在范围内错误");
    return Matrix{};
  }

  for(size_t mi = 0;mi < m;++mi)
  {
    matrix[r][mi] *= c;
  }
  return matrix;
}


Matrix algebra::ero_sum(const Matrix& matrix_t, size_t r1, double c, size_t r2)
{
  Matrix matrix = matrix_t;
  size_t n = matrix.size();
  if(n == 0)
    return Matrix{};
  size_t m = matrix[0].size();
  std::vector<double> tem(m,0);
  if(!(r1 >= 0&&r1 < n)||!(r2 >= 0&&r2 < n)  )
  {
    throw std::logic_error("指定行不在范围内错误");
    return Matrix{};
  }
  //将r1*c加到第r2行
  for(size_t mi = 0;mi < m;++mi)
  {
    matrix[r2][mi] +=  matrix[r1][mi]*c;
  }

  return matrix;
}


Matrix algebra::upper_triangular(const Matrix& matrix_t)
{
  Matrix matrix = matrix_t;
  size_t n = matrix.size();
  if(n == 0)
    return Matrix{};
  size_t m = matrix[0].size();
  if(n != m)
  {
    throw std::logic_error("参数错误，需要方阵");
  }
  for(size_t mi = 0;mi < m;++mi)
  {
    for(size_t ni = mi + 1;ni < n;++ni)
    {
      // 如果中间为0
      if(matrix[mi][mi] == 0)
      {
        // 往下找第一个不为0的然后交换
        size_t changer = mi;
        for(;changer < n;++changer)
        {
          if(matrix[changer][mi] != 0)
            break;
        }
        matrix = ero_swap(matrix,mi,changer);
      }
      matrix = ero_sum(matrix,mi,-matrix[ni][mi]/matrix[mi][mi],ni);
    }
  }

  return matrix;
}
