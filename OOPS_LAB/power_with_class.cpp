#include<iostream>
#include <cmath>
using namespace std;
class power{
private:
int a;
int b;
public:
void Input(){
    cout<<"Enter the value of a : ";
    cin>>a; 
    cout<<"Enter the value of b : ";
    cin>>b;

}

void use(){
  cout<< pow(a,b);
     
}
};
int main(){
    power p1;
    p1.Input();
    p1.use();
}