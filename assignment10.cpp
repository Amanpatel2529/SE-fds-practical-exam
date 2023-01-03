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

char *reverse(char arr[], int n)
{
    char *temp = new char[50];
    int n1 = 0, top = n - 1;
    for (int i = 0; i < n; i++)
    {
        n1 = push(temp, n1, pop(arr, &top));
    }
    return temp;
}

void print_original(char arr[], int n)
{
    char *temp = new char[50];
    int n1 = 0, top1 = n - 1;
    for (int i = 0; i < n; i++)
    {
        n1 = push(temp, n1, pop(arr, &top1));
    }
    int top2 = n1 - 1;
    cout << "Original string : ";
    for (int i = 0; i < n; i++)
    {
        cout << pop(temp, &top2);
    }
    cout << endl;
}

void print_reverse(char arr[], int n)
{
    int top = n - 1;
    cout << "Reversed string : ";
    for (int i = 0; i < n; i++)
    {
        cout << pop(arr, &top);
    }
    cout << endl;
}

bool isPalindrome(char arr[], int n)
{
    char *reversed = reverse(arr, n);
    int top1 = n - 1, top2 = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (pop(arr, &top1) != pop(reversed, &top2))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char stack[50], current = -1;
    int n = 0;
    cout << "Enter string :";

    while (true)
    {
        current = getchar();
        if (current == '\n')
            break;
        else if (current != ' ')
            n = push(stack, n, current);
    }
    print_original(stack, n);
    print_reverse(stack, n);
    if (isPalindrome(stack, n))
    {
        cout << "Given string is a palindrome!" << endl;
    }
    else
    {
        cout << "Given string is not a palindrome!" << endl;
    }
    return 0;
}