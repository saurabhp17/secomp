#include<iostream>
#include<string>

using namespace std;
class cStack
{

    private:
    char stk[25],str[25],ModStr[25];
    int top,len,count;

    void push(char);
    char pop();


     public:
    cStack()
    {
        top=-1;
        len=0;
        count=0;
    }

    void getString();
    void Palindrome();
};

void cStack::getString()
{
    cout<<"Enter the string-->\t";
    cin.getline(str,25);
    for ( int i = 0; str[i]!='\0'; i++)
    {
        len++;
    }
    int j=0;
    for (int  i = 0;str[i]!='\0'; i++)
    {
        if (str[i]!= ' ')
        {
            ModStr[j] = str[i];
            j++;
        }
        
    }
    
len =j;    
}

void cStack :: push(char temp)
{
    top++;
    stk[top] = temp;
}


char cStack :: pop()
{
    char temp = stk[top];
    top--;
    return temp;
}

void cStack::Palindrome()
{

    for(int i=0;i<len;i++)
    {
      
        push(ModStr[i]);

    }

    for ( int i = 0; i < len; i++)
    {
        if (ModStr[i]==pop())
        {
            count++;
        }
        
    }

    if(count==len)
    {
        cout<<"\n String is palindrome!";
    }

    else
        cout<<"\nString is not palindrome!";
           
}

int main()
{
    
    cStack  obj;
    obj.getString();
    obj.Palindrome();
    return 0;

}