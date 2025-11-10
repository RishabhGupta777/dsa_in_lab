#include <bits/stdc++.h>
using namespace std;

class Number{
    int number;
public:
Number(int n=0){
    number = n;
}
void operator-(){
    number=-number;
}

void display(){
    cout<<"number: "<<number<<endl;
}

};
int main(){
Number n1(10);
-n1;
n1.display();
}