/*
###########################
Diseñado por: David Infante Casas
###########################
*/

#ifndef OBJECT3D_H
#define OBJECT3D_H

#include <vector>
#include <iostream>
#include <cmath>
#include "stdlib.h"
#include <GL/gl.h>
#include <vertex.h>
using namespace std;

class Object3D {
   protected:
      vector<_vertex3f> puntos;
      vector<_vertex3i> triangulos;
      vector<_vertex3f> normales_vertices;
      vector<_vertex3f> normales_triangulos;
      bool b_normales_triangulos;
      bool b_normales_vertices;
      _vertex4f ambiente;
      _vertex4f difusa;
      _vertex4f especular;
      float brillo;
      _vertex4f color;

   public:
      //Constructor por defecto
      Object3D() {
         puntos.clear();
         triangulos.clear();
         normales_triangulos.clear();
         normales_vertices.clear();
         b_normales_triangulos = false;
         b_normales_vertices = false;
         color = _vertex4f(0.0, 1.0, 0.0, 1.0);
      }

      //Constructor con parametros
      Object3D(vector<_vertex3f> otro_p, vector<_vertex3i> otro_t);

      //Calculo de normales en los vertices
      void calcular_normales_vertices();

      //Calculo de normales en las caras
      void calcular_normales_triangulos();

      //Dibujado iluminación plana
      void draw_iluminacion_plana();

      //Dibujado iluminación suave
      void draw_iluminacion_suave();

      //Dibujado de los puntos de una figura
      void draw_puntos();

      //Dibujado de las aristas de una figura
      void draw_alambre();

      //Dibujado de una figura solida
      void draw_solido();

      //Dibujado de una figura en ajedrez
      void draw_ajedrez();

      inline vector<_vertex3f> getPuntos() {
         return puntos;
      }

      inline vector<_vertex3i> getTriangulos() {
         return triangulos;
      }

      inline void setMaterial(vector<_vertex4f> material) {
         ambiente = material.at(0);
         difusa = material.at(1);
         especular = material.at(2);
      }

      void invertirNormales() {
         for (int i = 0; i < normales_triangulos.size(); ++i)
            normales_triangulos[i] *= -1;
      }

      void setColor(float r, float g, float b) {
         color = _vertex4f(r, g, b, 1.0);
      }

};

#endif
