#include<iostream>

template<typename T>
class Types
{
    public:
        using I=int;
};

template<typename T,typename U=typename Types<T>::I>
class S;

template<>
class S<void>
{
public:
    int m=10;
};

template<>
class S<char,char>;

int main()
{
    /*
    S<int>* si;
    std::cout<<si->m<<std::endl;
    S<int> e1;
    std::cout<<e1.m<<std::endl;
    */
    S<void>* pv;
    std::cout<<pv->m<<std::endl;
    S<void,int> sv;
    std::cout<<sv.m<<std::endl;

}

template<typename T,typename U>
class S
{
public:
    int m=0;
};