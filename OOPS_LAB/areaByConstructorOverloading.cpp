//types of polymorphism
//1.fn area 2.
#include<iostream>
#include<math.h>
#include<string>
using namespace std;
class area{
public:
float result;

area(int a){
    result=a*a;
    print("square");
   }
area(int a,int b){
    result=a*b;
    print("rectangle");
   }
area(int a,int b,int c){
    double s = (double)(a+b+c)/2; //typeCasting
    result= sqrt(s*(s-a)*(s-b)*(s-c));
    print("triangle");
   }
   
     void print(string s){
    cout << "area of "<<s<<"="<< result << endl;
  }

};
int main(){
    int a,b,c,d;
    cout<<"Enter the 1st no.";
    cin>>a; 
    cout<<"Enter the 2nd no.";
    cin>>b;
    cout<<"Enter the 3rd no.";
    cin>>c;
    area a1(a);
    area a2(a,b);
    area a3(a,b,c);
    
    
}