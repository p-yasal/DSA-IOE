/*Perform operations in Deque( Double ended queue) for:
a. Add at beginning
b. Add at end
c. Delete from beginning
d. Delete from end*/
#include <iostream>
#include <cstring>
#define size 5
using namespace std;
template <typename T>
class Queue
{
private:
    T arr[size];
    int front = -1, rear = -1;

public:
    bool is_empty()
    {
        return front == -1 && rear == -1;
    }
    bool is_full()
    {
        return front == 0 && rear == size - 1 || front == rear + 1;
    }
    void enqueue_from_end(T data)
    {
        if (is_full())
        {
            cout << "Queue full" << endl;
            exit(0);
        }
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = data;
    }
    void enqueue_from_beginning(T data)
    {
        if (is_full())
        {
            cout << "Queue is full";
            exit(0);
        }
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = data;
    }
    T dequeue_from_beginning()
    {
        if (is_empty())
        {
            cout << "Queue is empty";
            exit(0);
        }
        T ans = arr[front];

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        return ans;
    }

    T dequeue_from_end()
    {
        if (is_empty())
        {
            cout << "Queue is empty";
            exit(0);
        }
        T ans = arr[rear];

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (rear == -1)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
        return ans;
    }
    void display_queue()
    {
        if (is_empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Elements in Queue are:" << endl;
        int i = front;

        while (i != rear)
        {
            cout << arr[i] << "\t";
            i = (i + 1) % size;
        }
        cout << arr[rear];
        cout << endl;
    }
    void options()
    {
        int option;
        while (1)
        {
            cout << "Enter the action to be done:" << endl
                 << "1 for enqueue in beginning" << endl
                 << "2 for Dequeue in beginning" << endl
                 << "3 for enqueue in end" << endl
                 << "4 for Dequeue in end" << endl
                 << "5 to display queue" << endl
                 << "6 for quit" << endl;
            cin >> option;
            if (option == 1)
            {
                T d;
                cout << "Enter the element to be enqueued from beginning:";
                cin >> d;
                enqueue_from_beginning(d);
            }
            else if (option == 2)
            {
                cout << "Dequeued element from front:" << dequeue_from_beginning() << endl;
            }
            else if (option == 3)
            {
                T d;
                cout << "Enter the element to be enqueued from end:";
                cin >> d;
                enqueue_from_end(d);
            }
            else if (option == 4)
            {
                cout << "Dequeued element from end:" << dequeue_from_end() << endl;
            }
            else if (option == 5)
            {
                display_queue();
            }
            else if (option == 6)
            {
                exit(0);
            }
            options();
        } // end of while loop
    }
}; // end of class
int main()
{
    Queue<int> q;
    q.options();
    return 0;
}