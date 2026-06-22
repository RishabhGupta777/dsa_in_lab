#include <bits/stdc++.h>
using namespace std;

class Queue {
    int arr[5];
    int front, rear, size;

public:
    Queue() {
        front = -1;
        rear = -1;
        size = 5;
    }

    void add(int x) {
        if ((rear + 1) % size == front) {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1) front = 0;

        rear = (rear + 1) % size;
        arr[rear] = x;
    }

    void remove() {
        if (front == -1) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << "Removed: " << arr[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }

        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.add(1);
    q.add(2);
    q.add(3);

    q.display();

    q.remove();
    q.display();
}