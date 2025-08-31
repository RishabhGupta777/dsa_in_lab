#include<iostream>
#include <queue>
using namespace std;


   void heapify(int i,int arr[],int n){
    while(true){  //pop ka rearangement wala part
        int left=i*2,right=i*2+1;
        if(left>=n) break;
        if(right>=n){ //right to aage badh gya lekin kahi mera left size ke ander hi ho aur arr[i] se chota ho
            if(arr[left]<arr[i]){
                swap(arr[left],arr[i]);
                i=left;
            }
            break;
        }
        if(arr[left]<arr[right]){
           if(arr[left]<arr[i]){
                swap(arr[left],arr[i]);
                i=left;
            }
            else break;
        }
         else{    //(arr[left]>arr[right])
           if(arr[right]<arr[i]){
                swap(arr[right],arr[i]);
                i=right;
            }
            else break;
        }
    }

   }

   void print(int arr[],int n){
     for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
 }
 cout<<endl;
   }


int main(){
int arr[]={-1,10,2,14,11,1,4};
int n=sizeof(arr)/4;
 print(arr,n);
 for(int i=n/2;i>=1;i--){  //n/2 se suru isliye kiye h due to taki left=2*i calulate kiya jaa sake 
    heapify(i,arr,n);      //means left ya right ki aise value calulate kiya jaa saje jo arr ke ander ho
 }
  print(arr,n);
}