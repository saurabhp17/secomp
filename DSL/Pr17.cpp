
//  Deque implementation using one-dimensional array

#include <iostream>
using namespace std;

#define max 4

class cDQ
{
        int front, rear;
        int DQ[max];

public:
        cDQ()
        {
                front = rear = -1;
        }

        void InsertRight();
        void InsertLeft();
        void DeleteRight();
        void DeleteLeft();
        int isEmpty();
        int isFull();
        void DisplayDQ();
};

int cDQ ::isEmpty()
{
        if (front == -1 && rear == -1)
                return 1;

        else
                return 0;
}

int cDQ ::isFull()
{
        if (rear == max - 1)
                return 1;

        else
                return 0;
}

void cDQ::InsertRight()
{

        int element;
        

        if (isFull())
                cout << "Queue is Full";

        else
        {
                cout << "\n Enter the element-->";
                cin >> element;
                if (front == -1 && rear == -1) // initially if queue is empty
                {
                        front++;
                        rear++;
                        DQ[rear] = element;
                }

                else
                {
                        rear++;
                        DQ[rear] = element;
                }
        }
}

void cDQ::InsertLeft()
{
        int element;
        

        if (isFull())
                cout << "Queue is Full";

        else
        {
                        cout << "\n Enter the element-->";
                        cin >> element;
                if (front == -1 && rear == -1) // initially if queue is empty
                {
                        front++;
                        rear++;
                        DQ[front] = element;
                }

                else if (front == 0) // if front pointing to first element then shift to right
                {
                        for (int i = rear; i >= front; i--)
                        {
                                DQ[i + 1] = DQ[i];
                        }

                        front++;
                        rear++;

                        front--;
                        DQ[front] = element;
                }

                else
                {
                        front--;
                        DQ[front] = element;
                }
        }
}

void cDQ::DeleteLeft()
{

        if (isEmpty())
                cout << "Queue is Empty";

        else
        {
                cout << "Deleted element from Queue-->" << DQ[front];
                if (front == rear) // if only one element
                {
                        front = rear = -1;
                }

                else
                {
                        front = front + 1;
                }
        }
}

void cDQ::DeleteRight()
{
        if (isEmpty())
                cout << "Queue is Empty";

        else
        {
                cout << "Deleted element from Queue-->" << DQ[rear];

                if (front == rear) // if only one element
                {
                        front = rear = -1;
                }

                else
                {
                        rear--;
                }
        }
}

void cDQ::DisplayDQ()
{

        if (isEmpty())
                cout << "Queue is Empty";

        else
        {
                cout << "Queue elements--> ";
                int i = front;
                while (i <= rear)
                {
                        cout << "\t" << DQ[i];
                        i++;
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
                        obj.InsertLeft();
                        break;

                case 2:
                        obj.InsertRight();
                        break;

                case 3:
                        obj.DeleteLeft();
                        break;

                case 4:
                        obj.DeleteRight();
                        break;

                case 5:
                        obj.DisplayDQ();
                        break;
                }

                cout << "\nDo You want to continue(y/n)";
                cin >> ans;

        } while (ans == 'y');
        return 0;
}