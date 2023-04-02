#include<cstddef>
#include<utility>
#include<iostream>
#include<memory>

template<typename T1,typename T2,typename RT=std::common_type_t<T1,T2>>
RT max(T1 t1,T2 t2)
{
    return t1>t2 ? t1:t2;
}

/*
template<typename T1, typename T2>
std::common_type_t<T1,T2> max (T1 a, T2 b)
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
