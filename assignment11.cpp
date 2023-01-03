#include <iostream>
using namespace std;
int push(char arr[], int n, char tar)
{
    try
    {
        if (n == 50)
            throw 10;
    }
    catch (int e)
    {
        cout << "Overflow error! tried to push a full stack..";
    }
    arr[n] = tar;
    n = n + 1;
    return n;
}

char pop(char arr[], int *top)
{
    try
    {
        if (*top == -1)
            throw 10;
    }
    catch (int a)
    {
        cout << "Underflow error! tried to pop an empty stack..";
    }
    int index = *top;
    *top = *top - 1;
    return arr[index];
}

char peek(char arr[], int top)
{
    return arr[top];
}

int precedence(char op)
{
    if (op == '-')
    {
        return 1;
    }
    if (op == '+')
    {
        return 2;
    }
    else if (op == '*')
    {
        return 3;
    }
    else // for '/'
    {
        return 4;
    }
}

void convert_to_postfix(char stack2[], int n2)
{
    char opstack[50];
    int opn = 0;
    int top = n2 - 1;
    int optop = opn - 1;
    for (int i = 0; i < n2; i++)
    {
        optop = opn - 1;
        char current = pop(stack2, &top);
        if (current == '(')
        {
            opn = push(opstack, opn, current);
        }
        else if (current == ')')
        {
            char popped = ' ';
            while ((popped = pop(opstack, &optop)) != '(')
            {
                cout << popped;
            }
            opn = optop + 1;
        }
        else if (current == '+' || current == '-' || current == '*' || current == '/')
        {
            if (opn == 0)
            {
                opn = push(opstack, opn, current);
            }
            else if (precedence(current) > precedence(peek(opstack,
                                                           optop)) ||
                     peek(opstack, optop) == '(')

            {
                opn = push(opstack, opn, current);
            }
            else
            {
                char popped = peek(opstack, optop);
                while (precedence(current) <= precedence(popped) &&
                       popped != '(' && optop > -1)

                {
                    popped = pop(opstack, &optop);
                    cout << popped;
                    opn = optop + 1;
                    popped = peek(opstack, optop);
                }
                opn = push(opstack, opn, current);
            }
        }
        else
        {
            cout << current;
        }
    }
    if (opn > 0)
    {
        optop = opn - 1;
        for (int i = 0; i < opn; i++)
        {
            cout << pop(opstack, &optop);
        }
    }
}
int main()
{
    char stack1[50];
    char stack2[50];
    int n1 = 0;
    int n2 = 0;
    char ch = 0;
    cout << "Enter infix expression :"; // + - * /
    while ((ch = getchar()) != '\n')
    {
        n1 = push(stack1, n1, ch);
    }
    int top1 = n1 - 1;

    for (int i = 0; i < n1; i++)
    {
        n2 = push(stack2, n2, pop(stack1, &top1));
    }
    cout << "Postfix expression :";
    convert_to_postfix(stack2, n2);
    return 0;
}