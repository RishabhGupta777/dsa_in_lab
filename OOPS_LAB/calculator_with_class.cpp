#include<iostream>
using namespace std;
class power{
private:
int a;
int b;
int c;
public:
void input(){
    cout<<"Enter the 1st no.";
    cin>>a; 
    cout<<"Enter the 2nd no.";
    cin>>b;
}

void sum(){
    c=a+b;
   }
    void sub(){
    c=a-b;
   }
    void mul(){
    c=a*b;
   }
    void divide(){
    c=a/b;
   }

  void print(){
    cout<<c;
  }

};
int main(){
    power p1;
    p1.input();
    char option;
   cout<<"Chose Your opration:\nfor sum:+\nfor sub:-\nfor mul:*\nfor dvide:/\n";
   cin>>option;
    if(option=='+'){
           p1.sum();
    }
    else if(option=='-'){
           p1.sub();
    }
    else if(option=='*'){
           p1.mul();
    }
    else if(option=='/'){
           p1.divide();
    };
    p1.print();
}