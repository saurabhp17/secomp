#include<iostream>
using namespace std;
struct node
{
    int Jid;
    struct node *next;
};
class cQueue
{
    node *front,*rear;
   
    public:
        int isEmpty();
        void addJob();
        void delJob();
        void dispJobQ();

cQueue()
{
    front=NULL;
    rear=NULL;
}
};
int cQueue ::isEmpty()
{
	if (front == NULL)
	{
		return 1;
	}
	else
		return 0;
}
 
void cQueue::addJob()
{
     front=rear=NULL;
    node *nn;
    int n;
    cout<<"Enter job Id:";
    cin>>n;
    nn=new node;
    nn->next=NULL;
    nn->Jid=n;
    if(rear==NULL)
        rear=front=nn;
    else
    {
        rear->next=nn;
        rear=nn;
    }                    
}

 void cQueue :: delJob() // from front end
{
	struct node *temp;
	if (isEmpty())
	{
		cout << "Queue is empty";
	}
	else
	{
		cout<<"\n deleted job  "<<front->Jid;
		temp = front;
		front = front->next;
		delete (temp);
	}
}


void cQueue::dispJobQ()
{
 //front=rear=NULL;
    struct node *temp;
    temp=front;
    while(temp!=NULL)
    {
        cout<<temp->Jid;
        temp=temp->next;
    }
}
int main()
{
    cQueue q;
    int choice;
    char x;
    do{
        cout<<"**** Menu **** \n 1.Add Job \n 2.Delete Job \n 3.Display \n";
        cout<<"Enter choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
                   q.addJob();
                   break;
                   
            case 2:
                   q.delJob();
                   break;
                   
            case 3:
                   q.dispJobQ();
                   break;
        }
        cout<<"\n Do you want to continue?";
        cin>>x;
       }
        while(x=='y');
        return 0;       
      
}              
        