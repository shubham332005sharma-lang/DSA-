#include<iostream>
using namespace std;


// node class
class node
{
    static int node_count;

public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = nullptr;
        node_count++;
    }

    ~node()
    {
        node_count--;
    }

    static int get_node_count()
    {
        return node_count;
    }
};
int node::node_count = 0;

class list
{
    node *head;

public:
    list()
    {
        head = nullptr;
    }
    void insert_at_start(int val);
    void insert_at_end(int val);
    void insert_at_positiom(int position, int val);
    void delete_from_start();
    void delete_from_end();
    void delete_from_positiom(int position);
    void display();
    void reverse();
};
int main()
{   
    list l1;
    l1.display();
    l1.insert_at_end(5);
    l1.display();
    l1.insert_at_end(4);
    l1.display();
    l1.insert_at_end(3);
    l1.insert_at_end(2);
    l1.insert_at_end(1);
    l1.display();
    return 0;
}

void list::insert_at_start(int val)
{
    node *newnode = new node(val);

    if (head == nullptr)
    {
        head = newnode;
        head->next = head;
        return;
    }

    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = head;
    head = newnode;
}

void list:: insert_at_end(int val)
{
    node* newnode = new node(val);

    if(head==nullptr){
        head = newnode;
        newnode->next=head;
    }else{
        node* temp =head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
    }

}

void list:: insert_at_positiom(int position , int val){
    if(position<1){
        cout<<"Please enter a valid position argument !!!"<<endl;
        return;
    }
    node* temp=head;
    int step_count =0;
    while(step_count != position-1 || temp!=head){

    }

}

void list :: display(){
    if(head==nullptr){
        cout<<"Empty list : nothing to display ."<<endl;
        return;
    }else if(head->next == head){
        cout<<head->data<<"<->"<<head->data<<endl;
        return;
    }
    node* temp = head->next;
    cout<<head->data<<"<->";
    while(temp != head){
        cout<<temp->data<<"<->";
        temp=temp->next;
    }
    cout<<head->data<<endl;
    return;
}