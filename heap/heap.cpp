#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
 arr[0]=-1;
 size=0;

    }


    void insert(int val){
        size+=1;
        int indx=size;
        arr[indx]=val;
        while(indx>1){
            int parent=indx/2;
            if(arr[parent]<arr[indx]){
                swap(arr[parent],arr[indx]);
                indx=parent;
            }
            else{
                return;
            }
        
    }



    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    
    int amin(){
        heap h;
        h.insert(10);
         h.insert(20);
          h.insert(5);
           h.insert(30);
            h.insert(1);

            h.print();

    }

};
