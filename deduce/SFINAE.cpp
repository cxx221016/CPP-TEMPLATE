#include<iostream>
template<typename T>
auto f(T p)
{
    return p->m;
}

int f(...)
{
    return 0;
}

template<typename T>
class S
{
private:
        T m;
public:
        S(T t):m(t){}
};


int main()
{
    
    S s(1);
    system("pause");
    return 0;
}