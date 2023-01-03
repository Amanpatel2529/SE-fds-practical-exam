#include <iostream>
using namespace std;
class MyQ
{
    string Q[50];
    int front;
    int rear;

public:
    MyQ()
    {
        front = -1;
        rear = -1;
    }
    int insert_rear(string);
    int insert_front(string);
    string del_front();
    string del_rear();
    bool isEmpty();
};

int MyQ ::insert_rear(string elem)
{
    if (front == -1)
    {
        front++;
    }
    rear++;
    Q[rear] = elem;
    return rear;
}
int MyQ ::insert_front(string elem)
{
    if (front == -1)
    {
        front++;
        rear++;
        Q[front] = elem;
        return front;
    }
    else
    {
        for (int i = rear + 1; i > front; i--)
        {
            Q[i] = Q[i - 1];
        }
        rear++;
        Q[front] = elem;
        return rear;
    }
}

string MyQ ::del_front()
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
        front++;
        return Q[temp];
    }
}

string MyQ ::del_rear()
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
        int temp = rear;
        rear--;
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
    Q.insert_rear("Elem1");
    Q.insert_rear("Elem2");
    cout << Q.del_front() << endl;
    Q.insert_front("Elem3");
    Q.insert_front("Elem4");
    cout << Q.del_rear() << endl;
    cout << Q.del_front() << endl;
    cout << Q.del_rear() << endl;
    return 0;
}