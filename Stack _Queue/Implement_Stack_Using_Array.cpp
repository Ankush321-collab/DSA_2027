#include <bits/stdc++.h>
using namespace std;

#define MAX 100

class Stack {
public:
    int arr[MAX];
    int top;

    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top >= MAX - 1) {
            cout << "Stack is overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (top < 0) {
            cout << "Stack is underflow\n";
            return;
        }
        top--;
    }

    int peek() {
        if (top < 0 || top >= MAX) {
            cout << "Not capable of showing\n";
            return -1;
        }
        return arr[top];
    }

    bool isempty() {
        return top < 0;
    }

    void display() {
        if (top < 0) {
            cout << "No elements in stack\n";
            return;
        }
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    s.pop();

    cout << "Is stack empty? " << (s.isempty() ? "Yes" : "No") << endl;
    cout << "Top element: " << s.peek() << endl;
    cout << "Stack contents: ";
    s.display();

    return 0;
}
