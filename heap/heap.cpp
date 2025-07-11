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
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deletefromheap(){
        if(size==0){
            cout<<"nothing to delete" << endl;
            return;
        }
        arr[1]=arr[size];
        size--;
        int i=1;
        while(i<=size){
            int left=2*i;
            int right=2*i+1;
            int largest=i;

            if(left<=size && arr[left]>arr[largest]){
                largest=left;
            }
            if(right<=size && arr[right]>arr[largest]){
                largest=right;
            }
            if(largest!=i){
                swap(arr[i],arr[largest]);
                i=largest;
            }
            else{
                break;
            }
        }
    }
};

int main(){
    heap h;
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);
    h.insert(1);

    h.print();
    h.deletefromheap();
    h.print();
}