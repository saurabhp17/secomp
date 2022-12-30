

#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;
class kochCurve
{
public:
      void koch(int it, int x1, int y1, int x5, int y5)
      {
            int x2, y2, x3, y3, x4, y4;
            int slicex, slicey;
            if (it == 0)
            {
                  line(x1, y1, x5, y5);
            }
            else
            {
                  delay(1);
                  slicex = (x5 - x1) / 3;
                  slicey = (y5 - y1) / 3;
                  x2 = x1 + slicex;
                  y2 = y1 + slicey;
                  x3 = (int)(0.5 * (x1 + x5) + sqrt(3) * (y1 - y5) / 6);
                  y3 = (int)(0.5 * (y1 + y5) + sqrt(3) * (x5 - x1) / 6);
                  x4 = 2 * slicex + x1;
                  y4 = 2 * slicey + y1;
                  koch(it - 1, x1, y1, x2, y2);
                  koch(it - 1, x2, y2, x3, y3);
                  koch(it - 1, x3, y3, x4, y4);
                  koch(it - 1, x4, y4, x5, y5);
            }
      }
};
int main()
{
      kochCurve k;
      int it;
      cout << "Enter Number Of Iterations : " << endl;
      cin >> it;
      int gd = DETECT, gm;
      initgraph(&gd, &gm, NULL);
      k.koch(it, 150, 20, 20, 280);
      k.koch(it, 280, 280, 150, 20);
      k.koch(it, 20, 280, 280, 280);
      getch();
      closegraph();
      return 0;
}





 
