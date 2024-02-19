/*SLL.IMPLEMENT STACK AS LINKED LIST*/
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class Linked_List
{
private:
    Node *start, *newnode, *temp, *display, *var;

public:
    Linked_List()
    {
        start = NULL;
    }
    bool is_empty()
    {
        return start == NULL;
    }
    void create_new_node(int value)
    {
        newnode = new Node;
        newnode->data = value;
        newnode->next = NULL;
    }
    void push(int data)
    {
        create_new_node(data);
        if (start == NULL)
        {
            start = newnode;
            temp = newnode;
        }
        else
        {
            var = temp;
            temp->next = newnode;
            temp = newnode;
        }
    }
    int pop()
    {
        Node *var = NULL;
        if (is_empty())
        {
            cout << "Stack is empty";
            exit(0);
        }
        temp = start;
        while (temp->next != NULL)
        {
            var = temp;
            temp = temp->next;
            // var->next = NULL;
        }
        int ans = temp->data;
        if (var != NULL)
        {
            var->next = NULL;
        }
        else
        {
            // If var is NULL, it means there was only one element in the stack
            start = NULL;
        }
        return ans;
    }
    void display_stack()
    {
        display = start;
        while (display != NULL)
        {

            cout << display->data << "\t";
            display = display->next;
        }
        cout << endl;
    }
    void options()
    {
        int option;
        cout << "1 for pushing element in linked list" << endl
             << "2 for popping element from linked list" << endl
             << "3 for display" << endl
             << "4 for quit" << endl;
        while (option != 4)
        {
            cout << "option=";
            cin >> option;
            if (option == 1)
            {
                int value;
                cout << "Enter the element to be pushed into linked list:";
                cin >> value;
                push(value);
            }
            else if (option == 2)
            {
                cout << "popped element:" << pop() << endl;
            }
            else if (option == 3)
            {
                display_stack();
            }
        }
    }
};
int main()
{
    Linked_List l;
    l.options();
    return 0;
}