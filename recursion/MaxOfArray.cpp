#include<iostream>
using namespace std;

int maxi(int arr[],int max,int idx){
   if(idx==6) return max;
   if(arr[idx]>max) max=arr[idx];
   maxi(arr,max,idx+1);

}

int main(){
    int arr[]={2,9,5,7,4,8};
    cout<<maxi(arr,arr[0],0);
}