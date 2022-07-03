#include <graphics.h>
#include <stdio.h>

int main()
{
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "C:\\TC\\BGI");
   int left = 150, top = 250;
   int right = 450, bottom = 350;
   int x = 250, y = 200;
   int start_angle = 0;
   int end_angle = 360;
   int x_rad = 100;
   int y_rad = 50;
   int ch;
   int run = 1;
   while(run==1){
        printf("Enter your choice:\n1. Line\n2. Ellipse\n3. Circle\n4. Triangle\n5. Rectangle\n6. Square\n7. Arc\n8. Incircle\n");
        scanf("%d", &ch);
        cleardevice();
        switch(ch) {
            case 1:  {
                line(100, 100, 200, 200);
                break;
                }
            case 2: {
                ellipse(x, y, start_angle, end_angle, x_rad, y_rad);
                break;
                }
            case 3: {
                circle(250, 200, 50);
                break;
                }
            case 4: {
                line(300, 100, 200, 200);
                line(300, 100, 400, 200);
                line(200, 200, 400, 200);
                break;
                }
            case 5: {
                rectangle(left, top, right, bottom);
                break;
                }
            case 6: {
                rectangle(200, 200, 400, 400);
                break;
                }
            case 7: {
                ellipse(x, y, 0, 120, 80, 80);
                break;
            }
            case 8: {
                circle(300, 150, 50);
                line(300, 70, 200, 200);
                line(300, 70, 400, 200);
                line(200, 200, 400, 200);
                break;
            }
        }
        printf("Again?\n1. Yes\n2. No\n");
        scanf("%d", &run);
    }
    closegraph();
    return 0;
}
