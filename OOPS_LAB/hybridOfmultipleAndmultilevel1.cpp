#include <bits/stdc++.h>
using namespace std;

class human{
public:
    void humanProperty() {
        cout << "Be Spritual." << endl;
    } 
};

class Student:public human{
public:
     void studentProperty() {
        cout << "Be polite." << endl;
    } 
};

class player{
    public:
    void playerProperty(){
        cout << "Be Active anywhere and Fit" << endl;
    }

};

class boy:public Student,public player{
   public:
   void boyProperties() {
        cout << "He is a good boy" << endl;
    }
};

int main(){
  boy Ram;
  Ram.boyProperties();
  Ram.humanProperty();
  Ram.playerProperty();
  Ram.studentProperty();
}