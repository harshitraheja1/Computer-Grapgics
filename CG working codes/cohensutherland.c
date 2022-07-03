#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
int x[2], y[2], xclip[2], yclip[2];
int xmin = -50, xmax = 50, ymin = -50, ymax = 50;
void clippedLine(float, float);
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
int code[2][4];
for(int i = 0; i < 4; i++)
{
for(int j = 0; j < 2; j++)
{
if(x[j] >= xmin)
code[j][i] = 1;
else
code[j][i] = 0;
if(x[j] <= xmax)
code[j][i] = 1;
else
code[j][i] = 0;
if(y[j] <= ymin)
code[j][i] = 1;
else
code[j][i] = 0;
if(y[j] >= ymax)
code[j][i] = 1;
else
code[j][i] = 0;
}
}
int decVar = 0;
for(int i = 0; i < 4; i++)
{
if((code[0][i] == code[1][i]) && (code[0][i] == 1))
{
decVar = 1;
break;
}
}
glColor3f(1, 0, 1);
glBegin(GL_LINE_LOOP);
glVertex2f(xmin, ymin);
glVertex2f(xmin, ymax);
glVertex2f(xmax, ymax);
glVertex2f(xmax, ymin);
glEnd();
if(decVar == 0)
{
int X, Y, counter = 0;
float m, c;
m = (float) (y[1] - y[0]) / (x[1] - x[0]);
c = (float) y[0] - (m * x[0]);
for(X = x[0]; X < x[1]; X++)
{
Y = round(m * X + c);
glPointSize(3.0);
glColor3f(1, 0, 0);
glBegin(GL_POINTS);
glVertex2i(X, Y);
glEnd();
if(X >= xmin && X <= xmax && Y >= ymin && Y <= ymax)
{
if(X == xmin || X == xmax || Y == ymin || Y == ymax)
{
if (counter == 0)
{
counter = 1;
xclip[0] = X;
yclip[0] = Y;
}
else if(counter == 1)
{
counter = 2;
xclip[1] = X;
yclip[1] = Y;
}
else
{
}
}
glColor3f(0, 1, 0);
glBegin(GL_POINTS);
glVertex2i(X, Y);
glEnd();
}
}
}
glFlush();
}
void ClippedLine(float m, float c)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1, 0, 1);
glBegin(GL_LINE_LOOP);
glVertex2f(xmin, ymin);
glVertex2f(xmin, ymax);
glVertex2f(xmax, ymax);
glVertex2f(xmax, ymin);
glEnd();
int X, Y;
for(X = xclip[0]; X < xclip[1]; X++)
{
Y = round(m * X + c);
glColor3f(1, 0, 0);
glLineWidth(5.0);
glBegin(GL_POINTS);
glVertex2i(X, Y);
glEnd();
}
glFlush();
}
int main(int argc, char** argv)
{
printf("Enter Co-ordinates of first point of line: ");
scanf("%d%d", &x[0], &y[0]);
printf("Enter Co-ordinates of second point of line: ");
scanf("%d%d", &x[1], &y[1]);
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500, 500);
glutInitWindowPosition(300, 300);
glutCreateWindow("Cohen Surtherland Line Clipping");
glClearColor(1, 1, 1, 0);
gluOrtho2D(-100, 100, -100, 100);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
