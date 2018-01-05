/*
###########################
Diseñado por: David Infante Casas
###########################
*/

#ifndef ICOSAEDRO3D_H
#define ICOSAEDRO3D_H

#include "Object3D.h"

class Icosaedro3D: public Object3D {

   public:
      //Constructor
      Icosaedro3D(GLfloat altura=7.5) {
         _vertex3f punto1_i(0, 15, 0);
         _vertex3f punto2_i(-15, altura, 5);
         _vertex3f punto3_i(15, altura, 5);
         _vertex3f punto4_i(-7.5, altura, -12.5);
         _vertex3f punto5_i(7.5, altura, -12.5);
         _vertex3f punto6_i(0, altura, 15);
         _vertex3f punto7_i(0, -altura, -15);
         _vertex3f punto8_i(-15, -altura, -5);
         _vertex3f punto9_i(15, -altura, -5);
         _vertex3f punto10_i(7.5, -altura, 12.5);
         _vertex3f punto11_i(-7.5, -altura, 12.5);
         _vertex3f punto12_i(0, -15, 0);

         _vertex3i vertice1_i(0, 1, 3);
         _vertex3i vertice2_i(0, 3, 4);
         _vertex3i vertice3_i(0, 4, 2);
         _vertex3i vertice4_i(0, 5, 1);
         _vertex3i vertice5_i(0, 2, 5);
         _vertex3i vertice6_i(3, 6, 4);
         _vertex3i vertice7_i(3, 7, 6);
         _vertex3i vertice8_i(1, 7, 3);
         _vertex3i vertice9_i(1, 10, 7);
         _vertex3i vertice10_i(5, 1, 10);
         _vertex3i vertice11_i(5, 9, 10);
         _vertex3i vertice12_i(2, 5, 9);
         _vertex3i vertice13_i(2, 9, 8);
         _vertex3i vertice14_i(2, 4, 8);
         _vertex3i vertice15_i(4, 6, 8);
         _vertex3i vertice16_i(10, 11, 9);
         _vertex3i vertice17_i(9, 11, 8);
         _vertex3i vertice18_i(8, 11, 6);
         _vertex3i vertice19_i(6, 11, 7);
         _vertex3i vertice20_i(7, 11, 10);

         puntos.push_back(punto1_i);
         puntos.push_back(punto2_i);
         puntos.push_back(punto3_i);
         puntos.push_back(punto4_i);
         puntos.push_back(punto5_i);
         puntos.push_back(punto6_i);
         puntos.push_back(punto7_i);
         puntos.push_back(punto8_i);
         puntos.push_back(punto9_i);
         puntos.push_back(punto10_i);
         puntos.push_back(punto11_i);
         puntos.push_back(punto12_i);

         triangulos.push_back(vertice1_i);
         triangulos.push_back(vertice2_i);
         triangulos.push_back(vertice3_i);
         triangulos.push_back(vertice4_i);
         triangulos.push_back(vertice5_i);
         triangulos.push_back(vertice6_i);
         triangulos.push_back(vertice7_i);
         triangulos.push_back(vertice8_i);
         triangulos.push_back(vertice9_i);
         triangulos.push_back(vertice10_i);
         triangulos.push_back(vertice11_i);
         triangulos.push_back(vertice12_i);
         triangulos.push_back(vertice13_i);
         triangulos.push_back(vertice14_i);
         triangulos.push_back(vertice15_i);
         triangulos.push_back(vertice16_i);
         triangulos.push_back(vertice17_i);
         triangulos.push_back(vertice18_i);
         triangulos.push_back(vertice19_i);
         triangulos.push_back(vertice20_i);
      }

};
#endif
