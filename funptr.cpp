#include <iostream>

class TA
{
public:
    int a;

    void TA1() 
    {
        //this->a = 5;
        printf("a=%d\n", a); 
    }

    void TA2()
    {
        printf("hha\n");
    }
};

union UU
{
    void* p;
    void(TA::*pfn)();
};

typedef void(*Func)(TA&);

int main(int argc, char** argv)
{
    std::cout<< reinterpret_cast<uintptr_t*>((void*)(&TA::TA1))<<std::endl;
    std::cout<< reinterpret_cast<uintptr_t*>((void*)(&TA::TA2))<<std::endl;
    TA ta;
    ta.a = 2;
 
    UU u;
    u.pfn = &TA::TA1;
    std::cout<<(uintptr_t*)u.p<<std::endl;

    Func jj = (Func)((uintptr_t*)u.p);
    jj(ta);

    std::cout<<(uintptr_t*)u.p + 6<<std::endl;
    //Func jj1111 = (Func)((uintptr_t*)u.p + 0xbe);
    //jj1111(ta);
    u.pfn = &TA::TA2;
    printf("%p\n", (uintptr_t*)u.p);
    
    Func jj2 = (Func)((uintptr_t*)u.p);
    jj2(ta);
    
    system("pause");
    return 0;
}