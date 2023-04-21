#pragma once

class Toro
{
private:
	float x;
	float y;
	float innerRadius;
	float outerRadius;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

public:
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void setPos(float ix, float iy);
	void setRadio(float r_in, float r_out);
	void dibuja();
};