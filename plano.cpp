#include"freeglut.h"
#include"plano.h"

void Poligono::setColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
}

void Poligono::setPos(float ix, float iy)
{
	x = ix;
	y = iy;
}

void Poligono::dibuja()
{
	glDisable(GL_LIGHTING);
	glTranslatef(x, y, 0);
	glBegin(GL_POLYGON);
	glColor3ub(rojo, verde, azul);
	glVertex3f(-5.0f, 0.0f, -5.0f);
	glVertex3f(-5.0f, 0.0f, 5.0f);
	glColor3ub(rojo, verde+255, azul);
	glVertex3f(5.0f, 0.0f, 5.0f);
	glVertex3f(5.0f, 0.0f, -5.0f);
	glEnd();
	glEnable(GL_LIGHTING);
	glTranslatef(-x, -y, 0);
}
