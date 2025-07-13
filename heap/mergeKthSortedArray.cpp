#include<bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> Node;


vector<int>merges(vector<vector<int>>& array){
    priority_queue<Node,vector<Node>,greater<Node>>hp;

    vector<int>result;

    for(int i=0;i<array.size();i++){
        if(!array.empty()){
            hp.push({array[i][0],{i,0}});
        }

    }

    while(!hp.empty()){
        Node current=hp.top();
        hp.pop();

        int value=current.first;
        int arrayindx=current.second.first;
        int elemindx=current.second.second;
        result.push_back(value);


        if(elemindx+1<array[arrayindx].size()){
            hp.push({array[arrayindx][elemindx+1],{arrayindx,elemindx+1}});
        }
    }
return result;
}

int main(){
    vector<vector<int>>array={
           {1, 4, 5},
        {1, 3, 4},
        {2, 6}

    };
    vector<int>ans=merges(array);

    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}
