#include <bits/stdc++.h>
using namespace std;

class Vehicle {
public:
    void vehicleType() {
        cout << "Has a metallic body." << endl;
    }
};

class car{
public:
    void carType() {
        cout << "It has four wheels" << endl;
    }
};

class TataNano : public Vehicle ,public car{
    public:
    void nanoProperties() {
        cout << "It has comfortable price for the Middle Class family" << endl;
    }
};

int main(){
   TataNano T1;
   T1.vehicleType();
   T1.carType();
   T1.nanoProperties();
}