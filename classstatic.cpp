#include<iostream>
using namespace std;
class INIT
{
    inline static int a=0;
public:
    INIT() { cout << "INIT constructor" << endl; }
    void print()
    {
        cout<<"a: "<<a<<endl;
    }
    ~INIT() { cout << "INIT destructor" << endl; }
};

int main()
{
    INIT init;
    init.print();
    system("pause");
    return 0;
}
