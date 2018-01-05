/*
###########################
Diseñado por: David Infante Casas
###########################
*/

#ifndef TETRAEDRO3D_H
#define TETRAEDRO3D_H

#include "Object3D.h"

class Tetraedro3D: public Object3D {

   public:
      //Constructor
      Tetraedro3D(GLfloat tam=30, GLfloat altura=50) {
         _vertex3f punto1_t(-tam, -tam, tam);//abajo izq
         _vertex3f punto2_t(tam, -tam, tam);//abajo dch
         _vertex3f punto3_t(0, -tam, -tam);//centro abajo
         _vertex3f punto4_t(0, altura, 0);//centro arriba

         _vertex3i cara1_t(0, 3, 2);
         _vertex3i cara2_t(1, 3, 0);
         _vertex3i cara3_t(2, 3, 1);
         _vertex3i cara4_t(1, 0, 2);

         puntos.push_back(punto1_t);
         puntos.push_back(punto2_t);
         puntos.push_back(punto3_t);
         puntos.push_back(punto4_t);

         triangulos.push_back(cara1_t);
         triangulos.push_back(cara2_t);
         triangulos.push_back(cara3_t);
         triangulos.push_back(cara4_t);
      }

};
#endif
