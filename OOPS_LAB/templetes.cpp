#include <iostream>
using namespace std;

// Template definition for the vector class
template <class T>
class vector {
public:
    T * arr;
    int size;

    // Constructor to initialize the vector
    vector(int m) {
        size = m;
        arr = new T[size]; // Dynamic allocation of an array of type T
    }
    
    // Member function to calculate the dot product of two vectors
    T dotProduct(vector &v) {
        T d = 0; // Initialize the dot product result
        
        for (int i = 0; i < size; i++) {
            // Calculate the sum of the product of corresponding elements
            d += this->arr[i] * v.arr[i]; 
        }
        
        return d;
    }
    
};

int main() {
    // 1. Example using float vectors
    
    // Create vector v1 of size 3 with float elements
    vector <float> v1(3);  // like class obj;
    v1.arr[0] = 1.4;       // like obj.something
    v1.arr[1] = 3.3;
    v1.arr[2] = 0.1;
    
    // Create vector v2 of size 3 with float elements
    vector <float> v2(3);
    v2.arr[0] = 0.1;
    v2.arr[1] = 1.90;
    v2.arr[2] = 0.1;
    
    // Calculate the dot product
    float a = v1.dotProduct(v2);
    
    // The calculation is: (1.4 * 0.1) + (3.3 * 1.90) + (0.1 * 0.1)
    // 0.14 + 6.27 + 0.01 = 6.42
    
    cout << a << endl;
    
    // You could also test with int vectors, although it's not shown in the main function screenshots:
    // vector <int> v3(3);
    // v3.arr[0] = 1;
    // v3.arr[1] = 2;
    // v3.arr[2] = 3;
    
    // vector <int> v4(3);
    // v4.arr[0] = 4;
    // v4.arr[1] = 5;
    // v4.arr[2] = 6;
    
    // int b = v3.dotProduct(v4); // (1*4) + (2*5) + (3*6) = 4 + 10 + 18 = 32
    // cout << b << endl;
    
    return 0;
}