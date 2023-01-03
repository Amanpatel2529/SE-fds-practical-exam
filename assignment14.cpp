#include <iostream>
#define MAX 10
using namespace std;
class MyQ
{
    string Q[MAX]; // Max is 10
    int front;
    int rear;

public:
    MyQ()
    {
        front = -1;
        rear = 0;
        for (int i = 0; i < MAX; i++)
        {
            Q[i] = "Empty";
        }
    }
    int insert(string);
    string del();
    bool isEmpty();
};

int MyQ ::insert(string elem)
{
    if (front == (rear + 1) % MAX)
    {
        cout << "Queue is full!";
        return -1;
    }
    else
    {
        if (front == -1)
            front = rear = 0;
        else
        {
            rear = (rear + 1) % MAX;
        }
        Q[rear] = elem;
        return rear;
    }
}
string MyQ ::del()
{
    try
    {
        if (isEmpty())
        {
            throw 10;
        }
    }
    catch (int e)
    {
        cout << "Underflow error! trying to delete empty Queue!";
        return "error";
    }
    if (front == rear)
    {
        int temp = front;
        front = -1;
        rear = -1;
        return Q[temp];
    }
    else
    {
        int temp = front;
        front = (front + 1) % MAX;
        return Q[temp];
    }
}

bool MyQ ::isEmpty()
{
    if (front == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    MyQ Q;
    Q.insert("1_PepperoniPizza");
    Q.insert("2_Number9s");
    Q.insert("1_Number9Large");
    Q.insert("1_Number6WithExtraDip");
    Q.insert("1_Number7");
    Q.insert("1_Number45");
    Q.insert("1_Number45WithCheese");
    Q.insert("1_LargeSoda");
    while (!Q.isEmpty())
    {
        cout << Q.del() << endl;
    }
    return 0;
}