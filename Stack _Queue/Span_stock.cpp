#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st;

    StockSpanner() {
        // Constructor
    }

    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

int main() {
    StockSpanner* obj = new StockSpanner();

    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> result;

    cout << "Day\tPrice\tSpan\n";
    cout << "---------------------\n";
    for (int i = 0; i < prices.size(); i++) {
        int span = obj->next(prices[i]);
        result.push_back(span);
        cout << i + 1 << "\t" << prices[i] << "\t" << span << "\n";
    }

    return 0;
}
