//TODO: LINKED LIST IMPLEMENTATION IN CPP
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

// create a class named list :
class list{
    Node* head;
    Node* tail;
    public:
    list(){
        head=tail=NULL;
    }
//- PUSH FRONT DEFINITION
    void insert_at_start(int val){
        Node* newNode= new Node(val);// creating new node that is to be pushed
        if(head==NULL){
            head=tail=newNode;
            return;
        }else{
            newNode->next=head;// establishing connection (*newnode.next=head)
            head=newNode;// updating head
           
        }
    }
//- PUSH BACK DEFINITION
    void insert_at_end(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    } 
//-POP FRONT DEFINITION
    void delete_from_start(){
        if(head==NULL){
            cout<<" linked list is empty "<<endl;
        }else{
            Node* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
    }
//-POP BACK DEFINITION
    void delete_from_end(){
            if(head==NULL){
                cout<<" empty linked list."<<endl;
            }else{
            Node* temp=head;
            while(temp->next->next!=NULL){//to travere to 2nd last node without using tail.
                temp=temp->next;
            }
            temp->next=NULL;
            delete tail;
            tail=temp;

        }
    }
//- INSERT FUNCTION DEFINITION
    void insert(int val,int position){
        if(position<0){ 
            cout<<"invalid position"<<endl;
        }else if(position==0){
            Node* newNode = new Node(val);
            newNode->next=head;
            head=newNode;
        }
        else{
        Node* newNode = new Node(val);
        int i=0;
        Node* temp=head;
        while(i<position-1 &&temp!=NULL){
            temp=temp->next;
            i++;
        }
        if( temp==NULL){
            cout<<"position argument is greater than size ."<<endl;
        return;}
        newNode->next=temp->next;
        temp->next=newNode;
    return;
    }
    }
//- DELETE FUNCTION DEFININTION :-
    void delete_from_index(int position){
        if(position<0){
            cout<<" INVALID POSITION ARGUMENT "<<endl;
            return;
        }else if(position==0){
            Node* temp=head;
            head=head->next;
            temp->next=NULL;
            delete head;
        }else{
            Node* temp=head;
        for(int i=0;i<position-1 && temp != nullptr;i++){
            temp=temp->next;
        }
        if(temp == nullptr || temp->next == nullptr){
        cout << "Invalid position" << endl;
        return;
        }
        Node* todelete=temp->next;    
        temp->next=temp->next->next;
        delete todelete;

        }
    }
//-SEARCH FUNCTION DEFINITION :-
    int search(int value){
        int index=0;
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data==value){
                cout<<"element present at index :"<<index<<endl;
                return index;
            }
            index++;
            temp=temp->next;
        }
        cout<< value<<" not in given linked list."<<endl;
        return -1;
    }
//-DISPLAY FUNCTION DEFINITION :-
    void display(){
        Node* temp=head;// creating a copy of head as we cant use the head directly ( bc it needs to be preserved because we cant travel back otherwise) 
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
//- REVERSE FUNCTION DEFINITION:-
    void reverse(){
        Node* prev =NULL;
        Node* curr=head;
        Node* next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        Node* temp=head;
        head=tail;
        tail=temp;
    }
};
int main()
{   list ll;
    int m ,n,o,p,q;
    cout<<"Enter element to be inserted : ";
    cin>>m;
    ll.insert_at_start(m);
    cout<<"Enter element to be inserted : ";
    cin>>n;
    ll.insert_at_start(n);
    cout<<"Enter element to be inserted : ";
    cin>>o;
    ll.insert_at_start(o);
    ll.display();
    cout<<endl;
    cout<<"Reversed linked list is : ";
    ll.reverse();
    ll.display();
    // ll.insert_at_end(5);
    // ll.display();
    // ll.delete_from_start();
    // ll.display();
    // ll.delete_from_end();
    // ll.display();
    cout<<"Enter position element to be inserted : ";
    cin>>p;
    cout<<"Enter element to be inserted : ";
    cin>>q;
    ll.insert(q,p);
    cout<<" linked list now is : ";
    ll.display();

    // ll.delete_from_index(2);
    // ll.display();
    // ll.search(17);
    return 0;
}