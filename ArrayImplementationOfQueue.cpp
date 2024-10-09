#include<iostream>
using namespace std;

void insertion(int arr[],int &r,int val){
      if(r==5){
        cout<<"queue is full";
        return ;
      }
      arr[r]=val;
      r++;
}
void deletion(int &f,int &r){
    if(f-r==0){
       cout<<"queue is Empty";
        return; 
    }
        f++;
    
}
void front(int arr[],int &f,int &r){
    if(f-r==0){
       cout<<"queue is Empty";
        return; 
    }
    cout<<arr[f];
    cout<<endl;
}

int size(int &f,int &r){
   return r-f;
}

void display(int arr[],int f,int r){
    for(int i=f;i<r;i++){
    cout<<arr[i]<<" ";
   }
   cout<<endl;
}

int main(){
    int arr[5]; 
    int r=0;
    int f=0; 
   front(arr,f,r);
   cout<<endl;
   deletion(f,r);
   cout<<endl;
   insertion(arr,r,2);
   insertion(arr,r,3);
   insertion(arr,r,5);
   insertion(arr,r,6);
   insertion(arr,r,7);
   insertion(arr,r,8);// stack is full
   cout<<endl;
   front(arr,f,r);       // 2
   display(arr,f,r);     // 2 3 5 6 7
   deletion(f,r);
   display(arr,f,r);     // 3 5 6 7
   front(arr,f,r);       //3
   cout<<"size of queue="<<size(f,r); //4
}