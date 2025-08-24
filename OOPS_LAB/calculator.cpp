#include<iostream>
using namespace std;

int c=0;
void sum(int a,int b){
    c=a+b;
   }
    void sub(int a,int b){
    c=a-b;
   }
    void mul(int a,int b){
    c=a*b;
   }
    void divide(int a,int b){
    c=a/b;
   }

   
int main(){
   int a,b;
   cout<<"Ener the first no.";
   cin>>a;
   cout<<"Ener the 2nd no.";
   cin>>b;
   
   int option;
   cout<<"Chose Your opration:\n1:for sum\n2:for sub\n3:for mul,\n4:for dvide\n";
   cin>>option;
   switch(option){
    case 1: {
           sum(a,b);
        break;
    };
    case 2:{
          sub(a,b);
        break;
    };
    case 3:{
        mul(a,b);
    break;
    }
    case 4:{
        divide(a,b);
    break;
    }
   }

   cout<<c;
   
}