/*
###########################
Diseñado por: David Infante Casas
###########################
*/

#include "Object3D.h"

//Constructor con parametros
Object3D::Object3D(vector<_vertex3f> otro_p, vector<_vertex3i> otro_t) {
   if (otro_p.size() != 0) {
      puntos.resize((int) otro_p.size());
      for (unsigned int i = 0; i < otro_p.size(); ++i)
         puntos[i] = otro_p[i];
   }

   if (otro_t.size() != 0) {
      triangulos.resize((int) otro_t.size());
      for (unsigned int i = 0; i < otro_t.size(); ++i)
         triangulos[i] = otro_t[i];
   }
   
   normales_triangulos.clear();
   normales_vertices.clear();
   b_normales_triangulos = false;
   b_normales_vertices = false;
}

//Calculo de normales en las caras
void Object3D::calcular_normales_triangulos() {
   normales_triangulos.resize(triangulos.size());

   for (unsigned long i = 0; i < triangulos.size(); ++i) {
      _vertex3f a1 = puntos[triangulos[i].y] - puntos[triangulos[i].x];
      _vertex3f a2 = puntos[triangulos[i].z] - puntos[triangulos[i].x];
      _vertex3f n = a1.cross_product(a2);

      float m = sqrt(n.x*n.x + n.y*n.y + n.z*n.z);
      normales_triangulos[i] = _vertex3f(n.x/m,n.y/m,n.z/m);
   }
   b_normales_triangulos = true;
}

//Calculo de normales en los vertices
void Object3D::calcular_normales_vertices() {
   if (!b_normales_triangulos) calcular_normales_triangulos();

   normales_vertices.resize(puntos.size());

   for (unsigned long i = 0; i < triangulos.size(); ++i) {
      normales_vertices[triangulos[i].x] += normales_triangulos[i];
      normales_vertices[triangulos[i].y] += normales_triangulos[i];
      normales_vertices[triangulos[i].z] += normales_triangulos[i];
   }
   b_normales_vertices = true;
}

//Dibujado iluminación plana
void Object3D::draw_iluminacion_plana() {
   brillo = 60.0;

   if (!b_normales_triangulos) calcular_normales_triangulos();

   glEnable(GL_CULL_FACE);
      //glShadeModel(GL_FLAT);
      glShadeModel(GL_SMOOTH);
      glEnable(GL_LIGHTING);
         glEnable(GL_NORMALIZE);

         glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, (GLfloat *) &ambiente);
         glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, (GLfloat *) &difusa);
         glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, (GLfloat *) &especular);
         glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, (GLfloat *) &brillo);

         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         glBegin(GL_TRIANGLES);
            for (int i = 0; i < triangulos.size(); ++i) {
               glNormal3f(normales_triangulos[i].x, normales_triangulos[i].y, normales_triangulos[i].z);
               glVertex3f(puntos[triangulos[i].x].x, puntos[triangulos[i].x].y, puntos[triangulos[i].x].z);
               glVertex3f(puntos[triangulos[i].y].x, puntos[triangulos[i].y].y, puntos[triangulos[i].y].z);
               glVertex3f(puntos[triangulos[i].z].x, puntos[triangulos[i].z].y, puntos[triangulos[i].z].z);
            }
         glEnd();
      glDisable(GL_LIGHTING);
   glDisable(GL_CULL_FACE);
}

//Dibujado iluminación suave
void Object3D::draw_iluminacion_suave() {
   brillo = 60.0;

   if (!b_normales_vertices) calcular_normales_vertices();

   glEnable(GL_CULL_FACE);
      glShadeModel(GL_SMOOTH);
      glEnable(GL_LIGHTING);
         glEnable(GL_NORMALIZE);

         glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, (GLfloat *) &ambiente);
         glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, (GLfloat *) &difusa);
         glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, (GLfloat *) &especular);
         glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, (GLfloat *) &brillo);

         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         glBegin(GL_TRIANGLES);
            for (int i = 0; i < triangulos.size(); ++i) {
               glNormal3f(normales_vertices[triangulos[i].x].x, normales_vertices[triangulos[i].x].y, normales_vertices[triangulos[i].x].z);
               glVertex3f(puntos[triangulos[i].x].x, puntos[triangulos[i].x].y, puntos[triangulos[i].x].z);
               glNormal3f(normales_vertices[triangulos[i].y].x, normales_vertices[triangulos[i].x].y, normales_vertices[triangulos[i].x].z);
               glVertex3f(puntos[triangulos[i].y].x, puntos[triangulos[i].y].y, puntos[triangulos[i].y].z);
               glNormal3f(normales_vertices[triangulos[i].z].x, normales_vertices[triangulos[i].x].y, normales_vertices[triangulos[i].x].z);
               glVertex3f(puntos[triangulos[i].z].x, puntos[triangulos[i].z].y, puntos[triangulos[i].z].z);
            }
         glEnd();
      glDisable(GL_LIGHTING);
   glDisable(GL_CULL_FACE);
}

//Dibujado de los puntos de una figura
void Object3D::draw_puntos(){
   glBegin(GL_POINTS);
   glColor3f(color.x, color.y, color.z);
   for (unsigned int i = 0; i < puntos.size(); ++i) {
      glVertex3fv((GLfloat *) &puntos[i]);
   }
   glEnd();
}

//Dibujado de las aristas de una figura
void Object3D::draw_alambre(){
   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
   glBegin(GL_TRIANGLES);
   glColor3f(color.x, color.y, color.z);
   for (unsigned int i = 0; i < triangulos.size(); ++i) {
      glVertex3fv((GLfloat *) &puntos[triangulos[i].x]);
      glVertex3fv((GLfloat *) &puntos[triangulos[i].y]);
      glVertex3fv((GLfloat *) &puntos[triangulos[i].z]);
   }
   glEnd();
}

//Dibujado de una figura solida
void Object3D::draw_solido(){
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glBegin(GL_TRIANGLES);
   glColor3f(color.x, color.y, color.z);
   for (unsigned int i = 0; i < triangulos.size(); ++i) {
      glVertex3fv((GLfloat *) &puntos[triangulos[i].x]);
      glVertex3fv((GLfloat *) &puntos[triangulos[i].y]);
      glVertex3fv((GLfloat *) &puntos[triangulos[i].z]);
   }
   glEnd();
}

//Dibujado de una figura en ajedrez
void Object3D::draw_ajedrez(){
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glBegin(GL_TRIANGLES);
   for (unsigned int i = 0; i < triangulos.size(); ++i) {
      switch(i % 2) {
         case 0:
            glColor3f(1,0,0);
         break;
         case 1:
            glColor3f(0,1,0);
         break;
      }
      glVertex3fv((GLfloat *) &puntos[triangulos[i].x]);
      glVertex3fv((GLfloat *) &puntos[triangulos[i].y]);
      glVertex3fv((GLfloat *) &puntos[triangulos[i].z]);
   }
   glEnd();
}

