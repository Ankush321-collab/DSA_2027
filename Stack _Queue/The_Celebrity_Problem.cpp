#include<bits/stdc++.h>
using namespace std;


int cele(vector<vector<int>>& arr,int n){
    stack<int>st;

    for(int i=0;i<n-1;i++){
        st.push(i);
    }

    while(st.size()>1){
        int i=st.top();st.pop();
        int j=st.top();st.pop();

        if(arr[i][j]==0){
            st.push(i);  
        }
        else{
            st.push(j);
        }
    }

    int ans=st.top();
for (int i = 0; i < n; i++) {
        if (i != ans && (arr[i][ans] == 0 || arr[ans][i] == 1)) {
            return -1;
        }
    return ans;

}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int celebrity = cele(arr, n);
    cout << celebrity << endl;

    return 0;
}