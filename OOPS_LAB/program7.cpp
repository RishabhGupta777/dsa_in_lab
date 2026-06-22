#include <bits/stdc++.h>
using namespace std;

class DB;
class DM{
    public:
    float metres;
    float centimetres;
    public:
    void getData(){
        cout<<"Enter Distance in m and cm:\n";
        cout<<"Metres: ";
        cin>>metres;
        cout<<"Centrimeters: ";
        cin>>centimetres;
    }
    void showData(){
        cout<<"Distance= "<<metres<<"metres and"<<centimetres<<"centimetres\n";
    }
    friend void add(DM,DB);
};

class DB{
    public:
    float feet;
    float inches;
    public:
    void getData(){
        cout<<"Enter Distance in feet and inches:\n";
        cout<<"Feet: ";
        cin>>feet;
        cout<<"Inches: ";
        cin>>inches;
    }
    void showData(){
        cout<<"Distance= "<<feet<<"feet and"<<inches<<"inches\n";
    }
    friend void add(DM,DB);
};

void add(DM m,DB b){
    float sumMetres =m.metres + (m.centimetres/100) + (b.feet * 0.3048)*(b.inches* 0.0254);
    int metres=int(sumMetres);
    float centimeters=(sumMetres-metres)*100;

cout<<"After adding\n";
cout<<"Total Distances= "<<metres<<"metres and"<<centimeters<<"centimetres\n";

}

int main(){
    DB b;
    DM m;
    m.getData();
    b.getData();
    cout<<"choose 1 for metes and centrimetres and 2 for feet and inches";
    int expression;
    cin>>expression;
    switch (expression)
    {
    case 1:
        add(m,b);
        break;
    case 2: {
            // Compute total in feet/inches directly
            float totalMeters = m.metres + (m.centimetres / 100)
                                + (b.feet * 0.3048) + (b.inches * 0.0254);

            float totalInFeet = totalMeters / 0.3048;
            int feet = int(totalInFeet);
            float inches = (totalInFeet - feet) * 12;

            cout << "\nAfter adding (in feet and inches):\n";
            cout << "Total Distance = " << feet << " feet and " << inches << " inches\n";
            break;
        }

        default:
            cout << "Invalid choice!\n";
            break;
    

    return 0;
}}