#include <bits/stdc++.h>
using namespace std;

class Mystack {
public:
    queue<int> q1, q2;

    Mystack() {}

    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front()); // corrected from s1.top() to q1.front()
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }

    bool isempty() {
        return q1.empty();
    }
};

int main() {
    Mystack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "Top element: " << s.top() << endl; // Should print 40

    s.pop(); // Removes 40

    cout << "Top after pop: " << s.top() << endl; // Should print 30

    cout << "Empty or not: " << (s.isempty() ? "yes" : "no") << endl;

    return 0;
}
