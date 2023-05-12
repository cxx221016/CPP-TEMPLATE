#include<type_traits>
#include<iostream>
#include<memory>

template<typename>
struct cxx_traits;

template<typename S,typename T>
struct cxx_traits<T S::*>
{
    using member_type=T;
    using class_type=S;
};

template<typename T>
using member_type_t=typename cxx_traits<T>::member_type;

template<typename T>
using class_type_t=typename cxx_traits<T>::class_type;

template<auto T>
class Counter
{
private:
    class_type_t<decltype(T)>& instance;
public:
    Counter(class_type_t<decltype(T)>& inst):instance(inst)
    {
        ++(instance.*T);
    }
    ~Counter()
    {
        --(instance.*T);
    }
};



struct A
{
    int a;
    double b;
};



int main()
{
    A a{0,0.0};
    Counter<&A::a> c1(a);
    Counter<&A::b> c2(a);
    std::cout<<a.a<<std::endl;
    std::cout<<a.b<<std::endl;
    c1.~Counter();
    c2.~Counter();
    std::cout<<a.a<<std::endl;
    std::cout<<a.b<<std::endl;
    system("pause");
    return 0;
}