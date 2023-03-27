#include "tarea3.h"

int traslacion_up(int TIPO_FIGURA)
{
 int k,i,n;
 int TR_UP;
 n=Figura.numero_de_cubos;
 for(i=0;i<n;i++)
 {
  k=Figura.c[i].k;
  k++;
  TR_UP=(k<=2 &&
  Espacio[Figura.c[i].i][Figura.c[i].j][k].ocupado==NO);
  if(TR_UP)
   continue;
  else
   return TR_UP;
 }  
 for(i=0;i<n;i++)
  Figura.c[i].k++;
 return TR_UP;
}

int traslacion_down(int TIPO_FIGURA)
{
 int k,i,n;
 int TR_DOWN;
 n=Figura.numero_de_cubos;
 for(i=0;i<n;i++)
 {
  k=Figura.c[i].k;
  k--;
  TR_DOWN=(k>=0 &&
  Espacio[Figura.c[i].i][Figura.c[i].j][k].ocupado==NO);
  if(TR_DOWN)
   continue;
  else
   return TR_DOWN;
 }  
 for(i=0;i<n;i++)
  Figura.c[i].k--;
 return TR_DOWN;
}
   
int traslacion_left(int TIPO_FIGURA)
{
 int i,it,n;
 int TR_LEFT;
 n=Figura.numero_de_cubos;
 for(it=0;it<n;it++)
 {
  i=Figura.c[it].i;
  i--;
  TR_LEFT=(i>=0 &&
  Espacio[i][Figura.c[it].j][Figura.c[it].k].ocupado==NO);
  if(TR_LEFT)
   continue;
  else
   return TR_LEFT;
 }  
 for(it=0;it<n;it++)
  Figura.c[it].i--;
 return TR_LEFT;
   
} 
 
int traslacion_right(int TIPO_FIGURA)
{
 int i,it,n;
 int TR_RIGHT;
 n=Figura.numero_de_cubos;
 for(it=0;it<n;it++)
 {
  i=Figura.c[it].i;
  i++;
  TR_RIGHT=(i<=2 &&
  Espacio[i][Figura.c[it].j][Figura.c[it].k].ocupado==NO);
  if(TR_RIGHT)
   continue;
  else
   return TR_RIGHT;
 }  
 for(it=0;it<n;it++)
  Figura.c[it].i++;
 return TR_RIGHT;
} 
  
int traslacion_in(int TIPO_FIGURA)
{
 int j,i,n;
 int TR_IN;
 n=Figura.numero_de_cubos;
 for(i=0;i<n;i++)
 {
  j=Figura.c[i].j;
  j++;
  TR_IN=(j<=9 &&
  Espacio[Figura.c[i].i][j][Figura.c[i].k].ocupado==NO);
  if(TR_IN)
   continue;
  else
   return TR_IN;
 }  
 for(i=0;i<n;i++)
  Figura.c[i].j++;
 return TR_IN;
} 
  
int traslacion_out(int TIPO_FIGURA)
{
 int j,i,n;
 int TR_OUT;
 n=Figura.numero_de_cubos;
 for(i=0;i<n;i++)
 {
  j=Figura.c[i].j;
  j--;
  TR_OUT=(j>=0 &&
  Espacio[Figura.c[i].i][j][Figura.c[i].k].ocupado==NO);
  if(TR_OUT)
   continue;
  else
   return TR_OUT;
 }  
 for(i=0;i<n;i++)
  Figura.c[i].j--;
 return TR_OUT;
} 
