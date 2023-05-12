#include<iostream>
#include<functional>

using namespace std;

class Base {
public:
  Base() = default;
  virtual 
  void print()       { std::cout <<"Actual Type:  Base" << std::endl; }
  virtual void getaddr()=0;
  void PointerType() { std::cout <<"Pointer Type: Base" << std::endl;}
  virtual ~Base()    { std::cout <<"base-dtor"<< std::endl;}
};

class Derived : public Base{
public:
  Derived() = default;
  void print()       { std::cout <<"Actual Type:  Derived" << std::endl; }
  void getaddr()     { cout<<reinterpret_cast<uintptr_t*>(&random_)<<endl;}
  void PointerType() { std::cout <<"Pointer Type: Derived" << std::endl;}
  ~Derived()         { std::cout <<"derived-dtor ";}
//private:
   int random_{0};
};


typedef void(*func)();

func getclassfun(Base* base,uintptr_t offset)
{
    uintptr_t** vptr=reinterpret_cast<uintptr_t**>(base);
    cout<<"random: "<<*reinterpret_cast<int*>(vptr+1)<<endl;
    uintptr_t* vtbl=*vptr;
    return reinterpret_cast<func>(*(vtbl+offset));
}

#define GET(A , m)  (&((A*)0)->m)

int main(int argc, char const *argv[]) {
  Base* base = new Derived; 
  base->getaddr();
  // 编译器完成调用 
  base->print();     
  // 我们自己调用
  auto print = getclassfun(base,0); // 指向print函数的函数指针
  print();  // 调用print函数

  delete base;
  cout<< GET(Derived,random_)<<endl;
  system("pause");
  return 0;
}