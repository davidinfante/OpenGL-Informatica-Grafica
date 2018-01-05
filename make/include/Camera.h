/*
###########################
Diseñado por: David Infante Casas
###########################
*/

#ifndef CAMERA_H
#define CAMERA_H

class Camera {
   private:
      GLfloat Observer_distance;
      GLfloat Observer_angle_x;
      GLfloat Observer_angle_y;
      GLfloat Observer_position; //Posición para moverse a izquierda y derecha

   public:
      Camera (GLfloat OObserver_distance, GLfloat OObserver_angle_x, GLfloat OObserver_angle_y) {
         Observer_distance = OObserver_distance;
         Observer_angle_x = OObserver_angle_x;
         Observer_angle_y = OObserver_angle_y;
         Observer_position = 0;
      }

      GLfloat getObserver_distance() {
         return Observer_distance;
      }

      GLfloat getObserver_angle_x() {
         return Observer_angle_x;
      }

      GLfloat getObserver_angle_y() {
         return Observer_angle_y;
      }

      void setObserver_distance(GLfloat ob_dis) {
         Observer_distance = ob_dis;
      }

      void setObserver_angle_x(GLfloat ob_x) {
         Observer_angle_x = ob_x;
      }

      void setObserver_angle_y(GLfloat ob_y) {
         Observer_angle_y = ob_y;
      }

      void aumentarObserver_distance() {
         Observer_distance*=1.2;
      }

      void disminuirObserver_distance() {
         Observer_distance/=1.2;
      }

      void aumentarObserver_angle_x() {
         Observer_angle_x++;
      }

      void disminuirObserver_angle_x() {
         Observer_angle_x--;
      }

      void aumentarObserver_angle_y() {
         Observer_angle_y++;
      }

      void disminuirObserver_angle_y() {
         Observer_angle_y--;
      }

      void aumentarObserver_position() {
         Observer_position++;
      }

      void disminuirObserver_position() {
         Observer_position--;
      }

      void girar(int x, int y, int x_mouse, int y_mouse) {
         GLfloat yn, xn;
         yn = Observer_angle_x + (y - y_mouse);
         xn = Observer_angle_y + (x - x_mouse);
         Observer_angle_y = xn;
         Observer_angle_x = yn;
      }

      void setObservador() {
         glTranslatef(Observer_position, 0, -1 * Observer_distance);
         glRotatef(Observer_angle_x, 1, 0, 0);
         glRotatef(Observer_angle_y, 0, 1, 0);
      }

};
#endif
