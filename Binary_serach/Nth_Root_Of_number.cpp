#include<bits/stdc++.h>
using namespace std;


int fun(int n,int m,int mid){
    long long ans=1;

    for(int i=1;i<=n;i++){
        ans=ans*mid;
        if(ans>m)return 2;
    }
    if(ans==m)return 1;

   return 0; 
}


int number(int n,int m){
    //we will use binary search
    int l=1,h=m;

    while(l<=h){
        int mid=(l+h)/2;
        int midn=fun(n,m,mid);

        if(midn==mid)return mid;

        else if(midn==0)l=mid+1;
        else h=mid-1;
    }
    return -1
}

int main(){
    int n = 3, m = 27;
    int ans = number(n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}