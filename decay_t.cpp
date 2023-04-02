#include<cstddef>
#include<utility>
#include<iostream>
#include<memory>

template<typename T1, typename T2>
auto max (T1 a, T2 b) -> typename std::decay<decltype(true?a:b)>::type
{
  return  b < a ? a : b;
}

/*
template<typename T1, typename T2,
         typename RT = std::decay_t<decltype(true ? T1() : T2())>>
RT max (T1 a, T2 b)
{
  return  b < a ? a : b;
}

template<typename T1, typename T2,
         typename RT = std::decay_t<decltype(true ? std::declval<T1>()
                                                  : std::declval<T2>())>>
RT max (T1 a, T2 b)
{
  return  b < a ? a : b;
}
*/

int main()
{
    std::cout<<(::max(3,4.5))<<std::endl;
    std::cout<<(::max(5,4.5))<<std::endl;
    std::cout<<(::max("cxy","cxx"))<<std::endl;
    std::cout<<(::max(char('a'),1))<<std::endl;
    system("pause");
    return  0;
}