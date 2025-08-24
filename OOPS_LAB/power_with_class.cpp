#include<iostream>
#include <cmath>
using namespace std;
class power{
private:
int a;
int b;
public:
void print(){
    cout<<"print the value of a";
    cin>>a; 
    cout<<"print the value of b";
    cin>>b;

}

void use(){
  cout<< pow(a,b);
     
}
};
int main(){
    power p1;
    p1.print();
    p1.use();
}