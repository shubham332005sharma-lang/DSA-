//TODO: IMPLEMENT CIRCULAR QUEUES

//CONCEPT - mostly while implementing the ques when we deque , that space gets wasted .Circular queues are a good way to prevent that fromt happening.

//LOGIC - to return at the starting index we use rear = (rear+1)%capacity .this will always generate a number which belongs to [0,capacity-1].

#include<iostream>
using namespace std;
template <typename T>
class Queue{
    int front,rear,current_size;
    T* array;
    int capacity;
    public : 
    Queue(){
        front=0;
        rear=-1;
        current_size=0;
        capacity=10;
        array = new T[capacity];
    }

// enque function defintion :
    void enque(T val){
        if(current_size==capacity){
            cout<<"QUEUE OVERFLOW"<<endl;
            return;
        }
        rear = (rear+1)%capacity;
        array[rear]=val;
        current_size++;
    }

// deque function defintion :
    void deque(){
        if(current_size==0){
            cout<<"QUEUE UNDERFLOW"<<endl;
        }else{
        front=(front+1)%capacity;
        current_size--;
        }
    }
// display function defintion :
    void display(){
        if(current_size==0){
            cout<<"QUEUE IS EMPTY -> nothing to display";
        }else{
        int steps=0;
        int point=front;
        while(steps!=current_size){
            cout<<array[point]<<endl;
            point=(point+1)%capacity;
            steps++;
        }
    }
    }
// peek function defintion :
    T peek() {
        if (current_size == 0) {
            cout << "QUEUE IS EMPTY" << endl;
            return T();
        }else{
        return array[front];
        }
    }
// size function definition :
    int size() {
        return current_size;
    }
};
int main()
{   Queue<string> cq;
    cq.enque("ujjawal");
    cq.enque("shubham");
    cq.enque("naincy");
    cq.enque("shubham");
    cq.deque();
    cq.enque("deepanshu");
    cq.display();
    return 0;
}