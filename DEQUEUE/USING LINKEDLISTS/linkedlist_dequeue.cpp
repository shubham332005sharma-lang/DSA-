//TODO : IMPLEMENT DEQUEUE USING LINKED LISTS.
#include<iostream>
using namespace std;

// node class
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
    }
};

// deque class
class Deque{
    Node* front;
    Node* rear;
    public: 
    Deque(){
        front=rear=nullptr;
    }

    //enque_front function definition :
    void enque_front(int val){
        Node* new_node = new Node(val);
        if(front==nullptr){
            front=rear=new_node;
            return;
        }
        Node* temp=front;
        front->prev=new_node;
        new_node->next=front;
        front=new_node;
    }

    //enque_back function definition :
    void enque_back(int val){
        Node* new_node = new Node(val);
        if(front==nullptr){
            front=rear=new_node;
            return;
        }
        rear->next=new_node;
        new_node->prev=rear;
        rear=new_node;
    }

    //deque_front function defintion :
    void deque_front(){
        if(front == nullptr){
            cout<<"QUEUE UNDERFLOW "<<endl;
            return ;
        }
        Node* temp=front;
        front=front->next;
        delete temp;
    }

    //deque_rear function defintion :
    void deque_rear(){
        if(rear == nullptr){
            cout<<"QUEUE UNDERFLOW "<<endl;
            return ;
        }
        Node* temp = rear;
        rear = rear->prev;
        delete temp;
    }
    //display function defintion :
    void display(){
        if(front==nullptr){
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
{
    return 0;
}