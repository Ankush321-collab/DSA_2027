// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // Function to find the sum of contiguous subarray with maximum sum.
    static int maxSubarraySum(int arr[], int n) {
        int sum = 0;
        int maxi = arr[0];
        
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            maxi = max(sum, maxi);
            
            if (sum < 0)
                sum = 0;
        }
        return maxi;
    }
};

// { Driver Code Starts.

int main() {
    int arr[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = 9;

    int ans = Solution::maxSubarraySum(arr, n);
    cout << "ans is: " << ans << endl;

    return 0;
}

// } Driver Code Ends
