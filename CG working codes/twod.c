#include<stdio.h>
#include<GL/glut.h>
#include<GL/freeglut.h>
#include<math.h>
#define MAX 10
int choice, choice1, choice2;
int vertices, x[MAX], y[MAX];
int i, xaux[MAX], yaux[MAX];
int line_x[2], c;
float slope;
void init()
{
glClearColor(0.101, 1.0, 0.980, 1.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-500, 500, -500, 500);
}
void display()
{
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(1000, 750);
glutCreateWindow("2D Transformations");
init();
glClear(GL_COLOR_BUFFER_BIT);
if(choice == 4)
{
glBegin(GL_LINES);
glColor3f(1, 1, 1);
glVertex2f(0, 500);
glVertex2f(0, -500);
glVertex2f(-500, 0);
glVertex2f(500, 0);
glEnd();
}
if(choice1 == 3 || choice == 4)
{
glBegin(GL_LINES);
glColor3f(1, 1, 1);
glVertex2f(500, 500);
glVertex2f(-500, -500);
glVertex2f(-500, 500);
glVertex2f(500, -500);
glEnd();
}
if(choice1 == 6)
{
glBegin(GL_LINES);
glColor3f(1, 1, 1);
glVertex2f(line_x[0], ((slope * line_x[0]) + c));
glVertex2f(line_x[1], ((slope * line_x[1]) + c));
glEnd();
}
glLineWidth(5.0);
glBegin(GL_LINE_LOOP);
glColor3f(0, 0, 0);
for(i = 0; i < vertices; i++)
glVertex2f(x[i], y[i]);
glEnd();
glLineWidth(5.0);
glBegin(GL_LINE_LOOP);
glColor3f(1, 0, 0);
for(i = 0; i < vertices; i++)
glVertex2f(xaux[i], yaux[i]);
glEnd();
glFlush();
glutMainLoop();
}
void translation()
{
printf("\n\nTRANSLATION\n");
int dx, dy;
printf("Enter translation factor(dx dy): ");
scanf("%d%d", &dx, &dy);
for(i = 0; i < vertices; i++)
{
xaux[i] = xaux[i] + dx;
yaux[i] = yaux[i] + dy;
}
display();
}
void rotation()
{
printf("\n\nROTATION\n");
int x_pivot, y_pivot, angle, x_shifted, y_shifted;
printf("Enter pivot point: ");
scanf("%d%d", &x_pivot, &y_pivot);
printf("Enter angle of rotation (in degrees): ");
scanf("%d", &angle);
for(i = 0; i < vertices; i++)
{
x_shifted = xaux[i] - x_pivot;
y_shifted = yaux[i] - y_pivot;
xaux[i] = x_pivot + (x_shifted * cos(angle * 3.14/180) - y_shifted * sin(angle * 3.14/180));
yaux[i] = y_pivot + (x_shifted * sin(angle * 3.14/180) - y_shifted * cos(angle * 3.14/180));
}
display();
}
void scaling()
{
printf("\n\nSCALING\n");
int x_scale, y_scale;
printf("Enter the scaling factor: ");
scanf("%d%d", &x_scale, &y_scale);
for(i = 0; i < vertices; i++)
{
xaux[i] *= x_scale;
yaux[i] *= y_scale;
}
display();
}
int main(int argc, char** argv)
{
glutInit(&argc, argv);
printf("Before transformation color (Black)\n");
printf("After transformation color (Red)\n");
printf("Range of x and y is -500 to 500\n\n");
printf("Enter the number of vertices of polygon: ");
scanf("%d", &vertices);
printf("Enter the co-ordinates in clockwise / anti-clockwise order:\n");
for(i = 0; i < vertices; i++)
{
printf("Vertex - %d: ", i+1);
scanf("%d%d", &x[i], &y[i]);
xaux[i] = x[i];
yaux[i] = y[i];
}
printf("\n\n2D TRANSFORMATION\n\n");
printf("1. Translation \n2. Rotation \n3. Scaling \nEnter your choice: ");
scanf("%d", &choice);
switch(choice)
{
case 1:
translation();
break;
case 2:
rotation();
break;
case 3:
scaling();
break;
default:
translation("Wrong Input\n");
break;
}
return 0;
}
