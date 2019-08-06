#include<iostream>
#include<utility>
using namespace std;
class A{
public:
    A(){cout<<"ctor"<<endl;}
    void show(){cout<<"show"<<endl;}
    ~A(){cout<<"dtor!"<<endl;}
};
template<typename T>
class unique_ptr{
private:
    T*_ptr;
public:
    explicit unique_ptr(T* ptr = nullptr):_ptr(ptr)
    {}
    ~unique_ptr()
    {
        if(_ptr!=nullptr)
            delete _ptr;
    }
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;
    
    unique_ptr(unique_ptr&& up):_ptr(up._ptr){
        up._ptr = nullptr;
    }
    unique_ptr& operator=(unique_ptr&&up){
        if(&up != this){
            if(_ptr!=nullptr)
                delete _ptr;
            _ptr = up._ptr;
        }
        up._ptr = nullptr;
        return *this;
    }

    T& operator*()const{
        return *_ptr;
    }
    T* operator->()const{
        return _ptr;
    }
    T* get()const{
        return _ptr;
    }
    void reset(T* ptr = nullptr){
        if(ptr!=_ptr){
            if(_ptr!=nullptr)
                delete _ptr;
            _ptr = ptr;
        }
    }
};
int main(){
    unique_ptr<A>ptr(new A);
    ptr->show();
    (*ptr).show();
    cout<<ptr.get()<<endl;
    ptr.reset(new A);
    cout<<ptr.get()<<endl;

    cout<<"move assignment"<<endl;
    ptr = unique_ptr<A>(new A);

    unique_ptr<A>a(new A);
    cout<<"move copy"<<endl;
    unique_ptr<A>b = move(a);

    ptr.reset();
    cout<<ptr.get()<<endl;   
}
