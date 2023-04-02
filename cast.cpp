#include<iostream>
#include<any>
using namespace std;

class A {
    int __m_a;
    virtual void print()
    {
        cout<<"A:print()"<<endl;
    }
public:
    int m_a;
    A()
    {
        cout<<"__m_a: "<<reinterpret_cast<uintptr_t*>(&__m_a)<<endl;
    }
};

class D:public A
{
public:
    virtual void print()
    {
        cout<<"D:print()"<<endl;
    }

    void print_nv()
    {
        cout<<"D:print_nv()"<<endl;
    }
};

 

class B {
    int __m_b;
    virtual void print()
    {
        cout<<"B:print()"<<endl;
    }
public:

    int m_b;
    B()
    {
        cout<<"__m_b: "<<reinterpret_cast<uintptr_t*>(&__m_b)<<endl;
    }

};

 

class C : public A, public B
{
public:
    virtual void print()
    {
        cout<<"C:print()"<<endl;
    }

    void print_nv()
    {
        cout<<"C:print_nv()"<<endl;
    }
};

/*
int main()
{
    C c;
    /*
    cout<<"-------------------------------"<<endl;
    cout<<&c<<endl;
    cout<<reinterpret_cast<B*>(&c)<<endl;
    cout<<static_cast<B*>(&c)<<endl;
    cout<<&(c.m_a)<<endl;
    cout<<&(c.m_b)<<endl;
    cout<<"-------------------------------"<<endl;
    uintptr_t** vptr=reinterpret_cast<uintptr_t**>(&c);
    uintptr_t* vtbl=*vptr;
    cout<<"c: "<<&c<<endl;
    //cout<<static_cast<uintptr_t*>((void*)&c)<<endl;
    cout<<"m_a: "<<reinterpret_cast<uintptr_t*>(&(c.m_a))<<endl;
    cout<<"m_b: "<<reinterpret_cast<uintptr_t*>(&(c.m_b))<<endl;
    cout<<"print_v(): "<<vtbl<<endl;
    cout<<"print(): "<<reinterpret_cast<uintptr_t*>((void*)&C::print)<<endl;
    cout<<"print_nv(): "<<reinterpret_cast<uintptr_t*>((void*)&C::print_nv)<<endl;
    system("pause");
    return 0;
}*/

int main()
{
    A* c=new D;
    uintptr_t** vptr=reinterpret_cast<uintptr_t**>(c);
    uintptr_t* vtbl=*vptr;
    cout<<"c: "<<c<<endl;
    cout<<"m_a: "<<reinterpret_cast<uintptr_t*>(&(c->m_a))<<endl;
    cout<<"print_v(): 0x"<<hex<<*vtbl<<endl;
    cout<<"print(): "<<reinterpret_cast<uintptr_t*>((void*)&D::print)<<endl;
    //cout<<"print(): "<<any_cast<uintptr_t>(static_cast<any>(&D::print))<<endl;
    cout<<"print(): "<<reinterpret_cast<uintptr_t*>((void*)(&D::print))<<endl;
    cout<<"print()+8: "<<reinterpret_cast<uintptr_t*>((void*)&D::print)+8<<endl;
    cout<<"print_nv(): "<<reinterpret_cast<uintptr_t*>((void*)&D::print_nv)<<endl;
    system("pause");
    return 0;
}