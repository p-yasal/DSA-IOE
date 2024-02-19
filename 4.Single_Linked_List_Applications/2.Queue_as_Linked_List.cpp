/*SLL.IMPLEMENT QUEUE AS LINKED LIST*/
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class Queue
{
private:
    Node *start, *newnode, *temp, *display, *var;

public:
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
    void enqueue(int value)
    {
        create_new_node(value);
        if (start == NULL)
        {
            start = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    void dequeue()
    {
        if (is_empty())
        {
            cout << "Queue is empty" << endl;
            exit(0);
        }
        cout << "Dequeued element:" << start->data << endl;
        start = start->next;
    }
    void display_queue()
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
        int option = 0;
        cout << "Enter the option specified:";
        cout << "Enter the action to  be done:" << endl
             << "1 for enqueue element in linked list" << endl
             << "2 for dequeue element from linked list" << endl
             << "3 for display elements of the linked list" << endl
             << "4 for quit" << endl;
        while (option != 4)
        {
            cout << "option=";
            cin >> option;
            if (option == 1)
            {
                int v;
                cout << "Enter the element to be enqueued in linked list:";
                cin >> v;
                enqueue(v);
            }
            else if (option == 2)
            {
                dequeue();
            }
            else if (option == 3)
            {
                display_queue();
            }
        }
    }
};
int main()
{
    Queue q;
    q.options();
    q.display_queue();
    return 0;
}
