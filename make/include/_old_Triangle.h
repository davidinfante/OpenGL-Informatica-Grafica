/*
###########################
Diseñado por: David Infante Casas
###########################
*/

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <cmath>
#include "stdlib.h"
#include <GL/gl.h>
using namespace std;

class Triangle{
   private:
      //numero de lados
      int a, b, c;

   public:
      //Constructor por defecto y con parametros
      Triangle(int=0, int=0, int=0) {
         this->a = a;
         this->b = b;
         this->c = c;
      }

      //Return del primer vertice del triangulo
      inline int getA(){
         return a;
      }

      //Return del segundo vertice del triangulo
      inline int getB(){
         return b;
      }

      //Return del segundo vertice del triangulo
      inline int getC(){
         return c;
      }

};

#endif
