#include<bits/stdc++.h>
using namespace std;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int total = n + m;

        // Handle empty array cases
        if (n == 0) {
            if (m % 2 == 1) return nums2[m / 2];
            return (nums2[m / 2] + nums2[m / 2 - 1]) / 2.0;
        }
        if (m == 0) {
            if (n % 2 == 1) return nums1[n / 2];
            return (nums1[n / 2] + nums1[n / 2 - 1]) / 2.0;
        }

        int i = 0, j = 0, count = 0;
        int ind1 = (total - 1) / 2;
        int ind2 = total / 2;

        int el1 = 0, el2 = 0;

        while (i < n && j < m) {
            int val;
            if (nums1[i] < nums2[j]) {
                val = nums1[i++];
            } else {
                val = nums2[j++];
            }

            if (count == ind1) el1 = val;
            if (count == ind2) el2 = val;
            count++;
        }

        while (i < n) {
            int val = nums1[i++];
            if (count == ind1) el1 = val;
            if (count == ind2) el2 = val;
            count++;
        }

        while (j < m) {
            int val = nums2[j++];
            if (count == ind1) el1 = val;
            if (count == ind2) el2 = val;
            count++;
        }

        if (total % 2 == 1) {
            return el2;
        }
        return (el1 + el2) / 2.0;
    }

    int main(){
        vector<int>nums1={1,2,3,4,5};
                vector<int>nums2={4,6,7,8,9};

                double ans=findMedianSortedArrays(nums1,nums2);

                cout<<ans<<endl;
                return 0;


    }

