#include <iostream>
#include <string>

using namespace std;
struct node
{
    string stud_name;
    struct node *next;
    string PRN;
};

typedef struct node node;

node *change_president(node *head, string president, string PRN)
{
    if (head == NULL)
    {
        node *temp = new node;
        temp->stud_name = president;
        temp->PRN = PRN;
        temp->next = NULL;
        head = temp;
        return head;
    }
    else
    {
        head->stud_name = president;
        head->PRN = PRN;
        return head;
    }
}

void add_mem(node *head, string member, string PRN)
{
    node *ptr = head;
    node *preptr = ptr;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    node *temp = new node;
    temp->next = ptr;
    temp->stud_name = member;
    temp->PRN = PRN;
    temp->next = temp;
    preptr->next = temp;
}

void remove_mem(node *head, string member)
{
    node *ptr = head;
    node *preptr = ptr;
    while (ptr->stud_name != member)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    ptr = NULL;
}

void change_secretary(node *head, string secretary, string PRN)
{
    node *ptr = head;
    int count = 1;
    while (ptr->next != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    if (count == 1)
    {
        node *temp = new node;
        temp->stud_name = secretary;
        temp->next = NULL;
        temp->PRN = PRN;
        ptr->next = temp;
    }
    else
    {
        ptr->stud_name = secretary;
        ptr->PRN = PRN;
    }
}

void display(node *head)
{
    if (head == NULL)
        cout << "Linked list uninitialized";
    else
    {
        int count = 0;
        node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr == head)
            {
                cout << "\nPresident : ";
                count++;
            }
            else if (ptr->next == NULL)
            {
                cout << "Secretary : ";
            }
            else if (count == 1)
            {
                cout << "Members : " << endl;
                count++;
            }
            cout << "Name - ";
            cout << ptr->stud_name;
            cout << " | PRN - " << ptr->PRN << endl;
            ptr = ptr->next;
        }
    }
}

int total_members(node *head)
{
    int count = 0;
    node *ptr = head;
    while (ptr->next != NULL)
    {
        if (ptr != head)
        {
            count++;
        }
        ptr = ptr->next;
    }
    return count;
}

void append_list(node *head1, node *head2)
{
    node *ptr = head1;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = head2;
}

int main()
{
    int start = 1;
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    head1 = change_president(head1, "No president", "No president");

    head2 = change_president(head2, "No president", "No president");

    change_secretary(head1, "No secretary", "No secretary");
    change_secretary(head2, "No secretary", "No secretary");
    cout << "\nEnter choice 1 to add president" << endl;
    cout << "Enter choice 2 to add secretary" << endl;
    cout << "Enter choice 3 to add members" << endl;
    cout << "Enter choice 4 to delete president" << endl;
    cout << "Enter choice 5 to delete secretary" << endl;
    cout << "Enter choice 6 to delete member" << endl;
    cout << "Enter choice 7 to compute total members" << endl;
    cout << "Enter choice 8 to display all members" << endl;
    cout << "Enter choice 9 to append division 1 to division 2" << endl;

    cout << "Enter choice 10 to exit" << endl;
    while (start)
    {
        string member_name;
        int whichclass, size;
        string name;
        string PRN;
        int choice = 9;
        cout << "Your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nWhich division? (1 or 2) : ";
            cin >> whichclass;
            cout << "Enter name of president: ";
            cin >> name;
            cout << "Enter PRN of president: ";
            cin >> PRN;
            if (whichclass == 1)
                change_president(head1, name, PRN);
            else
                change_president(head2, name, PRN);
            break;
        case 2:
            cout << "\nWhich division? (1 or 2) : ";
            cin >> whichclass;
            cout << "Enter name of secretary: ";
            cin >> name;
            cout << "Enter PRN of secretary: ";
            cin >> PRN;
            if (whichclass == 1)
                change_secretary(head1, name, PRN);
            else
                change_secretary(head2, name, PRN);
            break;
        case 3:
            cout << "How many members to add : ";
            cin >> size;
            cout << "\nWhich division? (1 or 2) : ";
            cin >> whichclass;
            if (whichclass == 1)
                for (int i = 0; i < size; i++)
                {
                    cout << "Enter name of member " << i + 1 << ": ";

                    cin >> name;
                    cout << "Enter PRN of member " << i + 1 << ": ";

                    cin >> PRN;
                    add_mem(head1, name, PRN);
                }
            else
                for (int i = 0; i < size; i++)
                {
                    cout << "Enter name of member: ";
                    cin >> name;
                    cout << "Enter PRN of member: ";
                    cin >> PRN;
                    add_mem(head2, name, PRN);
                }
            break;
        case 4:
            cout << "\nWhich division? (1 or 2) : ";
            cin >> whichclass;
            if (whichclass == 1)
            {
             change_president(head1, "No president", "No president");
            }
            else if (whichclass == 2)
            {
             change_president(head2, "No president", "No president");
            }
            break;
        case 5:
            cout << "\nWhich division? (1 or 2) : ";
            cin >> whichclass;
            if (whichclass == 1)
            {
              change_secretary(head1, "No secretary", "No secretary");
            }
            else if (whichclass == 2)
            {
              change_secretary(head2, "No secretary", "No secretary");
            }
            break;
        case 6:
            cout << "\nWhich division? (1 or 2) : ";
            cin >> whichclass;
            if (whichclass == 1)
            {
              cout << "Enter name of member to remove :";
              cin >> member_name;
              remove_mem(head1, member_name);
            }
            else if (whichclass == 2)
            {
               cout << "Enter name of member to remove :";
               cin >> member_name;
               remove_mem(head2, member_name);
            }
            break;
        case 7:
            cout << "\nWhich division? (1 or 2) : ";
            cin >> whichclass;
            if (whichclass == 1)
            cout << "\nDivision 1 has " << total_members(head1) << " members." << endl;
            else if (whichclass == 2)
            cout << "\nDivision 2 has " << total_members(head2) << " members." << endl;

            break;
        case 8:
            cout << "\nFor divison 1 :" << endl;
            display(head1);
            cout << "\nFor divison 2 :" << endl;
            display(head2);
            break;
        case 9:
            int append_choice;
            cout << "\nEnter 1 to append division 1 to end of division 2 "<< endl;
            cout<< "Enter 2 to append division 2 to end of division 1 "<< endl;
            cout<< "Your choice :";
            cin >> append_choice;
            if (append_choice == 1)
            {
              append_list(head2, head1);
            }
          else if (append_choice == 2)
            {
              append_list(head1, head2);
            }
            break;
        case 10:
            start = 0;
            break;
        default:
            start = 0;
            break;
        }
    }
    return 0;
}