/*Infix expression to postfix expression*/
// Doesnot work if there is unbalanced parenthesis
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
#define size 15

class Stack
{
private:
    char arr[size];
    int top = -1;
    string infix_expression, postfix_expression = "";
    char ch;

public:
    Stack()
    {
    }
    bool is_full()
    {
        if (top == size - 1)
        {
            return true;
        }
        else
            return false;
    }
    bool is_empty()
    {
        if (top == -1)
        {
            return true;
        }
        else
            return false;
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
        cout << "Enter the infix expression: ";
        cin >> infix_expression;
        return infix_expression;
    }
    bool is_rightparenthesis(char ch)
    {
        return ch == ')' || ch == '}' || ch == ']';
    }
    bool is_leftparenthesis(char ch)
    {
        return ch == '(' || ch == '{' || ch == '[';
    }
    bool is_operator(char ch)
    {
        return ch == '*' || ch == '/' || ch == '+' || ch == '-';
    }
    int precedence(char ch)
    {
        if (ch == '^')
            return 3;
        else if (ch == '*' || ch == '/')
            return 2;
        else if (ch == '+' || ch == '-')
            return 1;
        else if (is_leftparenthesis(ch))
            return -1; // Lower precedence for left parenthesis
        else
            return 0;
    }
    string make_posfix_expression()
    {
        for (int i = 0; i < infix_expression.length(); i++)
        {
            char ch = infix_expression[i];

            if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9')
            {
                postfix_expression += ch;
            }
            else if (is_leftparenthesis(ch))
            {
                push(ch);
            }
            else if (is_rightparenthesis(ch))
            {
                push(ch);
                pop();
                do
                {
                    postfix_expression += pop();
                } while (!is_leftparenthesis(arr[top]));
                pop();
            }
            else if (is_operator(ch))
            {

                if (precedence(ch) <= precedence(arr[top]))
                {
                    postfix_expression += pop();
                }
                push(ch);
            }
        }
        while (!is_empty())
        {
            if (!is_leftparenthesis(ch) && !is_rightparenthesis(ch))
            {
                postfix_expression += pop();
            }
            else
                pop();
        }
        return postfix_expression;
    }
};

int main()
{
    Stack s;
    s.getdata();
    cout << "The required postfix expression is: " << s.make_posfix_expression();
    return 0;
}
