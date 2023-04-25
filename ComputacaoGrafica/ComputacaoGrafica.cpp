#include <iostream>
#include <fstream>
#include <vector>
#include <GL/freeglut.h>
#include <string>
#include "Obj.h"
#include "Material.h"

using namespace std;

Obj obj;
bool lightAmb = true;
bool lightDif = true;
bool lightSpe = true;

bool light1 = true;
bool light2 = true;
bool light3 = true;

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)w / (GLfloat)h, 0.1, 1000.0);
	glMatrixMode(GL_MODELVIEW);
}

void drawObj()
{
	glPushMatrix();

	Material bronze(0.2125f, 0.1275f, 0.054f, 0.714f, 0.4284f, 0.18144f, 0.393548f, 0.271906f, 0.166721f, 0.2f);
	bronze.ativar();

	glTranslatef(obj.pos[0], obj.pos[1], obj.pos[2]);

	glScalef(obj.scale, obj.scale, obj.scale);
	glRotatef(obj.rotation[0], 1, 0, 0);
	glRotatef(obj.rotation[1], 0, 1, 0);
	glRotatef(obj.rotation[2], 0, 0, 1);

	GLfloat pos1[] = { 0.f, 0.f, 1.f, 1.f };
	GLfloat pos2[] = { 0.f, 0.f, 1.f, 0.f };
	GLfloat pos3[] = { 0.5f, 0.5f, 0.f, 0.f };
	glLightfv(GL_LIGHT0, GL_POSITION, pos1);
	glLightfv(GL_LIGHT1, GL_POSITION, pos2);
	glLightfv(GL_LIGHT2, GL_POSITION, pos3);

	glCallList(obj.idGlList);
	glPopMatrix();
}

void keyboard(unsigned char key, int x, int y) {
	GLfloat a[4];
	GLfloat d[4];
	GLfloat s[4];

	std::cout << key;
	switch (key) {
	case 27:
		exit(0);
		break;
	case 'i':
		obj.walkUp();
		break;
	case 'k':
		obj.walkDown();
		break;
	case 'l':
		obj.walkRight();
		break;
	case 'j':
		obj.walkLeft();
		break;
	case 'o':
		obj.walkFront();
		break;
	case 'u':
		obj.walkBack();
		break;
	case 'q':
		obj.rotateX(-1.5);
		break;
	case 'w':
		obj.rotateX(1.5);
		break;
	case 's':
		obj.rotateY(1.5);
		break;
	case 'a':
		obj.rotateY(-1.5);
		break;
	case 'x':
		obj.rotateZ(1.5);
		break;
	case 'z':
		obj.rotateZ(-1.5);
		break;
	case ',':
		obj.scaleDown();
		break;
	case '.':
		obj.scaleUp();
		break;
	case '1':
		light1 = !light1;

		if (light1) {
			a[0] = 0.1f;
			a[1] = 0.1f;
			a[2] = 0.1f;
			a[3] = 1.0f;
			d[0] = 0.8f;
			d[1] = 0.8f;
			d[2] = 0.8f;
			d[3] = 1.0f;
			s[0] = 1.0f;
			s[1] = 1.0f;
			s[2] = 1.0f;
			s[3] = 1.0f;
		}
		else {
			a[0] = 0.0f;
			a[1] = 0.0f;
			a[2] = 0.0f;
			a[3] = 1.0f;
			d[0] = 0.0f;
			d[1] = 0.0f;
			d[2] = 0.0f;
			d[3] = 1.0f;
			s[0] = 0.0f;
			s[1] = 0.0f;
			s[2] = 0.0f;
			s[3] = 1.0f;
		}

		glLightfv(GL_LIGHT0, GL_AMBIENT, a);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
		glLightfv(GL_LIGHT0, GL_SPECULAR, s);

		break;
	case '2':
		light2 = !light2;

		if (light2) {
			a[0] = 0.1f;
			a[1] = 0.1f;
			a[2] = 0.1f;
			a[3] = 1.0f;
			d[0] = 0.8f;
			d[1] = 0.8f;
			d[2] = 0.8f;
			d[3] = 1.0f;
			s[0] = 1.0f;
			s[1] = 1.0f;
			s[2] = 1.0f;
			s[3] = 1.0f;
		}
		else {
			a[0] = 0.0f;
			a[1] = 0.0f;
			a[2] = 0.0f;
			a[3] = 1.0f;
			d[0] = 0.0f;
			d[1] = 0.0f;
			d[2] = 0.0f;
			d[3] = 1.0f;
			s[0] = 0.0f;
			s[1] = 0.0f;
			s[2] = 0.0f;
			s[3] = 1.0f;
		}

		glLightfv(GL_LIGHT1, GL_AMBIENT, a);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, d);
		glLightfv(GL_LIGHT1, GL_SPECULAR, s);

		break;
	case '3':
		light3 = !light3;

		if (light3) {
			a[0] = 0.1f;
			a[1] = 0.1f;
			a[2] = 0.1f;
			a[3] = 1.0f;
			d[0] = 0.8f;
			d[1] = 0.8f;
			d[2] = 0.8f;
			d[3] = 1.0f;
			s[0] = 1.0f;
			s[1] = 1.0f;
			s[2] = 1.0f;
			s[3] = 1.0f;
		}
		else {
			a[0] = 0.0f;
			a[1] = 0.0f;
			a[2] = 0.0f;
			a[3] = 1.0f;
			d[0] = 0.0f;
			d[1] = 0.0f;
			d[2] = 0.0f;
			d[3] = 1.0f;
			s[0] = 0.0f;
			s[1] = 0.0f;
			s[2] = 0.0f;
			s[3] = 1.0f;
		}

		glLightfv(GL_LIGHT2, GL_AMBIENT, a);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, d);
		glLightfv(GL_LIGHT2, GL_SPECULAR, s);

		break;
	}
}

void display(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	drawObj();
	glutSwapBuffers();
}

void timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(10, timer, 0);
}

void initialize(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 800);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("T2 - Matheus e Carlos");
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);

	float globalAmb[] = { 0.1f, 0.1f ,0.1f, 1.f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmb);

	GLfloat amb[] = { 0.1f, 0.1f, 0.1f, 1.f };
	GLfloat dif[] = { 0.8f, 0.8f, 0.8f, 1.f };
	GLfloat spe[] = { 1.f, 1.f, 1.f, 1.f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, spe);
	glLightfv(GL_LIGHT2, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, dif);
	glLightfv(GL_LIGHT2, GL_SPECULAR, spe);
	glLightfv(GL_LIGHT1, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, dif);
	glLightfv(GL_LIGHT1, GL_SPECULAR, spe);

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(10, timer, 0);
}

int main(int argc, char** argv)
{
	initialize(argc, argv);
	obj = Obj();
	obj.loadObjFile("mba1.obj");
	glutMainLoop();
	return 0;
}