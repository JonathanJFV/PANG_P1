#include "freeglut.h"
#include "math.h"
#include "mundo.h"
#include "esfera.h"
#include"toro.h"

Mundo world;
/*
class Poligono
{
public:
	float x;
	float y;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
};
Poligono plano = {0, 0, 255, 255, 255};
*/
/*
struct Torous
{
	float innerRadius;
	float outerRadius;
	float sides;
	float rings;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
};
Torous toro = {1, 5.5, 20, 20, 0, 255, 0};
*/


//declaracion de funciones

//void Dibuja(Poligono p);
//void Dibuja(Torous t);




//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	

int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	//inicialización de los datos de la simulación
		//equivale a esfera.rojo=200; esfera.verde=0....
	
	/*
		esfera.setColor(200, 0, 0);
	esfera.setRadio(1);
	esfera.setPos(2, 0);
	esfera2.setColor(0, 200, 0);
	esfera2.setRadio(2);
	esfera2.setPos(3, 0);
	*/

	world.inicializa();

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	
	return 0;   
}


/*
void Dibuja(Poligono p)
{
	glDisable(GL_LIGHTING);
	glTranslatef(0, 0, 0);
	glBegin(GL_POLYGON);
	glColor3ub(p.rojo, p.verde=0, p.azul=0);
	glVertex3f(-5.0f,0.0f, -5.0f);
	glVertex3f(-5.0f, 0.0f, 5.0f);
	glColor3ub(p.rojo, p.verde = 255, p.azul = 0);
	glVertex3f(5.0f, 0.0f, 5.0f);
	glVertex3f(5.0f, 0.0f, -5.0f);
	glEnd();
	glEnable(GL_LIGHTING);
}
*/
/*
void Dibuja(Torous t)
{
	glColor3ub(t.rojo, t.verde, t.azul);
	glutSolidTorus(t.innerRadius, t.outerRadius, t.sides, t.rings);
}

*/



void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	

	gluLookAt(world.x_ojo, world.y_ojo, world.z_ojo,      // posicion del ojo
		      0.0, 0, 0.0,      // hacia que punto mira  (0,0,0)
		      0.0, 1.0, 0.0);   // definimos hacia arriba (eje Y)


	//aqui es donde hay que poner el código de dibujo
	//llamadas a los métodos de Esfera
	 
	
	//esfera.dibuja();
	//esfera2.dibuja();

	//Dibuja(plano);
	//Dibuja(toro);
/*
	glColor3ub(255, 255, 0);
	glutWireCube(8);
	glColor3ub(255, 0, 255);
	glutSolidSphere(1, 50, 50);
	//glutWireSphere(5, 50, 50);
	//glutSolidCube(5);
	//glutWireCone(2, 3, 10, 10);
	//glutSolidCone(2, 3, 10, 10);
	//glutSolidTorus(2, 4, 20, 20);
	glColor3ub(0, 255, 255);
	glutWireTorus(2, 3, 20, 20);
	//glutSolidDodecahedron();

	glTranslatef(10, 0, 0);
	//glutWireDodecahedron();
	glutWireTeapot(3);
	glTranslatef(-20, 0, 0);
	glutSolidTeapot(3);
	glTranslatef(10, 7, 0);
	glutSolidTetrahedron();
	//glutWireTetrahedron();
	//glutSolidIcosahedron();
	//glutWireIcosahedron();

	glTranslatef(0, -7, 0); // de vuelta al centro
*/


	/*
	glDisable(GL_LIGHTING); //Desactivar iluminacion
	glColor3ub(255,255,255); //color blanco
	glBegin(GL_POLYGON);
		glColor3ub(255, 0, 0);
		glVertex3f(-5.0f, -5.0f, 0.0f);
		glColor3ub(255, 255, 0);
		glVertex3f(-5.0f, 5.0f, 0.0f);
		glColor3ub(255, 255, 255);
		glVertex3f(5.0f, 5.0f, 0.0f);
		glColor3ub(0, 255, 255);
		glVertex3f(5.0f, -5.0f, 0.0f);
	glEnd();
	glEnable(GL_LIGHTING);
	*/


	/*
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 255);
		glVertex3f(10, 10, 0);
		glVertex3f(10, 5, 0);
		glColor3ub(255, 0, 0);
		glVertex3f(20, 5, 0);
		glVertex3f(20, 10, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex3f(-5, 0, 0);
		glVertex3f(0, 7, 0);
		glVertex3f(5, 0, 0);
	glEnd();

	glBegin(GL_LINES);
		glVertex3f(0, -10, 0);
		glVertex3f(10, -5, 0);
	glEnd();
	*/
	



	////////////////////////////////////////////
	/////////////////PRACTICA 2/////////////////
	world.dibuja();


	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	world.tecla(key);
	/*
		//poner aqui el codigo de teclado
	if (key == '+' && esfera.radio < 3)
		esfera.radio += 0.5;
	if (key == '-' && esfera.radio > 1)
		esfera.radio -= 0.5;

	*/

	//Cambios de color para la esfera1

	/*
		if (key == 'r') esfera.setColor(255, 0, 0);
	if (key == 'g') esfera.setColor(0, 255, 0);
	if (key == 'b') esfera.setColor(0, 0, 255);
	*/

	/*
	//desplazamientos
	if (key == 'a') //izq. X negativo
	{
		esfera.x -= 0.1f;
	}
	if (key == 'd') //der. X positivo
	{
		esfera.x += 0.1f;
	}
	if (key == 's')  //down Y negativo
	{
		esfera.y -= 0.1f;
	}
	if (key == 'w')  //up. Y positivo
	{
		esfera.y += 0.1f;
	}

	*/


	glutPostRedisplay();

}

void OnTimer(int value)
{
	//poner aqui el codigo de la animacion


	world.rotarOjo();
	world.mueve();


	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	//Informa que despues de cambiar las cosas hay que redibujar
	//ademas se vuelve a registrar el callback para volver a fijar
	//la temporizacion para dentro de unos 25 milisegundos
	glutPostRedisplay(); 

}

