#include<cstddef>
#include<utility>
#include<iostream>
#include<memory>
#include<vector>


//enable_if
template<bool F,typename T=void >
struct enable_if{};

template<typename T>
struct enable_if<true,T>{typedef T type;};

template<bool F,typename T=void >
using enable_if_t=typename enable_if<F,T>::type;

//ifthenelse
template<bool Cond,typename TT,typename FT>
struct ifthenelse{};

template<typename TT,typename FT>
struct ifthenelse<true,TT,FT>{using type=TT;};

template<typename TT,typename FT>
struct ifthenelse<false,TT,FT>{using type=FT;};



template<typename T,typename S=enable_if_t<std::is_convertible_v<T,int>>>
void funint(T x)
{
    std::cout<<x<<std::endl;
}


int main()
{
    funint(4);
    funint('a');
    funint((short)3);
    std::vector<std::pair<int,int>> nums;
    std::cout<<std::boolalpha<<std::endl;
    std::cout<<std::is_same_v<decltype(nums.push_back(std::pair<int,int>{1,1})),void><<std::endl;
    std::cout<<std::is_same_v<std::decay_t<decltype(nums.emplace_back(1,1))>,std::pair<int,int>><<std::endl;
    system("pause");
    return 0;
}