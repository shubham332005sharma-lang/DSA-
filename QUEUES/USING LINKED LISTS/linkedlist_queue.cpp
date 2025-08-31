//TODO: IMPLEMENT QUEUE USING LINKED LISTS.
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        this->data=val;
        this->next=nullptr;
    }
};
class Queue{
    Node* front;
    Node* rear;
    public:
    Queue(){
        front=nullptr;
        rear=nullptr;
    }

    //enque fucntion definition :
    void enque(int val){
        Node* new_node = new Node(val);
        if(front==nullptr){
            front=rear=new_node;
            return;
        }
        rear->next=new_node;
        rear=new_node;
    }

    //deque function defintion :
    void deque(){
        if(front == nullptr){
            cout<<"QUEUE UNDERFLOW "<<endl;
            return ;
        }
        Node* temp=front;
        front=front->next;
        delete temp;
    }

    //display function defintion :
    void display(){
        if(front==rear){
            cout<<"EMPTY QUEUE -> NOTHING TO BE DISPLAYED"<<endl;
            return;
        }
        Node* temp=front;
        cout<<"QUEUE : FRONT TO REAR"<<endl;
        while(temp!=nullptr){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
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
    return 0;
}