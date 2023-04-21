#pragma once

class Poligono
{
private:
	float x;
	float y;
	unsigned char rojo=255;
	unsigned char verde=255;
	unsigned char azul=255;

public:
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void setPos(float ix, float iy);
	void dibuja();
	
};
