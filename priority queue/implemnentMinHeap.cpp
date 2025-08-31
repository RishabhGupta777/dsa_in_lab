#include<iostream>
#include <queue>
using namespace std;
class MinHeap{
public:
   int arr[50];
   int idx;
   MinHeap(){
    idx=1;
   }
   int top( ){
    return arr[1];
   }

   int size(){
    return idx-1;
   }

   void push(int x){
   arr[idx]=x;
   int i=idx;
   idx++;
   while(i!=1){
    int parent =i/2;
    if(arr[parent]>arr[i]){
        swap(arr[parent],arr[i]);
    }
    else break;
    i=parent;  //or i=i/2
   }
   }

   void pop(){
    idx--;
    arr[1]=arr[idx];
    int i=1;
    // rearangement wala part niche
    while(true){
        int left=i*2,right=i*2+1;
        if(left>size()) break;
        if(right>size()){ //right to aage badh gya lekin kahi mera left size ke ander hi ho aur arr[i] se chota ho
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

   void display(){
    for(int i=1;i<=size();i++){
    cout<<arr[i]<<" ";
    }
    cout<<endl;
   }
   
   
};


int main(){
   MinHeap pq;
 pq.push(10);
 pq.push(20);
 cout<<pq.top()<<" "<<pq.size()<<endl;
 pq.push(11);
  pq.push(2);
 cout<<pq.top()<<" "<<pq.size()<<endl;
pq.display();
pq.pop();
 cout<<pq.top()<<" "<<pq.size()<<endl;
pq.display();
 
}