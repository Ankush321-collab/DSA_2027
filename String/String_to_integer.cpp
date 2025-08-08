#include<bits/stdc++.h>
using namespace std;

 int myAtoi(string s) {
        if(s.length()==0) return 0;
        int i=0;
        while(i<s.size() && s[i]==' '){
            i++;
        }
        s=s.substr(i);
        long ans=0;
        int sign=1;
        if(s[0]=='-')sign=-1;

        int max=INT_MAX,min=INT_MIN;

        i=(s[0]=='-' || s[0]=='+') ? 1:0;
        while(i<s.length()){
            if(s[i]==' ' || !isdigit(s[i]))break;
ans = ans * 10 + (s[i] - '0');
            if((ans*sign)>max)return INT_MAX;
            if((ans*sign)<min)return INT_MIN;
            i++;
        }
        return (ans*sign);
        
    }

    int main(){
        string s="  142ankush";
        int ans=myAtoi(s);
        cout<<ans;
        return 0;

    }