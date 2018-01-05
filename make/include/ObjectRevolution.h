/*
###########################
Diseñado por: David Infante Casas
###########################
*/


#ifndef OBJECTREVOLUTION_H
#define OBJECTREVOLUTION_H

#include "ObjectPly.h"

class ObjectRevolution: public ObjectPly {
   
   private:
      vector<_vertex3f> profile;

   public:
      int degrees;

      ObjectRevolution();

      ObjectRevolution(vector<_vertex3f> v, char axis);

      ObjectRevolution(const string &filename, char axis);

      void readRevolution(const string &filename);

      /**
      *  Crea un objeto a partir de revolucionar un perfil y le añade, si no tiene, tapas
      */
      void doRevolution(char axis);

      void newObjectRevolution(const string &filename, char axis);

      _vertex3f rotateX(_vertex3f punto, float degree);

      _vertex3f rotateY(_vertex3f punto, float degree);

      _vertex3f rotateZ(_vertex3f punto, float degree);

      void copyObjectRevolution(ObjectRevolution other);

      inline vector<_vertex3f> getProfile() {
         return profile;
      }

};

#endif
