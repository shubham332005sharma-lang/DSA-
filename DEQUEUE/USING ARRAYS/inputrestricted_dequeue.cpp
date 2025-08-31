//TODO : IMPLEMENT INPUT RESTRICTED DEQUEUE USING ARRAYS

//CONCEPT - dequeue is also called doubly ended queue , its a queue which supports more operations such as removing from rear or inserting at the end . Dequeues with some restrictions are :-                                                                                                                i) input restricted dequeue                                                                                         ii) output resticted dequeue

#include<iostream>
#include<optional>
using namespace std;

class Dequeue{
    int front,rear,capacity,curr_size;
    int* array;
    public:
    Dequeue(int val){
        curr_size=0;
        rear=-1;
        front=0;
        this->capacity=val;
        array=new int[capacity];
    }
    Dequeue(){
        curr_size=0;
        front=0;
        rear=-1;
        capacity=10;
        array = new int[capacity]; 
        
    }

    //enque_back function defintion :-
    void enque_back(int val){
        if(curr_size==capacity){
            cout<<"QUEUE OVERFLOW"<<endl;
        }
        else{
            rear=(rear+1)%capacity;
            array[rear]=val;
            curr_size++;
        }
    }

    //enque_front fucntion defintion : 
    void enque_front(int val) {
        if (curr_size == capacity) {
            cout << "QUEUE OVERFLOW" << endl;
            return;
        }
        front = (front - 1 + capacity) % capacity; //modular wrapper which prevents -ve value and moves backwards.
        array[front] = val;
        curr_size++;
    }

    //deque_back function definition :
    void deque_back(){
        if(curr_size==0){
            cout<<"QUEUE UNDERFLOW -> NOTHING TO REMOVE"<<endl;
        }else{
            rear = (rear - 1 + capacity) % capacity;
            curr_size--;
        }
    }

    //deque_front function defintion :
    void deque_front(){
        if(curr_size==0){
            cout<<"QUEUE UNDERFLOW -> NOTHING TO REMOVE"<<endl;
        }else{
            front=(front+1)%capacity;
            curr_size--;
        }
    }

    //peek function defintion :
        int  peek(){
        if(curr_size==0){
            cout<<"QUEUE IS EMPTY -> PEEK ABSENT";
            return -1; //this returns null value when peek doesnt exists .
        }
        return array[rear];
    }

    //display function defintion :
    void display(){
        if(curr_size==0){
            cout<<"EMPTY ARRAY-> NOTHING TO DISPLAY"<<endl;
            return;
        }
        int count=0;
        int temp=front;
        while(count!=curr_size){
            cout<<array[temp]<<endl;
            temp=(temp+1)%capacity;
            count++;
        }
    }

};

class inputrestricted : public Dequeue{
    public :
    using Dequeue::deque_back;
    using Dequeue::deque_front;
    using Dequeue::enque_front;
    private :
    using Dequeue::enque_back;

    // a smart way to inherit only specific fucntions from a class to a subclass :
};
int main()
{   inputrestricted q;
    q.display();
    cout<<q.peek()<<endl;
    // q.enque_back(2);
    // q.enque_back(2);                 they wont work due to restricted inheritance.
    // q.enque_back(3);
    // q.enque_back(4);
    q.enque_front(1);
    q.enque_front(1);
    q.enque_front(1);
    q.enque_front(1);
    q.enque_front(1);
    q.enque_front(1);
    q.enque_front(1);
    q.deque_front();
    q.deque_front();
    q.enque_front(0);
    q.deque_back();
    cout<<" peek is: " << q.peek()<<endl;
    q.display();
    return 0;
}