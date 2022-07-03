#include <graphics.h>
#include <stdio.h>
 
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	circle(200,200,100);
	getch();
	closegraph();
} 
