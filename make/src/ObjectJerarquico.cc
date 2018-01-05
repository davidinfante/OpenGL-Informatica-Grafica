/*
###########################
Diseñado por: David Infante Casas
###########################
*/

#include "ObjectJerarquico.h"

ObjectJerarquico::ObjectJerarquico() {

   puntos = false;
   alambre = false;
   solido = true;
   ajedrez = false;
   iluminacion_plana = false;
   iluminacion_suave = false;

   ObjectRevolution cyl("models/cylinder_rev.ply", 'y');
   ObjectPly sph("models/sphere.ply");
   Cubo3D cube(5);
   _cuerpo.copyObjectRevolution(cyl);
   _cuerpo_extensible.copyObjectRevolution(cyl);
   _cabeza.copyObjectPly(sph);
   _piernaizq.copyObjectRevolution(cyl);
   _piernadch.copyObjectRevolution(cyl);
   _pieizq.copyCubo3D(cube);
   _piedch.copyCubo3D(cube);
   _ojoizq.copyObjectRevolution(cyl);
   _ojodch.copyObjectRevolution(cyl);

   move_head = 0;
   move_feet = 0;
   move_neck = 0;

   bool_move_head = true;
   bool_move_feet = true;
   bool_move_neck = true;

   speed_head = 0;
   speed_feet = 0;
   speed_neck = 0;

}

void ObjectJerarquico::cuerpo(int parte_seleccionada) {
	glPushMatrix();

		if (parte_seleccionada == 0)
         _cuerpo.setColor(0.8431372, 0.8431372, 0.6392156862);
      else _cuerpo.setColor(0.0, 1.0, 0.0);

      glScalef(2.1, 2, 2.1);

		if (puntos) _cuerpo.draw_puntos();
      else if (alambre) _cuerpo.draw_alambre();
      else if (solido) _cuerpo.draw_solido();
      else if (ajedrez) _cuerpo.draw_ajedrez();
      else if (iluminacion_plana) _cuerpo.draw_iluminacion_plana();
      else if (iluminacion_suave) _cuerpo.draw_iluminacion_suave();

	glPopMatrix();
}

void ObjectJerarquico::cuerpo_extensible(int parte_seleccionada) {
	glPushMatrix();

      if (parte_seleccionada == 0)
         _cuerpo_extensible.setColor(0.8431372, 0.8431372, 0.6392156862);
      else _cuerpo_extensible.setColor(0.0, 1.0, 0.0);

      glScalef(2.0, 1.9, 2.0);

		if (puntos) _cuerpo_extensible.draw_puntos();
      else if (alambre) _cuerpo_extensible.draw_alambre();
      else if (solido) _cuerpo_extensible.draw_solido();
      else if (ajedrez) _cuerpo_extensible.draw_ajedrez();
      else if (iluminacion_plana) _cuerpo_extensible.draw_iluminacion_plana();
      else if (iluminacion_suave) _cuerpo_extensible.draw_iluminacion_suave();

	glPopMatrix();
}

void ObjectJerarquico::cabeza(int parte_seleccionada) {
	glPushMatrix();

      if (parte_seleccionada == 0)
         _cabeza.setColor(0.749019, 0.749019, 0.635294117);
      else _cabeza.setColor(0.0, 1.0, 0.0);

      glTranslatef(0.0, 20.0, 8.0);
      glScalef(18.5, 18.5, 18.5);

		if (puntos) _cabeza.draw_puntos();
      else if (alambre) _cabeza.draw_alambre();
      else if (solido) _cabeza.draw_solido();
      else if (ajedrez) _cabeza.draw_ajedrez();
      else if (iluminacion_plana) _cabeza.draw_iluminacion_plana();
      else if (iluminacion_suave) _cabeza.draw_iluminacion_suave();

	glPopMatrix();
}

void ObjectJerarquico::piernaizq(int parte_seleccionada) {
	glPushMatrix();

      if (parte_seleccionada == 0)
         _piernaizq.setColor(0.749019, 0.749019, 0.635294117);
      else _piernaizq.setColor(0.0, 1.0, 0.0);

      glTranslatef(-10.0, -37.0, 0.0);
      glScalef(0.3, 0.7, 0.3);

		if (puntos) _piernaizq.draw_puntos();
      else if (alambre) _piernaizq.draw_alambre();
      else if (solido) _piernaizq.draw_solido();
      else if (ajedrez) _piernaizq.draw_ajedrez();
      else if (iluminacion_plana) _piernaizq.draw_iluminacion_plana();
      else if (iluminacion_suave) _piernaizq.draw_iluminacion_suave();

	glPopMatrix();
}

void ObjectJerarquico::piernadch(int parte_seleccionada) {
	glPushMatrix();

      if (parte_seleccionada == 0)
         _piernadch.setColor(0.749019, 0.749019, 0.635294117);
      else _piernadch.setColor(0.0, 1.0, 0.0);

      glTranslatef(10.0, -37.0, 0.0);
      glScalef(0.3, 0.7, 0.3);

		if (puntos) _piernadch.draw_puntos();
      else if (alambre) _piernadch.draw_alambre();
      else if (solido) _piernadch.draw_solido();
      else if (ajedrez) _piernadch.draw_ajedrez();
      else if (iluminacion_plana) _piernadch.draw_iluminacion_plana();
      else if (iluminacion_suave) _piernadch.draw_iluminacion_suave();

	glPopMatrix();
}

void ObjectJerarquico::pieizq(int parte_seleccionada) {
	glPushMatrix();

      if (parte_seleccionada == 0)
         _pieizq.setColor(0.8431372, 0.8431372, 0.6392156862);
      else _pieizq.setColor(0.0, 1.0, 0.0);

      glTranslatef(-11.0, -48.0, 0.0);
      glScalef(1.5, 0.1, 2.5);

		if (puntos) _pieizq.draw_puntos();
      else if (alambre) _pieizq.draw_alambre();
      else if (solido) _pieizq.draw_solido();
      else if (ajedrez) _pieizq.draw_ajedrez();
      else if (iluminacion_plana) _pieizq.draw_iluminacion_plana();
      else if (iluminacion_suave) _pieizq.draw_iluminacion_suave();

	glPopMatrix();
}

void ObjectJerarquico::piedch(int parte_seleccionada) {
	glPushMatrix();

      if (parte_seleccionada == 0)
         _piedch.setColor(0.8431372, 0.8431372, 0.6392156862);
      else _piedch.setColor(0.0, 1.0, 0.0);

      glTranslatef(11.0, -48.0, 0.0);
      glScalef(1.5, 0.1, 2.5);

		if (puntos) _piedch.draw_puntos();
      else if (alambre) _piedch.draw_alambre();
      else if (solido) _piedch.draw_solido();
      else if (ajedrez) _piedch.draw_ajedrez();
      else if (iluminacion_plana) _piedch.draw_iluminacion_plana();
      else if (iluminacion_suave) _piedch.draw_iluminacion_suave();

	glPopMatrix();
}

void ObjectJerarquico::ojoizq(int parte_seleccionada) {
	glPushMatrix();

      if (parte_seleccionada == 0)
         _ojoizq.setColor(0.949019607, 0.949019607, 0.4745098);
      else _ojoizq.setColor(0.0, 1.0, 0.0);

      glTranslatef(-5.0, 25.0, 25.0);
      glRotatef(80.0, 1.0, 0.0, 0.0);
      glScalef(0.3, 0.05, 0.3);

		if (puntos) _ojoizq.draw_puntos();
      else if (alambre) _ojoizq.draw_alambre();
      else if (solido) _ojoizq.draw_solido();
      else if (ajedrez) _ojoizq.draw_ajedrez();
      else if (iluminacion_plana) _ojoizq.draw_iluminacion_plana();
      else if (iluminacion_suave) _ojoizq.draw_iluminacion_suave();

	glPopMatrix();
}

void ObjectJerarquico::ojodch(int parte_seleccionada) {
	glPushMatrix();

      if (parte_seleccionada == 0)
         _ojodch.setColor(0.949019607, 0.949019607, 0.4745098);
      else _ojodch.setColor(0.0, 1.0, 0.0);

      glTranslatef(5.0, 25.0, 25.0);
      glRotatef(80.0, 1.0, 0.0, 0.0);
      glScalef(0.3, 0.05, 0.3);

		if (puntos) _ojodch.draw_puntos();
      else if (alambre) _ojodch.draw_alambre();
      else if (solido) _ojodch.draw_solido();
      else if (ajedrez) _ojodch.draw_ajedrez();
      else if (iluminacion_plana) _ojodch.draw_iluminacion_plana();
      else if (iluminacion_suave) _ojodch.draw_iluminacion_suave();

	glPopMatrix();
}

void ObjectJerarquico::draw(int parte_seleccionada) {
   if (seleccion != 0) seleccion[parte_seleccionada-1] = !seleccion[parte_seleccionada-1];
   nombres(parte_seleccionada);

   glPushMatrix();
      glLoadName(1);
      if (seleccion[0]) cuerpo(1);
      else cuerpo(0);

      glPushMatrix();
         glRotatef(move_feet, 1.0, 0.0, 0.0);
         glLoadName(2);
         if (seleccion[1]) piernaizq(1);
         else piernaizq(0);
         glLoadName(3);
         if (seleccion[2]) pieizq(1);
         else pieizq(0);
      glPopMatrix();

      glPushMatrix();
         glRotatef(-move_feet, 1.0, 0.0, 0.0);
         glLoadName(4);
         if (seleccion[3]) piernadch(1);
         else piernadch(0);
         glLoadName(5);
         if (seleccion[4]) piedch(1);
         else piedch(0);
      glPopMatrix();

      glPushMatrix();
         glTranslatef(0.0, move_neck, 0.0);

         glPushMatrix();    
            glRotatef(move_head, 0.0, 1.0, 0.0);
            glLoadName(6);
            if (seleccion[5]) cabeza(1);
            else cabeza(0);
            glLoadName(7);
            if (seleccion[6]) ojoizq(1);
            else ojoizq(0);
            glLoadName(8);
            if (seleccion[7]) ojodch(1);
            else ojodch(0);
         glPopMatrix();

         glLoadName(9);
         if (seleccion[8]) cuerpo_extensible(1);
         else cuerpo_extensible(0);
      glPopMatrix();

	glPopMatrix();
}

void ObjectJerarquico::nombres(int parte_seleccionada) {
   if (parte_seleccionada-1 == 0) cout << "Has seleccionado el cuerpo" << endl;
   else if (parte_seleccionada-1 == 1) cout << "Has seleccionado la pierna izquierda" << endl;
   else if (parte_seleccionada-1 == 2) cout << "Has seleccionado el pie izquierdo" << endl;
   else if (parte_seleccionada-1 == 3) cout << "Has seleccionado la pierna derecha" << endl;
   else if (parte_seleccionada-1 == 4) cout << "Has seleccionado el pie derecho" << endl;
   else if (parte_seleccionada-1 == 5) cout << "Has seleccionado la cabeza" << endl;
   else if (parte_seleccionada-1 == 6) cout << "Has seleccionado el ojo izquierdo" << endl;
   else if (parte_seleccionada-1 == 7) cout << "Has seleccionado el ojo derecho" << endl;
   else if (parte_seleccionada-1 == 8) cout << "Has seleccionado el cuerpo extensible" << endl;
}

void ObjectJerarquico::IdleMovement() {
   if (move_head == -35 || move_head < -35) bool_move_head = false;
   if (move_head == 35 || move_head > 35) bool_move_head = true;
   if (move_feet == -20 || move_feet < -20) bool_move_feet = false;
   if (move_feet == 20 || move_feet > 20) bool_move_feet = true;
   if (move_neck == 0 || move_neck < 0) bool_move_neck = false;
   if (move_neck == 25 || move_neck > 25) bool_move_neck = true;

   if (bool_move_head) {--move_head; move_head -= speed_head;}
   if (!bool_move_head) {++move_head; move_head += speed_head;}
   if (bool_move_feet) {--move_feet; move_feet -= speed_feet;}
   if (!bool_move_feet) {++move_feet; move_feet += speed_feet;}
   if (bool_move_neck) {--move_neck; move_neck -= speed_neck;}
   if (!bool_move_neck) {++move_neck; move_neck += speed_neck;}
}

void ObjectJerarquico::Idle() {
   IdleMovement();
   glutPostRedisplay();
}

void ObjectJerarquico::setMaterial(vector<_vertex4f> material) {
   _cuerpo.setMaterial(material);
   _cuerpo_extensible.setMaterial(material);
   _cabeza.setMaterial(material);
   _piernaizq.setMaterial(material);
   _piernadch.setMaterial(material);
   _pieizq.setMaterial(material);
   _piedch.setMaterial(material);
   _ojoizq.setMaterial(material);
   _ojodch.setMaterial(material);
}
