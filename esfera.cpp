#include "freeglut.h"
#include "esfera.h"

void Esfera::setColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
}

void Esfera::setRadio(float r)
{
	if (r < 0.1f) r = 0.1f;
	radio = r;
}

void Esfera::setPos(float ix, float iy)
{
	x = ix;
	y = iy;
}

void Esfera::dibuja()
{
	glColor3ub(rojo, verde, azul);
	glTranslatef(x, y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-x, -y, 0);
}

void Esfera::mueve()
{
	radio += 0.1f;
	if (radio > 3)
		radio = 0.5f;

}

float Esfera::getRadio()
{
	return radio;
}

float Esfera::getX() {
	return x;
}

float Esfera::getY() {
	return y;
}