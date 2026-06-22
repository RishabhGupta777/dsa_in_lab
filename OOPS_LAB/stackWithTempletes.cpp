#include <iostream>
using namespace std;

template <class T>
class Stack {
private:
    T stack[100];   
    int top;        

public:
    Stack() {
        top = -1;   
    }

    void push(T value) {
        if (top >= 99) {
            cout << "Stack Overflow!" << endl;
        } else {
            stack[++top] = value;
            cout << value << " pushed into stack." << endl;
        }
    }


    void pop() {
        if (top < 0) {
            cout << "Stack Underflow!" << endl;
        } else {
            cout << stack[top--] << " popped from stack." << endl;
        }
    }

    void display() {
        if (top < 0) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    
    Stack<int> intStack; //integer ka stack
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.display();
    intStack.pop();
    intStack.display();

    return 0;
}
