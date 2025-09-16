//TODO - IMPLEMENT STACKS USING ARRAYS.
#include<iostream>
using namespace std;
class Stack{
    public:
    static const int MAX = 100;
    int array[MAX]; 
    int topIndex;

    //constructor : 
    Stack(){
        this->topIndex=-1;
    }

    // push function definition:
    void push(int val){
        if(topIndex<MAX){
        array[++topIndex]=val;}
        else{cout<<" STACK OVERFLOW "<<endl;}
    }

    // pop function definition
    void pop(){
        if(topIndex>-1){
        topIndex--;}
        else{cout<<" STACK UNDERFLOW "<<endl; }
    }

    //peek function definition 
    int peek(){
        if(topIndex==-1){cout<<" STACK IS EMPTY"<<endl;
        return -1;}else{
        return array[topIndex];}
    }

    // is_empty function definition
    bool is_empty(){
        if(topIndex==-1){cout<<"STACK IS EMPTY"<<endl;
        return 1;}
        else{ return 0;}
    }

    // size function definition
    int size(){
        cout<< "SIZE : "<<topIndex+1 << endl;
        return topIndex+1;
    }

};
int main()
{   
    do
    {
    
    } while ();
    
    return 0;
}