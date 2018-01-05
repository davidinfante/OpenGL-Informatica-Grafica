/*
###########################
Diseñado por: David Infante Casas
###########################
*/

#ifndef MATERIALS_H
#define MATERIALS_H

#include "stdlib.h"
#include <GL/gl.h>
#include <vertex.h>
#include <vector>
using namespace std;

class Materials {   
   private:
      vector<_vertex4f> material;

   public:
      Materials() {
         material.clear();
      }

      vector<_vertex4f> material1() {
         material.clear();
         //Los materiales se añaden al vector en el orden ambiente, difusa, especular
         material.push_back({0.022, 0.17, 0.02, 1.0});
         material.push_back({0.022, 0.17, 0.02, 1.0});
         material.push_back({0.63, 0.73, 0.63, 1.0});
         return material;
      }

      vector<_vertex4f> material2() {
         material.clear();
         material.push_back({0.1745, 0.01175, 0.01175, 1.0});
         material.push_back({0.61424, 0.04136, 0.04136, 1.0});
         material.push_back({0.727811, 0.626959, 0.626959, 1.0});
         return material;
      }

      vector<_vertex4f> material3() {
         material.clear();
         material.push_back({0.24725, 0.1995, 0.0745, 1.0});
         material.push_back({0.75164, 0.60648, 0.22648, 1.0});
         material.push_back({0.628281, 0.555802, 0.366065, 1.0});
         return material;
      }
};

#endif
