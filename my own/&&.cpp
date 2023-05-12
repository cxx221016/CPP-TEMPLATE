#include<type_traits>
#include<iostream>
using namespace std;

bool and_all()
{
    return true;
}

template<class T>
bool and_all(T cond)
{
    return cond;
}

template<typename T,typename... Ts>
bool and_all(T cond,Ts... conds)
{
    return cond&&and_all(conds...);
}

template<typename... T>
bool g(T... t)
{
    return and_all(t...);
}

template<typename... T>
bool h(T... t)
{
    return (t&&...&& true);
}

int main()
{
    cout<<and_all(1,2,34,5)<<'\n';
    cout<<"----------------------\n";
    cout<<g(1,3,4,5)<<'\n';
    cout<<"----------------------\n";
    cout<<h(1,3,4,5)<<'\n';
    system("pause");
    return 0;
}