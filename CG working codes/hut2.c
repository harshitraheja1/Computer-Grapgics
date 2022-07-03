#include <GL/glut.h> //It is a library of utilities for OpenGL programs
int x,y;
void init(void)
{
 glClearColor(1.0,1.0,1.0,0.0);
 glMatrixMode(GL_PROJECTION); //glMatrixMode sets the current matrix mode
 gluOrtho2D(0,600,0,550);
}
void house(void)
{
 glClear(GL_COLOR_BUFFER_BIT); //It clears the OpenGl color and depth buffers
 glPointSize(4.0);
glBegin(GL_QUADS);
	glColor3f(0.0,1.0,0.0); //glColor3f is used to give each vertex its own colour
	glVertex2i(150,20); //glVertex2i is used to specify point, line and polygon vertices
	glVertex2i(450,20);
	glVertex2i(450,250);
	glVertex2i(150,250);
glEnd();
glBegin(GL_QUADS);
	glColor3f(0.6,0.75,0.8); //glColor3f is used to give each vertex its own colour
	glVertex2i(80,250); //glVertex2i is used to specify point, line and polygon vertices
	glVertex2i(520,250);
	glVertex2i(430,380);
	glVertex2i(170,380);
glEnd();
glBegin(GL_QUADS);
	glColor3f(0.9,0,0.9); //glColor3f is used to give each vertex its own colour
	glVertex2i(200,20); //glVertex2i is used to specify point, line and polygon vertices
	glVertex2i(270,20);
	glVertex2i(270,165);	
	glVertex2i(200,165);
glEnd();
glBegin(GL_QUADS);
	glColor3f(0.6,0.5,0.8); //glColor3f is used to give each vertex its own colour
	glVertex2i(330,130); //glVertex2i is used to specify point, line and polygon vertices
	glVertex2i(400,130);
	glVertex2i(400,200);	
	glVertex2i(330,200);
glEnd();
glBegin(GL_LINES);
	glColor3f(1,2,3); //glColor3f is used to give each vertex its own colour
	glVertex2i(365,130); //glVertex2i is used to specify point, line and polygon vertices
	glVertex2i(365,200);
glEnd();
glBegin(GL_LINES);
	glColor3f(0,0,0); //glColor3f is used to give each vertex its own colour
	glVertex2i(330,165); //glVertex2i is used to specify point, line and polygon vertices
	glVertex2i(400,165);
glEnd();
glBegin(GL_QUADS);
	glColor3f(0.3,0.3,0.3); //glColor3f is used to give each vertex its own colour
	glVertex2i(380,380); //glVertex2i is used to specify point, line and polygon vertices
	glVertex2i(400,380);
	glVertex2i(400,400);
	glVertex2i(380,400);
glEnd();
glColor3f(0,1,0); //glColor3f is used to give each vertex its own colour
glBegin(GL_POLYGON);
glVertex2i(110,20); //glVertex2i is used to specify point, line and polygon vertices
glVertex2i(110,10);
glVertex2i(120,10);
glVertex2i(120,20);
glEnd();
 glFlush(); 
}
void mouse(int button, int state, int mousex, int mousey)
{
x=mousex-0;
y=550-mousey;
if(button==GLUT_LEFT_BUTTON && button==GLUT_DOWN)
{
if(mousex>110 && mousex<120 && mousey>10 && mousey<20)
{
glColor3f(0,1,0);
}
if(mousex> 130 && mousex<140 && mousey>10 && mousey<20)
{
glColor3f(1,1,1);
}
if (mousex>150 && mousex<160 && mousey>10 && mousey<20)
{
glColor3f(1,0,1);
}
glBegin(GL_POLYGON);
glVertex2i(380,380);
	glVertex2i(400,380); //glVertex2i is used to specify point, line and polygon vertices
	glVertex2i(400,400);
	glVertex2i(380,400);
glEnd();
glFlush(); //glFlush function empties all these buffers, causing all issued commands to be executed as quickly as they are accepted by the actual rendering engine
}
}
int main(int argc, char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(50,100); //Location of window in screen Coordinates
 glutInitWindowSize(400,300); //Size of display area, in pixels
 glutCreateWindow("House Design"); //Parameter is window title
 init();
 glutDisplayFunc(house); //glutDisplayFunc sets the display callback for the current window
glutMouseFunc(mouse); //glutMouseFunc sets the mouse callback for the current window
 glutMainLoop(); //Run the event Loop! This function does not return;
 return 0;
}
