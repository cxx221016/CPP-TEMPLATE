#include<cstddef>
#include<utility>
#include<iostream>
#include<memory>
#include<vector>

//成员member
#define DEFINE_HAS_MEMBER(Member)                                   \
  template<typename, typename = std::void_t<>>                      \
  struct HasMemberT_##Member                                        \
   : std::false_type { };                                           \
  template<typename T>                                              \
  struct HasMemberT_##Member<T, std::void_t<decltype(&T::Member)>>  \
   : std::true_type { } // ; intentionally skipped

template< typename T,typename F=void >
struct has_member:std::false_type{};

template<typename T>
struct has_member<T,std::void_t<decltype(T::member)>>: std::true_type{};

template<typename T> inline 
constexpr bool has_member_v {has_member<T>::value};

//类型value_type
#define DEFINE_HAS_TYPE(MemType)                                   \
  template<typename, typename = std::void_t<>>                     \
  struct HasTypeT_##MemType                                        \
   : std::false_type { };                                          \
  template<typename T>                                             \
  struct HasTypeT_##MemType<T, std::void_t<typename T::MemType>>   \
   : std::true_type { } // ; intentionally skipped

template <typename T,typename F=void>
struct has_value_type:std::false_type{};

template <typename T>
struct has_value_type<T,std::void_t<typename T::value_type>>: std::true_type{};

template <typename T> inline
constexpr bool has_value_type_v{has_value_type<T>::value};

//is_smart_ptr
template <typename T,typename F=void>
struct is_smart_pointer:std::false_type{};

template <typename T>
struct is_smart_pointer<T,std::void_t<decltype(std::declval<T>().operator->()),decltype(std::declval<T>().get())>>:std::true_type{};

template <typename T> inline
constexpr bool is_smart_pointer_v{is_smart_pointer<T>::value};

//string
template<typename T> inline 
constexpr bool is_string_v{std::is_same_v<T,std::string>|| std::is_same_v<T,const char*>};

//reference
template<typename T>
struct is_reference:std::false_type{};

template<typename T>
struct is_reference<T&>:std::true_type{};

template<typename T>inline 
constexpr bool is_reference_v{is_reference<T>::value};

//EQ < +
template<typename T1,typename T2,typename F=void>
struct is_eqcompare: std::false_type{};

template<typename T1,typename T2>
struct is_eqcompare<T1,T2,
std::void_t<decltype(std::declval<T1>()==std::declval<T2>()) , decltype(std::declval<T1>()!=std::declval<T2>())>>:
std::true_type{};

template<typename T1,typename T2> inline 
constexpr bool is_eqcompare_v{is_eqcompare<T1,T2>::value};

//begin or end
template<typename T,typename F=void>
struct has_begin:std::false_type{};

template<typename T>
struct has_begin<T,std::void_t<decltype(std::declval<T>().begin())>>:std::true_type{};

template<typename T> inline 
constexpr bool has_begin_v{has_begin<T>::value};

//is_class
template<typename T,typename F=void>
struct is_class:std::false_type{};

template<typename T>
struct is_class<T,std::void_t<int T::*>>:std::true_type{};

template<typename T> inline 
constexpr bool is_class_v{is_class<T>::value};

//isconstructible
template<typename T,typename F=void>
struct is_constructible:std::false_type{};

template<typename T>
struct is_constructible<T,std::void_t<decltype(T())>>:std::true_type{};

template<typename T> inline 
constexpr bool is_constructible_v{is_constructible<T>::value};

//is_function
template<typename T>
struct is_function:std::false_type{};

template<typename T,typename... Args>
struct is_function<T(Args...)>:std::true_type{};

template<typename T,typename... Args> inline 
constexpr bool is_function_v{is_function<T>::value};

class  A
{
public:
    int member;
};

class B
{
public:
    typedef int value_type;
};

class C
{
    int c;
public:
    C(int c=0):c(c){};
    friend bool operator ==(const C& a,const C& b)
    {
        return a.c==b.c;
    }
    friend bool operator!=(const C &c1, const C &c2)
    {
        return c1.c!=c2.c;
    }
};

class D
{
    int d;
public:
    D(int c=0):d(c){};
    friend bool operator!=(const D &c1, const D &c2)
    {
        return c1.d!=c2.d;
    }
};

void print(int i)
{
    std::cout<<"function"<<std::endl;
}

struct noprint
{

};

void hello(int &a,int &b)
{
    std::cout<<"hello"<<std::endl;
}
DEFINE_HAS_TYPE(value_type);

int main()
{
    std::cout<<std::boolalpha;
    std::cout<<"has_member"<<std::endl;
    std::cout<<has_member_v<A><<std::endl;
    std::cout<<has_member_v<B><<std::endl;

    std::cout<<"has_value_type"<<std::endl;
    std::cout<<has_value_type_v<A><<std::endl;
    std::cout<<has_value_type_v<B><<std::endl;

    std::shared_ptr<A> shareptr (new A);
    std::weak_ptr<A> weakptr (shareptr);
    std::unique_ptr<A> uniqueptr (new A);
    A* ptr (new A);
    std::cout<<"is_smart_ptr"<<std::endl;
    std::cout<<is_smart_pointer_v<decltype(shareptr)><<std::endl;
    std::cout<<is_smart_pointer_v<decltype(weakptr)><<std::endl;
    std::cout<<is_smart_pointer_v<decltype(uniqueptr)><<std::endl;
    std::cout<<is_smart_pointer_v<decltype(ptr)><<std::endl;
    
    int i;
    int &ref=i;
    int *pi=&i;
    std::cout<<"is_reference"<<std::endl;
    std::cout<<is_reference_v<decltype(ref)><<std::endl;
    std::cout<<is_reference_v<decltype(pi)><<std::endl;

    C c1,c2;
    std::cout<<"is_eqcompare"<<std::endl;
    std::cout<<(c1==c2)<<std::endl;
    std::cout<<is_eqcompare_v<std::string,int><<std::endl;
    std::cout<<is_eqcompare_v<double,int><<std::endl;
    std::cout<<is_eqcompare_v<bool,int><<std::endl;
    std::cout<<is_eqcompare_v<char,int><<std::endl;
    std::cout<<is_eqcompare_v<C,D><<std::endl;
    std::cout<<is_eqcompare_v<C,C><<std::endl;

    std::cout<<"is_function"<<std::endl;
    std::cout<<is_function_v<noprint><<std::endl;
    std::cout<<is_function_v<decltype(print)><<std::endl;
    std::cout<<is_function_v<decltype(hello)><<std::endl;

    
    std::cout<<"has_type"<<HasTypeT_value_type<std::vector<int>>::value<<std::endl;
    system("pause");
    return 0;
}