/*Perform enqueue and dequeue operations in Circular Queue*/
#include <iostream>
using namespace std;
#define size 5
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
    void enqueue()
    {
        if (is_full())
        {
            cout << "Queue is Full" << endl;
            exit(0);
        }
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        cout << "Enter the element to be added in the queue:";
        cin >> arr[rear];
    }
    T dequeue()
    {
        if (is_empty())
        {
            cout << "Queue is empty";
            exit(0);
        }
        T ans = arr[front];
        if (rear == front)
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
    void display_queue()
    {
        cout << "Elements in Queue are:" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "   ";
        }
    }
    void operations()
    {
        int option;
        cout << "Enter anything mentioned below:" << endl
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
            operations();
        }
    }
};
int main()
{
    Queue<int> q;
    q.operations();

    return 0;
}