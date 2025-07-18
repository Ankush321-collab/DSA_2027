#include <iostream>
#include <vector>
#include <algorithm> // for min()

using namespace std;

class MinStack {
public:
    vector<pair<int,int>> st;

    MinStack() { }

    void push(int val) {
        if(st.empty()){
            st.push_back({val, val});
        } else {
            st.push_back({val, min(st.back().second, val)}); // comparing last min with new value
        }
    }

    void pop() {
        st.pop_back();
    }

    int top() {
        return st.back().first;
    }

    int getMin() {
        return st.back().second;
    }
};

int main() {
    MinStack ms;

    ms.push(5);
    ms.push(3);
    ms.push(7);
    ms.push(2);
    ms.push(6);

    cout << "Top element: " << ms.top() << endl;       // 6
    cout << "Minimum: " << ms.getMin() << endl;        // 2

    ms.pop(); // removes 6
    cout << "After pop:" << endl;
    cout << "Top element: " << ms.top() << endl;       // 2
    cout << "Minimum: " << ms.getMin() << endl;        // 2

    ms.pop(); // removes 2
    cout << "After another pop:" << endl;
    cout << "Top element: " << ms.top() << endl;       // 7
    cout << "Minimum: " << ms.getMin() << endl;        // 3

    return 0;
}
