/*
###########################
Diseñado por: David Infante Casas
###########################
*/

#ifndef POINT3D_H
#define POINT3D_H

#include <iostream>
#include <cmath>
#include "stdlib.h"
#include <GL/gl.h>
using namespace std;

class Point3D{
   private:
      GLfloat x, y, z;

   public:
      //Constructor por defecto y con parametros
      Point3D(GLfloat=0, GLfloat=0, GLfloat=0) {
         this->x = x;
         this->y = y;
         this->z = z;
      }

      //Return de la coordenada x
      inline GLfloat getX(){
         return x;
      }

      //Return de la coordenada y
      inline GLfloat getY(){
         return y;
      }

      //Return de la coordenada x
      inline GLfloat getZ(){
         return z;
      }

      //Agregar coordenada x
      inline void setX(GLfloat a){
         x = a;
      }

      //Agregar coordenada y
      inline void setY(GLfloat a){
         y = a;
      }

      //Agregar coordenada z
      inline void setZ(GLfloat a){
         z = a;
      }

};

#endif
