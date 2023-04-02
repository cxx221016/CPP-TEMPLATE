 #include<iostream>
 #include<utility>

 using namespace std;
 class Foo { 
    public:
        Foo() { std::cout<<"default"<<std::endl; }

        Foo(const Foo& rhs) { std::cout<<"ctor"<<std::endl; }
        Foo(Foo&& rhs) { std::cout<<"mtor"<<std::endl; }
    };

 Foo return_urvo_value() { 
      return Foo{}; 
    }

    Foo return_nrvo_value() { 
      Foo local_obj;
      return local_obj; 
    }

void pass_by_value(Foo foo) { 
      // ...
    }

    int main(int argc, char const *argv[]) {
      auto x = return_urvo_value();
      auto y = return_nrvo_value(); 

      pass_by_value(Foo{});
      pass_by_value(std::move(x));
      system("pause");
      return 0;
    }