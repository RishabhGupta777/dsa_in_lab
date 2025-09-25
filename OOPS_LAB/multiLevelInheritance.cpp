#include <bits/stdc++.h>
using namespace std;


class Vehicle {
public:
    void vehicleType() {
        cout << "Has a metallic body." << endl;
    }
};

class car:public Vehicle{
public:
    void carType() {
        cout << "It has four wheels" << endl;
    }
};
class sportsCar:public car{
public:
    void sportsFeratures() {
        cout << "This is a high speedCar." << endl;
    }
};
class ElectricSportsCar:public sportsCar{
public:
    void ElectricSportsCarFeatures() {
        cout << "This is a electric car runs for 400 km on one time full charged." << endl;
    }
};

int main(){
    ElectricSportsCar farari;  
    farari.vehicleType();  
    farari.carType();
    farari.sportsFeratures();
    farari.ElectricSportsCarFeatures();
}