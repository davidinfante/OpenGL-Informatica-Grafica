/*
###########################
Diseñado por: David Infante Casas
###########################
*/

#ifndef OBJECTJERARQUICO_H
#define OBJECTJERARQUICO_H

#include "ObjectRevolution.h"
#include "Cubo3D.h"
#include <GL/gl.h>
#include <GL/glut.h>

class ObjectJerarquico: public Object3D {

	private:
      ObjectRevolution _cuerpo;
      ObjectRevolution _cuerpo_extensible;
      ObjectPly _cabeza;
      ObjectRevolution _piernaizq;
      ObjectRevolution _piernadch;
      Cubo3D _pieizq;
      Cubo3D _piedch;
      ObjectRevolution _ojoizq;
      ObjectRevolution _ojodch;

      bool seleccion[9] = {false};

   public:
      bool puntos, alambre, solido, ajedrez, iluminacion_plana, iluminacion_suave;
      int move_head, move_feet, move_neck;
      bool bool_move_head, bool_move_feet, bool_move_neck;
      int speed_head, speed_feet, speed_neck;

      ObjectJerarquico();

      void cuerpo(int parte_seleccionada);
      void cuerpo_extensible(int parte_seleccionada);
      void cabeza(int parte_seleccionada);
      void piernaizq(int parte_seleccionada);
      void piernadch(int parte_seleccionada);
      void pieizq(int parte_seleccionada);
      void piedch(int parte_seleccionada);
      void ojoizq(int parte_seleccionada);
      void ojodch(int parte_seleccionada);

      void draw(int parte_seleccionada);
      void nombres(int parte_seleccionada);

      void IdleMovement();
      void Idle();

      void setMaterial(vector<_vertex4f> material);
};

#endif
