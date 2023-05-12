#include <iostream>

template<typename T>
void tmplParamIsReference(T t) {
  t=2;
  std::cout << "T is reference: " << std::is_reference_v<T> << '\n';
}

template<typename T>
void tmplParamIsReferenceth(T& t) {
  t=3;
  std::cout << "T is reference: " << std::is_reference_v<T> << '\n';
}

int main()
{
  std::cout << std::boolalpha;
  int i=1;
  int& r = i;
  tmplParamIsReference(i);         // false
  std::cout<<i<<std::endl;
  tmplParamIsReference(r);         // false
  std::cout<<i<<std::endl;
  tmplParamIsReference<int&>(i);   // true
  std::cout<<i<<std::endl;
  tmplParamIsReference<int&>(r);   // true
  std::cout<<i<<std::endl;
  tmplParamIsReferenceth(i);         // false
  std::cout<<i<<std::endl;
  tmplParamIsReferenceth(r);         // false
  std::cout<<i<<std::endl;
  tmplParamIsReferenceth<int&>(i);   // true
  std::cout<<i<<std::endl;
  tmplParamIsReferenceth<int&>(r);   // true
  std::cout<<i<<std::endl;
  system("pause");
}
