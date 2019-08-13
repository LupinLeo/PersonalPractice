#include<iostream>
#include<vector>

using  namespace std;

void bubbleSort(vector<int>&arr){
    if(arr.size()<2)
        return;
    for(int i =arr.size()-1;i>=1;i--){
        for(int j =0;j<i;j++){
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}

int main(){
    vector<int>arr = {5,2,9,4,2,3,1,-5,4,8};
    bubbleSort(arr);
    for(int i =0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    return 0;
}
