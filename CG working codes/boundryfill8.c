#include<stdio.h>
#include<graphics.h>
void boundary_fill_8(int x,int y,int fillcolor,int boundarycolor)
{
if(getpixel(x,y)!=boundarycolor && getpixel(x,y)!=fillcolor)
{
putpixel(x,y,fillcolor);
boundary_fill_8(x+1,y,fillcolor,boundarycolor);
boundary_fill_8(x,y+1,fillcolor,boundarycolor);
boundary_fill_8(x-1,y,fillcolor,boundarycolor);
boundary_fill_8(x,y-1,fillcolor,boundarycolor);
boundary_fill_8(x+1,y+1,fillcolor,boundarycolor);
boundary_fill_8(x-1,y+1,fillcolor,boundarycolor);
boundary_fill_8(x+1,y-1,fillcolor,boundarycolor);
boundary_fill_8(x-1,y-1,fillcolor,boundarycolor);
}
}
int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"");
rectangle(100,200,300,350);
boundary_fill_8(200,250,5,15); // 5 is MAGENTA and 15 is white
getch();
closegraph();
}
