#include <iostream>
using namespace std;

class A{
 private:
 int a_ka_private=10;
 private:
 friend void show(A &a); //int a_ka_private staic nahi to use object bana kar hi deal karenge
     //and friend function ke sath A ka object bhi bejh dena is a good practice
};

void  show(A &a){  //ye show fn us class ka part nahi h globally declared h phir bhi dekh lo 
                   //friend function ki tagat a_ke_private ko access karwa diya
    cout<<a.a_ka_private; //show a ka friend h so hum a_ke_private ko access kr paye
}

int main(){
    A a;
    show(a);

}