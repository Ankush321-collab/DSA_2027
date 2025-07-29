#include<bits/stdc++.h>
using namespace std;

vector<int> nextsmall(vector<int> &arr, int n) {
    stack<int> st;
    vector<int> ans(n);  // FIXED

    st.push(-1);  // Sentinel value

    for (int i = n - 1; i >= 0; i--) {
        int curr = arr[i];
        while (st.top()!=-1 && st.top() >= curr) {
            st.pop();
        }
        ans[i] = st.top();  // Safe now
        st.push(i);
    }
    return ans;
}

vector<int> prevsmall(vector<int> &arr, int n) {
    stack<int> st;
    vector<int> ans(n);  // FIXED

    st.push(-1);  // Sentinel value

    for (int i = 0; i <n; i++) {
        int curr = arr[i];
        while (st.top()!=-1 && st.top() >= curr) {
            st.pop();
        }
        ans[i] = st.top();  // Safe now
        st.push(i);
    }
    return ans;
}


int largestTriangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> next = nextsmall(heights, n);
    vector<int> prev = prevsmall(heights, n);
    
    int maxArea = 0;
    
    for (int i = 0; i < n; i++) {

        if (next[i] == -1) next[i] = n;  // If no next smaller element, use n
        if (prev[i] == -1) prev[i] = -1;  //
        int width = next[i] - prev[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }
    
    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int maxArea = largestTriangleArea(heights);
    cout << "Largest Triangle Area: " << maxArea << endl;
    return 0;
}