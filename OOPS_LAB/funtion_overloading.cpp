//types of polymorphism
//1.fn overloading 2.
#include<iostream>
using namespace std;
class overloading{
public:
int a,b,c,d;
int result;

void input(){
    cout<<"Enter the 1st no.";
    cin>>a; 
    cout<<"Enter the 2nd no.";
    cin>>b;
     cout<<"Enter the 3rd no.";
    cin>>c; 
    cout<<"Enter the 4th no.";
    cin>>d;
}

void sum(int a,int b){
    result=a+b;
   }
   void sum(int a,int b,int c){
    result=a+b+c;
   }
   void sum(int a,int b,int c,int d){
    result=a+b+c+d;
   }
     void print(){
    cout << "Result = " << result << endl;
  }

};
int main(){
    overloading p1;
    p1.input();
    p1.sum(p1.a,p1.b);
     p1.print();
    p1.sum(p1.a,p1.b,p1.c);
     p1.print();
    p1.sum(p1.a,p1.b,p1.c,p1.d);
     p1.print();
    
}