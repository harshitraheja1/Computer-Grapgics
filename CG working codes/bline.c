#include<stdio.h>
#include<graphics.h>
 int x0,t0,x1,t1;
void drawline()
{
    int dx, dy, p, x, y;
 
dx=x1-x0;
dy=t1-t0;
 
x=x0;
y=t0;
 
p=2*dy-dx;
 
while(x<x1)
{
if(p>=0)
{
putpixel(x,y,7);
y=y+1;
p=p+2*dy-2*dx;
}
else
{
putpixel(x,y,7);
p=p+2*dy;
}
x=x+1;
}
}
 
int main()
{
printf("Enter co-ordinates of first point: ");
scanf("%d%d", &x0,&t0);
printf("Enter co-ordinates of second point: ");
scanf("%d%d", &x1,&t1);
int gdriver=DETECT, gmode;
initgraph(&gdriver, &gmode, "NULL");
drawline();
return 0;
}
