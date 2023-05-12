#include "ratio.hpp"
#include"ratioadd.hpp"
#include<iostream>

int main()
{
    typedef Ratio<4,5> R1;
    typedef Ratio<1,5> R2;
    typedef RatioAdd<R1,R2> RES;
    std::cout<<RES::den<<" "<<RES::num<<std::endl;
    system("pause");
}