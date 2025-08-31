//TODO : you're building a Call Log system for a mobile phone:
    // It stores the most recent calls.
    // When a new call is added, it appears at the front (like the top of the log).
    // You can delete a specific call from the log.
    // You can display the entire call log (from most recent to oldest).
    // This mimics how recent call logs work in basic phones or dialers.

#include<iostream>
using namespace std;
class Node{
    public:
    string name;
    Node* next;
    Node(string name){
        this->name=name;
        this->next=NULL;
    }
};
class calls{
    // member attributes
    Node* head;
    Node* tail;
    public:
    calls(){
        head=tail=NULL;
    }

    //class methods / member methods 

//- new call function:-
void new_call(string name){
    Node* newNode = new Node(name);
    if(head==NULL){
        head=tail=newNode;
    }else{
        newNode->next=head;
        head=newNode;
    }
}
//- delete call by name :
void delete_call(string name){
    if(head==NULL){
        cout<<" No calls to delete ."<<endl;
        return;}
    if(head->name==name){
        Node* todelete=head;
        head=head->next;
        if (todelete == tail) {
        tail = NULL;}
        delete todelete;
        cout << "Deleted call: " << name << endl;
        return;
    }
    // case 2 - searching for the node to delete( done using 2 pointers)
        Node* prev=head;
        Node* curr=head->next;
        while(curr!=NULL && curr->name != name){
            prev=curr;
            curr=curr->next;
        }
    
        if(curr==NULL){
            cout<<" caller "<<name<<" not in call log."<<endl;
            return;
        }
        //adjusting pointer and deleting the node
        prev->next=curr->next;

        // Update tail if needed
        if (curr == tail) {
            tail = prev;
        }

        delete curr;
        cout << "Deleted call: " << name << endl;
}


//- length function : 
int length(){
    int count=0;
        Node* temp=head;
            while(temp!=NULL){
                temp=temp->next;
            count++;
        }
    return count;
}
// display by size 
void call_log(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->name<<endl;
        temp=temp->next;
    }
}
};
int main()
{   calls c1;
    c1.new_call("sanjay sir");
    c1.new_call("naincy");
    c1.new_call("bihari ji");
    c1.delete_call("naincy");
    cout<<endl;

    cout<<"*********call log************"<<endl;
    cout<<endl;
    c1.call_log();
    cout<<endl;
    cout<<"*****************************"<<endl;
    return 0;
}