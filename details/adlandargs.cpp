#include<iostream>

template<typename T>
void select();

namespace CXX
{
    class X
    {
        char c;
    };
    
    template<int I>
    void select(X* x)
    {
        std::cout<<"CXX::select(X*)\n";
    }
}

void g(CXX::X* x)
{
    select<3>(x);
}

int main()
{
    CXX::X x;
    g(&x);
    system("pause");
    return 0;
}