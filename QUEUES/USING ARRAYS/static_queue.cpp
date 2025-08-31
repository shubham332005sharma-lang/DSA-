//TODO: IMPLEMENT QUEUES USING STATIC ARRAYS.
#include<iostream>
using namespace std;

class Queue{
    int front,rear;
    static const int MAX=100;
    int array[MAX];
    public:

    Queue(){
        front=0;
        rear=-1;
    }
// enque function definiton :
    void enque(int val){
        if(rear == MAX - 1){
            cout<<"QUEUE OVERFLOW "<<endl;
        }else{
            array[++rear]=val;
        }
    }
    
// deque fucntion definition :
    void deque(){
        if(front>rear){
            cout<< "QUEUE UNDERFLOW "<<endl;
        }else{
            front++;
        }
    }

// display function definition :
    void display(){
        if(front>rear){
            cout<<"QUEUE IS EMPTY "<<endl;
        }else{
            cout<<"QUEUE : BOTTOM TO TOP "<<endl;
            for(int i =front; i<=rear;i++){
                cout<<array[i]<<endl;
            }
        }
    }

// size function definition 
    int size(){
        return rear-front+1;
    }

//peek function definition :
    int peek(){
        if(front > rear){
            cout << "QUEUE IS EMPTY" << endl;
            return -1;
        }
        return array[front];
    }

};
int main()
{   Queue q1;
    q1.deque();
    q1.display();
    q1.enque(5);
    q1.enque(6);
    q1.enque(7);
    q1.display();
    q1.deque();
    q1.display();
    cout<<"SIZE OF QUEUE IS :" <<q1.size()<<endl;

    return 0;
}