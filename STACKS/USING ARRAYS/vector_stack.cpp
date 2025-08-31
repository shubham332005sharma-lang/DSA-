// TODO: IMPLEMENT STACKS USING VETORS STL
#include <iostream>
#include <vector>
using namespace std;

class Stack
{
public:
    vector<int> array;

    // push function definition
    void push(int val)
    {
        array.push_back(val);
    }

    // pop function definition
    void pop()
    {
        if (array.size() == 0)
        {
            cout << " STACK IS EMPTY " << endl;
        }
        else
        {
            array.pop_back();
        }
    }

    // peek function definiton :
    int peek()
    {
        if (array.size() == 0)
        {
            cout << "STACK IS EMPTY " << endl;
            return -1;
        }
        else
        {
            return array.back();
        }
    }

    // is_empty function definition :
    bool is_empty()
    {
        return (array.size() == 0) ? true : false;
    }

    // display function deifiniton :
    void display()
    {
        for (int i = 0; i < array.size(); i++)
        {
            cout << array[i] << " ";
        }
    }
};

int main()
{
    return 0;
}