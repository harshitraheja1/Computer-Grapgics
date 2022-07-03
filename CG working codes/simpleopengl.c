#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/glext.h>
void init()
{
  glClearColor(1.0,1.0,1.0,0.0); // Set display-window color to white.
  glMatrixMode(GL_PROJECTION);   // Set projection parameters.
  gluOrtho2D(0.0,200.0,0.0,150.0); // set the dimension of coordinate system
}
void display()
{
  glClear(GL_COLOR_BUFFER_BIT); // Clear display window.
  glColor3f(1.0,0.0,0.0);  // set the color of object color
  glBegin(GL_LINES);
  glVertex2i(180.0,15.0);	// Specify line-segment geometry.
  glVertex2i(10.0,145.0);
  glEnd();
  glFlush();	// Process all OpenGL routines as quickly as possible.
}
int main(int argc,char **argv)
{
  glutInit(&argc,argv);	 // Initialize GLUT
  glutInitWindowPosition(200,100);	// Set display mode
  glutInitWindowSize(600,600);	// Set top-left display-window position.
  glutCreateWindow("Line-Program");	// Set display-window width and height.
  init();
  glutDisplayFunc(display); 	// Send graphics to display window.
  glutMainLoop(); // Display everything and wait
}
