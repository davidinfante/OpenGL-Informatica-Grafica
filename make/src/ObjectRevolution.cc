/*
###########################
Diseñado por: David Infante Casas
###########################
*/

#include "ObjectRevolution.h"


/**
*  Constructor por defecto
*/
ObjectRevolution::ObjectRevolution() {}

/**
*  Constructor con un vector de puntos
*/
ObjectRevolution::ObjectRevolution(vector<_vertex3f> v, char axis){
   degrees = 45;
   profile = v;
   doRevolution(axis);
}

/**
*  Constructor de un objecto revolution
*/
ObjectRevolution::ObjectRevolution(const string &filename, char axis) {
   degrees = 45;
   readRevolution(filename);
   profile = puntos;
   doRevolution(axis);
}

/**
*  Lectura de un perfil PLY para revolucionarlo
*/
void ObjectRevolution::readRevolution(const string &filename) {
   _file_ply file;
   file.open(filename);
   file.read(puntos, triangulos);
   file.close();
}

/**
*  Transformacion para añadir más revoluciones
*/
void ObjectRevolution::newObjectRevolution(const string &filename, char axis) {
   readRevolution(filename);
   profile = puntos;
   doRevolution(axis);
}

/**
*  Crea un objeto a partir de revolucionar un perfil y le añade, si no tiene, tapas
*/
void ObjectRevolution::doRevolution(char axis) {

   int original_size = profile.size();
   float N = 360 / degrees;
   double rotationAngle= (2.0 * 3.14159) / N;   
   bool bottomCover = false;
   bool topCover = false;
   int aux = -1;
   int aux_cover = -1;
   int num_triangs = 0;

   //Colocar tapa superior si no hay
   if (axis == 'x') {
      if (profile.front().y != 0 || profile.front().z != 0) {
         _vertex3f tapa_superior(profile.at(0).x, 0, 0);
         profile.insert(profile.begin(), tapa_superior);
         topCover = true;
      }
   } else if (axis == 'y') {
      if (profile.front().x != 0 || profile.front().z != 0) {
         _vertex3f tapa_superior(0, profile.at(0).y, 0);
         profile.insert(profile.begin(), tapa_superior);
         topCover = true;
      }
   } else if (axis == 'z') {
      if (profile.front().x != 0 || profile.front().y != 0) {
         _vertex3f tapa_superior(0, 0, profile.at(0).z);
         profile.insert(profile.begin(), tapa_superior);
         topCover = true;
      }
   }

   //Colocar tapa inferior si no hay
   if (axis == 'x') {
      if (profile.at(original_size).y != 0 || profile.at(original_size).z != 0) {
         _vertex3f tapa_inferior(profile.at(original_size).x, 0, 0);
         profile.push_back(tapa_inferior);
         bottomCover = true;
      }
   } else if (axis == 'y') {
      if (profile.at(original_size).x != 0 || profile.at(original_size).z != 0) {
         _vertex3f tapa_inferior(0, profile.at(original_size).y, 0);
         profile.insert(profile.end(), tapa_inferior);
         bottomCover = true;
      }
   } else if (axis == 'z') {
      if (profile.at(original_size).x != 0 || profile.at(original_size).y != 0) {
         _vertex3f tapa_inferior(0, 0, profile.at(original_size).z);
         profile.push_back(tapa_inferior);
         bottomCover = true;
      }
   }
 
   //Contador de puntos
   int counter = (int) profile.size();

   //Actualizar el contador de puntos en función de las tapas que haya
   if (topCover) --counter;
   if (bottomCover) --counter;
 
   //Numero de puntos que va a tener el objeto revolucionado
   int dots = counter * N;
 
   //Numero de vertices de la parte interior del objeto
   int interior_dots = counter * N;
 
   //Numero de triangulos que va a tener el objeto revolucionado
   int triang = 2 * N * (counter - 1);
 
   //Actualizar los contadores en funcion de las tapas
   if (topCover) {++dots; triang += N;}
   if (bottomCover) {++dots; triang += N;}
 
   //Vector auxiliar para almacenar los puntos
   vector<_vertex3f> auxPoints(dots);

   //Tapa inferior y superior
   for (unsigned int i = 0; i < profile.size() - 2; ++i)
      auxPoints[i] = profile[i+1];
             
   for (int i = 1; i < N; ++i)
      for (unsigned int j = 0; j < profile.size() - 1; ++j)
         switch (axis) {
            case 'x':
               auxPoints[i * counter + j] = rotateX(profile[j + 1], rotationAngle * i);
            break;
            case 'y':
               auxPoints[i * counter + j] = rotateY(profile[j + 1], rotationAngle * i);
            break;
            case 'z':
               auxPoints[i * counter + j] = rotateZ(profile[j + 1], rotationAngle * i);
            break;
         }
             
   auxPoints[dots - 2] = profile[0];
   auxPoints[dots - 1] = profile[profile.size() - 1];

   //Asignar puntos
   puntos.clear();
   puntos = auxPoints;

   //Vector auxiliar para almacenar los triangulos
   vector<_vertex3i> auxTriangles(triang);
 
   //Creo los triangulos intermedios
   for (int i = 0; i < (counter - 1); ++i) {
       for (int j = 0 ; j < N; ++j) {
           aux = counter * j + i;
 
           auxTriangles[num_triangs].x = aux % interior_dots;
           auxTriangles[num_triangs].y = (aux + counter) % interior_dots;
           auxTriangles[num_triangs].z = (aux + 1)% interior_dots;
 
           auxTriangles[num_triangs+1].x = (aux + counter) % interior_dots;
           auxTriangles[num_triangs+1].y = (aux + counter + 1) % interior_dots;
           auxTriangles[num_triangs+1].z = (aux + 1) % interior_dots;
           num_triangs += 2;
       }
   }

   //Triangulos de la tapa inferior
   if (bottomCover) {
      if (topCover) aux_cover = dots - 2;
      else aux_cover = dots - 1;
      
      for (int i = 0; i < N ; i++) {
         aux = i * counter;
         auxTriangles[num_triangs].x = aux_cover;
         auxTriangles[num_triangs].y = (aux + counter) % interior_dots;
         auxTriangles[num_triangs].z = aux % interior_dots;
         num_triangs++;
      }
   }

   //Triangulos de la tapa superior
   if (topCover) {
      aux_cover = dots - 1;
    
      for (int i = 0; i < N ; i++) {
         aux = i * counter + counter - 1;
         auxTriangles[num_triangs].x = aux % interior_dots;
         auxTriangles[num_triangs].y = (aux + counter) % interior_dots;
         auxTriangles[num_triangs].z = aux_cover;
         num_triangs++;
      }
   }
 
   //Asignar triangulos
   triangulos.clear();
   triangulos = auxTriangles;
}


/**
*  Rotación de un punto en el eje x
*/
_vertex3f ObjectRevolution::rotateX(_vertex3f punto, float degree) {
    _vertex3f point;

    point.x = punto.x;
    point.y = cos(degree) * punto.y - sin(degree) * punto.z;
    point.z = sin(degree) * punto.y + cos(degree) * punto.z;

    return point;
}

/**
*  Rotación de un punto en el eje y
*/
_vertex3f ObjectRevolution::rotateY(_vertex3f punto, float degree) {
    _vertex3f point;

    point.x = cos(degree) * punto.x + sin(degree) * punto.z;
    point.y = punto.y;
    point.z = -sin(degree) * punto.x + cos(degree) * punto.z;

    return point;
}

/**
*  Rotación de un punto en el eje z
*/
_vertex3f ObjectRevolution::rotateZ(_vertex3f punto, float degree) {
    _vertex3f point;

    point.x = cos(degree) * punto.x - sin(degree) * punto.y;
    point.y = sin(degree) * punto.x + cos(degree) * punto.y;
    point.z = punto.z;

    return point;
}

/**
*  Copia de un Objeto Revolución en this
*/
void ObjectRevolution::copyObjectRevolution(ObjectRevolution other) {
   degrees = other.degrees;
   profile.clear();
   profile = other.getProfile();
   puntos.clear();
   puntos = other.getPuntos();
   triangulos.clear();
   triangulos = other.getTriangulos();
}
