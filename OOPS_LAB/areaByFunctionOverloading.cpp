//types of polymorphism
//1.fn overloading 2.
#include<iostream>
#include<math.h>
#include<string>
using namespace std;
class overloading{
public:
int a,b,c,d;
float result;

void input(){
    cout<<"Enter the 1st no.";
    cin>>a; 
    cout<<"Enter the 2nd no.";
    cin>>b;
     cout<<"Enter the 3rd no.";
    cin>>c;
}
void area(int a){
    result=a*a;
   }
void area(int a,int b){
    result=a*b;
   }
   void area(int a,int b,int c){
    double s = (double)(a+b+c)/2; //typeCasting
    result= sqrt(s*(s-a)*(s-b)*(s-c));
   }
   
     void print(string s){
    cout << "area of "<<s<<"="<< result << endl;
  }

};
int main(){
    overloading p1;
    p1.input();
    p1.area(p1.a);
     p1.print("square");
    p1.area(p1.a,p1.b);
     p1.print("rectangle");
    p1.area(p1.a,p1.b,p1.c);
     p1.print("triangle");
    
}