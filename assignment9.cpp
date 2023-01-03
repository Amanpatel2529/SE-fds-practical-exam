#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next = NULL;
    struct node *prev = NULL;
};
typedef struct node node;

node *insert_at_start(node *head, int num)
{
    if (head == NULL)
    {
        node *temp = new node;
        temp->data = num;
        head = temp;
        return head;
    }
    else
    {
        node *temp = new node;
        temp->data = num;
        temp->next = head;
        head->prev = temp;
        head = temp;
        return head;
    }
}

void one_compl(node *head)
{
    while (head != NULL)
    {
        if (head->data == 1)
            cout << "0";
        else
            cout << "1";
        head = head->next;
    }
}

void twos_complement(node *head)
{
    int ones_comp[50];
    int twos_comp[50];
    int count = 0;
    int borrow = 0;
    int size = 0;
    while (head != NULL)
    {
        if (head->data == 1)
            ones_comp[count++] = 0;
        else
            ones_comp[count++] = 1;
        head = head->next;
    }
    count--;
    size = count;
    if (ones_comp[count] == 1)
    {
        twos_comp[count] = 0;
        borrow = 1;
    }
    else
    {
        twos_comp[count] = 1;
        borrow = 0;
    }
    count--;
    for (int i = count; i >= 0; i--)
    {
        if (ones_comp[i] == 1)
        {
            if (borrow == 1)
            {
                twos_comp[i] = 0;
            }
            else
            {
                twos_comp[i] = 1;
            }
        }
        if (ones_comp[i] == 0)
        {
            if (borrow == 1)
            {
                twos_comp[i] = 1;
                borrow = 0;
            }
            else
            {
                twos_comp[i] = 0;
            }
        }
    }
    for (int i = 0; i <= size; i++)
    {
        cout << twos_comp[i];
    }
}

void add(node *head1, node *head2)
{
    int sum[50];
    node *ptr1 = head1;
    node *ptr2 = head2;
    int size1 = 0;
    int size2 = 0;
    int smaller = 0;
    node *greater = NULL;
    int borrow = 0;
    int count = 0;
    while (ptr1->next != NULL)
    {
        size1++;
        ptr1 = ptr1->next;
    }
    size1++;
    while (ptr2->next != NULL)
    {
        size2++;
        ptr2 = ptr2->next;
    }
    size2++;
    if ((size1 - size2) < 0)
    {
        smaller = size1;
        greater = ptr2;
    }
    else
    {
        smaller = size2;
        greater = ptr1;
    }
    for (int i = 0; i < smaller; i++)
    {
        if ((ptr1->data + ptr2->data) == 1)
        {
            if (borrow == 0)
            {
                sum[count++] = 1;
            }
            else
            {
                sum[count++] = 0;
            }
        }
        else if ((ptr1->data + ptr2->data) == 0)
        {
            if (borrow == 0)

            {
                sum[count++] = 0;
            }
            else
            {
                sum[count++] = 1;
                borrow = 0;
            }
        }
        if ((ptr1->data + ptr2->data) == 2)
        {
            if (borrow == 0)
            {
                sum[count++] = 0;
                borrow = 1;
            }
            else
            {
                sum[count++] = 1;
                borrow = 1;
            }
        }
        ptr1 = ptr1->prev;
        ptr2 = ptr2->prev;
        greater = greater->prev;
    }
    while (greater != NULL)
    {
        if (greater->data == 1)
        {
            if (borrow == 1)
            {
                sum[count++] = 0;
            }
            else
            {
                sum[count++] = 1;
            }
        }
        if (greater->data == 0)
        {
            if (borrow == 1)
            {
                sum[count++] = 1;
                borrow = 0;
            }
            else
            {
                sum[count++] = 0;
            }
        }
        greater = greater->prev;
    }
    if (borrow == 1)
    {
        sum[count] = 1;
    }
    else
    {
        count--;
    }
    for (int i = count; i >= 0; i--)
    {
        cout << sum[i];
    }
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;

    int binary1;
    int binary2;

    cout << "Enter binary num 1 : ";
    cin >> binary1;

    while (binary1)
    {
        head1 = insert_at_start(head1, binary1 % 10);
        binary1 = binary1 / 10;
    }
    cout << "Enter binary num 2 : ";
    cin >> binary2;
    while (binary2)
    {
        head2 = insert_at_start(head2, binary2 % 10);
        binary2 = binary2 / 10;
    }
    cout << "sum of binary no. :  ";
    add(head1, head2);
    cout << endl;

    cout << "one compl of 1st binary no :  ";
    one_compl(head1);
    cout << endl;

    cout << "two compl of 1st binary no :  ";
    twos_complement(head1);
    cout << endl;

    cout << "one compl of 2nd binary no :  ";
    one_compl(head2);
    cout << endl;

    cout << "two compl of 2nd binary no :  ";
    twos_complement(head2);
}