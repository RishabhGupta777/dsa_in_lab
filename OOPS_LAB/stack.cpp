#include<iostream>
using namespace std;

class stack{
private:
int idx=-1;
int arr[5];
int capacity=(sizeof(arr)/sizeof(arr[0]))-1;

public:
void push(int val){
      if(idx==capacity){
        cout<<"stack is full";
        return ;
      }
      idx++;
      arr[idx]=val;
}
void pop(){
    if(idx==-1){
       cout<<"stack is Empty";
        return; 
    }
        idx--;
    
}
void top(){
    if(idx==-1){
       cout<<"stack is Empty";
        return; 
    }
    cout<<arr[idx];
    cout<<endl;
}

int size(){
   return idx=idx+1;
}

void display(){
    for(int i=0;i<=idx;i++){
    cout<<arr[i]<<" ";
   }
   cout<<endl;
}

};



int main(){
 stack s;
   s.top();
   cout<<endl;
   s.pop();
   cout<<endl;
   s.push(2);
   s.push(3);
   s.push(5);
   s.push(6);
   s.push(7);
   s.push(8); //stack is full
   cout<<endl;
   s.top();
   s.display();
   s.pop();
   s.display();
   s.top();
   cout<<"size of stack="<<s.size();
 

}