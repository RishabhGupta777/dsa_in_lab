#include<iostream>
using namespace std;
int main(){
    int arr[]={5,3,1,4,2};
    for(int i=0;i<4;i++){
          int min=INT16_MAX;
          int minidx;
        for(int j=i;j<5;j++){
        if(arr[j]<min){
           min=arr[j];
           minidx=j;
        }
        }
       swap(arr[i],arr[minidx]);
    }
    for(int i=0;i<5;i++){
        cout<<arr[i];
    }
}