#include<iostream>
#include <cmath>
using namespace std;
class power{
private:
int a;
int b;
public:
void print(){
    cout<<"print the value of a : ";
    cin>>a; 
    cout<<"print the value of b : ";
    cin>>b;
}

~power() {
    cout << "Destructor called! Object is being destroyed." << endl;
}

void use(){
  cout<< pow(a,b)<<endl;     
}



};
int main(){
    power p1;
    p1.print();
    p1.use();
}