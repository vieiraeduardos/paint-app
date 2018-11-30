/*
    Eduardo S. Vieira
*/

//#include <GL/gl.h>
//#include <GL/glu.h>
#include <GL/glut.h>
#include "pch.h"
#include <GL/freeglut.h>
static int ano = 0, dia = 0;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.85, 0.85, 0.09);


	glPushMatrix();
	glutWireSphere(1.0, 20, 16);   /* draw sun */
	
	glColor3f(0.2, 0.8, 0.6);
	glRotatef((GLfloat)ano, 0.0, 1.0, 0.0);
	glTranslatef(2.0, 0.0, 0.0);
	glRotatef((GLfloat)dia, 0.0, 1.0, 0.0);
	glutWireSphere(0.2, 10, 8);    /* draw earth */

	glColor3f(0.2, 0.6, 0.8);
	glRotatef((GLfloat)ano, 0.0, 0.5, 0.0);
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat)dia*0.4, 0.0, 2.0, 0.0);
	glutWireSphere(0.1, 5, 4);    /* draw satellite */

	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'd':
		dia = (dia + 10) % 360;
		glutPostRedisplay();
		break;
	case 'D':
		dia = (dia - 10) % 360;
		glutPostRedisplay();
		break;
	case 'a':
		ano = (ano + 5) % 360;
		glutPostRedisplay();
		break;
	case 'A':
		ano = (ano - 5) % 360;
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
