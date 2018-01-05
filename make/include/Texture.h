/*
###########################
Diseñado por: David Infante Casas
###########################
*/

#ifndef TEXTURE_H
#define TEXTURE_H

#include "stdlib.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string>

#include "CImg.h"
using namespace cimg_library;

class Texture {
   private:
      GLuint textura_id;
      std::vector<unsigned char> data;
      CImg<unsigned char> texture;

   public:
      int i_desp;
      int giro;

      Texture (const char *const filename) {
         i_desp = 0;
         giro = 0;
         texture.load(filename);

         for (long i = 0; i < texture.height(); ++i)
            for (long j = 0; j < texture.width(); ++j) {
               unsigned char *r = texture.data(j, i, 0, 0);
               unsigned char *g = texture.data(j, i, 0, 1);
               unsigned char *b = texture.data(j, i, 0, 2);
               data.push_back(*r);
               data.push_back(*g);
               data.push_back(*b);
            }

         glGenTextures(1, &textura_id);
      }

      //Draw textura sobre el tablero
      void newTexture(float lado, int n) {
         int desp;
         if (i_desp > n) i_desp = n;
         else if (i_desp < 0) i_desp = 0;
         desp = i_desp;

         glEnable(GL_TEXTURE_2D);
         glActiveTexture(GL_TEXTURE0);
         glBindTexture(GL_TEXTURE_2D, textura_id);

         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

         glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture.width(), texture.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, &data[0]);

         glColor3f(1, 1, 1);

         /**
         *  Quitar el comentario del tipo de aplicación de
         *  textura que se quiera usar y comentar el otro tipo
         */

         //Tipo 1 de aplicación de textura
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         for (int i = 0; i < n; ++i) {
            desp = i_desp;
            for (int j = 0; j < n; ++j) {
               if (desp == n) desp = 0;
               glBegin(GL_POLYGON);
                  if (giro == 0) glTexCoord2d(desp/(1.0*n), (n-i)/(1.0*n));
                  else if (giro == 1) glTexCoord2d((n+i)/(1.0*n), desp/(1.0*n));
                  else if (giro == 2) glTexCoord2d(-desp/(1.0*n), (-n+i)/(1.0*n));
                  else if (giro == 3) glTexCoord2d((-n-i)/(1.0*n), -desp/(1.0*n));
                  glVertex3f(j*lado/(1.0*n), i*lado/(1.0*n), 0.0);
                  glVertex3f((j+1)*lado/(1.0*n), i*lado/(1.0*n), 0.0);
                  glVertex3f((j+1)*lado/(1.0*n), (i+1)*lado/(1.0*n), 0.0);
                  glVertex3f(j*lado/(1.0*n), (i+1)*lado/(1.0*n), 0.0);
               glEnd();
               ++desp;
            }
         }

         //Tipo 2 de aplicación de textura
         /*glBegin(GL_QUADS);
            glTexCoord2f(0,0);         glVertex3f(0,100,0);
            glTexCoord2f(1,0);         glVertex3f(100,100,0);
            glTexCoord2f(1,1);         glVertex3f(0,0,0);
            glTexCoord2f(0,1);         glVertex3f(100,0,0);
         glEnd();
         
         glBindTexture(GL_TEXTURE_2D, 0);
         glDisable(GL_TEXTURE_2D);*/

      }
};

#endif
