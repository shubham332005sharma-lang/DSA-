// TODO : IMPLEMENT DOUBLE LINKED LISTS AND THEIR OPERATIONS.

// creating node class
class Node
{
public:
    static int node_count; // static variable to keep track of the number of nodes created .

    int data;
    Node *next;
    Node *prev;

    // constructor of class node
    Node(int val)
    {
        this->data = val;
        this->next = nullptr;
        this->prev = nullptr;
        node_count++;
    }
    ~Node()
    {
        node_count--;
    }

    static int node_count_function()
    {
        return node_count;
    }
};

// creating list class
class List
{
public:
    Node *head;
    Node *tail;

    // constructor of class lists
    List()
    {
        head = tail = nullptr;
    }
    // destructor of class List
    ~List()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = tail = nullptr;
    }

    // declaring all the functions ( later to be defined outside the class for the better readability .)
    void insert_at_end(int val);
    void insert_at_beggining(int val);
    void delete_from_front();
    void delete_from_end();
    void display();
    void insert_at(int position, int val);
    void delete_from_position(int position);
};

int Node ::node_count = 0;

#include <iostream>
using namespace std;

//- MENU DRIVEN MAIN FUNCTION :
int main()
{
    List l1;

    int choice = 0;
    while (true)
    {
        cout << "1 - Add element at the end . \n2 - Add element at the start .\n3 - Add at element in the middle .\n4 - Remove element from the end .\n5 - Remove element from the start .\n6 - Remove the element from middle .\n7 - Print the list .\n8 - Exit ." << endl;
        cout << "ENTER YOUR CHOICE : ";
        cin >> choice;
        switch (choice)
        {

        case 1:
        {
            int val;
            cout << "ENTER VALUE TO BE ADDED AT THE END : ";
            cin >> val;
            l1.insert_at_end(val);
            cout << val << " added succecfully . " << endl;
            break;
        }
        case 2:
        {
            int val;
            cout << "ENTER VALUE TO BE ADDED AT THE FRONT : ";
            cin >> val;
            l1.insert_at_beggining(val);
            cout << val << " added succecfully . " << endl;
            break;
        }
        case 3:
        {
            int position, val;
            cout << "ENTER POSITION THE VALUE TO BE ADDED AT : ";
            cin >> position;
            cout << "ENTER THE VALUE TO BE ADDED : ";
            cin >> val;
            l1.insert_at(position, val);
            cout << val << " added at " << position << " succecfully . " << endl;
            break;
        }
        case 4:
        {
            l1.delete_from_end();
            cout << "Element removed succecfully . " << endl;
            break;
        }
        case 5:
        {
            l1.delete_from_front();
            cout << "Element removed succecfully . " << endl;
            break;
        }
        case 6:
        {
            int m;
            cout << "Enter the position the element is to removed from : ";
            cin >> m;
            l1.delete_from_position(m);
            cout << "Element removed succecfully . " << endl;
            break;
        }
        case 7:
        {
            l1.display();
            cout << endl;
            break;
        }
        case 8:
        {
            return 0;
        }
        default:
        {
            cout << "PLEASE ENTER A VALID OPTION...." << endl;
            break;
        }
        }
    }
    return 0;
}

//- DEFINING MEMBER FUNCTIONS (OUTSIDE THE CLASS USING  :: )

void List::insert_at_end(int val)
{
    if (head == nullptr)
    {
        Node *new_node = new Node(val);
        head = tail = new_node;
        return;
    }
    Node *temp = head;
    Node *new_node = new Node(val);
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
    tail = new_node;
}

void List::insert_at_beggining(int val)
{
    if (head == nullptr)
    {
        Node *new_node = new Node(val);
        head = tail = new_node;
        return;
    }
    Node *new_node = new Node(val);
    head->prev = new_node;
    new_node->next = head;
    head = new_node;
}

void List::delete_from_end()
{
    if (head == nullptr)
    {
        cout << " LIST IS EMPTY ." << endl;
        return;
    }
    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
        return;
    }
    Node *temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
}

void List::delete_from_front()
{
    if (head == nullptr)
    {
        cout << " LIST IS EMPTY ." << endl;
        return;
    }
    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
        return;
    }
    Node *temp = head;
    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;
    delete temp;
}

void List::display()
{
    if (head == nullptr)
    {
        cout << " LIST IS EMPTY ." << endl;
        return;
    }
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << " NULL " << endl;
}

void List::insert_at(int position, int val)
{
    if (position > Node::node_count_function() + 1 || position < 1)
    {
        cout << "Invalid position argument !!!" << endl;
        cout << "please enter a position value between 1-" << (Node::node_count_function() + 1) << endl;
        return;
    }

    if (position == 1)
    {
        if (head == nullptr)
        {
            Node *newnode = new Node(val);
            head = tail = newnode;
        }
        else
        {
            Node *newnode = new Node(val);
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        return;
    }

    if (position == Node::node_count_function() + 1)
    {
        insert_at_end(val);
        return;
    }

    Node *newnode = new Node(val);
    Node *temp = head;
    for (int i = 1; i < position - 1; i++)
    { // stop at node before position
        temp = temp->next;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != nullptr)
    {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}

void List ::delete_from_position(int position)
{   if(position> (Node ::node_count_function())||position<1){
    cout<<"Please enter a valid psotion !!!";
    return;
}
    else if(position==1){
        delete_from_front();
        return;
    }
    else if(position== (Node ::node_count_function())){
        delete_from_end();
        return;
    }else{
    Node *temp = head;
    Node *temp2;
    for (int i = 0; i < position - 2; i++)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    temp2 = temp;
    temp = temp->next;
    temp->prev = temp2;
    return;
}
}