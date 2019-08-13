#include<iostream>
#include<vector>

using  namespace std;

void process(vector<int>&arr,int l,int r,vector<int>&tmp){
    if(r<=l)
        return;
    int mid = l+(r-l)/2;
    process(arr,l,mid,tmp);
    process(arr,mid+1,r,tmp);
    int index = 0,l1 = l,l2 = mid+1;
    while(l1<=mid&&l2<=r){
        if(arr[l1]<arr[l2]){
            tmp[index++] = arr[l1++];
        }else{
            tmp[index++] = arr[l2++];
        }
    }
    while(l1<=mid)
        tmp[index++]=arr[l1++];
    while(l2<=r)
        tmp[index++] = arr[l2++];
    for(int i =0;i<index;i++)
        arr[l+i] = tmp[i];
}
void mergeSort(vector<int>&arr){
    if(arr.size()<2)
        return;
    vector<int>tmp(arr.size());
    process(arr,0,arr.size()-1,tmp);    
}


void process1(vector<int>&arr,int l,int r,vector<int>&tmp){
    if(r<=l)
        return;
    int mid = l+(r-l)/2;
    process1(tmp,l,mid,arr);
    process1(tmp,mid+1,r,arr);
    int index = l,l1 = l,l2 = mid+1;
    while(l1<=mid&&l2<=r){
        if(arr[l1]<arr[l2]){
            tmp[index++] = arr[l1++];
        }else{
            tmp[index++] = arr[l2++];
        }
    }
    while(l1<=mid)
        tmp[index++]=arr[l1++];
    while(l2<=r)
        tmp[index++] = arr[l2++];
}
void mergeSort1(vector<int>&arr){
    if(arr.size()<2)
        return;
    vector<int>tmp(arr);
    process1(tmp,0,arr.size()-1,arr);    
}
int main(){
    vector<int>arr = {5,2,9,4,2,3,1,-5,4,8};
    mergeSort1(arr);
    for(int i =0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    return 0;
}
