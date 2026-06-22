#include <iostream>
using namespace std;

class TollBooth {
private:
    unsigned int payingCars;
    unsigned int nonPayingCars;
    double totalCash;

public:
    TollBooth() : payingCars(0), nonPayingCars(0), totalCash(0.0) {}

    void payingCar() {
        payingCars++;
        totalCash += 50.0;   // toll amount
    }

    void nonPayingCar() {
        nonPayingCars++;
    }

    void display() const {
        cout << "\n--- Toll Booth Report ---\n";
        cout << "Paying cars: " << payingCars << endl;
        cout << "Non-paying cars: " << nonPayingCars << endl;
        cout << "Total cars: " << (payingCars + nonPayingCars) << endl;
        cout << "Total cash collected: ₹" << totalCash << endl;
    }
};

int main() {
    TollBooth t;
    char choice;

    do {
        cout << "\nEnter car type:";
        cout << "\nP - Paying car";
        cout << "\nN - Non-paying car";
        cout << "\nQ - Quit and display report";
        cout << "\nChoice: ";
        cin >> choice;

        switch (toupper(choice)) {
            case 'P': t.payingCar(); break;
            case 'N': t.nonPayingCar(); break;
            case 'Q': t.display(); break;
            default: cout << "Invalid input! Try again.\n";
        }

    } while (toupper(choice) != 'Q');

    return 0;
}
