#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class A
{
    T a;
public:
    A()=default;
    template<typename F>
    class  SY
    {
    public:
        typedef F other;
    };
};

template<typename T,typename F>
using type =typename A<T>::template SY<F>::other;
/*A<T>::template*/

int main()
{
    A<int> tmp;
    type<string,int> a;
    cout<<a<<endl;
    system("pause");
}


/*
int main()
{
    int n;
    cin>>n;
    vector<int> status(n);
    for(auto& statu:status)
    {
        cin>>statu;
    }
    int res=0;
    int cur=1,spare=2,dest=3;
    for(int i=n-1;i>=0;--i)
    {
        if(status[i]==cur)
        {
            ::swap(spare,dest);
        }
        else if(status[i]==dest)
        {
            res+=(1<<i);
            ::swap(spare,cur);
        }
        else return -1;
    }
    cout<<"res:"<<res<<endl;
    system("pause");
}*/