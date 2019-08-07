#include<iostream>

using namespace std;

class Aux
{
private:
    Aux(){
        cout<<"aux ctor!"<<endl;
    }
    ~Aux(){
        cout<<"aux dtor!"<<endl;
    }
friend class A;
};

class A:virtual public Aux
{
    public:
        A(){
            cout<<"a ctor"<<endl; 
        }
        ~A()
        {
            cout<<"a dtor"<<endl;
        }
};
// error
class Child:public A
{
    public:
        Child(){}
        ~Child(){}
};

int main()
{
    // class A can be used normally
    A a;
    A* ptr = new A;
    delete ptr;
    Child c;
}
