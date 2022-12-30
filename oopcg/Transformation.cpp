

#include <graphics.h>
#include <stdlib.h>
#include<dos.h>
#include <iostream>
// #include<conio.h>
#include <math.h>
using namespace std;
class triangle

{
  int x1, x2, x3, y1, y2, y3, nx1, nx2, nx3, ny1, ny2, ny3, c;

public:
  void read();
  void draw();
  triangle operator+(triangle t);
  triangle operator*(triangle t);
  triangle operator/(triangle t);
};
void triangle::read()
{
  cout << "\t program for basic transformation";
  cout << "\n\t enter the coordinates of triangle";
  setcolor(11);
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  // draw(x1,y1,x2,y2,x3,y3);
}

void triangle::draw()
{
  line(x1, y1, x2, y2);
  delay(200);
  line(x2, y2, x3, y3);
  delay(200);
  line(x3, y3, x1, y1);
  delay(200);
  // getch();
}

triangle triangle::operator+(triangle t)
{
  int tx, ty;
  cout << "\Enter translation factors(tx and ty)";
  cin >> tx >> ty;
  t.x1 = x1 + tx;
  t.y1 = y1 + ty;
  t.x2 = x2 + tx;
  t.y2 = y2 + ty;
  t.x3 = x3 + tx;
  t.y3 = y3 + ty;
  delay(2000);
  return (t);
}

triangle triangle::operator*(triangle t)
{
  float sx, sy;
  cout << "\n Enter the scalling factor(Sx and Sy)";
  cin >> sx >> sy;
  t.x1 = x1 * sx;
  t.y1 = y1 * sy;
  t.x2 = x2 * sx;
  t.y2 = y2 * sy;
  t.x3 = x3 * sx;
  t.y3 = y3 * sy;
  return (t);
}

triangle triangle ::operator/(triangle t)
{
  int r;
  float theta;
  cout << "\n Enter the angle of rotation";
  cin >> r;
  theta = 3.14 * r / 180;
  t.x1 = abs(x1 * cos(theta) - y1 * sin(theta));
  t.y1 = abs(x1 * sin(theta) + y1 * sin(theta));
  t.x2 = abs(x2 * cos(theta) - y2 * sin(theta));
  t.y2 = abs(x2 * sin(theta) + y2 * cos(theta));
  t.y3 = abs(x3 * sin(theta) + y3 * cos(theta));
  return (t);
}
int main()
{
  int gm, c;
  int gd = DETECT;

  triangle t1, T, S, R, t2;
  t1.read();
  initgraph(&gd, &gm, NULL);
  t1.draw();
  cout << "\n 1.translation\n 2.rotation\n 3.scalling\n 4.exit";
  cout << "enter your choice:";
  cin >> c;

  switch (c)
  {
  case 1:
    T = t1 + t2; // t1++
    T.draw();
    break;
  case 2:
    R = t1 / t1;
    R.draw();
    break;
  case 3:
    S = t1 * t1;
    S.draw();
    break;
  case 4:
    exit(0);
  }
  closegraph();
  return 0;
}





 
