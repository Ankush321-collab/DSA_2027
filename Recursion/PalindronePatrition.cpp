#include<bits/stdc++.h>
using namespace std;


bool ispal(string s){
    int n=s.size();

    int i=0,j=n-1;

    while(i<=j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
}

void rec(string &s,vector<vector<string>>&ans,vector<string>&temp,int ind){
    int n=s.size();

    if(ind==n){
        ans.push_back(temp);
        return;
    }

    for(int i=ind;i<n;i++){
        string str=s.substr(ind,i-ind+1);
        if(ispal(str)){
            temp.push_back(str);
            rec(s,ans,temp,i+1);
            temp.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;

     rec(s,ans,temp,0);
     return ans;
        
    }

    int main(){
        string s;
        cout<<"enter the string:";
        cin>>s;

        vector<vector<string>>res=partition(s);


       for (auto i : res) {
    cout << "{ ";
    for (auto j : i) {
        cout << j << " ";
    }
    cout << "}" << endl;
}

        return 0;
    }