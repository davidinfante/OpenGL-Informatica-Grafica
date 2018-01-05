#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include "ejes.h"

Ejes::Ejes(){
    axisSize = 1000;
}

void Ejes::changeAxisSize(float newSize) {
	axisSize = newSize;
	createArrayData();
}

void Ejes::draw(){
	drawBeginEnd();
}

void Ejes::createArrayData(){
	colorArray[0] = 1; colorArray[1] = 0; colorArray[2] = 0;
	colorArray[3] = 1; colorArray[4] = 0; colorArray[5] = 0;
	colorArray[6] = 0; colorArray[7] = 1; colorArray[8] = 0;
	colorArray[9] = 0; colorArray[10] = 1; colorArray[11] = 0;
	colorArray[12] = 0; colorArray[13] = 0; colorArray[14] = 1;
	colorArray[15] = 0; colorArray[16] = 0; colorArray[17] = 1;

	vertexArray[0] = -axisSize; vertexArray[1] = 0; vertexArray[2] = 0;
	vertexArray[3] = axisSize; vertexArray[4] = 0; vertexArray[5] = 0;
	vertexArray[6] = 0; vertexArray[7] = -axisSize; vertexArray[8] = 0;
	vertexArray[9] = 0; vertexArray[10] = axisSize; vertexArray[11] = 0;
	vertexArray[12] = 0; vertexArray[13] = 0; vertexArray[14] = -axisSize;
	vertexArray[15] = 0; vertexArray[16] = 0; vertexArray[17] = axisSize;
}

void Ejes::drawBeginEnd(){
glBegin(GL_LINES);
	// eje X, color rojo
	glColor3f(1,0,0);
	glVertex3f(-axisSize,0,0);
	glVertex3f(axisSize,0,0);
	// eje Y, color verde
	glColor3f(0,1,0);
	glVertex3f(0,-axisSize,0);
	glVertex3f(0,axisSize,0);
	// eje Z, color azul
	glColor3f(0,0,1);
	glVertex3f(0,0,-axisSize);
	glVertex3f(0,0,axisSize);
	glEnd();
}

void Ejes::drawArray(){
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertexArray );
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, colorArray );
	glDrawArrays( GL_LINES, 0, 6 ) ;
}
