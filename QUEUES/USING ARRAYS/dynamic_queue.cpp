// TODO:  IMPLEMENT DYNAMIC QUEUES ( WITHOUT VECTORS )
#include <iostream>
using namespace std;

class Queue
{
public:
  int front, rear;
  int capacity;
  int *array;

  // constructor
  Queue()
  {
    front = 0;
    rear = -1;
    capacity = 1;
    array = new int[capacity];
  }
  // resize function definiton
  void resize()
  {
    capacity = 2 * capacity;
    int *array_dummy = new int[capacity];
    for (int i = front; i <= rear; i++)
    {
      array_dummy[i - front] = array[i];
    }
    delete[] array;
    array = array_dummy;
    rear -= front;
  }

  // enque function definition :
  void enque(int val)
  {
    if (rear == capacity - 1)
    {
      resize();
      array[++rear] = val;
    }
    else
    {
      array[++rear] = val;
    }
  }

  // deque function definition
  void deque()
  {
    if (front > rear)
    {
      cout << "QUEUE UNDERFLOW" << endl;
      return;
    }
    front = front + 1;
    if (front > rear)
    {
      front = 0;
      rear = -1;
    }
  }

  // peek fucntion definition
  int peek()
  {
    if (rear == -1)
    {
      cout << "QUEUE UNDERFLOW" << endl;
      return -1;
    }
    return array[front];
  }

  // size function definition
  int size()
  {
    if (rear == -1)
    {
      return 0;
    }
    return rear - front + 1;
  }

  // dis play function definition
  void display()
  {
    if (rear == -1)
    {
      cout << "QUEUE IS EMPTY -> NOTHING TO DISPLAY " << endl;
      return;
    }
    cout << "********************************" << endl;
    cout << "QUEUE : FRONT TO REAR" << endl;
    for (int i = front; i <= rear; i++)
    {
      cout << array[i] << endl;
    }
    cout << "********************************" << endl;
  }
};

int main()
{
  Queue q;
  int choice = 0;
  do
  {
    cout << "--------------------------------\n0 - Exit \n1 - Insert Element \n2- Remove Element \n3 - Display\n4 - Size of Queue\n--------------------------------" << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    switch (choice)
    {
    case 0:
      return 0;
      break;
    case 1:
      cout << "Enter values to be pushed in the Queue : ";
      int val;
      cin >> val;
      q.enque(val);
      cout << "Element : " << val << " inserted successfully . " << endl;
      break;
    case 2:
      q.deque();
      cout << "Element removed successfully . " << endl;
      break;
    case 3:
      q.display();
      break;
    case 4:
      cout << "Size of the Queue is : " << q.size() << endl;
      break;
    default:
      break;
    }

  } while (choice != 0);

  return 0;
}