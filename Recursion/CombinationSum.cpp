#include <bits/stdc++.h>
using namespace std;

void fun(vector<int>& arr, int target, vector<vector<int>>& res, vector<int>& ans, int i) {
    int n = arr.size();

    if (i == n) {
        if (target == 0) {
            res.push_back(ans);
        }
        return; // Important: return after reaching the end
    }

    // Take the element if it's less than or equal to target
    if (arr[i] <= target) {
        ans.push_back(arr[i]);
        fun(arr, target - arr[i], res, ans, i); // same index because repetition is allowed
        ans.pop_back(); // backtrack
    }

    // Skip the current element and move forward
    fun(arr, target, res, ans, i + 1);
}

vector<vector<int>> sum(vector<int> arr, int target) {
    vector<vector<int>> res;
    vector<int> ans;
    sort(arr.begin(), arr.end()); // Optional but helps to keep things ordered
    fun(arr, target, res, ans, 0);
    return res;
}

int main() {
    int n, target;
    cout << "enter the value of n: ";
    cin >> n;

    cout << "enter the target: ";
    cin >> target;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> result = sum(arr, target);

    for (auto i : result) {
        cout << "{ ";
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
