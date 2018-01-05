/*
###########################
Diseñado por: David Infante Casas
###########################
*/

#include "ObjectPly.h"

ObjectPly::ObjectPly() {}

ObjectPly::ObjectPly(const string &filename) {
   readPly(filename);
}

void ObjectPly::readPly(const string &filename) {
   _file_ply file;
   file.open(filename);
   file.read(puntos, triangulos);
   file.close();
}

/**
*  Copia de un Objeto Ply en this
*/
void ObjectPly::copyObjectPly(ObjectPly other) {
   puntos.clear();
   puntos = other.getPuntos();
   triangulos.clear();
   triangulos = other.getTriangulos();
}
