bool isvalid(vector<int> &stalls,int n,int k,int maxi){
    int cow=1,lastpos=stalls[0];


    for(int i=1;i<n;i++){
    if(stalls[i]-lastpos>=maxi){
        cow++;
        lastpos=stalls[i];
    }
    if(cow==k){
        return true;
    }

    }
    return  false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(),stalls.end());
    int n=stalls.size();
    if(k>n){
        return -1;
    }
    int s=0;
    int e=stalls[n-1]-stalls[0];
  int mid=s+(e-s)/2;
  int ans=0;
 
    while(s<=e){
        mid=s+(e-s)/2;

        if(isvalid(stalls,n,k,mid)){
            ans=mid;
           s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;



    

}