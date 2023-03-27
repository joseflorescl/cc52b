#include "tarea3.h"

int rotacionx(int TIPO_FIGURA,int d)
{
 cubo c;
 int ip,jp,kp,j,k,it,n;
 float J,K,delta;
 int ROT_X;
 n=Figura.numero_de_cubos;
 switch(TIPO_FIGURA)
 {
 /* caso trivial */
  case CUBO :
  case CUBO2 :
   i0=Figura.c[0].i;
   jo=Figura.c[0].j;
   k0=Figura.c[0].k;
   return 1;
   break;
  
/* solo caso 1 */
  case DOBLE_CUBO :
  case DOBLE_CUBO2 :
  case TRIPLE_CUBO :
  case CRUZ :
  case SILLA :
  case DOS_SILLAS :
  case SILLON_CHICO :
  
   c=Figura.c[0];
   i0=c.i;
   jo=c.j;
   k0=c.k;
   for(it=1;it<n;it++)
    {
     ip=Figura.c[it].i;
     jp=(k0-Figura.c[it].k)*d + jo;
     kp=(Figura.c[it].j-jo)*d + k0;
     if(Figura.c[it].j==jp && Figura.c[it].k==kp)
      continue;
     J=(Figura.c[it].j + jp)/2.0;
     K=(Figura.c[it].k + kp)/2.0;
   
     for(j=(int)(J-0.5);j<=(int)(J+0.5);j++)
      for(k=(int)(K-0.5);k<=(int)(K+0.5);k++)
      {
       ROT_X=(0<=j && j<=9 && 0<=k && k<=2 && Espacio[ip][j][k].ocupado==NO); 
       if(ROT_X)
        continue;
       else
        return ROT_X; 
     }
    }
   for(it=1;it<n;it++)
    { 
     jp=(k0-Figura.c[it].k)*d + jo;
     kp=(Figura.c[it].j-jo)*d + k0;
     Figura.c[it].j=jp;
     Figura.c[it].k=kp;
    } 
   return 1;  
   break; 
 
  /* casos 1 y/o 2 */
  case SILLON :
  case CUATRO_CUBOS :
  case ELE :
  case ESE :
  
   c=Figura.c[0];
   i0=c.i;
   jo=c.j;
   k0=c.k;
   for(it=1;it<n;it++)
    {     
     ip=Figura.c[it].i;
     jp=(k0-Figura.c[it].k)*d + jo;
     kp=(Figura.c[it].j-jo)*d + k0;
     if(!(0<=jp && jp<=9 && 0<=kp && kp<=2 ))
      return (!1); 
     if(Figura.c[it].j==jp && Figura.c[it].k==kp)
      continue;
     J=(Figura.c[it].j + jp)/2.0;
     K=(Figura.c[it].k + kp)/2.0;
     if(Figura.c[it].j!=jp  && Figura.c[it].k!=kp)/*caso 1*/
      delta=0.5;
     else
      delta=1.0; 
     for(j=(int)(J-delta);j<=(int)(J+delta);j++)
      for(k=(int)(K-delta);k<=(int)(K+delta);k++)
      { 
       if(0<=j && j<=9 && 0<=k && k<=2)
       { 
        ROT_X=(Espacio[ip][j][k].ocupado==NO); 
        if(ROT_X)
         continue;
        else
         return ROT_X;
       } 
       /*else el punto esta fuera del espacio; pero no importa
         porque solo se trata de un punto intermedio, y no
         el punto final del cubo*/  
     }
    }
   for(it=1;it<n;it++)
    { 
     jp=(k0-Figura.c[it].k)*d + jo;
     kp=(Figura.c[it].j-jo)*d + k0;
     Figura.c[it].j=jp;
     Figura.c[it].k=kp;
    } 
   return 1;  
   break; 
  }  
} 
 
  
   
   
int rotaciony(int TIPO_FIGURA,int d)
{
 cubo c;
 int ip,jp,kp,i,k,it,n;
 float I,K,delta;
 int ROT_Y;
 n=Figura.numero_de_cubos;
 switch(TIPO_FIGURA)
 {
  case CUBO :
  case CUBO2 :
   i0=Figura.c[0].i;
   jo=Figura.c[0].j;
   k0=Figura.c[0].k;
   return 1;
   break;
   
  case DOBLE_CUBO :
  case DOBLE_CUBO2 :
  case TRIPLE_CUBO :
  case CRUZ :
  case SILLA :
  case DOS_SILLAS :
  case SILLON_CHICO :
 
   c=Figura.c[0];
   i0=c.i;
   jo=c.j;
   k0=c.k;
   for(it=1;it<n;it++)
    {
     ip=(Figura.c[it].k - k0)*d + i0;
     jp=Figura.c[it].j;
     kp=(i0 - Figura.c[it].i)*d + k0;
     if(Figura.c[it].i==ip && Figura.c[it].k==kp)
      continue;
     I=(Figura.c[it].i + ip)/2.0;
     K=(Figura.c[it].k + kp)/2.0;
  
     for(i=(int)(I-0.5);i<=(int)(I+0.5);i++)
      for(k=(int)(K-0.5);k<=(int)(K+0.5);k++)
      {
       ROT_Y=(0<=i && i<=2 && 0<=k && k<=2 && Espacio[i][jp][k].ocupado==NO); 
       if(ROT_Y)
        continue;
       else
        return ROT_Y; 
      }
     }
    for(it=1;it<n;it++) 
     {
      ip=(Figura.c[it].k - k0)*d + i0;
      kp=(i0 - Figura.c[it].i)*d + k0;
      Figura.c[it].i=ip;
      Figura.c[it].k=kp;
     } 
    return 1; 
    break; 
   
  case SILLON :
  case CUATRO_CUBOS :
  case ELE :
  case ESE :
  
   c=Figura.c[0];
   i0=c.i;
   jo=c.j;  
   k0=c.k;
   for(it=1;it<n;it++)
    {
     ip=(Figura.c[it].k - k0)*d + i0;
     jp=Figura.c[it].j;
     kp=(i0 - Figura.c[it].i)*d + k0;
     if(!(0<=ip && ip<=2 && 0<=kp && kp<=2  ))
      return(!1);
     if(Figura.c[it].i==ip && Figura.c[it].k==kp)
      continue;
     I=(Figura.c[it].i + ip)/2.0;
     K=(Figura.c[it].k + kp)/2.0;
     if(Figura.c[it].i != ip && Figura.c[it].k != kp)/*caso 1*/
      delta=0.5;
     else
      delta=1.0; 
  
     for(i=(int)(I-delta);i<=(int)(I+delta);i++)
      for(k=(int)(K-delta);k<=(int)(K+delta);k++)
      {
       if(0<=i && i<=2 && 0<=k && k<=2)
       { 
        ROT_Y=(Espacio[i][jp][k].ocupado==NO); 
        if(ROT_Y)
         continue;
        else
         return ROT_Y;
       }   
      }
     }
    for(it=1;it<n;it++) 
     {
      ip=(Figura.c[it].k - k0)*d + i0;
      kp=(i0 - Figura.c[it].i)*d + k0;
      Figura.c[it].i=ip;
      Figura.c[it].k=kp;
     } 
    return 1; 
    break; 
    
    
 }     
}     

int rotacionz(int TIPO_FIGURA,int d)
{
 cubo c;
 int ip,jp,kp,i,j,it,n;
 float I,J,delta;
 int ROT_Z;
 n=Figura.numero_de_cubos;
 switch(TIPO_FIGURA)
 {
  case CUBO :
  case CUBO2 :
   i0=Figura.c[0].i;
   jo=Figura.c[0].j;
   k0=Figura.c[0].k;
   return 1;
   break;
   
  case DOBLE_CUBO :
  case DOBLE_CUBO2 :
  case TRIPLE_CUBO :
  case CRUZ :
  case SILLA :
  case DOS_SILLAS :
  case SILLON_CHICO :

   
   c=Figura.c[0];
   i0=c.i;
   jo=c.j;
   k0=c.k;
   for(it=1;it<n;it++)
    {
     ip=(jo-Figura.c[it].j)*d + i0;
     jp=(Figura.c[it].i-i0)*d + jo;
     kp=Figura.c[it].k;
     if(Figura.c[it].i==ip && Figura.c[it].j==jp)
      continue;
     I=(Figura.c[it].i + ip)/2.0;
     J=(Figura.c[it].j + jp)/2.0;
  
     for(i=(int)(I-0.5);i<=(int)(I+0.5);i++)
      for(j=(int)(J-0.5);j<=(int)(J+0.5);j++)
      {
       ROT_Z=(0<=i && i<=2 && 0<=j && j<=9 && Espacio[i][j][kp].ocupado==NO); 
       if(ROT_Z)
        continue;
       else
        return ROT_Z; 
      }
     }
    for(it=1;it<n;it++)
     {
      ip=(jo-Figura.c[it].j)*d + i0;
      jp=(Figura.c[it].i-i0)*d+jo;
      Figura.c[it].i=ip;
      Figura.c[it].j=jp;
     } 
    return 1;  
    break;
    
  case SILLON :
  case CUATRO_CUBOS :
  case ELE :
  case ESE :

   c=Figura.c[0];
   i0=c.i;
   jo=c.j;
   k0=c.k;
   for(it=1;it<n;it++)
    {
     ip=(jo-Figura.c[it].j)*d + i0;
     jp=(Figura.c[it].i-i0)*d+jo;
     kp=Figura.c[it].k;
     if(!(0<=ip && ip<=2 && 0<=jp && jp<=9  ))
      return(!1); 
     if(Figura.c[it].i==ip && Figura.c[it].j==jp)
      continue;
     I=(Figura.c[it].i + ip)/2.0;
     J=(Figura.c[it].j + jp)/2.0;
     if(Figura.c[it].i!=ip && Figura.c[it].j!=jp)
      delta=0.5;
     else
      delta=1.0; 
  
     for(i=(int)(I-delta);i<=(int)(I+delta);i++)
      for(j=(int)(J-delta);j<=(int)(J+delta);j++)
      {
       if(0<=i && i<=2 && 0<=j && j<=9)
       {
        ROT_Z=(Espacio[i][j][kp].ocupado==NO); 
        if(ROT_Z)
         continue;
        else
         return ROT_Z;
       }   
      }
     }
    for(it=1;it<n;it++)  
     {
      ip=(jo-Figura.c[it].j)*d + i0;
      jp=(Figura.c[it].i-i0)*d+jo;
      Figura.c[it].i=ip;
      Figura.c[it].j=jp;
     } 
    return 1;  
    break;
    
    
 }  
}
