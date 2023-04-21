#include"esfera.h"
#include"plano.h"
#include"toro.h"
#pragma once

class Mundo
{
public:
		float x_ojo;
		float y_ojo;
		float z_ojo;
		
		void rotarOjo();
		void inicializa();
		void dibuja();
		void mueve();
		void tecla(unsigned char key);

		Esfera sphere, sphere2, sphere3;
		Poligono polygon, polygon2;
		Toro torus;
};
