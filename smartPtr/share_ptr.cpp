
#include<iostream>
using namespace std;

template<typename T>
class share_ptr{
public:
    share_ptr()
        :_ptr(nullptr),
        _count(new int(0))
    {}
    share_ptr(T*ptr)
        :_ptr(ptr),
        _count(new int(1))
    {}
    share_ptr(const share_ptr&rhs)
        :_ptr(rhs._ptr),
        _count(rhs._count)
    {
        *_count++;
    }
    share_ptr& operator=(const share_ptr& rhs)
    {
        if(&rhs == this)
            return *this;
        if(--*_count==0){
            delete _ptr;
            delete _count;
        }
        ++*rhs._count;
        _ptr = rhs._ptr;
        _count = rhs._count;
        return *this;
    }
    ~share_ptr(){
        if(--*_count==0){
            delete _ptr;
            delete _count;
        }
    }
    T& operator*(){return *_ptr;}
    T* operator->(){return _ptr;}
private:
    T* _ptr;
    int* _count;
};

class A{
public:
    int a;
    A(int val):a(val){}
    int get(){
        return a;
    }

    ~A(){
        cout<<"dtor!"<<endl;
    }
};
int main()
{
    share_ptr<A>ptr1 = new A(1);
    share_ptr<A>ptr2(new A(2));
    cout<<(*ptr1).get()<<endl;
    cout<<ptr2->get()<<endl;
    ptr2 = ptr1;
    while(1);

}
