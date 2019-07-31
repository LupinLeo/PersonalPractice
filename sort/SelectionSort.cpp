#include<iostream>
#include<vector>

using  namespace std;

void selectionSort(vector<int>&arr){
    if(arr.size()<2)
        return;
    for(int i = 0;i<arr.size()-1;i++){
        int minIndex = i;
        for(int j =i+1;j<arr.size();j++){
            if(arr[minIndex]>arr[j]){
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}

int main(){
    vector<int>arr = {5,2,9,4,2,3,1,-5,4,8};
    selectionSort(arr);
    for(int i =0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    return 0;
}
