//TODO:  IMPLEMENT A GENERIC STACKS USING LINKED LISTS :
#include<iostream>
using namespace std;
template<typename T=int>
class Node{
    public:
    T data;
    Node<T>* next;
    Node(T val){
        this->data=val;
        this->next=nullptr;
    }
};
template<typename T=int>
class Stack{
    Node<T>* head;
    public:
    Stack(){
        head=nullptr;
    }

    ~Stack(){
        Node<T>* temp =head;
        while(temp!=nullptr){
            Node<T>* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
    //push fucntion definition
    void push(T val){
        Node<T>* new_node= new Node<T>(val);
        new_node->next=head;
        head=new_node;
    }

    //pop function definition
    void pop(){
        if(head!=nullptr){
        Node<T>* temp=head;
        head=head->next;
        delete temp;}
        else{
            cout<<"STACK UNDERFLOW"<<endl;
        }
    }

    //peek fucntion definiton
    T peek(){
        if(head==nullptr){
            cout<<" STACK IS EMPTY "<<endl;
            return T();
        }
        return head->data;
    }

    //is_empty function definiton
    bool  is_empty(){
        return (head==nullptr) ? true : false ;
    }

    //size function definition
    int size(){
        if(head==nullptr){
            return 0;
        }
        Node<T>* temp=head;
        int count=0;
        while(temp!=nullptr){
            temp=temp->next;
            count++;
        }
        return count;
    }

    //display function definiton 
    void display(){
        if(head==nullptr){
            cout<<"STACK EMPTY "<<endl;
            return ;
        }
        Node<T>* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main()
{   Stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.pop();
    s1.pop();
    s1.pop();
    s1.display();
    cout<<"Size : "<<s1.size()<<endl;
    cout<<(s1.is_empty() ? "Stack empty ": "Stack not empty ")<<endl; 


    return 0;
}