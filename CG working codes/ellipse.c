#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0, 0, 0.3);
glPointSize(5.0);
glBegin(GL_POINTS);
int a = 80, b = 50, sa, sb, x = 0, y = b;
double d1, d2;
sa = a * a;
sb = b * b;
d1 = sb + sa * (0.25 - b);
while(sa * (y - 0.5) > sb * (x + 1))
{
if(d1 < 0)
{
d1 = d1 + sb * (2 * x + 3);
}
else
{
d1 = d1 + sb * (2 * x + 3) - sa * (2 * y - 2);
y--;
}
x++;
glVertex2i(x, y);
glVertex2i(x, -y);
glVertex2i(-x, y);
glVertex2i(-x, -y);
}
d2 = sb * (x + 0.5) * (x + 0.5) + sa * (y - 1) * (y - 1) - sa * sb;
while(y > 0)
{
if(d2 < 0)
{
d2 = d2 + 2 * sb * (x + 1) - sa * (2 * y - 3);
x++;
}
else
{
d2 = d2 - sa * (2 * y - 3);
}
y--;
glVertex2i(x, y);
glVertex2i(x, -y);
glVertex2i(-x, y);
glVertex2i(-x, -y);
}
glEnd();
glFlush();
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(1000, 1000);
glutInitWindowPosition(300, 300);
glutCreateWindow("Bresenham's Ellipse Drawing Algorithm");
glClearColor(1, 1, 1, 0);
gluOrtho2D(-100, 100, -100, 100);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
