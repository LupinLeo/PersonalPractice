#include<iostream>
#include<vector>
#include<string>

using namespace std;

void getNext(vector<int>&arr,string& str){
    if(arr.size()==1){
        arr[0] = -1;
        return;
    }
    arr[0] = -1;
    arr[1] = 0;
    for(int i =2;i<arr.size();i++){
        int index = i-1;
        while(arr[index]!=-1){
            if(str[i]==str[arr[index]]){
                arr[i] = arr[index]+1;
                break;
            }
            index = arr[index];
        }
    }
}

int KMP(string& str,string& t){
    if(str.empty()||t.empty()||t.size()>str.size())
        return -1;
    vector<int>next(t.size());
    getNext(next,t);
    int is = 0,it = 0;
    while(is<str.size()){
        if(str[is]==t[it]){
            is++;
            it++;
        }else if(it ==0){
            is++;
        }
        else{
            it = next[it];
        }
        if(it == t.size()){
            return is - it;
        }
    }
    return -1;
}

int main(){
    string s1 = "hello",t1 = "ll";
    cout<< KMP(s1,t1)<<endl;
    string s2 = "aaaaa",t2 = "bba";
    cout<<KMP(s2,t2)<<endl;
}

