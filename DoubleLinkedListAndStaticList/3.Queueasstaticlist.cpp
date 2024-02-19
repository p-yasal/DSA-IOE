/*Static Linked List
WAP TO REPRESENT QUEUE AS A LIST.*/
#include <iostream>
using namespace std;

const int MAX_SIZE = 10; // Maximum size of the queue

class StaticQueue
{
private:
    struct Node
    {
        int data;
        int nextIndex;
    };

    Node arr[MAX_SIZE];
    int front;
    int rear;
    int freeIndex;

public:
    StaticQueue()
    {
        for (int i = 0; i < MAX_SIZE - 1; ++i)
        {
            arr[i].nextIndex = i + 1; // Initialize all nodes as free nodes
        }
        arr[MAX_SIZE - 1].nextIndex = -1; // Last node's nextIndex indicates end of list
        front = -1;                       // Initialize front and rear to -1 (empty queue)
        rear = -1;
        freeIndex = 0; // Initialize freeIndex to the first index
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return front == -1;
    }

    // Function to check if the queue is full
    bool isFull()
    {
        return freeIndex == -1;
    }

    // Function to enqueue (add) an element to the rear of the queue
    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        int newIndex = freeIndex;
        freeIndex = arr[freeIndex].nextIndex; // Update freeIndex to next free node
        arr[newIndex].data = value;
        arr[newIndex].nextIndex = -1;

        if (isEmpty())
        {
            front = newIndex;
        }
        else
        {
            arr[rear].nextIndex = newIndex;
        }
        rear = newIndex;
    }

    // Function to dequeue (remove) an element from the front of the queue
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        int temp = front;
        front = arr[front].nextIndex;
        arr[temp].nextIndex = freeIndex; // Make the dequeued node as free node
        freeIndex = temp;

        if (front == -1)
        {
            rear = -1; // Reset rear if queue becomes empty
        }
    }

    // Function to display the queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        int current = front;
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
    StaticQueue queue;
    int choice, value;
    cout << "\nStatic Queue Operations:" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Display the queue" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";

    while (true)
    {
        cout << "Choice=";
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (!queue.isFull())
            {
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
            }
            else
            {
                cout << "Queue is full. Cannot enqueue." << endl;
            }
            break;
        case 2:
            if (!queue.isEmpty())
            {
                queue.dequeue();
            }
            else
            {
                cout << "Queue is empty. Cannot dequeue." << endl;
            }
            break;
        case 3:
            cout << "Queue: ";
            queue.display();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
