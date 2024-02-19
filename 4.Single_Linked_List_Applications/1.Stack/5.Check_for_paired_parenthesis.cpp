/*Check the paired parenthesis in mathematical expression*/
#include <iostream>
#include <cstring>
#define size 100
using namespace std;
class Stack
{
private:
    string mathematical_expression;
    int top = -1;
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

    bool is_rightparenthesis(char ch)
    {
        return ch == ')' || ch == '}' || ch == ']';
    }
    bool is_leftparenthesis(char ch)
    {
        return ch == '(' || ch == '{' || ch == '[';
    }
    void push(char ch)
    {
        if (is_full())
        {
            cout << "Stack is empty";
            exit(0);
        }
        else
            arr[++top] = ch;
    }
    char pop()
    {
        if (is_empty())
        {
            cout << "Stack is empty";
            exit(0);
        }
        else
            return arr[top--];
    }
    string getdata()
    {
        cout << "Enter the mathematical expression:";
        cin >> mathematical_expression;
        return mathematical_expression;
    }
    void is_balanced()
    {

        for (int i = 0; i < mathematical_expression.length(); i++)
        {
            ch = mathematical_expression[i];
            if (is_leftparenthesis(ch))
            {
                push(ch);
            }
            else if (is_rightparenthesis(ch))
            {
                pop();
            }
        }
        if (is_empty())
            cout << "The parenthesis are balanced";
        else
            cout << "The parenthesis are unbalanced";
    }
};

int main()
{
    Stack s;
    s.getdata();
    s.is_balanced();
    return 0;
}