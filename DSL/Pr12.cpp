#include<iostream>

using namespace std;
struct node {
  int data;
  node * prev, * next;
};

class cBinary {
  public: struct node * head,* last;
  struct node * create();
   void display();
  void add(struct node * , struct node * );
  cBinary() { head = NULL; }
};


struct node * cBinary::create() {

  struct node * nn;
  head = NULL;
  int n, rem;
  cout << "Enter decimal no:";
  cin >> n;
  while (n != 0) {
    rem = n % 2;
    n = n / 2;

    nn = new node;
    nn -> prev = nn -> next = NULL;
    nn -> data = rem;
    if (head == NULL) {
      last = head = nn;
    } else {
      struct node * oh;
      oh = head;
      oh -> prev = nn;
      nn -> next = oh;
      head = nn;
    }
  }
  return (nn);
}
void cBinary::display() {

  struct node * temp = head;
  while (temp != NULL) {
    cout << temp -> data;
    temp = temp -> next;
  }
  cout << endl;
}

void cBinary::add(struct node * p, struct node * q) 
{
    int n;
    n=10;
  int a[10] = {0};
  int i;
  i = n-1;
  int cnt=0;
  struct node * temp1 = NULL, * temp2 = NULL, * head1 = NULL, * head2 = NULL;
  cout << "\nStarted Addition" << endl;
  temp1 = p, head1 = p, head = p;
  display();
  temp2 = q, head2 = q, head = q;
  display();
  int carry;
  carry = 0;
  while (temp1 -> next != NULL) {
    temp1 = temp1 -> next;
  }
  while (temp2 -> next != NULL) {
    temp2 = temp2 -> next;
  }

  while (temp1 != NULL || temp2 != NULL) {
    if (temp1 == NULL) {
      node * p = new(struct node);
      p -> next = temp1;
      p -> data = 0;
      p -> prev = NULL;
      temp1 = p;
    }

    if (temp2 == NULL) {
      node * p = new(struct node);
      p -> next = temp2;
      p -> data = 0;
      p -> prev = NULL;
      temp2 = p;
    }

    if (temp1 -> data == 1 && temp2 -> data == 1 && carry == 0) 
    {
      a[i] = 0;
      carry = 1;
    } 
    else if (temp1 -> data == 1 && temp2 -> data == 1 && carry == 1) 
    {
      a[i] = 1;
      carry = 1;
    }
     else if (temp1 -> data == 1 && temp2 -> data == 0 && carry == 1)
     {
      a[i] = 0;
      carry = 1;
    }
     else if (temp1 -> data == 0 && temp2 -> data == 0 && carry == 0) 
     {
      a[i] = 0;
      carry = 0;
    } 
    else if (temp1 -> data == 0 && temp2 -> data == 1 && carry == 1) 
    {
      a[i] = 0;
      carry = 1;
    }
     else if (temp1 -> data == 1 && temp2 -> data == 0 && carry == 0) 
     {
      a[i] = 1;
      carry = 0;
    }
     else if (temp1 -> data == 0 && temp2 -> data == 0 && carry == 1) 
     {
      a[i] = 1;
      carry = 0;
    }
     else if (temp1 -> data == 0 && temp2 -> data == 1 && carry == 0) 
     {
      a[i] = 1;
      carry = 0;
    }

    head1 = temp1;
    head2 = temp2;
    temp1 = temp1 -> prev;
    temp2 = temp2 -> prev;
    i--;
    cnt++;

  }
  if (carry == 1)
   {
    a[i] = 1;
    cnt++;
  }
  cnt=n-cnt;
  for (i = cnt; i < 10; i++)
   {
    cout << a[i];
  }

}
int main() {

  cBinary c, b;
  int ch;
  struct node * a, * p;
  do {
    cout << " \n Enter choice:";
    cout << " 1.Addition 2.Exit" << endl;

    cin >> ch;
    switch (ch) {
    case 1:
      a = b.create();
      p = c.create();
      b.add(a, p);
      break;


    case 2:
      return 0;
    default:
      cout << "You have enter wrong choice!!!!";
      break;
    }
  }
  while (true);
  return 0;
}