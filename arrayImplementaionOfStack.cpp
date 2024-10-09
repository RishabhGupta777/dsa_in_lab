#include<iostream>
using namespace std;

void push(int arr[],int &idx,int val,int capacity){
      if(idx==capacity){
        cout<<"stack is full";
        return ;
      }
      idx++;
      arr[idx]=val;
}
void pop(int &idx){
    if(idx==-1){
       cout<<"stack is Empty";
        return; 
    }
        idx--;
    
}
void top(int arr[],int &idx){
    if(idx==-1){
       cout<<"stack is Empty";
        return; 
    }
    cout<<arr[idx];
    cout<<endl;
}

int size(int &idx){
   return idx=idx+1;
}

void display(int arr[],int idx){
    for(int i=0;i<=idx;i++){
    cout<<arr[i]<<" ";
   }
   cout<<endl;
}

int main(){
    int arr[5]; 
    int capacity=(sizeof(arr)/sizeof(arr[0]))-1;
    int idx=-1;
   top(arr,idx);
   cout<<endl;
   pop(idx);
   cout<<endl;
   push(arr,idx,2,capacity);
   push(arr,idx,3,capacity);
   push(arr,idx,5,capacity);
   push(arr,idx,6,capacity);
   push(arr,idx,7,capacity);
   push(arr,idx,8,capacity);
   cout<<endl;
   top(arr,idx);
   display(arr,idx);
   pop(idx);
   display(arr,idx);
   top(arr,idx);
   cout<<"size of stack="<<size(idx);
 
 
}