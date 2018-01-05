/*
###########################
Diseñado por: David Infante Casas
###########################
*/

#ifndef LIGHT_H
#define LIGHT_H

#include "stdlib.h"
#include <GL/gl.h>
#include <vertex.h>
#include "ObjectPly.h"
using namespace std;

class Light {   
   private:
      GLenum index;
      _vertex4f col_ambiente, col_difuso, col_especular;

   public:
      float x_light, y_light, z_light;
      int alpha_light, beta_light;

      Light(GLenum indice, float x, float y, float z, int alpha, int beta); 

      void activar();
};

#endif
