#include <bits/stdc++.h>
using namespace std;

class Student{
public:
    char name;
    int roll_no;
    Student(){
        cout<<"Give name:";
        cin>>name;
        cout<<"Give Roll no.:";
        cin>>roll_no;
    }

};

class marks:public Student{
public:
    int physics;
    int maths;
    marks(){
        cout<<"Give name:";
        cin>>name;
        cout<<"Give Roll no.:";
        cin>>roll_no;
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
//   boy Ram;
//   Ram.boyProperties();
//   Ram.humanProperty();
//   Ram.playerProperty();
//   Ram.studentProperty();
}