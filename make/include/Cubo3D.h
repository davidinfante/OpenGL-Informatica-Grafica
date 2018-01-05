/*
###########################
Diseñado por: David Infante Casas
###########################
*/

#ifndef CUBO3D_H
#define CUBO3D_H

#include "Object3D.h"

class Cubo3D: public Object3D {

   public:
      //Constructor
      Cubo3D(GLfloat tam=50) {
         _vertex3f punto1_c(-tam, -tam, tam);
         _vertex3f punto2_c(tam, -tam, tam);
         _vertex3f punto3_c(tam, tam, tam);
         _vertex3f punto4_c(-tam, tam, tam);

         _vertex3f punto5_c(-tam, -tam, -tam);
         _vertex3f punto6_c(tam, -tam, -tam);
         _vertex3f punto7_c(tam, tam, -tam);
         _vertex3f punto8_c(-tam, tam, -tam);

         _vertex3i vertice1_c(0, 1, 2);
         _vertex3i vertice2_c(2, 3, 0);

         _vertex3i vertice3_c(1, 5, 6);
         _vertex3i vertice4_c(6, 2, 1);

         _vertex3i vertice5_c(7, 6, 5);
         _vertex3i vertice6_c(5, 4, 7);

         _vertex3i vertice7_c(4, 0, 3);
         _vertex3i vertice8_c(3, 7, 4);

         _vertex3i vertice9_c(4, 5, 1);
         _vertex3i vertice10_c(1, 0, 4);

         _vertex3i vertice11_c(3, 2, 6);
         _vertex3i vertice12_c(6, 7, 3);

         puntos.push_back(punto1_c);
         puntos.push_back(punto2_c);
         puntos.push_back(punto3_c);
         puntos.push_back(punto4_c);
         puntos.push_back(punto5_c);
         puntos.push_back(punto6_c);
         puntos.push_back(punto7_c);
         puntos.push_back(punto8_c);

         triangulos.push_back(vertice1_c);
         triangulos.push_back(vertice2_c);
         triangulos.push_back(vertice3_c);
         triangulos.push_back(vertice4_c);
         triangulos.push_back(vertice5_c);
         triangulos.push_back(vertice6_c);
         triangulos.push_back(vertice7_c);
         triangulos.push_back(vertice8_c);
         triangulos.push_back(vertice9_c);
         triangulos.push_back(vertice10_c);
         triangulos.push_back(vertice11_c);
         triangulos.push_back(vertice12_c);
      }

   /**
   *  Copia de un Objeto Cubo3D en this (Copy Constructor)
   */
   void copyCubo3D(Cubo3D other) {
      puntos.clear();
      puntos = other.getPuntos();
      triangulos.clear();
      triangulos = other.getTriangulos();
   }

};
#endif
