/*Infix expression to prefix expression*/
// Doesnot work if unbalanced parenthesis is present
#include <iostream>
#include <cstring>
#include <algorithm>
#define size 15
using namespace std;

class Stack
{
private:
    string infix_expression, prefix_expression = "";
    char arr[size], ch;
    int top = -1;

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
            cout << "Stack is full";
            exit(0);
        }
        else
        {
            arr[++top] = ch;
        }
    }

    char pop()
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
        cout << "Enter the Infix expression:";
        cin >> infix_expression;
        return infix_expression;
    }
    int precedence(char ch)
    {
        if (ch == '^')
            return 3;
        else if (ch == '*' || ch == '/')
            return 2;
        else if (ch == '+' || ch == '-')
            return 1;
        else
            return 0;
    }
    string make_prefix()
    {
        for (int i = infix_expression.length() - 1; i >= 0; --i)
        {
            char ch = infix_expression[i];

            if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9')
            {
                prefix_expression += ch;
            }
            else if (is_rightparenthesis(ch))
            {
                push(ch);
            }
            else if (is_leftparenthesis(ch))
            {
                push(ch);
                pop();
                do
                {
                    prefix_expression += pop();
                } while (!is_rightparenthesis(arr[top]));
                pop();
            }
            else if (is_operator(ch))
            {
                push(ch);
                if (precedence(ch) < precedence(arr[top]))
                {
                    prefix_expression += pop();
                }
            }
        }
        while (!is_empty())
        {
            if (!is_leftparenthesis(ch) && !is_rightparenthesis(ch))
            {
                prefix_expression += pop();
            }
            else
                pop();
        }
        return prefix_expression;
    }

    string reverse_prefix_expression()
    {
        string reversed_prefix = prefix_expression;
        reverse(reversed_prefix.begin(), reversed_prefix.end());
        return reversed_prefix;
    }
};

int main()
{
    Stack s;
    s.getdata();
    s.make_prefix();
    cout << "The required prefix expression is: " << s.reverse_prefix_expression() << endl;
    return 0;
}
