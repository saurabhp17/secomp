#include<iostream>
using namespace std;
class cstack
{ 
    #define MAX 20
    char stk[MAX];
    int top;
  public:
     cstack()
 {
   top=-1;
 }
    int isFull();
    int isEmpty();
    void push(char);
    void pop();
    char getTop();
   };
 int cstack::isFull()
{
  if(top==MAX-1)
    return 1;
  else
    return 0;
}
int cstack::isEmpty()
{
  if(top==-1)
     return 1;
  else
    return 0;
}
void cstack::push(char c)
{
    if(isFull()==1)
      cout<<"stack is overflow";
   else
     {
       top++;
       stk[top]=c;
     }
}
void cstack::pop()
{
   if(isEmpty())
   cout<<"stack is underflow";
   else
   {
     cout<<"popped char:"<<stk[top];
     top--;
   }
}
char cstack::getTop()
{
   return stk[top];
}
int main()
{   
  int i;
  cstack s;
  char s1[20];
   cout<<"Enter the expression";
   cin>>s1;

for(i=0;s1[i]!='\0';i++)
{
   if(s1[i]=='(' || s1[i]=='[' || s1[i]=='{')
{
    s.push(s1[i]);
}
else
{
  if(s1[i]==')' || s1[i]==']' || s1[i]=='}')

{
char c=s.getTop();

    if(s1[i]==')' && c=='(' || s1[i]==']' && c=='[' || s1[i]=='}' && c=='{')
     s.pop(); 
}
}
}
if(s.isEmpty())
  cout<<"Expresssion is well parenthesized";
else
cout<<"Expression is not well parenthesizes";
}
