#include"freeglut.h"
#include"toro.h"

void Toro::setColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
};

void Toro::setPos(float ix, float iy)
{
	x = ix;
	y = iy;
}

void Toro::setRadio(float r_in, float r_out)
{
	innerRadius = r_in;
	outerRadius = r_out;
}

void Toro::dibuja()
{
	glTranslatef(x, y, 0);
	glColor3ub(rojo, verde, azul);
	glutSolidTorus(innerRadius, outerRadius, 20, 20);
	glTranslatef(-x, -y, 0);
}