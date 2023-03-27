#include "tarea3.h"

main()
{
 short evento,theta; 
 int boton,n,i,j,d;
 
 float x,y,z;
  
 
 /*        Definiciones de Ventana (y otras yerbas) */


 prefsize((TAM_PANT/6)+TAM_PANT+(TAM_PANT/3),TAM_PANT);
 
 
 winopen("X B L O C K   O U T ");
 doublebuffer();

 colores();
 rectangulo();
 
 pantalla1();
 color(120 + 7);
 clear();
 dibujar_columna_de_rectangulos();
 dibujar_level();
 dibujar_nivel(1);
  
 pantalla3();
 color(BLACK);
 clear();
 dibujar_block_out();
 dibujar_rectangulo_pantalla3();
 dibujar_username();
 dibujar_nombre();
 dibujar_score();
 Puntaje=0;
 dibujar_puntaje(0);
 dibujar_cubes_played();
 Cubos_Jugados=0;
 dibujar_cubos_jugados(0);


 pantalla2();

 swapbuffers(); 
  
  
 unqdevice(INPUTCHANGE);
 
 
 qdevice(ESCKEY);
 qdevice(AKEY);
 qdevice(SKEY);
 qdevice(DKEY);
 
 qdevice(QKEY);
 qdevice(WKEY);
 qdevice(EKEY);
 
 qdevice(IKEY);
 qdevice(JKEY);
 qdevice(KKEY);
 qdevice(LKEY);
 
 qdevice(PKEY);
 qdevice(SPACEKEY); 
 qdevice(NKEY);
 
 qdevice(MKEY);
 
 while(qread(&evento)!=REDRAW)
                ;
 Numero_de_Muros=0;
 nivel=0;
 inicializar_niveles(); 
 nseg=Nivel[nivel].seg;
 figuras=Nivel[nivel].figuras;
 delta_t = 1000000*nseg;
 interval= delta_t;
 Traslacion_In=NO;
 signal(SIGALRM,ring);
 
 

 
 inicializar_espacio();
 fondo();
 dibujar_espacio();
 cubo_line();
 
 boton=!ESCKEY;
 
 srand((int)(time(NULL) + 2));

 Figura.FIGURA_ACTUAL=rand()%figuras;
 
 inicializar_figura(Figura.FIGURA_ACTUAL);
 
 pushmatrix();
  translate(-15.0,-50.0,-15.0); 
  dibujar_figura(Figura.FIGURA_ACTUAL);
  swapbuffers();
 popmatrix();
 
 ualarm(delta_t,interval);
 while(boton!=ESCKEY)
 {
 
  if(Traslacion_In==SI)
  {
   Traslacion_In=NO;
   if(traslacion_in(Figura.FIGURA_ACTUAL))
     {
      for(y=-5.0;y<=0.0;y+=5.0)
      {
       fondo();
       dibujar_espacio();
       pushmatrix();
       translate(-15.0,-50.0,-15.0);
       dibujar_espacio_ocupado(9,0);
        pushmatrix();
        translate(0.0,y,0.0);
        dibujar_figura(Figura.FIGURA_ACTUAL);
        popmatrix();
        swapbuffers();
       popmatrix();
      }
     } 
   else
     {
      figura_llega_al_fondo();
     } 
    ualarm(delta_t,interval);
  } 
  if(qtest())
  {
   boton=qread(&evento);
   boton=qread(&evento);
   Pausa_nunca_en_mi_vida_habia_usado_goto :
   switch(boton)
   {
    case IKEY :
     if(traslacion_up(Figura.FIGURA_ACTUAL))
     {
      for(z=-5.0;z<=0.0;z+=5.0)
      {
       fondo();
       dibujar_espacio();
       pushmatrix();
       translate(-15.0,-50.0,-15.0);
       dibujar_espacio_ocupado(9,0);
        pushmatrix();
        translate(0.0,0.0,z);
        dibujar_figura(Figura.FIGURA_ACTUAL);
        popmatrix();
        swapbuffers();
       popmatrix();
      } 
     } 
     break;
     
     
    case KKEY : 
     if(traslacion_down(Figura.FIGURA_ACTUAL))
     {
      for(z=5.0;z>=0.0;z-=5.0)
      {
       fondo();
       dibujar_espacio();
       pushmatrix();
       translate(-15.0,-50.0,-15.0);
       dibujar_espacio_ocupado(9,0);
        pushmatrix();
        translate(0.0,0.0,z);
        dibujar_figura(Figura.FIGURA_ACTUAL);
        popmatrix();
        swapbuffers();
       popmatrix();
      } 
     } 
     break;
     
    case JKEY : 
     if(traslacion_left(Figura.FIGURA_ACTUAL))
     {
      for(x=5.0;x>=0.0;x-=5.0)
      {
       fondo();
       dibujar_espacio();
       pushmatrix();
       translate(-15.0,-50.0,-15.0);
       dibujar_espacio_ocupado(9,0);
        pushmatrix();
        translate(x,0.0,0.0);
        dibujar_figura(Figura.FIGURA_ACTUAL);
        popmatrix();
        swapbuffers();
       popmatrix();
      } 
     } 
     break;
     
    case LKEY : 
     if(traslacion_right(Figura.FIGURA_ACTUAL))
     {
      for(x=-5.0;x<=0.0;x+=5.0)
      {
       fondo();
       dibujar_espacio();
       pushmatrix();
       translate(-15.0,-50.0,-15.0);
       dibujar_espacio_ocupado(9,0);   
        pushmatrix();
        translate(x,0.0,0.0);
        dibujar_figura(Figura.FIGURA_ACTUAL);
        popmatrix();
        swapbuffers();
       popmatrix();
      } 
     } 
     break;

    
    case MKEY : 
     if(traslacion_out(Figura.FIGURA_ACTUAL))
     {
      for(y=5.0;y>=0.0;y-=5.0)
      {
       fondo();
       dibujar_espacio();
       pushmatrix();
       translate(-15.0,-50.0,-15.0);
       dibujar_espacio_ocupado(9,0);
        pushmatrix();
        translate(0.0,y,0.0);
        dibujar_figura(Figura.FIGURA_ACTUAL);
        popmatrix();
        swapbuffers();
       popmatrix();
      } 
     } 
     break;
     
     
    case AKEY : 
    case QKEY :
     if(boton==AKEY)
      d=1;
     else
      d=-1; 
      
     if(rotacionx(Figura.FIGURA_ACTUAL,d))
     {
      for(theta=-450*d;(theta*d)<=0;theta+=(450*d))
      {
       fondo();
       dibujar_espacio();
       pushmatrix();
       translate(-15.0,-50.0,-15.0);
       dibujar_espacio_ocupado(9,0);
        pushmatrix();
        translate((float)(10*(i0+0.5)),(float)(10*(jo+0.5)),(float)(10*(k0+0.5)));
        rotate(theta,'x');

dibujar_figurarot(Figura.FIGURA_ACTUAL,-10*(i0+0.5),-10*(jo+0.5),-10*(k0+0.5));
        popmatrix();
        swapbuffers();
       popmatrix();
      } 
      
     } 
     break; 
    
      
    case EKEY : 
    case DKEY :
     if(boton==EKEY)
      d=1;
     else
      d=-1; 
     
     if(rotaciony(Figura.FIGURA_ACTUAL,d))
     {
      for(theta=-450*d;(theta*d)<=0;theta+=(450*d))
      {
       fondo();
       dibujar_espacio();
       pushmatrix();
       translate(-15.0,-50.0,-15.0);
       dibujar_espacio_ocupado(9,0);
        pushmatrix();
        translate((float)(10*(i0+0.5)),(float)(10*(jo+0.5)),(float)(10*(k0+0.5)));
        rotate(theta,'y');

dibujar_figurarot(Figura.FIGURA_ACTUAL,-10*(i0+0.5),-10*(jo+0.5),-10*(k0+0.5));
        popmatrix();
        swapbuffers();
       popmatrix();
      } 
      
     } 
     break;
    
    case WKEY :
    case SKEY :
     if(boton==WKEY)
      d=1;
     else
      d=-1; 
     if(rotacionz(Figura.FIGURA_ACTUAL,d))
     {
      for(theta=-450*d;(theta*d)<=0;theta+=(450*d))
      {
       fondo();
       dibujar_espacio();
       pushmatrix();
       translate(-15.0,-50.0,-15.0);
       dibujar_espacio_ocupado(9,0);
        pushmatrix();
        translate((float)(10*(i0+0.5)),(float)(10*(jo+0.5)),(float)(10*(k0+0.5)));
        rotate(theta,'z');

dibujar_figurarot(Figura.FIGURA_ACTUAL,-10*(i0+0.5),-10*(jo+0.5),-10*(k0+0.5));
        popmatrix();
        swapbuffers();
       popmatrix();
      } 
      
     } 
     break;
     
    case PKEY :
     ualarm(0,0);
     boton=qread(&evento);
     boton=qread(&evento);
     ualarm(delta_t,interval);
     goto Pausa_nunca_en_mi_vida_habia_usado_goto ;
     break;
       
    case SPACEKEY : 
     ualarm(0,0);
     while(traslacion_in(Figura.FIGURA_ACTUAL))
     {
      fondo();
      dibujar_espacio();
      pushmatrix();
      translate(-15.0,-50.0,-15.0);
      dibujar_espacio_ocupado(9,0);
      dibujar_figura(Figura.FIGURA_ACTUAL);
      swapbuffers();
      popmatrix();
     }  
     figura_llega_al_fondo();  
     ualarm(delta_t,interval);   
     qreset();
     break;
     
    case NKEY :
     ualarm(0,0);
     nivel=(nivel+1)%(NUMERO_DE_NIVELES);
     Numero_de_Muros=0;
     pantalla1();
     dibujar_nivel(nivel+1);
     pantalla2();
     
     figuras=Nivel[nivel].figuras;
     nseg=Nivel[nivel].seg;
     srand(time(NULL)+2);
     Figura.FIGURA_ACTUAL=rand()%figuras;     
     fondo();
     inicializar_espacio();
     pantalla1();
     dibujar_columna_de_rectangulos();
     pantalla2();
     inicializar_figura(Figura.FIGURA_ACTUAL);
     dibujar_espacio();
     pushmatrix();
     translate(-15.0,-50.0,-15.0);
     dibujar_figura(Figura.FIGURA_ACTUAL);
     swapbuffers();
     popmatrix();
     delta_t=1000000*nseg;
     interval=delta_t;
     ualarm(delta_t,interval); 
     break;
      
   }  
  }    
 }

 gexit();
}
