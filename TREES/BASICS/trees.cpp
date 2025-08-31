//TODO : TREES IN CPP (being more specific, binary trees )

#include<iostream>
using namespace std;

class Node{

    public: 
    int data;
    Node* left;
    Node* right;

    Node(int Data){

        this->data = Data;
        this->left = nullptr;
        this->right = nullptr;

    }
};

class Trees{
    public:

    Node* root;
    Trees(int data){

        Node* new_node= new Node(data);
        root=new_node;

    }

    void tree_builder(Node* root){
            cout<<
    }

};
int main()
{
    return 0;
}