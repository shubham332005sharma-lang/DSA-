//TODO: IMPLEMENT STACKS USING DYNAMIC ARRAYS( NOT VECTORS )
#include<iostream>
using namespace std;

class stack{
    public:
    int top_index;
    int capacity;
    int* array;
    
    stack(){
        top_index=-1;
        capacity=1;
        array= new int[capacity];
    }

    //resize fucntion defintion :
    void resize(){
        capacity=2*capacity;
        int* array1= new int[capacity];
        for(int i=0;i<=top_index;i++){
            array1[i]=array[i];
        }
        delete[] array;
        array=array1;
    }

    //push function defintion :
    void push(int val){
        if(top_index==capacity-1){resize();}
        array[++top_index]=val;
    }

    //pop fucntion definition :
    void pop(){
        if(top_index>-1){
        top_index--;
        }else{
            cout<<"STACK UNDERFLOW ( nothing to remove )"<<endl;
        }
    }

    // peek function definition :
    int peek(){
        if(top_index>-1){
        return array[top_index];
        }
            cout<<"STACK UNDERFLOW ( peek doesnt exists )"<<endl;
            return -1;
    }

    //display funtion definiton :
    void display(){
        if(top_index<0){
            cout<<"STACK IS EMPTY ( nothing to display )"<<endl;
            return;
        }
        for(int i=0;i<=top_index;i++){
            cout<<array[i]<<" ";
        }
    }

    //is_empty fucntion definition :
    bool is_empty(){
        if(top_index==-1){
            return 1;
        }else{return 0;}
    }

    //size function definition :
    int size(){
        return top_index+1;
    }

    //shrink fucntion definition :
    void shrink(){
        if(top_index*4<capacity && capacity > 1){
            capacity=capacity/2;
            int* array1 = new int[capacity];
            for(int i=0;i<=top_index;i++){
            array1[i]=array[i];
        }
        delete[] array;
        array=array1; 
        }else{
            cout<<"SHRINK NOT SUGGESTED "<<endl;
        }
    }
};

int main()
{   stack s1;
    s1.display();
    s1.pop();
    s1.peek();
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.push(7);
    s1.pop();
    s1.shrink();
    s1.display();
    return 0;
}