// Deque implementation using doubly linked list

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

class cDQ
{
    struct node *front, *rear;

public:
    void InsertAtFront();
    void InsertAtEnd();
    void DeleteFirst();
    void DeleteLast();
    int isEmpty();
    void Display();
    cDQ()
    {
        front = rear = NULL;
    }
};

int cDQ ::isEmpty()
{
    if (front == NULL && rear == NULL)
    {
        return 1;
    }
    else
        return 0;
}

void cDQ ::InsertAtFront()
{
    int element;
    cout << "\nEnter data-->";
    cin >> element;
    struct node *nn;
    nn = new node;
    nn->next = NULL;
    nn->prev = NULL;
    nn->data = element;

    if (isEmpty())
    {
        front = rear = nn;
    }
    else
    {
        nn->next = front;
        front->prev = nn;
        front = nn;
    }
}

void cDQ ::InsertAtEnd()
{
    int element;
    cout << "\nEnter data-->";
    cin >> element;
    struct node *nn;
    nn = new node;
    nn->next = NULL;
    nn->prev = NULL;
    nn->data = element;

    if (isEmpty())
    {
        front = rear = nn;
    }
    else
    {
        rear->next = nn;
        nn->prev = rear;
        rear = nn;
    }
}

void cDQ::DeleteFirst()
{
    if (isEmpty())
    {
        cout << "\nQueue is empty !";
    }

    else
    {
        if (front == rear) // if only one node
        {
            cout << "\n Deleted element -> " << front->data;
            struct node *d;
            d = front;
            delete (d);
            front = rear = NULL;
        }

        else
        {
            cout << "\n Deleted element -> " << front->data;
            struct node *d;
            d = front;
            front = front->next;
            front->prev = NULL;
            delete (d);
        }
    }
}

void cDQ ::DeleteLast()
{
    if (isEmpty())
    {
        cout << "\nQueue is empty !";
    }
    else
    {
        if (front == rear) // if only one node
        {
            cout << "\n Deleted element -> " << rear->data;
            struct node *d;
            d = rear;
            delete (d);
            front = rear = NULL;
        }

        else
        {
            cout << "\n Deleted element -> " << rear->data;
            struct node *d;
            d = rear;
            rear = rear->prev;
            rear->next = NULL;
            delete (d);
        }
    }
}

void cDQ ::Display()
{
    if (isEmpty())
    {
        cout << "\n Deque is empty !";
    }

    else
    {
        struct node *temp;
        temp = front;
        if (front == rear) // if only one node
        {
            cout << "\t" << temp->data;
        }

        else
        {
            while (temp != NULL)
            {
                cout << "\t" << temp->data;
                temp = temp->next;
            }
        }
    }
}

int main()
{

    cDQ obj;
    int choice;
    char ans;
    do
    {

        cout << "\n***MENU*** \n1. Insert at front \n2. Insert at last \n3. Delete first \n4.Delete Last\n5.Display ";
        cout << "\nEnter the choice :";
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.InsertAtFront();
            break;

        case 2:
            obj.InsertAtEnd();
            break;

        case 3:
            obj.DeleteFirst();
            break;

        case 4:
            obj.DeleteLast();
            break;

        case 5:
            obj.Display();
            break;
        }

        cout << "\nDo You want to continue(y/n)";
        cin >> ans;

    } while (ans == 'y');
    return 0;
}