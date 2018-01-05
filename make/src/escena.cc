/*
###########################
Modificado por: David Infante Casas
###########################
*/

#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include <iostream>
#include <vector>
#include <GL/gl.h>
#include <GL/glut.h>
#include "escena.h"
#include "Cubo3D.h"
#include "Tetraedro3D.h"
#include "Icosaedro3D.h"
#include "ObjectRevolution.h"
#include "ObjectJerarquico.h"
#include "Light.h"
#include "Materials.h"
#include "Texture.h"
#include "Camera.h"

//Declaracion de variables globales
//Variables para el ratón
int estadoRaton[3], //dependiendo del click dado
   x_mouse, y_mouse; //posición del ratón

//Parte Seleccionada
int parte_seleccionada = 0;

//Cámara actual
int cam_actual = 0;

//Zoom de la proyección ortogonal
int zoom_orto = 1;

//Número de revoluciones al objRevolution
int rev_deg = 45;

//Última tecla pulsada
char last_key = ' ';

//Creación de los modelos
Tetraedro3D tetraedro(30, 50);
Cubo3D cubo(25);
Icosaedro3D icosaedro(7.5);
ObjectPly ply("models/ant.ply");
ObjectRevolution rev("models/peon_rev.ply", 'y');
ObjectJerarquico robot;
Texture tex("textures/logo.jpg");

//Creación de los materiales
Materials materiales;

//Creación de las luces
Light luz_0(GL_LIGHT0, 0, 120, 0, 0, 0);
Light luz_1(GL_LIGHT1, 0, 0, 100, 0, 0);

//Creación del vector de cámaras
vector<Camera> camaras;


//Constructor de la escena
Escena::Escena(){
   Front_plane=50;
   Back_plane=2000;
   ejes.changeAxisSize(5000);

   puntos = false;
   alambre = false;
   solido = false;
   ajedrez = false;
   iluminacion_plana = false;
   iluminacion_suave = false;
   cubo_dibujado = false;
   tetraedro_dibujado = false;
   icosaedro_dibujado = false;
   ply_dibujado = false;
   revolution_dibujado = false;
   jerarquico_dibujado = false;
   textura_dibujada = false;

   //Creación de las cámaras
   Camera cam0(Front_plane*2, 0, 0);
   Camera cam1(Front_plane*2, 0, 270);
   Camera cam2(Front_plane*2, 0, 0);
   camaras.push_back(cam0);
   camaras.push_back(cam1);
   camaras.push_back(cam2);
}

void Escena::inicializar(int UI_window_width,int UI_window_height) {
   glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)
   glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer
   change_projection();
   Width=UI_window_width;
   Height=UI_window_height;
   glViewport(0,0,UI_window_width,UI_window_height);
}

//**************************************************************************
// Funcion que dibuja objetos en la escena
//**************************************************************************
void Escena::draw_objects() {
   rev.newObjectRevolution("models/peon_rev.ply", 'y');
   luz_0.activar();
   luz_1.activar();
   //Animación Idle del robot ObjectJerarquico
   if (last_key != 's' && last_key != 'S' && last_key != 'd' && last_key != 'D' && last_key != 'f' && last_key != 'F')
      robot.Idle();

   glPointSize(3);
   glLineWidth(1);

   //Cambio de dibujo según tecla pulsada
   //Tetraedro
   if (tetraedro_dibujado) {
      if (puntos) tetraedro.draw_puntos();
      else if (alambre) tetraedro.draw_alambre();
      else if (solido) tetraedro.draw_solido();
      else if (ajedrez) tetraedro.draw_ajedrez();
      else if (iluminacion_plana) tetraedro.draw_iluminacion_plana();
      else if (iluminacion_suave) tetraedro.draw_iluminacion_suave();
      else tetraedro.draw_solido();
   }
   //Cubo 
   else if (cubo_dibujado) {
      if (puntos) cubo.draw_puntos();
      else if (alambre) cubo.draw_alambre();
      else if (solido) cubo.draw_solido();
      else if (ajedrez) cubo.draw_ajedrez();
      else if (iluminacion_plana) cubo.draw_iluminacion_plana();
      else if (iluminacion_suave) cubo.draw_iluminacion_suave();
      else cubo.draw_solido();
   }
   //Icosaedro 
   else if (icosaedro_dibujado) {
      if (puntos) icosaedro.draw_puntos();
      else if (alambre) icosaedro.draw_alambre();
      else if (solido) icosaedro.draw_solido();
      else if (ajedrez) icosaedro.draw_ajedrez();
      else if (iluminacion_plana) icosaedro.draw_iluminacion_plana();
      else if (iluminacion_suave) icosaedro.draw_iluminacion_suave();
      else icosaedro.draw_solido();
   }
   //Modelo PLY 
   else if (ply_dibujado) {
      if (puntos) ply.draw_puntos();
      else if (alambre) ply.draw_alambre();
      else if (solido) ply.draw_solido();
      else if (ajedrez) ply.draw_ajedrez();
      else if (iluminacion_plana) ply.draw_iluminacion_plana();
      else if (iluminacion_suave) ply.draw_iluminacion_suave();
      else ply.draw_solido();
   }
   //Modelo por Revolución 
   else if (revolution_dibujado) {
      if (puntos) rev.draw_puntos();
      else if (alambre) rev.draw_alambre();
      else if (solido) rev.draw_solido();
      else if (ajedrez) rev.draw_ajedrez();
      else if (iluminacion_plana) rev.draw_iluminacion_plana();
      else if (iluminacion_suave) rev.draw_iluminacion_suave();
      else rev.draw_ajedrez();
   }
   //Modelo Jerárquico
   else if (jerarquico_dibujado) {
      robot.draw(parte_seleccionada);
   }
   //Tablero con textura
   else if (textura_dibujada) {
      tex.newTexture(100, 100);
   }
   parte_seleccionada = 0;
}


void Escena::dibujar() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
   change_observer();
   draw_axis();
   draw_objects();
   glutSwapBuffers();
}


int Escena::teclaPulsada(unsigned char Tecla1,int x,int y) {

   std::cout << "Tecla: " << Tecla1<< std::endl;
   
   switch (Tecla1){
      /*---Teclas para los tipos de dibujado---*/
      //Modo Puntos
      case 'z':
         puntos = true;
         alambre = false;
         solido = false;
         ajedrez = false;
         iluminacion_plana = false;
         iluminacion_suave = false;

         robot.puntos = true;
         robot.alambre = false;
         robot.solido = false;
         robot.ajedrez = false;
         robot.iluminacion_plana = false;
         robot.iluminacion_suave = false;
         
         last_key = 'z';
      break;
      //Modo Alambre
      case 'x':
         puntos = false;
         alambre = true;
         solido = false;
         ajedrez = false;
         iluminacion_plana = false;
         iluminacion_suave = false;

         robot.puntos = false;
         robot.alambre = true;
         robot.solido = false;
         robot.ajedrez = false;
         robot.iluminacion_plana = false;
         robot.iluminacion_suave = false;

         last_key = 'x';
      break;
      //Modo Sólido
      case 'c':
         puntos = false;
         alambre = false;
         solido = true;
         ajedrez = false;
         iluminacion_plana = false;
         iluminacion_suave = false;

         robot.puntos = false;
         robot.alambre = false;
         robot.solido = true;
         robot.ajedrez = false;
         robot.iluminacion_plana = false;
         robot.iluminacion_suave = false;

         last_key = 'c';
      break;
      //Modo Ajedrez
      case 'v':
         puntos = false;
         alambre = false;
         solido = false;
         ajedrez = true;
         iluminacion_plana = false;
         iluminacion_suave = false;

         robot.puntos = false;
         robot.alambre = false;
         robot.solido = false;
         robot.ajedrez = true;
         robot.iluminacion_plana = false;
         robot.iluminacion_suave = false;

         last_key = 'v';
      break;
      //Modo Iluminacion Plana
      case 'b':
         puntos = false;
         alambre = false;
         solido = false;
         ajedrez = false;
         iluminacion_plana = true;
         iluminacion_suave = false;

         robot.puntos = false;
         robot.alambre = false;
         robot.solido = false;
         robot.ajedrez = false;
         robot.iluminacion_plana = true;
         robot.iluminacion_suave = false;

         last_key = 'b';
      break;
      //Modo Iluminacion Suave
      case 'n':
         puntos = false;
         alambre = false;
         solido = false;
         ajedrez = false;
         iluminacion_plana = false;
         iluminacion_suave = true;

         robot.puntos = false;
         robot.alambre = false;
         robot.solido = false;
         robot.ajedrez = false;
         robot.iluminacion_plana = false;
         robot.iluminacion_suave = true;

         last_key = 'n';
      break;
      /*---Teclas para los movimientos de los modelos---*/
      //Aumentar y disminuir el número de revoluciones del ObjectRevolution
      case 'a':
         if (rev.degrees > 1) --rev.degrees;

         last_key = 'a';
      break;
      case 'A':
         if (rev.degrees <= 360) ++rev.degrees;

         last_key = 'A';
      break;
      //Movimiento en horizontal de la textura en el tablero
      case 'm':
         ++tex.i_desp;

         last_key = 'm';
      break;
      case 'M':
         --tex.i_desp;

         last_key = 'M';
      break;
      //Rotar la textura en el tablero
      case 'k':
         if (tex.giro == 3) tex.giro = 0;
         else ++tex.giro;

         last_key = 'k';
      break;
      case 'K':
         if (tex.giro == 0) tex.giro = 3;
         else --tex.giro;

         last_key = 'K';
      break;
      //Rotar la cabeza del robot
      case 's':
         if (robot.move_head > -35) --robot.move_head;

         last_key = 's';
      break;
      case 'S':
         if (robot.move_head < 35) ++robot.move_head;

         last_key = 'S';
      break;
      //Rotar las piernas del robot
      case 'd':
         if (robot.move_feet > -20) --robot.move_feet;

         last_key = 'd';
      break;
      case 'D':
         if (robot.move_feet < 20) ++robot.move_feet;

         last_key = 'D';
      break;
      //Trasladar el cuello y cabeza del robot
      case 'f':
         if (robot.move_neck > 0) --robot.move_neck;

         last_key = 'f';
      break;
      case 'F':
         if (robot.move_neck < 25) ++robot.move_neck;

         last_key = 'F';
      break;
      //Aumentar y disminuir velocidad de la cabeza del robot
      case 'g':
         if (robot.speed_head > 0) --robot.speed_head;

         last_key = 'g';
      break;
      case 'G':
         if (robot.speed_head < 10) ++robot.speed_head;

         last_key = 'G';
      break;
      //Aumentar y disminuir velocidad de los pies del robot
      case 'h':
         if (robot.speed_feet > 0) --robot.speed_feet;

         last_key = 'h';
      break;
      case 'H':
         if (robot.speed_feet < 7) ++robot.speed_feet;

         last_key = 'H';
      break;
      //Aumentar y disminuir velocidad del cuello del robot
      case 'j':
         if (robot.speed_neck > 0) --robot.speed_neck;

         last_key = 'j';
      break;
      case 'J':
         if (robot.speed_neck < 5) ++robot.speed_neck;

         last_key = 'J';
      break;
      //Aumentar y disminuir la x de la luz
      case 'w':
         --luz_1.x_light;

         last_key = 'w';
      break;
      case 'W':
         ++luz_1.x_light;

         last_key = 'W';
      break;
      //Aumentar y disminuir la y de la luz
      case 'e':
         --luz_1.y_light;

         last_key = 'e';
      break;
      case 'E':
         ++luz_1.y_light;

         last_key = 'E';
      break;
      //Aumentar y disminuir la z de la luz
      case 'r':
         --luz_1.z_light;

         last_key = 'r';
      break;
      case 'R':
         ++luz_1.z_light;

         last_key = 'R';
      break;
      //Aumentar y disminuir la alpha de la luz
      case 't':
         --luz_1.alpha_light;

         last_key = 't';
      break;
      case 'T':
         ++luz_1.alpha_light;

         last_key = 'T';
      break;
      //Aumentar y disminuir la beta de la luz
      case 'y':
         --luz_1.beta_light;

         last_key = 'y';
      break;
      case 'Y':
         ++luz_1.beta_light;

         last_key = 'Y';
      break;
      /*---Teclas para cargar los modelos---*/
      //Tetraedro
      case '1':
         tetraedro_dibujado = true;
         cubo_dibujado = false;
         icosaedro_dibujado = false;
         ply_dibujado = false;
         revolution_dibujado = false;
         jerarquico_dibujado = false;
         textura_dibujada = false;

         last_key = '1';
      break;
      //Cubo
      case '2':
         tetraedro_dibujado = false;
         cubo_dibujado = true;
         icosaedro_dibujado = false;
         ply_dibujado = false;
         revolution_dibujado = false;
         jerarquico_dibujado = false;
         textura_dibujada = false;

         last_key = '2';
      break;
      //Icosaedro
      case '3':
         tetraedro_dibujado = false;
         cubo_dibujado = false;
         icosaedro_dibujado = true;
         ply_dibujado = false;
         revolution_dibujado = false;
         jerarquico_dibujado = false;
         textura_dibujada = false;

         last_key = '3';
      break;
      //ObjectPly
      case '4':
         tetraedro_dibujado = false;
         cubo_dibujado = false;
         icosaedro_dibujado = false;
         ply_dibujado = true;
         revolution_dibujado = false;
         jerarquico_dibujado = false;
         textura_dibujada = false;

         last_key = '4';
      break;
      //ObjectRevolution
      case '5':
         tetraedro_dibujado = false;
         cubo_dibujado = false;
         icosaedro_dibujado = false;
         ply_dibujado = false;
         revolution_dibujado = true;
         jerarquico_dibujado = false;
         textura_dibujada = false;

         last_key = '5';
      break;
      //Robot ObjectJerarquico
      case '6':
         tetraedro_dibujado = false;
         cubo_dibujado = false;
         icosaedro_dibujado = false;
         ply_dibujado = false;
         revolution_dibujado = false;
         jerarquico_dibujado = true;
         textura_dibujada = false;

         last_key = '6';
      break;
      //Tablero con textura
      case '7':
         tetraedro_dibujado = false;
         cubo_dibujado = false;
         icosaedro_dibujado = false;
         ply_dibujado = false;
         revolution_dibujado = false;
         jerarquico_dibujado = false;
         textura_dibujada = true;

         last_key = '7';
      break;

      //Zoom proyección ortogonal
      case 'u':
         zoom_orto++;

         last_key = 'u';
      break;
      case 'U':
         if (zoom_orto > 1) zoom_orto--;

         last_key = 'U';
      break;

      //Mover cámara a la izquierda
      case 127: //Tecla SUPRIMIR (Supr / Del) Glut no dispone de una tecla reservada
         camaras[cam_actual].disminuirObserver_position();
      break;

      default:
         last_key = ' ';
      break;
   }

	if (toupper(Tecla1)=='Q') return 1;
	else return 0;
}

void Escena::teclaEspecial(int Tecla1,int x,int y) {

   switch (Tecla1){
      //Modificar ángulo de visión en las 4 direcciones
	   case GLUT_KEY_LEFT:
         camaras[cam_actual].disminuirObserver_angle_y();
      break;
	   case GLUT_KEY_RIGHT:
         camaras[cam_actual].aumentarObserver_angle_y();
      break;
	   case GLUT_KEY_UP:
         camaras[cam_actual].disminuirObserver_angle_x();
      break;
	   case GLUT_KEY_DOWN:
         camaras[cam_actual].aumentarObserver_angle_x();
      break;
      //Mover cámara hacia arriba, abajo y derecha (izquierda en Escena::teclaPulsada)
	   case GLUT_KEY_END:
         camaras[cam_actual].aumentarObserver_distance();
      break;
	   case GLUT_KEY_HOME:
         camaras[cam_actual].disminuirObserver_distance();
      break;
      case GLUT_KEY_PAGE_DOWN:
         camaras[cam_actual].aumentarObserver_position();
      break;

      //Teclas para cambiar de materiales
      case GLUT_KEY_F1:
            cubo.setMaterial(materiales.material1());
            tetraedro.setMaterial(materiales.material1());
            icosaedro.setMaterial(materiales.material1());
            ply.setMaterial(materiales.material1());
            rev.setMaterial(materiales.material1());
            robot.setMaterial(materiales.material1());
      break;
      case GLUT_KEY_F2:
            cubo.setMaterial(materiales.material2());
            tetraedro.setMaterial(materiales.material2());
            icosaedro.setMaterial(materiales.material2());
            ply.setMaterial(materiales.material2());
            rev.setMaterial(materiales.material2());
            robot.setMaterial(materiales.material2());
      break;
      case GLUT_KEY_F3:
            cubo.setMaterial(materiales.material3());
            tetraedro.setMaterial(materiales.material3());
            icosaedro.setMaterial(materiales.material3());
            ply.setMaterial(materiales.material3());
            rev.setMaterial(materiales.material3());
            robot.setMaterial(materiales.material3());
      break;
      //Teclas para cambiar de cámara
      case GLUT_KEY_F4:
         cam_actual = 0;
      break;
      case GLUT_KEY_F5:
         cam_actual = 1;
      break;
      case GLUT_KEY_F6:
         cam_actual = 2;
      break;
	}

	std::cout << "Camara: " << cam_actual << std::endl;
}


//**************************************************************************
// Funcion para dibujar la escena en modo Pick
//**************************************************************************

void Escena::dibujar_pick() {
   if (GL_SELECT) {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
      glMatrixMode(GL_MODELVIEW);
	   glLoadIdentity();
	   glTranslatef(0, 0, -camaras[cam_actual].getObserver_distance());
	   glRotatef(camaras[cam_actual].getObserver_angle_x(), 1, 0, 0);
	   glRotatef(camaras[cam_actual].getObserver_angle_y(), 0, 1, 0);
      draw_axis();
      draw_objects();
      glutSwapBuffers();     
   }
}


//**************************************************************************
// Funcion para seleccionar un objeto de la escena
//**************************************************************************

void Escena::pick (int x, int y) {
   unsigned int selectBuffer[256], hits;
   int viewport[4];
   int dx = glutGet(GLUT_WINDOW_WIDTH), dy = glutGet(GLUT_WINDOW_HEIGHT);

   glSelectBuffer(256, selectBuffer);
   glGetIntegerv(GL_VIEWPORT, viewport);
   glRenderMode(GL_SELECT);

   glInitNames();
   glPushName(0);

   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   gluPickMatrix(x, (viewport[3] - y), 5.0, 5.0, viewport);
   glFrustum(-Width, Width, -Height, Height, Front_plane, Back_plane);

   dibujar_pick();
   hits = glRenderMode(GL_RENDER);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glFrustum(-Width, Width, -Height, Height, Front_plane, Back_plane);


   parte_seleccionada = -1;
   if (hits > 0) {
      parte_seleccionada = selectBuffer[(0*4)+3];
      float min = selectBuffer[(0*4)+1];
      for(int i = 0; i < hits; ++i) {
         if (selectBuffer[i*4+1] < min) {
            min = selectBuffer[(i*4)+1];
            parte_seleccionada = selectBuffer[i*4+3];
         }
      }
   }
}


//**************************************************************************
//Función para reconocer el click del ratón
//**************************************************************************

void Escena::clickRaton(int boton, int estado, int x, int y) {
   //Modo mover cámara
   if(boton == GLUT_RIGHT_BUTTON) {
      if(estado == GLUT_DOWN) {
         estadoRaton[2] = 1;
         x_mouse = x;
         y_mouse = y;
      }
      else estadoRaton[2] = 0;
   }
   //Modo selección
   if ((boton == GLUT_LEFT_BUTTON) && (estado == GLUT_DOWN)) pick(x, y);
}


//**************************************************************************
//Función para reconocer el movimiento del ratón
//**************************************************************************

void Escena::ratonMovido(int x, int y) {
   if(estadoRaton[2] == 1) {
      camaras[cam_actual].girar(x, y, x_mouse, y_mouse);
      x_mouse = x;
      y_mouse = y;
      glutPostRedisplay();
   }
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//**************************************************************************

void Escena::change_projection() {
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   float aspect = GLfloat(glutGet(GLUT_WINDOW_WIDTH)) / GLfloat(glutGet(GLUT_WINDOW_HEIGHT));
   glFrustum(-Width*aspect, Width*aspect, -Height, Height, Front_plane, Back_plane);
   //glFrustum(-Width*0.5,Width*0.5,-Height*0.5,Height*0.5,Front_plane*0.5,Back_plane*0.5);
}

void Escena::redimensionar(int newWidth,int newHeight) {
   change_projection();
   Width=newWidth/10;
   Height=newHeight/10;
   glViewport(0,0,newWidth,newHeight);
   glutPostRedisplay();
}


//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void Escena::change_observer() {
   //cámara ortogonal
   if (cam_actual == 2) {
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);
      glRotatef(90, 1, 0, 0);
      glScalef(zoom_orto, 1.0, zoom_orto);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
   }
   //cámaras normales
   else {
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      change_projection();
      camaras[cam_actual].setObservador();
   }
}


//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void Escena::draw_axis() {
   ejes.draw();
}

