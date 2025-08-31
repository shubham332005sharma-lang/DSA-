//TODO : IMPLEMENT CIRCULAR LINKED LISTS IN C++.
// CONCEPT - a circular linked list is a list where last node pints to the first node instead of nullptr . they can be singly linked or doubly linked .

#include<iostream>
using namespace std;

// creating a node class 
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        this->data=val;
        this->next=nullptr;
    }
    ~Node(){
    }
};
// creating a list class
class Lists{
    public:
    Node* head;
    Node* tail;

    Lists(){
        head=tail=nullptr;
    }
    ~Lists(){
        if (head == nullptr) return;

        Node* temp = head;
        do {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != head);

        head = tail = nullptr;
    }
    
// declaring funcions:
void push_front(int val);
void push_back(int val);
void display();
void pop_front();
void pop_back();
void insert(int val,int pos);
void pop_index(int pos);
};
int main()
{   Lists l1;
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);
    l1.push_back(0);
    l1.pop_back();
    // l1.pop_front();
    l1.display();
    cout<<l1.head->data<< "  "<<l1.tail->data;
    return 0;
}

                //- defining the functions 
// push front function
void Lists::push_front(int val){
    if(head==nullptr){
        Node* new_node=new Node(val);
        head=tail=new_node;
        new_node->next=head;
        return;
    }
    Node* new_node=new Node(val);
    new_node->next=head;
    tail->next=new_node;
    head=new_node;

}
// display fucntion
void Lists::display(){
    if(head==nullptr){
        cout<<" empty list ."<<endl;
        return;
        
    }
    if(head==tail){
        cout<<head->data<< " -> "<<head->data <<endl;
        return;
    }
    Node* temp =head;
    while(temp !=tail){
        cout<< temp->data<<" -> ";
        temp=temp->next;
    }
    cout<< temp->data<<" -> "<<head->data<<endl;
}
// push back fucntion
void Lists::push_back(int val){
    if(head==nullptr){
        Node* new_node=new Node(val);
        head=tail=new_node;
        new_node->next=head;
        return;
    }
    Node* new_node=new Node(val);
    new_node->next=head;
    tail->next=new_node;
    tail=new_node;
}
// pop front function
void Lists::pop_front(){
    if(head==nullptr){
        cout<<" EMPTY LIST."<<endl;
    }
    else if(head==tail){
        delete head;
        head=tail=nullptr;
    }
    else{
        Node* temp=head;
        tail->next=head->next;
        head=head->next;
        delete temp;
    }

}
// pop back fucntion
void Lists::pop_back(){
    if(head==nullptr){
        cout<<" EMPTY LIST."<<endl;
    }
    else if(head==tail){
        delete head;
        head=tail=nullptr;
    }
    else{
        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=head;
        delete tail;
        tail=temp;
    }

}
