#include "tarea3.h"

void colores()
{
 
 mapcolor(AZUL1,83,83,250);
 mapcolor(102,60,60,235); 
 mapcolor(103,40,40,215);
 mapcolor(104,35,35,195);
 mapcolor(105,30,30,175);
 mapcolor(106,25,25,155);
 mapcolor(107,20,20,135);
 mapcolor(108,15,15,115);
 mapcolor(109,10,10,95);
 mapcolor(110,7,7,75);
 mapcolor(111,4,4,55);
 mapcolor(112,2,2,40);
 mapcolor(AZUL13,1,1,30);
 
 mapcolor(COLOR0,255,10,10);
 mapcolor(COLOR1,255,80,30);
 mapcolor(COLOR2,255,70,70);
 mapcolor(COLOR3,132,31,43);
 mapcolor(COLOR4,226,157,113);
 
 mapcolor(COLOR6,30,200,30);
 mapcolor(COLOR7,90,90,255);
 mapcolor(COLOR8,128,128,255);
 mapcolor(COLOR9,6,6,146);
 } 

void fondo()
{
 int bottom,top;
 int i;

 bottom=TAM_PANT - MULTIPLO;
 top=TAM_PANT;
 
 for(i=AZUL1;i<=AZUL13;i++)
 {
  viewport((TAM_PANT/6),(TAM_PANT/6)+TAM_PANT,bottom,top);
  color(i);
  clear();
  bottom-=MULTIPLO;
  top-=MULTIPLO;
 }
 viewport((TAM_PANT/6),(TAM_PANT/6)+TAM_PANT,13*MULTIPLO,17*MULTIPLO);
 color(BLACK);
 clear();
 bottom=0;
 top=MULTIPLO;
 for(i=AZUL1;i<=AZUL13;i++)
 {
  viewport((TAM_PANT/6),(TAM_PANT/6)+TAM_PANT,bottom,top);
  color(i);
  clear();
  bottom+=MULTIPLO;
  top+=MULTIPLO;
 }
 viewport((TAM_PANT/6),(TAM_PANT/6)+TAM_PANT,0,TAM_PANT);
}     

 



void inicializar_espacio()
{
 int i,j,k;
 for(i=0;i<3;i++)
  for(j=0;j<10;j++)
   for(k=0;k<3;k++)
   { 
    Espacio[i][j][k].ocupado=NO;
    Espacio[i][j][k].color=colorj(j);
   } 
    
}

 


void dibujar_espacio()
{
 float y,z,x;
 color(GREEN);
 polymode(PYM_LINE);
 for(y=-50.0;y<=50.0;y+=10.0)
 {
  pmv(-TAM_ESP,y,-TAM_ESP);
   pdr(TAM_ESP,y,-TAM_ESP);
   pdr(TAM_ESP,y,TAM_ESP);
   pdr(-TAM_ESP,y,TAM_ESP);
  pclos();
 }
 for(z=-TAM_ESP;z<=TAM_ESP;z+=10.0)
 {
  move(-TAM_ESP,-50.0,z);
  draw(-TAM_ESP,50.0,z);
  move(TAM_ESP,-50.0,z);
  draw(TAM_ESP,50.0,z);
 } 
 for(x=-5.0;x<=5.0;x+=10.0)
 {
  move(x,-50.0,TAM_ESP);
  draw(x,50.0,TAM_ESP);
  move(x,-50.0,-TAM_ESP);
  draw(x,50.0,-TAM_ESP);
 }
 move(-5.0,50.0,TAM_ESP);
 draw(-5.0,50.0,-TAM_ESP);
 move(5.0,50.0,TAM_ESP);
 draw(5.0,50.0,-TAM_ESP);
 move(-TAM_ESP,50.0,5.0);
 draw(TAM_ESP,50.0,5.0);
 move(-TAM_ESP,50.0,-5.0);
 draw(TAM_ESP,50.0,-5.0);
 polymode(PYM_FILL);
}    

void cubo_line()
{
 makeobj(CUBO_LINE);
 /* el color DEBE estar predefinido*/
 polymode(PYM_LINE);
 linewidth(3);
 pmv(0.0,0.0,0.0);
  pdr(0.0,0.0,10.0);
  pdr(10.0,0.0,10.0);
  pdr(10.0,0.0,0.0);
 pclos();
 pmv(0.0,10.0,0.0);
  pdr(0.0,10.0,10.0);
  pdr(10.0,10.0,10.0);
  pdr(10.0,10.0,0.0);
 pclos();
 move(0.0,0.0,0.0);
 draw(0.0,10.0,0.0);
 move(10.0,0.0,0.0);
 draw(10.0,10.0,0.0);
 move(0.0,0.0,10.0);
 draw(0.0,10.0,10.0);
 move(10.0,0.0,10.0);
 draw(10.0,10.0,10.0);
 
 polymode(PYM_FILL);
 linewidth(1);
 closeobj();
}  
 
void cubo_fill(int icf,int jcf,int kcf)
{
 float i,j,k;
/*el color DEBE estar predefinido*/

 i=(float)(10*icf);
 j=(float)(10*jcf);
 k=(float)(10*kcf);
 
 

 if(kcf==2 && (Espacio[icf][jcf][1].ocupado==NO))
 {
  pmv(i,j,k);
   pdr(i,j+10.0,k);
   pdr(i+10.0,j+10.0,k);
   pdr(i+10.0,j,k);
  pclos();  
 }
 else if(kcf==0 && (Espacio[icf][jcf][1].ocupado==NO))
 {
  pmv(i,j,k+10.0);
   pdr(i,j+10.0,k+10.0);
   pdr(i+10.0,j+10.0,k+10.0);
   pdr(i+10.0,j,k+10.0);
  pclos(); 
 }
 
 if(icf==0 && (Espacio[1][jcf][kcf].ocupado==NO))
 {
  pmv(i+10.0,j,k);
   pdr(i+10.0,j,k+10.0);
   pdr(i+10.0,j+10.0,k+10.0);
   pdr(i+10.0,j+10.0,k);
  pclos();
 }   
 else if(icf==2 && (Espacio[1][jcf][kcf].ocupado==NO))
 {
  pmv(i,j,k);
   pdr(i,j,k+10.0);
   pdr(i,j+10.0,k+10.0);
   pdr(i,j+10.0,k);
  pclos(); 
 } 
 

 
 
 polymode(PYM_LINE);
 color(BLACK);
 
 if(jcf<5)
  linewidth(2);
  
 color(BLACK);



 if(kcf==2 && (Espacio[icf][jcf][1].ocupado==NO))
 {
  pmv(i,j,k);
   pdr(i,j+10.0,k);
   pdr(i+10.0,j+10.0,k);
   pdr(i+10.0,j,k);
  pclos();  
 }
 else if(kcf==0 && (Espacio[icf][jcf][1].ocupado==NO))
 {
  pmv(i,j,k+10.0);
   pdr(i,j+10.0,k+10.0);
   pdr(i+10.0,j+10.0,k+10.0);
   pdr(i+10.0,j,k+10.0);
  pclos(); 
 }
 
 if(icf==0 && (Espacio[1][jcf][kcf].ocupado==NO))
 {
  pmv(i+10.0,j,k);
   pdr(i+10.0,j,k+10.0);
   pdr(i+10.0,j+10.0,k+10.0);
   pdr(i+10.0,j+10.0,k);
  pclos();
 }   
 else if(icf==2 && (Espacio[1][jcf][kcf].ocupado==NO))
 {
  pmv(i,j,k);
   pdr(i,j,k+10.0);
   pdr(i,j+10.0,k+10.0);
   pdr(i,j+10.0,k);
  pclos(); 
 }
  
 /*cara del frente*/
 
 polymode(PYM_FILL);
 color(colorj(jcf));
 
 if( (jcf>0 && (Espacio[icf][jcf-1][kcf].ocupado==NO || caras==SI))||(jcf==0) )
 { 
  pmv(i,j,k);
   pdr(i,j,k+10.0);
   pdr(i+10.0,j,k+10.0);
   pdr(i+10.0,j,k);
  pclos();

 polymode(PYM_LINE);
 color(BLACK);
  
  pmv(i,j,k);
   pdr(i,j,k+10.0);
   pdr(i+10.0,j,k+10.0);
   pdr(i+10.0,j,k);
  pclos();
 }
 
 polymode(PYM_FILL);
 linewidth(1);


}    
  
  
void dibujar_cubo(int i,int j,int k,int TIPO_CUBO)
{
 /* TIPO_CUBO == CUBO_LINE o CUBO_FILL*/
 if(TIPO_CUBO==CUBO_LINE)
 {
  pushmatrix();
  translate((float)(10*i),(float)(10*j),(float)(10*k));
  color(WHITE);
  callobj(CUBO_LINE);
  popmatrix();
 }
 else 
 {
  color(Espacio[i][j][k].color);
  cubo_fill(i,j,k);
 }
}

void dibujar_cubol(cubo c)
{
 dibujar_cubo(c.i,c.j,c.k,CUBO_LINE);
}

void dibujar_cubof(cubo c)
{
 dibujar_cubo(c.i,c.j,c.k,CUBO_FILL); 
}

void dibujar_figura(int TIPO_FIGURA)
{
 int i,n;
 n=Figura.numero_de_cubos;
 for(i=0;i<n;i++)
  dibujar_cubol(Figura.c[i]);
}

void dibujar_figurarot(int TIPO_FIGURA,int i,int j,int k)
{
 pushmatrix();
 translate((float)i,(float)j,(float)k);
 dibujar_figura(TIPO_FIGURA);
 popmatrix();
}

 int colorj(int j)
{
 if(j==5)
  return YELLOW;
 return(j+120);
}
 
void inicializar_figura(int TIPO_FIGURA)
{
 switch(TIPO_FIGURA)
 {
  case CUBO :
  case CUBO2 :
   Figura.c[0].i=1;
   Figura.c[0].j=0;
   Figura.c[0].k=1;
   Figura.numero_de_cubos=1;
   break;
 
  case DOBLE_CUBO :
  case DOBLE_CUBO2 :
   Figura.c[1].i=1;
   Figura.c[1].j=0;
   Figura.c[1].k=1;
   Figura.c[0].i=2;
   Figura.c[0].j=0;
   Figura.c[0].k=1;
   Figura.numero_de_cubos=2;
   break;
   
  case TRIPLE_CUBO :
   Figura.c[1].i=0;
   Figura.c[1].j=0;
   Figura.c[1].k=1;
   Figura.c[0].i=1;
   Figura.c[0].j=0;
   Figura.c[0].k=1;
   Figura.c[2].i=2;
   Figura.c[2].j=0;
   Figura.c[2].k=1;
   Figura.numero_de_cubos=3;
   break; 
 
  case SILLON :
   Figura.c[1].i=0;
   Figura.c[1].j= 1;
   Figura.c[1].k=1;
   Figura.c[0].i=1;
   Figura.c[0].j= 1;
   Figura.c[0].k=1;
   Figura.c[2].i= 2;
   Figura.c[2].j=1;
   Figura.c[2].k=1;
   Figura.c[3].i= 2;
   Figura.c[3].j=1;
   Figura.c[3].k= 2;
   Figura.c[4].i=2;
   Figura.c[4].j=0;
   Figura.c[4].k= 1;
   Figura.numero_de_cubos=5;
   break;
 
 
  case CRUZ :
   Figura.c[1].i=0;
   Figura.c[1].j=0;
   Figura.c[1].k=1;
   Figura.c[0].i=1;
   Figura.c[0].j=0;
   Figura.c[0].k=1;
   Figura.c[2].i=2;
   Figura.c[2].j=0;
   Figura.c[2].k=1;
   Figura.c[3].i=1;
   Figura.c[3].j=0;
   Figura.c[3].k=2;
   Figura.c[4].i=1;
   Figura.c[4].j=0;
   Figura.c[4].k=0;
   Figura.numero_de_cubos=5;
   break;
 
  case SILLA :
   Figura.c[1].i=0;
   Figura.c[1].j=0;
   Figura.c[1].k=1;
   Figura.c[0].i=1;
   Figura.c[0].j=0;
   Figura.c[0].k=1;
   Figura.c[2].i=1;
   Figura.c[2].j=0;
   Figura.c[2].k=2;
   Figura.numero_de_cubos=3;
   break;  
 
  case CUATRO_CUBOS :
   Figura.c[1].i=0;
   Figura.c[1].j=0;
   Figura.c[1].k=2;
   Figura.c[0].i=0;
   Figura.c[0].j=0;
   Figura.c[0].k=1;
   Figura.c[2].i=1;
   Figura.c[2].j=0;
   Figura.c[2].k=2;
   Figura.c[3].i=1;
   Figura.c[3].j=0;
   Figura.c[3].k=1;
   Figura.numero_de_cubos=4;
   break;
 
  case DOS_SILLAS :
   Figura.c[1].i=0;
   Figura.c[1].j=0;
   Figura.c[1].k=1;
   Figura.c[0].i=1;
   Figura.c[0].j=0;
   Figura.c[0].k=1;
   Figura.c[2].i=2;
   Figura.c[2].j=0;
   Figura.c[2].k=1;
   Figura.c[3].i=1;
   Figura.c[3].j=0;
   Figura.c[3].k=2;
   Figura.numero_de_cubos=4;
   break;
  
  case ELE :
   Figura.c[1].i=1;
   Figura.c[1].j=0;
   Figura.c[1].k=2;
   Figura.c[0].i= 1; 
   Figura.c[0].j=0;
   Figura.c[0].k=1;
   Figura.c[2].i=1;
   Figura.c[2].j= 0;
   Figura.c[2].k=0;
   Figura.c[3].i=2;
   Figura.c[3].j=0;
   Figura.c[3].k= 0;
   Figura.numero_de_cubos=4;
   break;
   
  case ESE :
   Figura.c[1].i=0;
   Figura.c[1].j=0;
   Figura.c[1].k=1;
   Figura.c[0].i= 1; 
   Figura.c[0].j=0;
   Figura.c[0].k=1;
   Figura.c[2].i=1;
   Figura.c[2].j= 0;
   Figura.c[2].k=0;
   Figura.c[3].i=2;
   Figura.c[3].j=0;
   Figura.c[3].k= 0;
   Figura.numero_de_cubos=4;
   break ;
   
  case SILLON_CHICO :
   Figura.c[1].i=1;
   Figura.c[1].j=1;
   Figura.c[1].k=2;
   Figura.c[0].i=1;
   Figura.c[0].j=1;
   Figura.c[0].k=1;
   Figura.c[2].i=1;
   Figura.c[2].j=0;
   Figura.c[2].k=1;
   Figura.c[3].i=2;
   Figura.c[3].j=1;
   Figura.c[3].k=1;
   Figura.numero_de_cubos=4;
   break;
 }
} 

void incorporar_al_espacio(int TIPO_FIGURA)
{
 int i,n;
 n=Figura.numero_de_cubos;
 for(i=0;i<n;i++)
  Espacio[Figura.c[i].i][Figura.c[i].j][Figura.c[i].k].ocupado=SI;
} 
 
 
int muro(int j)
{
 int cubos_de_colores=0;
 int i,k;
 for(i=0;i<=2;i++)
  for(k=0;k<=2;k++)
   if(Espacio[i][j][k].ocupado==SI)
    cubos_de_colores++;
 return cubos_de_colores;   
}
 
 
void dibujar_espacio_ocupado(int j1,int j2)
{
 int i,j,k;
 cubo c;
 
 if(j1==9 && j2==0)
  /*no es necesario dibujar todas las caras */
  caras=NO;
 else 
  caras=SI; 
 
 for(j=j1;j>=j2 && muro(j)>0;j--)
 { 
  i=0;
  for(k=2;k>=0;k--)
   if(Espacio[i][j][k].ocupado==SI)
   {
    c.i=i;
    c.j=j;
    c.k=k;
    dibujar_cubof(c);
   } 
  i=2; 
  for(k=2;k>=0;k--)
   if(Espacio[i][j][k].ocupado==SI)
   {
    c.i=i;
    c.j=j;
    c.k=k;
    dibujar_cubof(c);
   }
   i=1;
   for(k=2;k>=0;k--)
   if(Espacio[i][j][k].ocupado==SI)
   {
    c.i=i;
    c.j=j;
    c.k=k;
    dibujar_cubof(c);
   }          
 }
} 
 
 
int muros_llenos()
{
 int muros_llen=0;
 int m,j;
 for(j=9;j>=0 && (m=muro(j))>0;j--)
  if(m==9)
   Muros_Llenos[muros_llen++]=j;
 return muros_llen;
}
    
 
void sacar_muro_lleno_del_espacio(int m)
{
 int i,j,k;

 if(m==0)
 {
  for(i=0;i<=2;i++)
   for(k=0;k<=2;k++)
    Espacio[i][0][k].ocupado=NO;
 }  
 else
 {
  for(j=m-1;j>=0 && muro(j)>0;j--)
   for(i=0;i<=2;i++)
    for(k=0;k<=2;k++)
     Espacio[i][j+1][k].ocupado=Espacio[i][j][k].ocupado;
  for(i=0;i<=2;i++)
   for(k=0;k<=2;k++)
    Espacio[i][j+1][k].ocupado=NO;
 }     
}

int cabe_figura(int TIPO_FIGURA)
{
 int i,n;
 n=Figura.numero_de_cubos;
 for(i=0;i<n;i++)
  if(Espacio[Figura.c[i].i][Figura.c[i].j][Figura.c[i].k].ocupado==NO)   
   continue;
  else
   return 0;
 return 1;
} 

void game_over()
{
 int boton;
 short evento;
 
 pushmatrix();
 translate(-10.0,-50.0,-15.0);
 rotate(450,'x');
 cmov(5.0,4.0,4.0);
 hfont("times.rb");
 hcentertext(1);
 htextsize(4.0,4.0);
 color(CYAN);
 hcharstr("GAME OVER");
 popmatrix();
 swapbuffers();
 while(boton!=ESCKEY)
 {
  boton=qread(&evento);
  boton=qread(&evento);
 }
 gexit();
 exit(1);
}

int ring()
{
 signal(SIGALRM,ring);
 Traslacion_In=SI;
}

void inicializar_niveles()
{
 int nivel;
 
 for(nivel=0;nivel<=3;nivel++)
  Nivel[nivel].seg=2.0;
 for(nivel=4;nivel<=7;nivel++)
  Nivel[nivel].seg=1.0;
 for(nivel=8;nivel<=11;nivel++)
  Nivel[nivel].seg=0.5;
  
 Nivel[0].figuras=FIG_NIVEL0;
 Nivel[1].figuras=FIG_NIVEL1;
 Nivel[2].figuras=FIG_NIVEL2;
 Nivel[3].figuras=FIG_NIVEL3;
 Nivel[4].figuras=FIG_NIVEL4;
 Nivel[5].figuras=FIG_NIVEL5;
 Nivel[6].figuras=FIG_NIVEL6;
 Nivel[7].figuras=FIG_NIVEL7;
 Nivel[8].figuras=FIG_NIVEL8;
 Nivel[9].figuras=FIG_NIVEL9;
 Nivel[10].figuras=FIG_NIVEL10;
 Nivel[11].figuras=FIG_NIVEL11;    
}

void pantalla1()
{
 viewport(0,TAM_PANT/6,0,TAM_PANT);
 ortho2(0.0,10.0,0.0,60.0);
}

void pantalla2()
{
 viewport((TAM_PANT/6),(TAM_PANT/6)+TAM_PANT,0,TAM_PANT);
 window(-TAM_ESP,TAM_ESP,-TAM_ESP,TAM_ESP,20.0,-50.0);
 lookat(0.0,-72.3,0.0,0.0,100.0,0.0,0); /*-72.3*/
}

void pantalla3()
{
 viewport((TAM_PANT/6)+TAM_PANT,(TAM_PANT/6)+TAM_PANT+(TAM_PANT/3),0,TAM_PANT);
 ortho2(0.0,20.0,0.0,60.0);
}

void dibujar_block_out()
{
 makeobj(BLOCK_OUT);
 /*letra B*/
 
 color(RED);
 pmv2(0.0,12.0);
  pdr2(3.5,12.0);
  pdr2(4.0,11.0);
  pdr2(4.0,9.0);
  pdr2(3.5,8.5);
  pdr2(4.0,8.0);
  pdr2(4.0,6.0);
  pdr2(3.5,5.0);
  pdr2(0.0,5.0);
  pdr2(0.0,6.0);
  pdr2(0.5,6.0);
  pdr2(0.5,11.0);
  pdr2(0.0,11.0);
 pclos();  
 
 color(BLACK);
 arcf(2.0,10.0,1.0,-900,900);
 arcf(2.0,7.0,1.0,-900,900);
 
 
 color(YELLOW);
 pmv2(0.5,8.0);
  pdr2(2.0,9.0);
  pdr2(4.0,9.5);
  pdr2(4.0,9.0);
  pdr2(2.0,8.0);
  pdr2(0.5,7.0);
 pclos(); 
 
 
 polymode(PYM_LINE);
 linewidth(3);
 
 color(WHITE);
 
 pmv2(0.0,12.0);
  pdr2(3.5,12.0);
  pdr2(4.0,11.0);
  pdr2(4.0,9.0);
  pdr2(3.5,8.5);
  pdr2(4.0,8.0);
  pdr2(4.0,6.0);
  pdr2(3.5,5.0);
  pdr2(0.0,5.0);
  pdr2(0.0,6.0);
  pdr2(0.5,6.0);
  pdr2(0.5,11.0);
  pdr2(0.0,11.0);
 pclos(); 
 
 arc(2.0,10.0,1.0,-900,900);
 arc(2.0,7.0,1.0,-900,900);
  
 move2(2.0,9.0);
 draw2(2.0,11.0);
 move2(2.0,6.0);
 draw2(2.0,8.0); 
 
 
 
 /*letra L */
 
 polymode(PYM_FILL);
 
 color(RED);
 pmv2(4.0,12.0);
  pdr2(6.0,12.0);
  pdr2(6.0,11.5);
  pdr2(5.5,11.0);
  pdr2(5.5,8.0);
  pdr2(6.0,8.0);
  pdr2(6.0,9.5);
  pdr2(7.0,9.5);
  pdr2(7.0,7.0);
  pdr2(4.0,7.0);
 pclos();
  
 color(YELLOW);
 
 pmv2(4.0,9.5);
  pdr2(5.5,10.0);
  pdr2(5.5,9.0);
  pdr2(4.0,8.5);
 pclos();
 
 pmv2(6.0,9.5);
  pdr2(7.0,9.5);
  pdr2(7.0,8.5);
  pdr2(6.0,8.5);
 pclos();
 
 polymode(PYM_LINE);
 color(WHITE);
 
  pmv2(4.0,12.0);
  pdr2(6.0,12.0);
  pdr2(6.0,11.5);
  pdr2(5.5,11.0);
  pdr2(5.5,8.0);
  pdr2(6.0,8.0);
  pdr2(6.0,9.5);
  pdr2(7.0,9.5);
  pdr2(7.0,7.0);
  pdr2(4.0,7.0);
 pclos();
 
   
 
 /* letra O */
 
 polymode(PYM_FILL);
 color(RED);
 
 pmv2(7.5,12.0);
  pdr2(9.5,12.0);
  pdr2(10.0,11.5);
  pdr2(10.0,7.5);
  pdr2(9.5,7.0);
  pdr2(7.5,7.0);
  pdr2(7.0,7.5);
  pdr2(7.0,11.5);
 pclos();
  
 color(BLACK);
 
 pmv2(8.5,11.0);
  pdr2(9.0,10.5);
  pdr2(9.0,8.5);
  pdr2(8.5,8.0);
  pdr2(8.0,8.5);
  pdr2(8.0,10.5);
 pclos();
 
 color(YELLOW);
 
 pmv2(7.0,10.0);
  pdr2(8.0,10.0);
  pdr2(8.0,9.0);
  pdr2(7.0,9.0);
 pclos();
 
 pmv2(9.0,10.0);
  pdr2(10.0,10.0);
  pdr2(10.0,9.0);
  pdr2(9.0,9.0);
 pclos();   
 
 polymode(PYM_LINE);
 color(WHITE);
 
 pmv2(7.5,12.0);
  pdr2(9.5,12.0);
  pdr2(10.0,11.5);
  pdr2(10.0,7.5);
  pdr2(9.5,7.0);
  pdr2(7.5,7.0);
  pdr2(7.0,7.5);
  pdr2(7.0,11.5);
 pclos();
 
  pmv2(8.5,11.0);
  pdr2(9.0,10.5);
  pdr2(9.0,8.5);
  pdr2(8.5,8.0);
  pdr2(8.0,8.5);
  pdr2(8.0,10.5);
 pclos();
 
 /* letra C */
 
 polymode(PYM_FILL);
 color(RED);
 
 pmv2(10.5,12.0);
  pdr2(12.0,12.0);
  pdr2(12.5,11.5);
  pdr2(13.0,12.0);
  pdr2(13.0,10.5);
  pdr2(12.0,10.5);
  pdr2(11.5,11.0);
  pdr2(11.0,10.5);
  pdr2(11.0,8.5);
  pdr2(11.5,8.0);
  pdr2(12.0,8.5);
  pdr2(12.0,9.5);
  pdr2(13.0,9.5);
  pdr2(13.0,7.5);
  pdr2(12.5,7.0);
  pdr2(10.5,7.0);
  pdr2(10.0,7.5);
  pdr2(10.0,11.5);
 pclos();
 
 color(YELLOW);
 
 pmv2(10.0,10.0);
  pdr2(11.0,10.0);
  pdr2(11.0,9.0);
  pdr2(10.0,9.0);
 pclos();
 
 pmv2(12.0,9.5);
  pdr2(13.0,9.5);
  pdr2(13.0,8.5);
  pdr2(12.0,8.5);
 pclos();
    
 polymode(PYM_LINE);
 color(WHITE);
 
 pmv2(10.5,12.0);
  pdr2(12.0,12.0);
  pdr2(12.5,11.5);
  pdr2(13.0,12.0);
  pdr2(13.0,10.5);
  pdr2(12.0,10.5);
  pdr2(11.5,11.0);
  pdr2(11.0,10.5);
  pdr2(11.0,8.5);
  pdr2(11.5,8.0);
  pdr2(12.0,8.5);
  pdr2(12.0,9.5);
  pdr2(13.0,9.5);
  pdr2(13.0,7.5);
  pdr2(12.5,7.0);
  pdr2(10.5,7.0);
  pdr2(10.0,7.5);
  pdr2(10.0,11.5);
 pclos();
 
 /* letra K */
 
 polymode(PYM_FILL);
 color(RED);
 
 pmv2(13.0,12.0);
  pdr2(14.5,12.0);
  pdr2(14.5,10.0);
  pdr2(15.5,11.5);
  pdr2(15.5,12.0);
  pdr2(17.0,12.0);
  pdr2(17.0,11.0);
  pdr2(15.5,9.5);
  pdr2(16.5,7.0);
  pdr2(17.0,7.0);
  pdr2(17.0,5.0);
  pdr2(15.5,5.0);
  pdr2(15.5,6.5);
  pdr2(14.5,8.0);
  pdr2(14.5,5.0);
  pdr2(13.0,5.0);
 pclos();
 
 color(YELLOW);
 
 pmv2(13.0,10.0);
  pdr2(14.0,10.0);
  pdr2(15.5,9.5);
  pdr2(16.0,8.0);
  pdr2(13.0,9.0);
 pclos();
  
 polymode(PYM_LINE);
 color(WHITE);
 
 pmv2(13.0,12.0);
  pdr2(14.5,12.0);
  pdr2(14.5,10.0);
  pdr2(15.5,11.5);
  pdr2(15.5,12.0);
  pdr2(17.0,12.0);
  pdr2(17.0,11.0);
  pdr2(15.5,9.5);
  pdr2(16.5,7.0);
  pdr2(17.0,7.0);
  pdr2(17.0,5.0);
  pdr2(15.5,5.0);
  pdr2(15.5,6.5);
  pdr2(14.5,8.0);
  pdr2(14.5,5.0);
  pdr2(13.0,5.0);
 pclos();
 
 
 /* caja detras de out */
 
 polymode(PYM_FILL);
 color(RED);
 
 pmv2(4.0,5.0);
  pdr2(13.0,5.0);
  pdr2(13.0,0.0);
  pdr2(4.0,0.0);
 pclos();
 
 color(YELLOW);
 
 pmv2(4.0,3.0);
  pdr2(13.0,3.0);
  pdr2(13.0,2.0);
  pdr2(4.0,2.0);
 pclos();
   
 color(WHITE);
 
 pmv2(4.5,6.5);
  pdr2(12.5,6.5);
  pdr2(13.0,5.0);
  pdr2(4.0,5.0);
 pclos(); 
 
 polymode(PYM_LINE);
 
  pmv2(4.0,5.0);
  pdr2(13.0,5.0);
  pdr2(13.0,0.0);
  pdr2(4.0,0.0);
 pclos();
 
 /*letra o chica*/
 
 polymode(PYM_FILL);
 
 pmv2(5.0,5.0);
  pdr2(6.5,5.0);
  pdr2(7.0,4.5);
  pdr2(7.0,0.5);
  pdr2(6.5,0.0);
  pdr2(5.0,0.0);
  pdr2(4.5,0.5);
  pdr2(4.5,4.5);
 pclos(); 
 
 color(RED);
 
 pmv2(5.5,4.0);
  pdr2(6.0,4.0);
  pdr2(6.0,1.0);
  pdr2(5.5,1.0);
 pclos();
  
 color(YELLOW);
 
 pmv2(5.5,3.0);
  pdr2(6.0,3.0);
  pdr2(6.0,2.0);
  pdr2(5.5,2.0);
 pclos(); 
 
 
 /*letra u chica */
 
 color(WHITE);
 
 pmv2(7.25,5.0);
  pdr2(8.25,5.0);
  pdr2(8.25,4.0);
  pdr2(8.0,4.0);
  pdr2(8.0,1.5);
  pdr2(8.5,1.0);
  pdr2(9.0,1.5);
  pdr2(9.0,4.0);
  pdr2(8.75,4.0);
  pdr2(8.75,5.0);
  pdr2(9.75,5.0);
  pdr2(9.75,4.0);
  pdr2(9.5,4.0);
  pdr2(9.5,0.5);
  pdr2(9.0,0.0);
  pdr2(8.0,0.0);
  pdr2(7.5,0.5);
  pdr2(7.5,4.0);
  pdr2(7.25,4.0);
 pclos();
  
 
 
 /*letra t chica*/
 
 pmv2(10.0,5.0);
  pdr2(12.5,5.0);
  pdr2(12.5,3.5);
  pdr2(12.0,3.5);
  pdr2(12.0,4.5);
  pdr2(11.75,4.5);
  pdr2(11.75,0.5);
  pdr2(12.5,0.5);
  pdr2(12.5,0.0);
  pdr2(10.0,0.0);
  pdr2(10.0,0.5);
  pdr2(10.75,0.5);
  pdr2(10.75,4.5);
  pdr2(10.5,4.5);
  pdr2(10.5,3.5);
  pdr2(10.0,3.5);
 pclos(); 
 

 linewidth(1);
 
 
 closeobj();
 pushmatrix();
 translate(1.0,47.0,0.0);
 callobj(BLOCK_OUT);
 popmatrix();
 
} 

void rectangulo()
{
 makeobj(RECT);
 pmv2(0.0,0.0);
  pdr2(0.0,4.0);
  pdr2(4.0,4.0);
  pdr2(4.0,0.0);
 pclos();
 closeobj();
}

void dibujar_rectanguloj(int j)
{
 /*el color debe estar predefinido*/
 pushmatrix();
 translate(3.0,41.0-4.0*(float)(j),0.0);
 callobj(RECT);
 polymode(PYM_LINE);
 color(GREEN);
 callobj(RECT);
 popmatrix();
 polymode(PYM_FILL);
}

void dibujar_columna_de_rectangulos()
{
 int j;
 for(j=9;j>=0;j--)
 {
  if(muro(j)>0)
   color(colorj(j));
  else
   color(BLACK);
  dibujar_rectanguloj(j);
 }     
}

void dibujar_level()
{
 hfont("times.rb");
 hcentertext(1);
 htextsize(2.0,4.0);
 move2(5.0,57.0);
 color(WHITE);
 linewidth(2);
 hcharstr("LEVEL");
 linewidth(1);
} 
  
void dibujar_nivel(int nivel)
{
 char dev[4];
 sprintf(dev,"%d",nivel);
 pushmatrix();
 translate(3.0,50.0,0.0);
 color(BLACK);
 callobj(RECT);
 popmatrix();
 hfont("times.rb");
 hcentertext(1);
 htextsize(2.8,2.8);
 move2(5.0,52.0);
 color(GREEN);
 hcharstr(dev);
}
 
void dibujar_rectangulo_pantalla3()
{
 color(WHITE);
 pmv2(0.0,0.0);
  pdr2(0.0,46.0);
  pdr2(18.0,46.0);
  pdr2(18.0,0.0);
 pclos();
 color(colorj(7));
 pmv2(0.5,0.5);
  pdr2(0.5,45.5);
  pdr2(17.5,45.5);
  pdr2(17.5,0.5);
 pclos();
}   
 
void dibujar_score()
{
 color(WHITE);
 linewidth(2);
 hfont("times.rb");
 hcentertext(1);
 htextsize(2.0,4.0);
 move2(9.0,43.0);
 hcharstr("SCORE");
 linewidth(1);
}  

void dibujar_puntaje(int puntaje)
{
 char dev[6];
 
 sprintf(dev,"%d",puntaje);
 color(BLACK);
 pmv2(1.0,36.0);
  pdr2(1.0,40.0);
  pdr2(17.0,40.0);
  pdr2(17.0,36.0);
 pclos();
 hfont("times.rb");
 hcentertext(1);
 htextsize(2.6,4.0);
 move2(9.0,38.0);
 color(GREEN);
 hcharstr(dev);
} 
 
void dibujar_cubes_played()
{
 color(WHITE);
 linewidth(2);
 hfont("times.rb");
 hcentertext(1);
 htextsize(1.8,4.0);
 move2(9.0,33.0);
 hcharstr("CUBES PLAYED");
 linewidth(1);
}  
 
 
void dibujar_cubos_jugados(int cubos_jugados)
{
 char dev[6];
 
 sprintf(dev,"%d",cubos_jugados);
 color(BLACK);
 pmv2(1.0,26.0);
  pdr2(1.0,30.0);
  pdr2(17.0,30.0);
  pdr2(17.0,26.0);
 pclos();
 hfont("times.rb");
 hcentertext(1);
 htextsize(2.6,4.0);
 move2(9.0,28.0);
 color(GREEN);
 hcharstr(dev);
}     

   
   
void dibujar_username()
{
 color(BLACK);
 hfont("times.rb");
 hcentertext(1);
 htextsize(1.4,3.4);
 move2(9.0,3.0);
 hcharstr("jlflores@dcc.uchile.cl");
}     
  
void dibujar_nombre()
{
 makeobj(JLFV);
 /*J*/
 pmv2(0.0,18.5);
  pdr2(1.0,19.0);
  pdr2(4.0,19.0);
  pdr2(5.0,18.5);
  pdr2(4.0,18.0);
  pdr2(3.0,18.0);
  pdr2(3.0,16.0);
  pdr2(2.5,15.0);
  pdr2(0.0,15.0);
  pdr2(0.0,17.0);
  pdr2(1.0,17.0);
  pdr2(0.5,16.0);
  pdr2(1.5,15.5);
  pdr2(2.0,16.0);
  pdr2(2.0,18.0);
  pdr2(1.0,18.0);
 pclos();
 
 /*L*/
 pmv2(0.0,14.0);
  pdr2(2.0,14.0);
  pdr2(1.0,13.0);
  pdr2(1.0,11.0);
  pdr2(2.5,11.0);
  pdr2(3.0,12.0);
  pdr2(2.5,12.5);
  pdr2(4.0,12.5);
  pdr2(4.0,11.0);
  pdr2(3.0,10.0);
  pdr2(0.0,10.0);
 pclos(); 
 
 /*F*/
 pmv2(0.0,9.0);
  pdr2(3.0,9.0);
  pdr2(3.0,8.0);
  pdr2(1.0,8.0);
  pdr2(1.0,7.0);
  pdr2(2.0,7.0);
  pdr2(2.0,6.0);
  pdr2(1.0,6.0);
  pdr2(1.0,5.0);
  pdr2(0.0,5.0);
 pclos(); 
 
 /*V*/
 pmv2(0.0,4.0);
  pdr2(1.5,4.0);
  pdr2(1.5,3.0);
  pdr2(1.0,3.0);
  pdr2(2.0,1.0);
  pdr2(3.0,3.0);
  pdr2(2.5,3.0);
  pdr2(2.5,4.0);
  pdr2(4.0,4.0);
  pdr2(4.0,3.0);
  pdr2(2.5,0.0);
  pdr2(1.5,0.0);
  pdr2(0.0,3.0);
 pclos();
  
 closeobj();
 
 
 color(BLACK);
 pushmatrix();
 translate(1.0,5.0,0.0);
 callobj(JLFV);
 popmatrix();
 
 linewidth(3);
 hfont("times.rb");
 hcentertext(1);
 
 /*ose*/
 htextsize(3.6,4.0);
 move2(9.0,22.0);
 hcharstr("OSE"); 
 /*eonardo*/
 htextsize(2.6,4.0);
 move2(11.0,17.0);
 hcharstr("EONARDO");
 /*lores*/
 htextsize(3.2,4.0);
 move2(9.0,12.0);
 hcharstr("LORES");
 /*argas*/
 htextsize(2.8,4.0);
 move2(9.0,7.0);
 hcharstr("ARGAS");
 
 linewidth(1);
   
}  
  
void figura_llega_al_fondo()
{  
 int n,i,j;
 float y;

 incorporar_al_espacio(Figura.FIGURA_ACTUAL);
 fondo();
 dibujar_espacio();
 pushmatrix();
 translate(-15.0,-50.0,-15.0);
 dibujar_espacio_ocupado(9,0);
 popmatrix();
 pantalla1();
 dibujar_columna_de_rectangulos();
 Cubos_Jugados=(Cubos_Jugados+Figura.numero_de_cubos)%1000000;
 pantalla3();
 dibujar_cubos_jugados(Cubos_Jugados);
 pantalla2();        
 swapbuffers();
       
 n=muros_llenos();
      
 if(n>0)
  Puntaje=((int)((float)Puntaje+100.0*(float)(n*n)*(1.0+(float)nivel/(float)NUMERO_DE_NIVELES)))%1000000;
      
      
       
 for(i=0;i<n;i++)
 {
  for(y=0.0;y<=10.0;y+=5.0)
  {
   fondo();
   dibujar_espacio();
   pushmatrix();
    translate(-15.0,-50.0,-15.0);
    dibujar_espacio_ocupado(9,Muros_Llenos[i]+1);
    pushmatrix();
    translate(0.0,y,0.0);
    dibujar_espacio_ocupado(Muros_Llenos[i]-1,0);
    popmatrix();
   swapbuffers();
   popmatrix();
  }
  sacar_muro_lleno_del_espacio(Muros_Llenos[i]);

  for(j=i+1;j<n;j++)
   Muros_Llenos[j]++;

  fondo();
  dibujar_espacio();
  pushmatrix();
  translate(-15.0,-50.0,-15.0);
  dibujar_espacio_ocupado(9,0);
  popmatrix();
  pantalla1();
  dibujar_columna_de_rectangulos();
  pantalla2();
  swapbuffers();
 }
      
 if(n>0 && muro(9)==0)
  Puntaje=((int)((float)Puntaje+200.0*(1.0+(float)nivel/(float)NUMERO_DE_NIVELES)))%1000000;
      
 if(n>0)
 {
  pantalla3(); 
  dibujar_puntaje(Puntaje);
  Numero_de_Muros+=n;
  if(Numero_de_Muros>=NUMERO_DE_MUROS_EXIGIDOS)
  {
   Numero_de_Muros=0;
   ualarm(0,0);
   nivel=(nivel+1)%(NUMERO_DE_NIVELES);
   pantalla1();
   dibujar_nivel(nivel+1);
   pantalla2();
        
   figuras=Nivel[nivel].figuras;
   nseg=Nivel[nivel].seg;
   fondo();
   inicializar_espacio();
   pantalla1();
   dibujar_columna_de_rectangulos();
   pantalla2(); 
   dibujar_espacio();
   delta_t=1000000*nseg;
   interval=delta_t; 
  }
 }  
 pantalla2();   
        
 srand((int)(time(NULL)+ 2));  
 Figura.FIGURA_ACTUAL=rand()%figuras;
 inicializar_figura(Figura.FIGURA_ACTUAL);
 pushmatrix();
 translate(-15.0,-50.0,-15.0); 
 dibujar_figura(Figura.FIGURA_ACTUAL);
 popmatrix();
 swapbuffers();
 if(!(cabe_figura(Figura.FIGURA_ACTUAL)))
  game_over();
}
  
  
  
   








