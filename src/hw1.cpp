#include "../include/hw1.h"

#include <random>
#include <iomanip>

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