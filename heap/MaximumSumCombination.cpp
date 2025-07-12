#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> s;

        pq.push({a[n - 1] + b[n - 1], {n - 1, n - 1}});
        s.insert({n - 1, n - 1});

        vector<int> ans;

        while (k--){
            auto p = pq.top();
            pq.pop();
            int sum = p.first;
            int i = p.second.first;
            int j = p.second.second;

            ans.push_back(sum);

            if (s.find({i - 1, j}) == s.end()) {
                pq.push({a[i - 1] + b[j], {i - 1, j}});
                s.insert({i - 1, j});
            }

            if (s.find({i, j - 1}) == s.end()) {
                pq.push({a[i] + b[j - 1], {i, j - 1}});
                s.insert({i, j - 1});
            }
        }

        return ans;
    }
};

    int main(){
        vector<int> a = {3, 2};
    vector<int> b = {1, 4};
    int k = 2;
    Solution sol;

    vector<int>ans=sol.topKSumPairs(a,b,k);

cout<<"[";
    for(auto i:ans){
        cout<<i<<",";
    }
    cout<<"]";
    
    return 0;
    }

