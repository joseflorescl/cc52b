#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <math.h>
#include <vogl.h>
#include <vodevice.h>

#define TAM_ESP 15.0

#define AZUL1 101
#define AZUL13 113
#define COLOR0 120
#define COLOR1 121
#define COLOR2 122
#define COLOR3 123
#define COLOR4 124
#define COLOR5 YELLOW
#define COLOR6 126
#define COLOR7 127
#define COLOR8 128
#define COLOR9 129

#define TAM_PANT 500
#define MULTIPLO (int)(ceil(TAM_PANT/30.0))


#define SI 1
#define NO 0

#define CUBO         0
#define CUBO2        1 
#define DOBLE_CUBO   2
#define DOBLE_CUBO2  3 
#define TRIPLE_CUBO  4
#define SILLA        5
#define ELE          6
#define CUATRO_CUBOS 7
#define CRUZ         8
#define DOS_SILLAS   9
#define ESE          10
#define SILLON       11
#define SILLON_CHICO 12

#define NUMERO_DE_MUROS_EXIGIDOS 10


#define NUMERO_DE_NIVELES 12
#define FIG_NIVEL0  5
#define FIG_NIVEL1  8 
#define FIG_NIVEL2  11 
#define FIG_NIVEL3  13 
#define FIG_NIVEL4  5
#define FIG_NIVEL5  8 
#define FIG_NIVEL6  11 
#define FIG_NIVEL7  13 
#define FIG_NIVEL8  5
#define FIG_NIVEL9  8
#define FIG_NIVEL10  11
#define FIG_NIVEL11  13





#define CUBO_LINE 8
#define CUBO_FILL 9
#define BLOCK_OUT 10
#define RECT      11
#define JLFV      12

#define MAX_CUBOS 5


typedef struct casilla{
         int ocupado,color;
} casilla;

typedef struct cubo{
        int i,j,k;
} cubo;

typedef struct figura{
        cubo c[MAX_CUBOS];
        int FIGURA_ACTUAL;
        int numero_de_cubos;
} figura;         
        

typedef struct level{
        int figuras;
        float seg;
}level;
        


void colores();
void fondo();
void inicializar_espacio();
void dibujar_espacio();
void cubo_line();
void cubo_fill(int i,int j,int k);
void dibujar_cubo(int i,int j,int k,int TIPO_CUBO);
void dibujar_cubol(cubo c);
void dibujar_cubof(cubo c);
void dibujar_figura(int TIPO_FIGURA);
void dibujar_figurarot(int TIPO_FIGURA,int i,int j ,int k);
int traslacion_up(int TIPO_FIGURA);
int traslacion_down(int TIPO_FIGURA);
int traslacion_left(int TIPOI_FIGURA);
int traslacion_right(int TIPOI_FIGURA);
int traslacion_in(int TIPOI_FIGURA);
int traslacion_out(int TIPOI_FIGURA);
int rotacionx(int TIPO_FIGURA,int d);
int rotaciony(int TIPO_FIGURA,int d);
int rotacionz(int TIPO_FIGURA,int d);
int colorj(int j);
void inicializar_figura(int TIPO_FIGURA);
void incorporar_al_espacio(int TIPO_FIGURA);
int muro(int j);
void dibujar_espacio_ocupado(int j1,int j2);
int muros_llenos();
void sacar_muro_lleno_del_espacio(int m);
int cabe_figura(int TIPO_FIGURA);
void game_over();
int ring();
void inicializar_niveles();
void pantalla1();
void pantalla2();
void pantalla3();
void dibujar_block_out();
void rectangulo();
void dibujar_rectanguloj(int j);
void dibujar_columna_de_rectangulos();
void dibujar_level();
void dibujar_nivel(int nivel);
void dibujar_rectangulo_pantalla3();
void dibujar_score();
void dibujar_puntaje(int puntaje);
void dibujar_cubes_played();
void dibujar_cubos_jugados(int cubos_jugados);
void dibujar_username();
void dibujar_nombre();
void figura_llega_al_fondo();



figura Figura;
 
level Nivel[NUMERO_DE_NIVELES];

casilla Espacio[3][10][3];

int i0,jo,k0;/*centro de rotacion*/
int Muros_Llenos[10];
int Cubos_Jugados;
int Puntaje;
int nivel;
int Numero_de_Muros;
float nseg;
int figuras;
unsigned delta_t;
unsigned interval;
int Traslacion_In;
int caras;
