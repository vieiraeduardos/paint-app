/*
    Eduardo S. Vieira
*/

#include "pch.h"
#include <iostream>
#include <gl/freeglut.h>

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho (0, 256, 0, 256, -1 ,1);
	/*glutCreateMenu(0);
	glutAddMenuEntry("a) quadrado", 0);
	glutAddMenuEntry("b) cubo", 1);
	glutAddMenuEntry("c) casa", 2);
	glutAddMenuEntry("d) estrela", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);*/
}

void estrela(void) {

	glBegin(GL_LINE_LOOP);
	glVertex2i(50, 100);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2i(60, 70);
	glVertex2i(90, 70);
	glVertex2i(70, 50);
	glVertex2i(80, 20);
	glVertex2i(50, 40);
	glVertex2i(20, 20);
	glVertex2i(30, 50);
	glVertex2i(10, 70);
	glVertex2i(40, 70);
	glVertex2i(50, 100);
	glEnd();
	glFlush();
}

void casa(void) {
	glBegin(GL_QUADS); //parte maior
	glVertex2i(50, 100);
	glVertex2i(50, 50);
	glColor3f(0.3f, 0.0f, 0.1f);
	glVertex2i(100, 50);
	glVertex2i(100, 100);
	glEnd();

	glBegin(GL_QUADS); //porta
	glVertex2i(60, 70);
	glVertex2i(60, 50);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2i(80, 50);
	glVertex2i(80, 70);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(50, 100);

	glColor3f(0.9f, 0.7f, 0.8f);
	glVertex2i(75, 125);
	glVertex2i(100, 100);
	glEnd();


	glFlush();
}

void cubo(void) {

	glBegin(GL_QUADS); //costa
	glVertex2i(75, 125);
	glVertex2i(75, 75);
	glColor3f(0.5f, 0.0f, 0.5f);
	glVertex2i(125, 75);
	glVertex2i(125, 125);
	glColor3f(1.0f, 0.0f, 0.5f);
	glEnd();

	glBegin(GL_QUADS); //frente
	glVertex2i(50, 100);
	glVertex2i(50, 50);
	glColor3f(0.5f, 0.0f, 0.5f);
	glVertex2i(100, 50);
	glVertex2i(100, 100);
	glEnd();

	glBegin(GL_POLYGON); //cima
	glColor3f(0.6f, 0.0f, 0.3f);
	glVertex2i(75, 125);
	glVertex2i(50, 100);
	glVertex2i(100, 100);
	glVertex2i(125, 125);
	glEnd();

	glBegin(GL_POLYGON); //direita
	glVertex2i(100, 100);
	glVertex2i(100, 50);
	glColor3f(0.5f, 0.0f, 0.5f);
	glVertex2i(125, 75);
	glVertex2i(125, 125);
	glEnd();

	glFlush();
}

void quadrado(void) {

	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.2f, 0.1f);
	glVertex2i(50, 100);
	glVertex2i(50, 50);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2i(100, 50);
	glVertex2i(100, 100);
	glEnd();

	glFlush();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {

	case('a'):
		glutDisplayFunc(quadrado);
		break;

	case ('b'):
		glutDisplayFunc(cubo);
		break;

	case ('c'):
		glutDisplayFunc(casa);
		break;

	case ('d'):
		glutDisplayFunc(estrela);
		break;

	case 27:
		exit(0);
		break;
	}

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(256, 256);
	glutCreateWindow("Primeira Questão");
	glutKeyboardFunc(keyboard);
	init();

	
	
	glutMainLoop();

	return 0;
}
