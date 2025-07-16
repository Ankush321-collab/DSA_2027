#include<bits/stdc++.h>
using namespace std;


bool isvalid(string s){
    //first create stack
    stack<char>st;
    unordered_map<char,char>mp={{')','('}, {']', '['}, {'}', '{'}};

    for(char c:s){//ietration throug string if opening then
   if(mp.count(c)){//if its closing bracket then we will check in stack
    if(!st.empty() && st.top()==mp[c]){
        st.pop();
    }
    else{
    //if not present
    return false;

   }
}
else{
    //if its the opening bracken then push to stack
    st.push(c);
}
    }
    return st.empty()?true:false;


}

int main(){
    string s="()[]{}";
    bool ans=isvalid(s);
    if(ans){
        cout<<"true";
    }
    else{
        cout<<"false";
    }

    return 0;
}