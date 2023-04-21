#include"mundo.h"
#include"esfera.h"
#include<math.h>
#include"plano.h"
#include"toro.h"

void Mundo::rotarOjo()
{
	float dist = sqrt(x_ojo * x_ojo + z_ojo * z_ojo);
	float theta = atan2(z_ojo, x_ojo);
	theta += 0.05;
	x_ojo = dist * cos(theta);
	z_ojo = dist * sin(theta);
}

void Mundo::inicializa() //Se encarga de dar valores iniciales 
{
	x_ojo = 0.0;
	y_ojo = 10.0;
	z_ojo = 20.0;

	sphere.setColor(200, 0, 0);
	sphere.setRadio(1);
	sphere.setPos(2, 0);

	sphere2.setColor(0, 200, 0);
	sphere2.setRadio(2);
	sphere2.setPos(3, 0);

	polygon.setColor(255, 0, 0);
	polygon.setPos(0, 0);
	//polygon2.setColor(255, 255, 255);
	//polygon2.setPos(0, 2);
	torus.setColor(0, 255, 0);
	torus.setRadio(1, 5);
	torus.setPos(0, 0);

}

void Mundo::dibuja()
{
	sphere.dibuja();
	sphere2.dibuja();
	polygon.dibuja();
	//polygon2.dibuja();
	torus.dibuja();
}

void Mundo::mueve()
{
	sphere2.mueve(); sphere3.mueve();
}

void Mundo::tecla(unsigned char key)
{
	if (key == 'r') sphere.setColor(255, 0, 0);
	if (key == 'g') sphere.setColor(0, 255, 0);
	if (key == 'b') sphere.setColor(0, 0, 255);

	if (key == 'a') sphere.setPos(sphere.getX()-0.1f, sphere.getY());
	if (key == 'd') sphere.setPos(sphere.getX()+0.1f, sphere.getY());
	if (key == 's') sphere.setPos(sphere.getX(), sphere.getY() - 0.1f);
	if (key == 'w') sphere.setPos(sphere.getX(), sphere.getY() + 0.1f);

	if (key == '+' && sphere.getRadio() < 3)
		sphere.setRadio(sphere.getRadio() + 0.5);
	if (key == '-' && sphere.getRadio() > 1)
		sphere.setRadio(sphere.getRadio() - 0.5);

}

