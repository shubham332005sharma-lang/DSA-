//TODO: IMPLEMENT QUEUES USING VECTOR STL
#include<iostream>
#include<vector>
using namespace std;

class Queue{
    public:
    int front,rear;
    vector<int> array;   

    Queue(){
        front=0;
        rear=-1;
    }

// enque fucntion definiton
    void enque(int val){
        array.push_back(val);
        rear++;
    }

//  deque function definition 
    void deque(){
        if(front>rear){
            cout<<"QUEUE UNDEFLOW "<<endl;
            return;
        }
        front++;
        if (front > rear) {
        front = 0;
        rear = -1;
        }
    }

//peek funtion definition 
    int peek(){
        if(front>rear){cout<<"EMPTY QUEUE : PEEK DOESNT EXIST"<<endl;
        return -1;
        }
        return array[front];
    }

// size functrion defintion
    int size(){
        return rear-front+1;
    }

// display function definiton 
    void display(){
        if(front>rear){
            cout<<"QUEUE UNDERFLOW : nothing to display "<<endl;
            return;
        }
        for(int i=front;i<=rear;i++){
            cout<<array[i]<<endl;
        }
    }
};
int main()
{   Queue q;
    q.display();
    cout<<"size of queue is :"<<q.size()<<endl;
    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.display();
    cout<<"size of queue is :"<<q.size()<<endl;
    q.deque();
    q.display();
    return 0;
}