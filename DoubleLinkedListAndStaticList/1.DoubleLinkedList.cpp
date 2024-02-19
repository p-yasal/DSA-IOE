/*WRITE AN ALGORITHM AND PROGRAM FOR FOLLOWING CASES IN DOUBLY
LINEAR LINKED LIST:
1. INSERTION OPERATIONS
a. INSERT NODE AT BEGINNING OF THE LIST
b. INSERT NODE AT END OF THE LIST
c. INSERT NODE AFTER SPECIFIC NODE
d. INSERT NODE BEFORE SPECIFIC NODE

2. DELETION OPERATIONS
a. DELETE NODE FROM BEGINNING OF THE LIST
b. DELETE NODE FROM END OF THE LIST
c. DELETE NODE AFTER SPECIFIC NODE
d. DELETE NODE BEFORE SPECIFIC NODE*/
#include <iostream>
using namespace std;
class Node
{
public:
    Node *front, *rear;
    int data;
};
class DoubleLinkedList
{
private:
    Node *start, *newnode, *temp, *display, *var;
    int value;

public:
    DoubleLinkedList() {}
    void create_new_node(int value)
    {
        newnode = new Node;
        newnode->data = value;
        newnode->front = NULL;
        newnode->rear = NULL;
    }
    void insert_at_end(int value)
    {

        create_new_node(value);

        if (start == NULL)
        {
            start = newnode;
            start->front = NULL;
            // temp=newnode;
            var = newnode;
        }
        else
        {
            temp = start;
            while (temp->rear != NULL)
            {
                temp = temp->rear;
            }
            temp->rear = newnode;
            temp = newnode;
            temp->front = var;
            var = newnode;
        }
    }
    void insert_at_beginning(int value)
    {
        create_new_node(value);
        if (start == NULL)
        {
            start = newnode;
            start->front = NULL;
            // start->rear = NULL;
        }
        else
        {
            newnode->rear = start;
            start->front = newnode;
            newnode->front = NULL;
            start = newnode;
        }
    }
    void insert_after_specific_node(int value)
    {
        temp = start;
        while (temp->data != value)
        {
            temp = temp->rear;
        }
        int data;
        cout << "Enter the data to be inserted:";
        cin >> data;
        create_new_node(data);
        newnode->rear = temp->rear;
        var = temp;
        temp = temp->rear;
        var->rear = newnode;
        newnode->front = var;
        temp->front = newnode;
    }
    void display_list()
    {
        display = start;
        while (display != NULL)
        {
            cout << display->data << "\t";
            display = display->rear;
        }
        cout << endl;
    }
    void insert_before_specific_node(int value)
    {
        int d;
        cout << "Enter the data  which is to be inserted:";
        cin >> d;
        create_new_node(d);
        temp = start;
        while (temp->data != value)
        {
            var = temp;
            temp = temp->rear;
        }
        newnode->rear = var->rear;
        temp->front = newnode;
        var->rear = newnode;
        newnode->front = var;
    }
    void delete_from_beginning()
    {
        cout << "Deleted element:" << start->data << endl;
        start = start->rear;
        start->front = NULL;
    }
    void delete_from_end()
    {
        temp = start;
        while (temp->rear != NULL)
        {
            var = temp;
            temp = temp->rear;
        }
        cout << "Deleted element:" << temp->data << endl;
        var->rear = NULL;
    }
    void delete_after_specific_node(int value)
    {
        temp = start;
        while (temp->data != value)
        {
            temp = temp->rear;
        }
        var = temp->rear;
        cout << "Deleted element:" << var->data << endl;
        var = var->rear;
        var->front = temp;
        temp->rear = var;
    }
    void options()
    {
        int opt;
        cout << "1 for INSERT NODE AT BEGINNING OF THE LIST" << endl
             << "2 for INSERT NODE AT END OF THE LIST" << endl
             << "3 for INSERT NODE AFTER SPECIFIC NODE" << endl
             << "4 for INSERT NODE BEFORE SPECIFIC NODE" << endl
             << "5 for DELETE NODE FROM BEGINNING OF THE LIST" << endl
             << "6 for DELETE NODE FROM END OF THE LIST" << endl
             << "7 for DELETE NODE AFTER SPECIFIC NODE" << endl
             << "8 display" << endl
             << "9 for quit" << endl;
        while (opt != 9)
        {
            cout << "opt=";
            cin >> opt;
            if (opt == 1)
            {
                cout << "Enter the element to be inserted at beginning of list:";
                cin >> value;
                insert_at_beginning(value);
            }
            else if (opt == 2)
            {
                cout << "Enter the element to be inserted at end of list:";
                cin >> value;
                insert_at_end(value);
            }
            else if (opt == 8)
            {
                display_list();
            }
            else if (opt == 3)
            {
                cout << "Enter the element after which node is to be inserted:";
                cin >> value;
                insert_after_specific_node(value);
            }
            else if (opt == 4)
            {
                cout << "Enter the element before which node is to be inserted:";
                cin >> value;
                insert_before_specific_node(value);
            }
            else if (opt == 5)
            {
                delete_from_beginning();
            }
            else if (opt == 6)
            {
                delete_from_end();
            }
            else if (opt == 7)
            {
                int de;
                cout << "Enter the value of element after which element is to be deleted:";
                cin >> de;
                delete_after_specific_node(de);
            }
        }
    }
};
int main()
{
    DoubleLinkedList D;
    D.options();
    return 0;
}
