#include<vector>
#include<iostream>

using namespace std;
void heapInsert(vector<int>&arr,int index){
    while(index!=0&&arr[index]>arr[(index-1)/2]){
        swap(arr[index],arr[(index-1)/2]);
        index = (index-1)/2;
    }    
}
void heapify(vector<int>&arr,int len)
{
    int index = 0,left = index*2+1;
    while(left<len){
        int maxIndex = left+1<len&&arr[left+1]>arr[left]?left+1:left;
        maxIndex = arr[maxIndex]>arr[index]?maxIndex:index;
        if(maxIndex == index)
            break;
        swap(arr[maxIndex],arr[index]);
        index = maxIndex;
        left = 2*index+1;
    }
}
void heapSort(vector<int>&arr){
    if(arr.size()<2)
        return;
    int len = arr.size();
    for(int i =0;i<len;i++)
        heapInsert(arr,i);
    while(len>1){
        swap(arr[0],arr[--len]);
        heapify(arr,len);
    }
}

int main(){
    vector<int>arr = {5,2,9,4,2,3,1,-5,4,8};
    heapSort(arr);
    for(int i =0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
