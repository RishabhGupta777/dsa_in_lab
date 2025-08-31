#include<iostream>
#include<math.h>
#include<string>
using namespace std;
class area{
public:
int a,b;
float result;
area(){
    input();
    result=a*b;
    cout<<"area of rectangle : "<<result;
}
void input(){
    cout<<"Enter the 1st no.";
    cin>>a; 
    cout<<"Enter the 2nd no.";
    cin>>b;
}
};
int main(){
 area a1;
 return 0;
}