// circular queue (pizza parlor) implemenation using circular linked list

#include <iostream>
using namespace std;

struct node
{
    int OrderNo;
    struct node *next;
};

class cQueue
{

    struct node *front, *rear;

public:
    cQueue()
    {
        front = rear = NULL;
    }

    void receive(); // insertion
    void deliver(); // deletion
    void display();
    void Menu();
    int isEmpty();
};

int cQueue ::isEmpty()
{
    if (front == NULL && rear == NULL)
    {
        return 1;
    }
    else
        return 0;
}

void cQueue ::receive()
{

    int ItemNo;
    cout << "\n Enter order to be received :";
    cin >> ItemNo;
    struct node *nn;
    nn = new node;
    nn->OrderNo = ItemNo;
    nn->next = NULL;

    if (isEmpty()) // if new node is the only node in linked list
    {
        rear = front = nn;

        rear->next = front; // in circular linked list last node next part contains head
    }

    else
    {
        rear->next = nn;
        rear = nn;
        rear->next = front; // in circular linked list last node next part contains head
    }

    cout << "\n Order Received !";
}

void cQueue ::deliver() // deletion in circular queue (deleting first node)
{
    struct node *d; // to store the node to be deleted
    if (isEmpty())
    {
        cout << "\n No orders for delivery !";
    }

    else
    {
        cout << " Order no  " << front->OrderNo << "  Delivered! \n";

        if (front == rear) // if only one node
        {

            d = front;
            front = rear = NULL;
            delete (d);
        }

        else
        {
            d = front;
            front = front->next;
            rear->next = front;
            delete (d);
        }
    }
}

void cQueue ::Menu()
{
    cout << "\n *** Menu  *** ";
    cout << "\n1.Mushroom Pizza \n2. Corn Pizza \n3.Veggie Pizza \n4.meat Pizza \n5.Cheese Pizza";
}

void cQueue ::display()
{
    struct node *tmp;
    tmp = front;

    if (isEmpty())
    {
        cout << "\n No orders!";
    }

    else
    {
        cout << "\n Orders are";

        while (tmp->next != front) // since last node next part contains front
        {
            cout << "\t" << tmp->OrderNo;
            tmp = tmp->next;
        }

        cout << "\t" << tmp->OrderNo; // last node will not be printed in while loop
    }
}

int main()
{
    cQueue obj;
    int choice;
    char ans;
    do
    {
        cout << " \n1.Receive an order \n2.Deliver an order \n3.Display order Queue \n4. Display Menu ";
        cout << "\nEnter Your choice :";
        cin >> choice;

        switch (choice)
        {

        case 1:
            obj.receive();
            break;

        case 2:
            obj.deliver();
            break;

        case 3:
            obj.display();
            break;

        case 4:
            obj.Menu();
            break;
        }
        cout << "\nDo you want to continue(y/n)";
        cin >> ans;

    } while (ans == 'y');

    return 0;
}
