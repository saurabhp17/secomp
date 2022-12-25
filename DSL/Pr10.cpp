#include <iostream>
using namespace std;

struct node
{
    int roll;
    struct node *next;
};

class cSE
{
public:
    struct node *insert(); // returns head
    void display(struct node *);
    void intersect(struct node *, struct node *);
    void Either(struct node *, struct node *);
    void Neither(struct node *, struct node *, struct node *);
};

struct node *cSE ::insert()
{
    int n, i;
    node *temp, *nn, *head;
    head = NULL;
    cout << "\nEnter No of Elements-->";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        nn = new node;
        cout << "Enter Roll No of student-->";
        cin >> nn->roll;
        nn->next = NULL;

        if (head == NULL)
        {
            head = nn;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = nn;
        }
    }
    return (head);
}

void cSE ::display(struct node *t)
{
    struct node *temp;
    temp = t;
    while (temp != NULL)
    {
        cout << temp->roll << "\t";
        temp = temp->next;
    }
}

void cSE::intersect(struct node *p, struct node *q)
{
    struct node *temp1, *temp2;
    temp1 = p;
    temp2 = q;
    int count = 0;
    while (temp1 != NULL)
    {
        temp2 = q;
        while (temp2 != NULL)
        {
            if (temp1->roll == temp2->roll)
            {
                cout << temp1->roll << "\t";
                count = 1;
            }

            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    if (count == 0)
    {
        cout << "\n Not a single student like both Vanilla and Butterscotch";
    }
}

void cSE::Either(struct node *p, struct node *q)
{
    struct node *temp1, *temp2;

    temp1 = p;
    temp2 = q;
    while (temp1 != NULL)
    {
        int found = 0;
        temp2 = q;
        while (temp2 != NULL)
        {
            if (temp1->roll == temp2->roll)
            {
                found = 1;
            }
            temp2 = temp2->next;
        }
        if (found == 0)
        {
            cout << temp1->roll << "\t";
        }

        temp1 = temp1->next;
    }

    temp1 = p;
    temp2 = q;
    while (temp2 != NULL)
    {
        int found = 0;
        temp1 = p;
        while (temp1 != NULL)
        {
            if (temp2->roll == temp1->roll)
            {
                found = 1;
            }
            temp1 = temp1->next;
        }
        if (found == 0)
        {
            cout << temp2->roll << "\t";
        }

        temp2 = temp2->next;
    }
}

void cSE::Neither(struct node *p, struct node *q, struct node *r)
{
    node *temp = p, *temp1 = q, *temp2 = r;

    while (temp != NULL)
    {
        int found = 0;
        temp1 = q;
        temp2 = r;
        while (temp1 != NULL || temp2 != NULL)
        {
            if (temp->roll == temp1->roll or temp->roll == temp2->roll)
            {
                found = 1;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        if (found == 0)
        {
            cout << temp->roll << "\t";
        }

        temp = temp->next;
    }
}

int main()
{
    cSE obj;
    struct node *head1 = NULL, *head2 = NULL, *all = NULL;
    char ans;
    int choice;

    do
    {
        cout << "\n 1.Insert \n 2.Display  \n 3.Students who like both ";
        cout << "\n 4.Student who like either vanilla or Butterscotch but not both ";
        cout << "\n 5.Neither Vanilla nor Butterscotch ";
        cout << "\n Enter choice  :";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "\nAll SE class students-->";
            all = obj.insert();

            cout << "\nStudents who like Vanilla :";
            head1 = obj.insert();

            cout << "\nStudents Who like Butterscotch :";
            head2 = obj.insert();

            break;

        case 2:
            cout << "\nAll SE class students-->";
            obj.display(all);
            cout << "\nStudents who like Vanilla :";
            obj.display(head1);
            cout << "\nStudents Who like Butterscotch :";
            obj.display(head2);

            break;

        case 3:
            cout << "\n Students who like both Vanilla and Butterscotch-->";
            obj.intersect(head1, head2);
            break;

        case 4:
            cout << "\n Student who like Either vanilla or butterscotch but not both-->";
            obj.Either(head1, head2);
            break;

        case 5:
            cout << "\n Student who like Neither vanilla nor butterscotch -->";
            obj.Neither(all, head1, head2);
        }

        cout << "\nDo you want to continue (y/n)";
        cin >> ans;
    } while (ans == 'y');

    return 0;
}