#include<iostream>

template<typename T>
class B
{
public:
    enum E{e1=6,e2=28,e3=496};
    virtual void zero(E e=e1)
    {
        std::cout <<"zero"<< e << std::endl;
    }
    virtual void one(E& e)
    {
        std::cout <<"one"<< e << std::endl;
    }   
};

template<typename T>
class D:public B<T>
{
public:
    void f()
    {
        typename D<T>::E e;
        this->zero();
        this->one(e);
    }
};

int main()
{
    D<int> d;
    d.f();
    system("pause");
    return 0;
}
