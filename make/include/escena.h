/*
###########################
Modificado por: David Infante Casas
###########################
*/

#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"

class Escena {
private:
// tamaño de los ejes
#define AXIS_SIZE 5000
Ejes ejes;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Width, Height, Front_plane, Back_plane;

//Variables que controlan lo que se está dibujando
bool puntos, alambre, solido, ajedrez, iluminacion_plana, iluminacion_suave, cubo_dibujado, tetraedro_dibujado, icosaedro_dibujado, ply_dibujado, revolution_dibujado, jerarquico_dibujado, textura_dibujada;

private:
	void clear_window();
	void draw_axis();
	void draw_objects();

//Transformación de cámara
	void change_projection();
	void change_observer();


public:
   Escena();
	void inicializar(int UI_window_width,int UI_window_height);
	void redimensionar(int newWidth,int newHeight);

	// Dibujar
	void dibujar();
   void dibujar_pick();

	// Interacción con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y);
	void teclaEspecial(int Tecla1,int x,int y);
   void pick(int x, int y);
   void clickRaton(int boton, int estado, int x, int y);
   void ratonMovido(int x, int y);
};
#endif
