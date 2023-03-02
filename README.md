# c-matrix

一个c++的矩阵库，开发过程中使用makefile作为编译脚本，用google执行单元的测试

这个可以作为一个很好的模板作为单元测试


## 单元测试的编译gtest 特殊

在编译时需要将-lgtest添加在最后

这是makefile的一个例子
```
UNIT_TEST = src/unit_test.cpp
HW1 = src/hw1.cpp
MAIN = src/main.cpp

GCC = g++ -Wall -std=c++11 

T = main

$(T): $(UNIT_TEST) $(HW1) $(MAIN)
	$(GCC) $^ -o $@  -lgtest -lpthread


.PHONY:clean

clean:
	rm  $(T)
```

## 异常<stdexcept>

c++中异常要用这个库
#include <stdexcept>

有好几种不同的
### Logic errors

logic_error	Logic error exception (class)

domain_error	Domain error exception (class)

invalid_argument	Invalid argument exception (class)

length_error	Length error exception (class)

out_of_range	Out-of-range exception (class)

### Runtime errors
runtime_error	Runtime error exception (class)

range_error	Range error exception (class)

overflow_error	Overflow error exception (class)

underflow_error	Underflow error exception (class)


## 输出操作<iomanip>

```c++
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
```


### random库c++11
这个库用来生成随机数
```c++
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
```