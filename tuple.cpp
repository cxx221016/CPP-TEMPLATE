#include<cstddef>
#include<utility>
#include<iostream>
#include<memory>

template<typename... Args>
struct tuple
{
    tuple(Args...) {}
};

template<typename T,typename... Args>
struct tuple<T,Args...>:tuple<Args...>
{
    tuple(T v,Args... params):value_(v),tuple<Args...>(params...){};
    T value_;
};


template<size_t N,typename tpl>
struct tuple_element;

template<size_t N,typename T,typename... Args>
struct tuple_element<N,tuple<T,Args...>>:tuple_element<N-1,tuple<Args...>>{};

template<typename T,typename... Args>
struct tuple_element<0,tuple<T,Args...>>
{
    using type=T;
    using __tuple_type=tuple<T,Args...>;
};

template<size_t N,typename... Args>
typename tuple_element<N,tuple<Args...>>::type& get(tuple<Args...>& t)
{
    using __tuple_type=typename tuple_element<N,tuple<Args...>>::__tuple_type;
    return static_cast<__tuple_type&>(t).value_;
}

int main()
{
    int i = 1;
    auto t = tuple(0, i, '2', 3.0f, 4ll, std::string("five"));
    std::cout << std::is_same_v<
               tuple_element<3, decltype(t)>::type,
               float> << std::endl;                                 // output: 1
    std::cout << std::is_same_v<
               tuple_element<2, decltype(t)>::__tuple_type,
               tuple<char,float,long long, std::string>> << std::endl;  // output: 1
    i = 0;
    std::cout << get<1>(t) << std::endl;  // output: 1
    get<1>(t) = 0;
    std::cout << get<1>(t) << std::endl;  // output: 0
    system("pause");

}
