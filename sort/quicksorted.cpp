#include<iostream>
#include<vector>

using  namespace std;
void quicksorted(vector<int>&);
void process(vector<int>&,int,int);
vector<int>partition(vector<int>&,int,int);

void quicksorted(vector<int>&arr){
    if(arr.size()<2)
        return;
    process(arr,0,arr.size()-1);
}
void process(vector<int>&arr,int l, int r){
    if(l>=r)
        return;
    swap(arr[r],arr[rand()%(r-l+1)+l]);
    vector<int>tmp= partition(arr,l,r);
    process(arr,l,tmp[0]-1);
    process(arr,tmp[1]+1,r);
}
vector<int> partition(vector<int>&arr,int l,int r){
    int less = l,more = r;
    int index = l;
    while(index<more){
        if(arr[index]<arr[r])
            swap(arr[index++],arr[less++]);
        else if(arr[index]>arr[r])
            swap(arr[index],arr[--more]);
        else
            index++;
    }
    swap(arr[r],arr[more]);
    return vector<int>{less,more};
}

int main(){
    vector<int>arr = {5,2,9,4,2,3,1,-5,4,8};
    quicksorted(arr);
    for(int i =0;i<arr.size();i++)
        cout<<arr[i]<<endl;
    return 0;
}
