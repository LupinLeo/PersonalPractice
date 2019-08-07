#include<iostream>

using namespace std;

class A{
private:
    ~A(){
        cout<<"dtor"<<endl;
    }
public:
    A(){
        cout<<"ctor!"<<endl;        
    }
};


int main(){
    A* ptr = new A;
//    A a;//error!
}
