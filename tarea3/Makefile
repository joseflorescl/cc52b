LETRAS3D = 
# si quieres usar letras tridimensionales
# quita el comentario a la linea siguiente
LETRAS3D = -DHERSH

CFLAGS  = -I/usr/local/include/X11 -I/usr/local/include  $(LETRAS3D) 
LDFLAGS = -L/usr/local/lib/  
LIBS = -lvogl -lhershey -lX11  -lm 


tarea3 : tarea3.o traslaciones.o rotaciones.o administracion.o tarea3.h
	gcc $(CFLAGS) -o tarea3 tarea3.o traslaciones.o rotaciones.o administracion.o $(LDFLAGS) $(LIBS)
traslaciones.o : traslaciones.c tarea3.h 
	gcc $(CFLAGS) -c traslaciones.c -o traslaciones.o
rotaciones.o : rotaciones.c tarea3.h
	gcc $(CFLAGS) -c rotaciones.c -o rotaciones.o
administracion.o : administracion.c tarea3.h
	gcc $(CFLAGS) -c administracion.c -o administracion.o
tarea3.o : tarea3.c tarea3.h
	gcc $(CFLAGS) -c tarea3.c 
