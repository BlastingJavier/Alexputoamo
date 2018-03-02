#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "point.h"

int main (){
  Point *p1=NULL;
  Point *p2=NULL;
  char symbolaux;
  int coordenadaaux;
  /*En el caso en el que los parametros de point_ini por ejemplo se pidan al
    usuario.*/
  if ((p1 = point_ini (1,2,BARRIER)) == NULL){
    return 1;
  }
  if((p2 = point_ini (3,4,OUTPUT))==NULL){
    point_destroy(p1);
    return 1;
  }

  /*En el caso en el que los parametros de point_print tengan una entrada vacia
    o algo del estilo.*/
  if (!point_print (stdout,p1)){
    return 2;
  }
  if (!point_print (stdout,p2)){
    return 2;
  }
  fprintf (stdout,"\n");

  if (point_equals(p1,p2)==FALSE){
    fprintf(stdout,"Son iguales : NO");
  }
  else {
    fprintf(stdout,"Son iguales : SI");
  }
  fprintf (stdout,"\n");

  symbolaux = point_getSymbol(p1);
  if (!symbolaux){
    point_destroy(p1);
    return 3;
  }
  coordenadaaux = point_getCoordinateX(p2);
  if (!coordenadaaux){
    point_destroy(p1);
    point_destroy(p2);
    return 3;
  }

  fprintf(stdout,"El simbolo del primer punto es : %c",symbolaux);
  fprintf (stdout,"\n");
  fprintf(stdout,"La coordenada del segundo punto es : %d",coordenadaaux);
  fprintf (stdout,"\n");

  p2 = point_copy(p1);
  if (p2 == NULL){
    return 0;
  }

  /*En el caso en el que los parametros (por segunda vez) de point_print tengan una entrada vacia
    o algo del estilo.*/
  if (!point_print (stdout,p1)){
    return 2;
  }
  if (!point_print (stdout,p2)){
    return 2;
  }
  fprintf (stdout,"\n");


  if (point_equals(p1,p2)==FALSE){
    fprintf(stdout,"Son iguales : NO");
  }
  else {
    fprintf(stdout,"Son iguales : SI");
  }
  fprintf (stdout,"\n");


  point_destroy(p1);
  point_destroy(p2);

  return 0;
}
