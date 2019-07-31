#include<iostream>
#include<vector>

using  namespace std;

void insertionSort(vector<int>&arr){
    if(arr.size()<2)
        return;
    for(int i = 1;i<arr.size();i++){
        for(int j =i;j>0&&arr[j]<arr[j-1];j--){
            swap(arr[j],arr[j-1]);
        }
    }
}

int main(){
    vector<int>arr = {5,2,9,4,2,3,1,-5,4,8};
    insertionSort(arr);
    for(int i =0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    return 0;
}
