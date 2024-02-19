/*Static List
1. WAP TO INSERT AND DELETE IN A LIST.
 a. Insert to beginning of list
b. Insert at end of list
c. Insert after specific element
d. Delete from beginning of list
e. Delete from end of list
f. Delete after specific element*/
#include <iostream>
using namespace std;

const int MAX_SIZE = 10; // Maximum size of the list

class StaticLinkedList
{
private:
    struct Node
    {
        int data;
        int nextIndex;
    };

    Node arr[MAX_SIZE];
    int head;
    int freeIndex;

public:
    StaticLinkedList()
    {
        for (int i = 0; i < MAX_SIZE - 1; ++i)
        {
            arr[i].nextIndex = i + 1; // Initialize all nodes as free nodes
        }
        arr[MAX_SIZE - 1].nextIndex = -1; // Last node's nextIndex indicates end of list
        head = -1;                        // Initialize head to -1 (empty list)
        freeIndex = 0;                    // Initialize freeIndex to the first index
    }

    // Function to insert a value at the beginning of the list
    void insertAtBeginning(int value)
    {
        if (freeIndex == -1)
        {
            cout << "List is full. Cannot insert." << endl;
            return;
        }
        int newIndex = freeIndex;
        freeIndex = arr[freeIndex].nextIndex; // Update freeIndex to next free node
        arr[newIndex].data = value;
        arr[newIndex].nextIndex = head;
        head = newIndex;
    }

    // Function to insert a value at the end of the list
    void insertAtEnd(int value)
    {
        if (freeIndex == -1)
        {
            cout << "List is full. Cannot insert." << endl;
            return;
        }
        int newIndex = freeIndex;
        freeIndex = arr[freeIndex].nextIndex; // Update freeIndex to next free node
        arr[newIndex].data = value;
        arr[newIndex].nextIndex = -1;

        if (head == -1)
        {
            head = newIndex;
            return;
        }

        int current = head;
        while (arr[current].nextIndex != -1)
        {
            current = arr[current].nextIndex;
        }
        arr[current].nextIndex = newIndex;
    }

    // Function to insert a value after a specific element
    void insertAfter(int value, int afterValue)
    {
        if (freeIndex == -1)
        {
            cout << "List is full. Cannot insert." << endl;
            return;
        }

        int current = head;
        while (current != -1)
        {
            if (arr[current].data == afterValue)
            {
                int newIndex = freeIndex;
                freeIndex = arr[freeIndex].nextIndex; // Update freeIndex to next free node
                arr[newIndex].data = value;
                arr[newIndex].nextIndex = arr[current].nextIndex;
                arr[current].nextIndex = newIndex;
                return;
            }
            current = arr[current].nextIndex;
        }

        cout << "Element " << afterValue << " not found in the list." << endl;
    }

    // Function to delete from the beginning of the list
    void deleteFromBeginning()
    {
        if (head == -1)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        int temp = head;
        head = arr[head].nextIndex;
        arr[temp].nextIndex = freeIndex; // Make the deleted node as free node
        freeIndex = temp;
    }

    // Function to delete from the end of the list
    void deleteFromEnd()
    {
        if (head == -1)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        if (arr[head].nextIndex == -1)
        {
            deleteFromBeginning();
            return;
        }
        int prev = head;
        int current = arr[head].nextIndex;
        while (arr[current].nextIndex != -1)
        {
            prev = current;
            current = arr[current].nextIndex;
        }
        arr[prev].nextIndex = -1;           // Update the second last node's nextIndex to -1
        arr[current].nextIndex = freeIndex; // Make the deleted node as free node
        freeIndex = current;
    }

    // Function to delete after a specific element
    void deleteAfter(int afterValue)
    {
        if (head == -1)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        int current = head;
        while (current != -1)
        {
            if (arr[current].data == afterValue)
            {
                if (arr[current].nextIndex == -1)
                {
                    cout << "No element after " << afterValue << " to delete." << endl;
                    return;
                }
                int temp = arr[current].nextIndex;
                arr[current].nextIndex = arr[temp].nextIndex;
                arr[temp].nextIndex = freeIndex; // Make the deleted node as free node
                freeIndex = temp;
                return;
            }
            current = arr[current].nextIndex;
        }
        cout << "Element " << afterValue << " not found in the list." << endl;
    }

    // Function to display the list
    void display()
    {
        if (head == -1)
        {
            cout << "List is empty." << endl;
            return;
        }
        int current = head;
        while (current != -1)
        {
            cout << arr[current].data << " ";
            current = arr[current].nextIndex;
        }
        cout << endl;
    }
};

int main()
{
    StaticLinkedList list;
    int choice, value, afterValue;
    cout << "\nStatic Linked List Operations:" << endl;
    cout << "1. Insert at beginning" << endl;
    cout << "2. Insert at end" << endl;
    cout << "3. Insert after specific element" << endl;
    cout << "4. Delete from beginning" << endl;
    cout << "5. Delete from end" << endl;
    cout << "6. Delete after specific element" << endl;
    cout << "7. Display the list" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";

    while (choice != 8)
    {
        cout << "option=";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value to insert: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter value after which to insert: ";
            cin >> afterValue;
            list.insertAfter(value, afterValue);
            break;
        case 4:
            list.deleteFromBeginning();
            break;
        case 5:
            list.deleteFromEnd();
            break;
        case 6:
            cout << "Enter value after which to delete: ";
            cin >> afterValue;
            list.deleteAfter(afterValue);
            break;
        case 7:
            cout << "List: ";
            list.display();
            break;
        }
    }
    return 0;
}
