#include<bits/stdc++.h>
using namespace std;
//

struct Item{
    int profit;
    int weight;
};

bool cmp(Item a,Item b){
    int r1=(double)a.profit/a.weight;
    int r2=(double)b.profit/b.weight;
    return r1>r2;
}

int maximum(int w,vector<Item>&arr,int n){
    sort(arr.begin(),arr.end(),cmp);

    double totalvalue=0.0;

    for(int i=0;i<n;i++){
        if(arr[i].weight<=w){
            totalvalue+=arr[i].profit;
            w-=arr[i].weight;

        }
        else{
            //weight of item is more so we wiil b e gfredd and take fraction value*a/item weight

            totalvalue+=arr[i].profit*((double)w/arr[i].weight0);
            break;
            //using break to come outside of loop 
        }
    }
    return totalvalue;

}

int main(){
    int n,w;
    cout<<"Enter the number of items: ";
    cin>>n;
    cout<<"Enter the capacity of knapsack: ";
    cin>>w;

    vector<Item>arr(n);
    cout<<"Enter the profit and weight of each item:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i].profit>>arr[i].weight;
    }

    double maxProfit = maximum(w, arr, n);
    cout<<"Maximum profit in fractional knapsack is: "<<maxProfit<<endl;

    return 0;
}

