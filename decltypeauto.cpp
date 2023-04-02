#include<cstddef>
#include<utility>
#include<iostream>
#include<memory>


template<typename T1, typename T2>
constexpr auto max (T1 a, T2 b)
{
  return  b < a ? a : b;
}

/*
template<typename T1, typename T2>
auto max (T1 a, T2 b) -> decltype(b<a?a:b)
{
  return  b < a ? a : b;
}*/

int main()
{
    std::cout<<(::max(3,4.5))<<std::endl;
    std::cout<<(::max("cxy","cxx"))<<std::endl;
    std::cout<<(::max(char('a'),1))<<std::endl;
    system("pause");
    return  0;
}