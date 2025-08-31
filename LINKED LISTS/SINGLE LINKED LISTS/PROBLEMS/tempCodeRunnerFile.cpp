//TODO : IMPLEMENT MERGE SORT ON A LINKED LIST 
#include<iostream>
using namespace std;

//- create a linked list 
class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int val){
        this->data=val;
        this->next=nullptr;
    }
};

class List{
       public:
    Node* head;
    Node* tail;

 
    //constructor of List class
    List(){
        head=tail=nullptr;
    }

    //MEMBER FUNCTIONS - ( ONLY NECESSARY ONES)
    void push_back(int val){
        if(head==nullptr){
            Node* newNode= new Node(val);
            head=tail=newNode;
            return;
        }
        Node* newNode =new Node(val);
        tail->next=newNode;
        tail=newNode;
    }

    void display(){
        if(head==nullptr){
            cout<< "empty list . "<<endl;
            return;
        }
        Node* temp = head;
        while (temp->next!=nullptr){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
         cout<<temp->data<<" -> NULL "<<endl;

    }

    // declaring sort function 
    Node* sort(Node* head);
    Node* findmid(Node* head);
    Node* merge(Node* left ,Node* right);


};
//- MAIN FUNCTION
int main()
{   List l1;
    l1.push_back(1);
    l1.push_back(3);
    l1.push_back(2);
    cout<< " list before sorting : ";
    l1.display();
    l1.head=l1.sort(l1.head);
    cout<< " list after sorting  : ";
    l1.display();
    return 0;
}
// defining the function outside the class
Node* List::sort(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* mid=findmid(head);
    Node* left=head;
    Node* right=mid->next;
    mid->next=nullptr;
    // recursively sorting both parts
    left= sort(left);
    right= sort(right);

    Node* result= merge(left,right);

    Node* temp = result;
    while(temp->next != nullptr)
        temp = temp->next;
    this->tail = temp;  // Update tail of the list

    return result;
};


Node* List::findmid(Node* head){
    Node* slow=head;
    Node* fast=head;
    // this approach is called  TORTOISE AND HARE approach ( very intelligent )
    while(fast!=nullptr && fast->next != nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
};
Node* List::merge(Node* left,Node* right){
    if(left==nullptr) return right;
    if(right==nullptr) return left;
    Node* dummy=new Node(-1);
    Node* temp=dummy;
    while(left!=nullptr && right!= nullptr){
        if(left->data < right->data){
            temp->next=left;
            left=left->next;
        }
        else{
            temp->next=right;
            right=right->next;
        }
        temp=temp->next;
    }
    if(left)temp->next=left;
    if(right)temp->next=right; // in here we are adding the remaining chain so we dont have to loop through.
    
    Node* result =dummy->next;
    delete dummy;
    return result;
}