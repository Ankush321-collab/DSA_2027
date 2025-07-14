#include<bits/stdc++.h>
using namespace std;
#define MAX 100

class Queue{
    int arr[MAX];
    int front;
    int rear;
public:
    Queue(){
        front=-1;
        rear=-1;
    }

    void enqueue(int x){
        if(rear==MAX-1){
            cout<<"Queue overflow condition";
            return;
        }
        if(front==-1){
        front=0;}
        arr[++rear]=x;
    }


    void dequeue(){
        if(rear==-1 ||front>rear){
            cout<<"queue underflow condition";
            return;
        }
        front++;
    }

    int peek(){
        if(front==-1 || front>rear){
            cout<<"No elemts";
            return -1;
        }
        return arr[front];
    }

    bool isempty(){
        return front>rear||front==-1;
    }


    void display(){
        if(front==-1 || rear==-1 ||front>rear){
            cout<<"nothing to display";
            return;
        }
        for(int i=front; i<=rear;i++){
            cout<<arr[i]<<" ";
        }
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);

    q.enqueue(30);

    q.enqueue(40);
    q.enqueue(50);
    cout<<"after pushing:"<<endl;
    q.display();

    q.dequeue();
    cout<<endl;
    cout<<"after poping:"<<endl;
    q.display();

    cout<<"is empty"<<(q.isempty() ?"yes":"No")<<" ";
    cout<<endl;
   q.display();

    return 0;


}