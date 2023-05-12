#include<iostream>

template<typename X>
class Base
{
public:
    int basefield;
    using T=int;
};

class D1:public Base<Base<void>>
{
    public:
    void f()
    {
        basefield=7;
        std::cout<<basefield<<std::endl;
    }
};

template<typename T>
class D2:public Base<double>
{
    public:
    void f()
    {
        basefield=7;
        
    }
    T strange;
};

template<typename T>
class DD:public Base<T>
{
    public:
    void f()
    {
        std::cout<<this->basefield<<std::endl;
        this->basefield=7;
        std::cout<<this->basefield<<std::endl;
       /*
       std::cout<<Base<T>::basefield<<std::endl;
         Base<T>::basefield=7;
        std::cout<<Base<T>::basefield<<std::endl;
        */
    }
};

template<>
class Base<bool>
{
    public:
    //enum{basefield=42};
    int basefield;
};

int main()
{
    DD<bool> d;
    d.f();
    system("pause");
    return 0;
}

