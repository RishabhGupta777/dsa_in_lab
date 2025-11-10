#include <iostream>

using namespace std;

// Template definition with two type parameters: T1 and T2
template<class T1, class T2>
class myClass {
public:
    // Member variables of the two different template types
    T1 data1;
    T2 data2;

    // Constructor to initialize the data members
    myClass(T1 a, T2 b) {
        data1 = a;
        data2 = b;
    }

    // Function to display the data members
    void display() {
        // Outputting data1, a newline, and then data2
        cout << this->data1 << endl << this->data2;
    }
};

int main() {
    // Creating an object 'obj' of myClass. 
    // T1 is explicitly set to 'char' and T2 to 'float'.
    // The constructor is called with 'C' (char) and 1.8 (float).
    myClass<char, float> obj('C', 1.8); 
    
    // Calling the display function on the object
    obj.display();
    
    return 0;
}