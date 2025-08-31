//TODO - DETECT LOOP IN A LINKED LIST.
//concept - floyd's cycle finding algorithm.  

//logic - use slow and fast pointers ,increase them accordingly . if there is a loop then at some point they will meet surely.
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
    //constructor of List class
    List(){
        head=nullptr;
    }
    // function declarations 
    bool detect_loop();
    Node* find_loop_start();
    void remove_loop();


};
int main(){
    List l1;
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    a->next = b;
    b->next = c;
    c->next=d;
    d->next=a;
    // Introduce loop if needed:
     // loop at node 'b'

    l1.head = d;
    

    cout<<l1.find_loop_start()->data<<endl;
    l1.remove_loop();
    cout << (l1.detect_loop() ? "Loop detected!" : "No loop detected.") << endl;

    return 0;
}

bool List::detect_loop(){
    Node* slow=head;
    Node* fast=head;
    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            return true;}
        }
        return false;
    }
Node* List::find_loop_start() {
    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect loop
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Step 2: Find start of loop
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // This is the start of the loop
        }
    }

    return nullptr; // No loop
}

void List::remove_loop(){
    Node* start = find_loop_start();
    if (!start) return; 
    Node* temp=start;
    while(temp->next!=start){
        temp=temp->next;
    }temp->next=nullptr;
}