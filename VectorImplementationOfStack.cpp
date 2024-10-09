#include<iostream>
#include<vector>
using namespace std;

void push( vector<int>&v,int val){
      v.push_back(val); //vector never be overflow due to it has infinite space
}
void pop(vector<int>&v){
    if(v.size()==0){
       cout<<"stack is Empty";
        return; 
    }
        v.pop_back();
    
}
void top(vector<int>&v){
    if(v.size()==0){
       cout<<"stack is Empty";
        cout<<endl;
        return; 
    }
    cout<<v[v.size()-1];
    cout<<endl;
}

int size(vector<int>&v){
   return v.size();
}

void display(vector<int>&v){
    for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
   }
   cout<<endl;
}

int main(){
    vector<int> v;
   top(v);
   pop(v);
   push(v,2);
   push(v,3);
   push(v,5);
   push(v,6);
   push(v,7);
   push(v,8);
   cout<<endl;
   top(v);
   display(v);
   pop(v);
   display(v);
   top(v);
   cout<<"size of stack="<<size(v);
 
 
}