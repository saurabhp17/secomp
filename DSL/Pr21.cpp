
// circular queue (pizza parlor) implemenation using array

#include <iostream>
using namespace std;
#define max 3

class cQueue
{
    int CQ[max];
    int front, rear, ItemNo;

public:
    cQueue()
    {
        front = rear = -1;
    }

    void receive(); // insertion
    void deliver(); // deletion
    void display();
    void Menu();
    int isEmpty();
    int isFull();
};

int cQueue ::isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    else
        return 0;
}

int cQueue ::isFull()
{
    if ((front == 0 && rear == max - 1) || (front == rear + 1))
    {
        return 1;
    }
    else
        return 0;
}

void cQueue ::receive()
{

    if (isFull())
    {
        cout << "\n Sorry ! Can't receive order";
    }

    else
    {
        cout << "\n Enter order to be received :";
        cin >> ItemNo;

        if (isEmpty())
        {
            rear = front = 0;
            CQ[rear] = ItemNo;
        }

        else if ((rear == max - 1) && front != 0) // if rear pointing to last position and
        {                                         // front not pointing to first position then make rear = 0
            rear = 0;
            CQ[rear] = ItemNo;
        }

        else // if rear pointing elsewhere in middle
        {
            rear = rear + 1;
            CQ[rear] = ItemNo;
        }

        cout << "\n Order Received !";
    }
}

void cQueue ::deliver() // deletion in circular queue
{
    if (isEmpty())
    {
        cout << "\n No orders for delivery !";
    }

    else
    {
        cout << " Order no  " << CQ[front] << "  Delivered! \n";

        if (front == rear) // if only one element
        {
            front = rear = -1;
        }

        else if (front == max - 1) // if front and rear both pointing to last position
        {
            front = -1;
        }

        else // if front pointing elsewhere in middle
        {
            front = front + 1;
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
    int f = front, r = rear;

    if (isEmpty())
    {
        cout << "\n No orders!";
    }

    else
    {
        cout << "\n Orders are";

        if (front <= rear)
        {
            while (f <= r)
            {
                cout << "\t" << CQ[f];
                f++;
            }
        }
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
