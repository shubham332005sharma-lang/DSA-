//TODO:  IMPLEMENT DYNAMIC QUEUES ( WITHOUT VECTORS )
#include<iostream>
using namespace std;

class Queue{
  public :
  int front, rear;
  int capacity;
  int* array;
  

  //constructor 
  Queue(){
    front =0;
    rear=-1;
    capacity=1;
    array = new int[capacity];
    
  }
// resize function definiton
  void resize(){
    capacity = 2*capacity;
    int* array_dummy= new int[capacity];
    for(int i=front;i<=rear;i++){
        array_dummy[i-front]=array[i];
    }
    delete[] array;
    array=array_dummy;
    rear-=front;
    
  }

  // enque function definition : 
  void enque(int val){
    if(rear==capacity-1){
        resize();
        array[++rear]=val;
    }else{
        array[++rear]=val;
    }
  }

// deque function definition 
  void deque(){
    if(front>rear){
        cout<<"QUEUE UNDERFLOW"<<endl;
        return;
    }
    front=front+1;
    if (front > rear) {
        front = 0;
        rear = -1;
    }
  }

// peek fucntion definition
  int peek(){
    if(rear==-1){
        cout<<"QUEUE UNDERFLOW"<<endl;
        return -1;                   
    }
    return array[front];
  }

// size function definition
  int size(){
    if(rear==-1){
        return 0;
    }
    return rear-front+1;
  }

// dsiplay function definition 
  void display(){
    if(rear==-1){
        cout<<"QUEUE IS EMPTY -> NOTHING TO DISPLAY "<<endl;
        return;
    }
    cout<<"QUEUE : FRONT TO REAR"<<endl;
    for(int i=front;i<=rear;i++){
        cout<<array[i]<<endl;
    }
  }
};

int main()
{   Queue q;
    q.display();
    cout<<"size of queue is :"<<q.size()<<endl;
    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.display();
    cout<<"size of queue is :"<<q.size()<<endl;
    q.deque();
    cout<<q.size()<<endl;
    q.display();
    return 0;
}