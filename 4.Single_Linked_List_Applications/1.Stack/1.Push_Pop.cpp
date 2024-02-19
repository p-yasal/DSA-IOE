/*Push and pop oprerations in the stack*/
#include <iostream>
using namespace std;
#define size 5
template <typename T>
class Stack
{
private:
    T arr[size];
    int top = -1;

public:
    Stack()
    {
    }
    bool is_full()
    {
        if (top == size - 1)
        {
            return true;
        }
        else
            return false;
    }
    bool is_empty()
    {
        if (top == -1)
        {
            return true;
        }
        else
            return false;
    }
    void push()
    {
        if (is_full())
        {
            cout << "Stack is full";
            exit(0);
        }
        else

        {
            cout << "Enter the element to be pushed in stack:";
            cin >> arr[++top];
        }
    }
    T pop()
    {
        T top_element;
        if (is_empty())
        {
            cout << "Stack is empty";
            exit(0);
        }
        else
        {

            return arr[top--];
        }
    }
    void options()
    {
        int option;
        do
        {
            option = 0;
            cout << "Select an option" << endl;
            cout << "1 for Push" << endl
                 << "2 for Pop" << endl
                 << "3 for quit" << endl;
            cin >> option;

            if (option == 1)
            {
                push();
            }
            else if (option == 2)
            {

                cout << "popped element:" << pop() << endl;
            }

        } while (option != 3);
    }
};
int main()
{
    Stack<int> s;
    s.options();
    return 0;
}
