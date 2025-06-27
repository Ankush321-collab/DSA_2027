#include<bits/stdc++.h>
using namespace std;


struct Job{
    char id;
    int profit;
    int deadline;
};

bool comp(Job a,Job b){
    return a.profit>b.profit
;}

pair<int,int> fun(vector<Job>&job,int n){
    sort(job.begin(),job.end(),comp);
    int maxDeadline = 0;

    for(int i=0;i<n;i++){
        maxDeadline = max(maxDeadline, job[i].deadline);    

    }

    vector<int>slot(maxDeadline+1,-1);
    int profit=0;
    int countjob=0;

    //function to assign jobs to slots
    for(int i=0;i<n;i++){
        for(int j=job[i].deadline;j>0;j--){
            if(slot[j]==-1){
                //assign ith job 
                slot[j]=i;
                countjob++;
                profit+=job[i].profit;
                break;
            }
        }
    }
    return {countjob, profit};
}

int main(){
    int n;
    cout<<"enter the value of n:";
    cin>>n;

    vector<Job>job(n);
    cout<<"enter the jobs with id, profit and deadline:\n";
    for(int i=0;i<n;i++){
        cin>>job[i].id>>job[i].profit>>job[i].deadline  ;
      }
     pair<int,int>ans= fun(job,n);
    cout<<"Total jobs done: "<<ans.first<<endl;
    cout<<"Total profit: "<<ans.second<<endl;
    return 0;
      

}