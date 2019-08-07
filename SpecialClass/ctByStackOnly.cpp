#include<iostream>

using namespace std;

class A{
public:
    A(){
        cout<<"ctor!"<<endl;        
    }
    ~A(){
        cout<<"dtor"<<endl;
    }

    static void* operator new(size_t )=delete;
};


int main(){
    A* ptr = new A;//error!
    A a;
}
