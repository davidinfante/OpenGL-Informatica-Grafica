# OpenGL-Informatica-Grafica

### Autor: David Infante Casas
### Grupo: 3ro. C, grupo de prácticas C1
### Fecha: 2/1/2018


## Indice:
- Instrucciones de compilación
- Instrucciones de uso
- Explicación de ficheros y organización de carpetas


## Instrucciones de compilación:

### *** ES NECESARIO TENER INSTALADO MAGIC PARA CARGAR TEXTURAS ***  
`sudo apt-get install magic`
### *** EN CASO DE NO COMPILAR AUN ASÍ, INSTALAR IMAGEMAGICK ***  
`sudo apt-get install imagemagick`

1.- Descomprimir el archivo: Practica_IG_David_Infante_Casas.zip  
2.- Acceder con la terminal al directorio make descomprimido y utilizar el comando make para compilar el proyecto.   
3.- Ejecutar el ejecutable "main" creado en el directorio make/bin


## Instrucciones de uso:

### *** Instrucciones básicas ***
- tecla q: cerrar el programa

### *** Cámaras ***
- click derecho del ratón (mantener) + mover el ratón: mirar con la cámara (no funciona en la cámara ortogonal)
- teclas flechas direccionales: mirar con la cámara

- teclas Inicio/Fin: aumentar y disminuir el zoom en la escena (mover la cámara hacia delante y hacia atrás)
- tecla Av Pag: mover cámara hacia la derecha
- tecla Supr (Suprimir/Delete): mover cámara hacia la izquierda

- tecla F4: activar cámara 0 (frente)
- tecla F5: activar cámara 1 (perfil)
- tecla F6: activar cámara 2 (ortogonal)

- tecla u/U: zoom de la cámara ortogonal

### *** Selección de objetos ***
- click izquierdo del ratón: selección de un objeto (funcional con las distintas partes del modelo 
   jerárquico (robot, tecla 6), al clicar sobre una de las nueve partes del robot (cabeza, cuerpo, cuerpo extensible,
   ojos, piernas, pies), esta cambiará de color y se mostrará en la terminal sobre qué se ha clicado).
   Haga click de nuevo para deshacer el cambio de color.

### *** Modos de visualización ***
- tecla z: modo puntos
- tecla x: Modo aristas
- tecla c: modo sólido
- tecla v: modo ajedrez
- tecla b: modo iluminación plana (requiere material o se ve negro)
- tecla n: modo iluminación suave (requiere material o se ve negro)

### *** Materiales ***
- tecla F1: material esmeralda
- tecla F2: material rubí
- tecla F3: material oro

### *** Figuras ***
- tecla 1: tetraedro
- tecla 2: cubo
- tecla 3: icosaedro
- tecla 4: modelo PLY (modelo hormiga "ant.ply" cargado por defecto)
- tecla 5: perfil PLY para revolución (perfil de un peón cargado por defecto)
- tecla 6: modelo jerárquico (Robot)
- tecla 7: tablero con textura (textura "logo.jpg" cargada por defecto)

### *** Movimientos de los modelados ***
- tecla a: aumentar el número de revoluciones del objeto revolución
- tecla A: disminuir el número de revoluciones del objeto revolución

- tecla s: rotar la cabeza del robot hacia su derecha (esta tecla detiene la animación por defecto del robot, y pulsar otra tecla reactiva la animación)
- tecla S: rotar la cabeza del robot hacia su izquierda (esta tecla detiene la animación por defecto del robot, y pulsar otra tecla reactiva la animación)
- tecla d: rotar las piernas del robot en un sentido (esta tecla detiene la animación por defecto del robot, y pulsar otra tecla reactiva la animación)
- tecla D: rotar las piernas del robot en el otro sentido (esta tecla detiene la animación por defecto del robot, y pulsar otra tecla reactiva la animación)
- tecla f: trasladar el cuello y cabeza del robot hacia abajo (esta tecla detiene la animación por defecto del robot, y pulsar otra tecla reactiva la animación)
- tecla F: trasladar el cuello y cabeza del robot hacia arriba (esta tecla detiene la animación por defecto del robot, y pulsar otra tecla reactiva la animación)
(Cualquier otra tecla diferente a s/S, d/D y f/F reactivará la animación del Robot)
- tecla g: disminuir velocidad de la cabeza del robot
- tecla G: aumentar velocidad de la cabeza del robot
- tecla h: disminuir velocidad de los pies del robot
- tecla H: aumentar velocidad de los pies del robot
- tecla j: disminuir velocidad del cuello del robot
- tecla J: aumentar velocidad del cuello del robot

- tecla w/W: mover la luz_1 en el eje x
- tecla e/E: mover la luz_1 en el eje y
- tecla r/R: mover la luz_1 en el eje z
- tecla t/T: mover la luz_1 en círculos sobre el eje y
- tecla y/Y: mover la luz_1 en círculos sobre el eje x

- tecla m: mover la textura del tablero a la derecha
- tecla M: mover la textura del tablero a la izquierda
- tecla k: rotar la textura del tablero en sentido antihorario (0, 90, 180 y 270 grados)
- tecla K: rotar la textura del tablero en sentido horario (0, 90, 180 y 270 grados)


## Explicación de ficheros y organización de carpetas:

### *** ./Grafo_Jerarquico.PNG ***
Imagen que muestra el grafo para el objeto jerárquico (Robot)

### *** ./make ***
Directorio raíz del programa
- Makefile: fichero makefile para compilar el programa automáticamente (Funciones make y make clean)

### *** ./make/bin ***
Carpeta que almacena el archivo ejecutable "main"
- foo: este fichero evita el borrado de esta carpeta durante la compresión del proyecto

### *** ./make/lib ***
Carpeta que almacena las librerías creadas
- foo: este fichero evita el borrado de esta carpeta durante la compresión del proyecto

### *** ./make/obj ***
Carpeta que almacena los ficheros .o
- foo: este fichero evita el borrado de esta carpeta durante la compresión del proyecto

### *** ./make/textures ***
Carpeta que almacena texturas en formato de imagen
- logo.jpg: textura por defecto que se usa para probar el programa

### *** ./make/models ***
Carpeta que almacena archivos .ply para su dibujado en el programa
- ant.ply: hormiga
- beethoven.ply: busto de Beethoven
- cylinder_rev.ply: cilindro para revolucionar
- peon_rev.ply: peón para revolucionar sobre el eje y
- peon_revx.ply: peón para revolucionar sobre el eje x
- sphere.ply: esfera

### *** ./make/include ***
- Camera.h: clase que construye una cámara para observar la escena
- CImg.h: fichero para poder leer archivos de tipo imagen en C
- Cubo3D.h: clase que construye un Cubo en 3D
- ejes.h: clase ejes para su dibujado en la escena
- escena.h: clase escena que contiene los elementos necesarios para su creación y el bucle de funciones que OpenGL ejecuta
- file_ply_stl.h: fichero para poder leer archivos de tipo ply
- Icosaedro3D.h: clase que construye un icosaedro en 3D (falla en los modos de visualización con iluminación porque las caras no están bien puestas)
- Light.h: clase que construye una luz para iluminar modelados en OpenGL
- Materials.h: clase que contiene 3 materiales de ejemplo
- Object3D.h: clase que construye un modelo en 3D, es básica para el resto de clases que construyen objetos3D
- ObjectJerarquico.h: clase que construye un modelo en 3D a partir de figuras simples, en este caso, construye un robot
- ObjectPly.h: clase que lee un fichero .ply y crea un Object3D a partir de él
- ObjectRevolution.h: clase que lee un perfil en un fichero .ply y lo revoluciona para formar un objeto en 3D
- `_`old_Point3D.h: (NO SE USA, USADO EN LA PRIMERA PRÁCTICA) clase para interpretar un punto en el espacio, ha sido sustituída por "vertex.h"
- `_`old_Triangle.h: (NO SE USA, USADO EN LA PRIMERA PRÁCTICA) clase para interpretar una cara en el espacio, ha sido sustituída por "vertex.h"
- Tetraedro3D.h: clase que construye un Tetraedro en 3D
- Texture.h: clase que coloca una textura en el primer cuadrante (mirar el fichero para ver los tipos de aplicación de textura)
- vertex.h: fichero que contiene distintas estructuras de datos ideales para interpretar vértices, caras, colores, materiales...

### *** ./make/src ***
- ejes.cc: clase ejes para su dibujado en la escena
- escena.cc: clase escena que contiene los elementos necesarios para su creación y el bucle de funciones que OpenGL ejecuta
- file_ply_stl.cc: fichero para poder leer archivos de tipo ply
- Light.cc: clase que construye una luz para iluminar modelados en OpenGL
- main.cc: main del programa, se encarga de iniciar la ventana, asignar las funciones y comenzar el bucle de eventos
- Object3D.cc: clase que construye un modelo en 3D, es básica para el resto de clases que construyen objetos3D
- ObjectJerarquico.cc: clase que construye un modelo en 3D a partir de figuras simples, en este caso, construye un robot
- ObjectPly.cc: clase que lee un fichero .ply y crea un Object3D a partir de él
- ObjectRevolution.cc: clase que lee un perfil en un fichero .ply y lo revoluciona para formar un objeto en 3D
