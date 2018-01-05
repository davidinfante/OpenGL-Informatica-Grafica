/*
###########################
Diseñado por: David Infante Casas
###########################
*/

#ifndef OBJECTPLY_H
#define OBJECTPLY_H

#include "Object3D.h"
#include "file_ply_stl.h"

class ObjectPly: public Object3D {
   
   public:
      ObjectPly();

      ObjectPly(const string &filename);

      void readPly(const string &filename);

      void copyObjectPly(ObjectPly other);
};

#endif
