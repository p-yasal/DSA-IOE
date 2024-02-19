/*Evaluate the postfix expression*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define size 100
using namespace std;

class Stack
{
private:
    string postfix_expression;
    int top = -1;
    float A, B; // Changed the data type to float for operands
    char ch, arr[size];

public:
    bool is_full()
    {
        return top == size - 1;
    }

    bool is_empty()
    {
        return top == -1;
    }

    bool is_operator(char ch)
    {
        return ch == '*' || ch == '/' || ch == '+' || ch == '-';
    }

    bool is_number(int ch)
    {
        return ch >= 0 && ch <= 9;
    }

    void push(float n)
    {
        if (is_full())
        {
            cout << "Stack is full";
            exit(0);
        }
        else
        {
            arr[++top] = n;
        }
    }

    float pop()
    {
        if (is_empty())
        {
            cout << "Stack is empty";
            exit(0);
        }
        else
        {
            return arr[top--];
        }
    }

    string getdata()
    {
        cout << "Enter the postfix expression:";
        cin >> postfix_expression;
        return postfix_expression;
    }

    float evaluate_postfix_expression()
    {
        for (int i = 0; i < postfix_expression.length(); i++)
        {
            char ch = postfix_expression[i];

            if (is_number(ch))
            {
                push(ch - '0'); // Convert char to int
            }
            else if (is_operator(ch))
            {
                A = pop();
                B = pop();
                if (ch == '+')
                    push(A + B);
                else if (ch == '-')
                    push(B - A);
                else if (ch == '*')
                    push(A * B);
                else if (ch == '/')
                    push(B / A);
            }
        }
        return pop();
    }
};

int main()
{
    Stack s;
    s.getdata();
    cout << s.evaluate_postfix_expression();
    return 0;
}
