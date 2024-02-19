/*1. INSERTION OPERATIONS
a. INSERT NODE AT BEGINNING OF THE LIST
b. INSERT NODE AT END OF THE LIST
c. INSERT NODE AFTER SPECIFIC NODE
d. INSERT NODE BEFORE SPECIFIC NODE

2. DELETION OPERATIONS
a. DELETE NODE FROM BEGINNING OF THE LIST
b. DELETE NODE FROM END OF THE LIST
c. DELETE NODE AFTER SPECIFIC NODE*/
#include <iostream>
using namespace std;
class Node
{
public:
    Node *next;
    int data;
};
class Linked_List
{
private:
    Node *start, *newnode, *temp, *display, *var;
    int value;

public:
    Linked_List()
    {
        start = NULL;
        temp = NULL;
    }
    ~Linked_List()
    {
        temp = start;
        Node *nextNode;
        while (temp != NULL)
        {
            nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
    void create_new_node()
    {
        cout << "Enter the element in the list:";
        cin >> value;
        newnode = new Node;
        newnode->data = value;
        newnode->next = NULL;
    }
    void create_a_list()
    {
        char option;
        cout << "a for adding element in list" << endl
             << "b for display" << endl
             << "c for further operation" << endl;
        do
        {
            cout << "option=";
            cin >> option;
            if (option == 'a')
            {
                create_new_node();
                if (start == NULL)
                {
                    start = newnode;
                    temp = start;
                }
                else
                {
                    temp->next = newnode;
                    temp = newnode;
                }
            }

            else if (option == 'b')
            {
                display_list();
            }

        } while (option != 'c');
    }

    void display_list()
    {
        display = start;
        while (display != NULL)
        {
            cout << display->data << "->";
            display = display->next;
        }

        cout << endl;
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
             << "8 for display" << endl
             << "9 for quit" << endl;
        while (opt != 9)
        {
            cout << "opt=";
            cin >> opt;
            if (opt == 1)
            {
                insert_at_beginning();
            }
            else if (opt == 2)
            {
                insert_at_end();
            }
            else if (opt == 8)
            {
                display_list();
            }
            else if (opt == 3)
            {
                insert_after_specific_node();
            }
            else if (opt == 4)
            {
                insert_before_specific_node();
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
                delete_after_specific_node();
            }
            else if (opt == 9)
            {
                exit(0);
            }
        }
    }
    void insert_at_beginning()
    {
        create_new_node();
        newnode->next = start;
        start = newnode;
    }
    void insert_at_end()
    {
        create_new_node();
        if (start == NULL)
        {
            start = newnode;
            temp = start;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    void insert_after_specific_node()
    {
        int value;
        cout << "Enter the data of the node after which you want your node inserted:";
        cin >> value;
        temp = start;
        while (temp->next != NULL && temp->data != value)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            cout << "Data not found or use different command if you want to insert at end" << endl;
            return;
        }
        else
        {
            create_new_node();
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
    void insert_before_specific_node()
    {
        int val;
        cout << "Enter the element before which you want your data inserted:";
        cin >> val;

        temp = start;
        Node *var = nullptr;
        while (temp != NULL && temp->data != val)
        {
            var = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Element not found in the list." << endl;
            return;
        }
        else if (start->data == temp->data)
        {
            cout << "Use a different command to insert before the first element." << endl;
            return;
        }
        else
        {
            create_new_node();
            newnode->next = temp;
            var->next = newnode;
        }
    }
    void delete_from_beginning()
    {
        cout << "Deleted element:" << start->data << endl;
        start = start->next;
    }
    void delete_from_end()
    {
        Node *var = NULL;
        temp = start;
        while (temp->next != NULL)
        {
            var = temp;
            temp = temp->next;
        }
        cout << "Deleted element:" << temp->data << endl;
        if (var != NULL)
        {
            var->next = NULL;
        }
        else
        {
            start = NULL;
        }
    }
    void delete_after_specific_node()
    {
        int v;
        Node *var = NULL;
        temp = start;
        cout << "Enter the element after which you want to delete node:";
        cin >> v;

        while (temp->data != v)
        {
            temp = temp->next;
            var = temp;
        }
        var = temp->next;
        cout << "Deleted element:" << var->data << endl;
        temp->next = var->next;
    }
};
int main()
{
    Linked_List l;
    l.create_a_list();
    l.options();

    return 0;
}
