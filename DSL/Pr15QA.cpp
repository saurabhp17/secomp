#include <iostream>
using namespace std;
#define max 3

class cQueue
{
    int Q[max];
    int front, rear;

public:
    int isEmpty();
    int isFull();
    void addJob();
    void delJob();
    void DispJob();

    cQueue()
    {
        front = rear = -1;
    }
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
    if (rear == max - 1)
    {
        return 1;
    }
    else
        return 0;
}

void cQueue ::addJob()
{
    int jobID;
    cout << "\nEnter The job-->";
    cin >> jobID;

    if (isFull())
    {
        cout << "\n Queue is Full ! ";
    }

    else
    {
        if (rear == -1) // inserting first job
        {
            front++;
            rear++;
            Q[rear] = jobID;
        }

        else
        {
            rear++;
            Q[rear] = jobID;
        }
    }
}

void cQueue ::delJob()
{
    int i;
    if (isEmpty())
    {
        cout << "\n Queue is Empty ! ";
    }

    else
    {
        cout << "\n Deleted JOB-->" << Q[front];

        if (front == rear)
        {
            front = rear = -1;
        }

        else
        {
            front = front + 1;
        }
    }
}

void cQueue ::DispJob()
{

    if (isEmpty())
    {
        cout << "\nQueue is Empty";
    }
    else
    {
        int i = front;
        while (i <= rear)
        {
            cout << "\t" << Q[i];
            i++;
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
        cout << " \n 1.Insert Job ID \n 2. Delete Job ID \n3. Display";
        cout << "\nEnter Your choice :";
        cin >> choice;

        switch (choice)
        {

        case 1:
            obj.addJob();
            break;

        case 2:
            obj.delJob();
            break;

        case 3:
            obj.DispJob();
            break;
        }
        cout << "\nDo you want to continue(y/n)";
        cin >> ans;

    } while (ans == 'y');

    return 0;
}