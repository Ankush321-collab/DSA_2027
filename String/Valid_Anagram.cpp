#include<bits/stdc++.h>
using namespace std;
    bool isAnagram(string s, string t) {
        
        unordered_map<int,int>mp;
        if(s.size()!=t.size()) return false;

        for(int i=0;i<=s.size();i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for (auto i:mp){
            if(i.second!=0)return false;
        }
        return true;
        
    }
int main (){
    string s="cat";
    string t="act";

    bool ans=isAnagram(s,t);
    cout<<ans;

}