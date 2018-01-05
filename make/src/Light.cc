/*
###########################
Diseñado por: David Infante Casas
###########################
*/

#include "Light.h"

Light::Light(GLenum indice, float x, float y, float z, int alpha, int beta) {
   index = indice;
   x_light = x;
   y_light = y;
   z_light = z;
   alpha_light = alpha;
   beta_light = beta;
}

void Light::activar() {
   glEnable(index);
   col_ambiente = {1.0, 1.0, 1.0, 1.0};
   col_difuso = {1.0, 1.0, 1.0, 1.0};
   col_especular = {1.0, 1.0, 1.0, 1.0};
   GLfloat posicion[4] = {x_light, y_light, z_light, 1.0};
   ObjectPly sun("models/sphere.ply");
   

	glLightfv(index, GL_AMBIENT, (GLfloat *) &col_ambiente);
   glLightfv(index, GL_DIFFUSE, (GLfloat *) &col_difuso);	
   glLightfv(index, GL_SPECULAR, (GLfloat *) &col_especular);

    if (alpha_light > 360)
        alpha_light -= 360;
    if (alpha_light < -360)
        alpha_light += 360;      

    if (beta_light > 360)
        beta_light -= 360;
    if (beta_light < -360)
        beta_light += 360;

	glPushMatrix();
      glRotatef(alpha_light, 0, 1, 0);
		glRotatef(beta_light, 1, 0, 0);	
      glLightfv(index, GL_POSITION, (GLfloat *) &posicion);
	glPopMatrix();

   sun.invertirNormales();
   glPushMatrix();
      glTranslatef(x_light, y_light, z_light);
      glTranslatef(-x_light, -y_light, -z_light);
      glRotatef(alpha_light, 0, 1, 0);
		glRotatef(beta_light, 1, 0, 0);
      glTranslatef(x_light, y_light, z_light);

      glScalef(3.5, 3.5, 3.5);
      sun.draw_ajedrez();
   glPopMatrix();
}
