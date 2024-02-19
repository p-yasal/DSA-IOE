/*SLL.REPRESENT THE POLYNOMIAL EQUATION USING LINKED LIST TO PERFORM
ADDITION OF TWO POLYNOMIALS.*/
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    int degree;
    Node *next;
};
class Linked_List
{
private:
    Node *start1, *start2, *temp, *newnode, *display;

public:
    void create_new_node(int value, int deg)
    {
        newnode = new Node;
        newnode->data = value;
        newnode->degree = deg;
        newnode->next = NULL;
    }
    void create_a_list_for_a_polynomial()
    {
        char option;
        cout << "a for adding elements in list of polynomial" << endl
             << "b for display(note display after writing whole expression)" << endl
             << "c for creating list of another polynomial" << endl;
        do
        {
            cout << "option=";
            cin >> option;
            if (option == 'a')
            {
                int deg, value;
                cout << "Enter the element and degree in descending order of a polynomial:";
                cin >> value;
                cin >> deg;
                create_new_node(value, deg);
                if (start1 == NULL)
                {
                    start1 = newnode;
                    temp = newnode;
                }
                else
                {
                    temp->next = newnode;
                    temp = newnode;
                }
            }

        } while (option != 'b');
    }
    void display_list1(int degree)
    {
        display = start1;
        while (display != NULL)
        {
            cout << display->data << "x" << degree << "+"
                 << "\t";
            display = display->next;
        }
    }
};