/*Perform enqueue and dequeue operations in Linear Queue*/
#include <iostream>
using namespace std;
#define size 5
template <typename T>
class Queue
{
private:
    T arr[size];
    int front = -1, rear = -1, option;

public:
    Queue() {}
    bool is_empty()
    {
        return front == -1 && rear == -1 || front == rear + 1;
    }
    bool is_full()
    {
        return rear == size - 1;
    }

    void enqueue()
    {
        if (is_full())
        {
            cout << "Queue full" << endl;
            exit(0);
        }
        /*else if (front == rear)
        {
            front = -1;
            rear = -1;
        }*/

        cout << "Enter the element to be enqueued:";
        cin >> arr[++rear];
    }
    T dequeue()
    {
        if (is_empty())
        {
            cout << "Queue empty";
            exit(0);
        }
        else
            return arr[++front];
    }
    void options()
    {
        cout << endl
             << endl;
        cout << "Enter the action to  be done:" << endl
             << "1 for enqueue" << endl
             << "2 for dequeue" << endl
             << "3 for quit" << endl;
        cin >> option;
        while (option != 3)
        {
            if (option == 1)
            {
                enqueue();
            }
            else if (option == 2)
            {
                cout << "Dequeued element:" << dequeue() << endl;
            }
            options();
        }
    }
};
int main()
{
    Queue<int> q;
    q.options();
    return 0;
}