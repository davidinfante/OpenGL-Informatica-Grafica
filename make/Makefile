###########################
# Diseñado por: David Infante Casas
###########################
# fichero Makefile

all: bin/main

# nombre del fichero ejecutable
TARGETS= bin/main

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
LDFLAGS=  -lGLU -lGL -lglut

# definicion del compilador
CC = g++

obj/ejes.o:	src/ejes.cc include/ejes.h
	$(CC) -c -std=c++11 -o obj/ejes.o -Iinclude src/ejes.cc

obj/escena.o:	src/escena.cc include/escena.h
	$(CC) -c -std=c++11 -o obj/escena.o -g -Iinclude src/escena.cc

obj/Object3D.o:	src/Object3D.cc include/Object3D.h
	$(CC) -c -std=c++11 -o obj/Object3D.o -g -Iinclude src/Object3D.cc

obj/file_ply_stl.o:	src/file_ply_stl.cc include/file_ply_stl.h
	$(CC) -c -std=c++11 -o obj/file_ply_stl.o -g -Iinclude src/file_ply_stl.cc

obj/ObjectPly.o:	src/ObjectPly.cc include/ObjectPly.h
	$(CC) -c -std=c++11 -o obj/ObjectPly.o -g -Iinclude src/ObjectPly.cc

obj/ObjectRevolution.o:	src/ObjectRevolution.cc include/ObjectRevolution.h
	$(CC) -c -std=c++11 -o obj/ObjectRevolution.o -g -Iinclude src/ObjectRevolution.cc

obj/ObjectJerarquico.o:	src/ObjectJerarquico.cc include/ObjectJerarquico.h
	$(CC) -c -std=c++11 -o obj/ObjectJerarquico.o -g -Iinclude src/ObjectJerarquico.cc

obj/Light.o:	src/Light.cc include/Light.h
	$(CC) -c -std=c++11 -o obj/Light.o -g -Iinclude src/Light.cc

lib/libformas.a:	obj/ejes.o obj/escena.o obj/Object3D.o obj/file_ply_stl.o obj/ObjectPly.o obj/ObjectRevolution.o obj/ObjectJerarquico.o obj/Light.o
	ar rsv lib/libformas.a obj/ejes.o obj/escena.o obj/Object3D.o obj/file_ply_stl.o obj/ObjectPly.o obj/ObjectRevolution.o obj/ObjectJerarquico.o obj/Light.o

obj/main.o:	src/main.cc include/escena.h
	$(CC) -c -std=c++11 -o obj/main.o -g -Iinclude src/main.cc

$(TARGETS):	obj/main.o	lib/libformas.a
	$(CC)  -Llib/ -std=c++11 -O2 -o $(TARGETS) obj/main.o -lformas $(LDFLAGS) -L/usr/X11R6/lib/ -lGL -lGLU -lglut -lm -lX11 -lpthread

#############

clean:
	rm -f ./obj/*.o
	rm -f ./lib/*.a
	rm -f $(TARGETS)
