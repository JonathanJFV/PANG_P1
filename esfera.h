#pragma once
#include"freeglut.h"

class Esfera
{
private:
	float radio;
	float x;
	float y;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

	//tras los atributos, escribimos nuestros métodos
public:
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void setRadio(float r);
	void setPos(float ix, float iy);
	void dibuja();
	void mueve();
	float getRadio(); 
	float getX();
	float getY();
};