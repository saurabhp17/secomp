#include<graphics.h>
#include<iostream>

using namespace std;
void circle(int xc,int yc,int rad);
int main()
{
int xc,yc,rad,i,j,k=100;

//cout<<"Enter starting and ending point";
//cin>>xc>>yc;

cout<<"Enter the radius";
cin>>rad;


int gd=DETECT, gm=VGAMAX;
               initgraph(&gd, &gm, 0);

    for(j=0;j<5;j++)
 {
   for(i=100;i<200;i++)
   {
  
   circle(k,i,rad);
    delay(2);
    cleardevice();
     k++;
   }
  for(i=200;i>100;i--)
   {
    circle(k,i,rad);
    delay(2);
    cleardevice();
     k++;
   }
 }


                delay(10);
               closegraph();


 return 0;
}



