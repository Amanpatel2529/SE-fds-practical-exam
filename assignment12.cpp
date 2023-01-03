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
    int insert(string);
    string del();
    bool isEmpty();
};
int MyQ ::insert(string elem)
{
    if (front == -1)
    {
        front++;
    }
    rear++;
    Q[rear] = elem;
    return rear;
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
        front++;
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
    Q.insert("Open_VSCODE");
    Q.insert("Compile_C++Code");
    Q.insert("Throw_SegFault");
    Q.insert("Close_VSCODE");
    Q.insert("Open_MediaPlayer");
    Q.insert("Start_Movie");
    Q.insert("Shut_Down");
    while (!Q.isEmpty())
    {
        cout << Q.del() << endl;
    }
    return 0;
}