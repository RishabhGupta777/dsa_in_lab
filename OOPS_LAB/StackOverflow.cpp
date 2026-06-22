// Stack Underflow Exception
#include <iostream>
using namespace std;

class Stack {
    int arr[5];
    int top;

public:
    Stack() { top = -1; }

    void push(int x) {
        if (top == 4)
            throw overflow_error("Stack Overflow!");
        arr[++top] = x;
    }

    int pop() {
        if (top == -1)
            throw underflow_error("Stack Underflow!");
        return arr[top--];
    }
};

int main() {
    Stack s;

    try {
        cout << "Popping an element..." << endl;
        cout << s.pop() << endl;  // No elements → exception
    }
    catch (const underflow_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}