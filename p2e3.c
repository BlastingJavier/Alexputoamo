#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "map.h"
#include "point.h"
#define POSIBLES_MOV 4

int main (int argc , char *argv[]){
  FILE *pf;
  char buff[MAX_POINTS];
  int i;
  Point *point_input;
  Map *map;
  Stack* stack;
  Element *ele_visited, *ele_aux;
  stack = stack_ini();
  ele_visited = element_ini();
  map = map_ini();

  if (argc != 2){
    fprintf(stderr,"Problema con el numero de argumentos amigo: %s <m2.txt>",argv[0]);
    return 0;
  }
  pf = fopen (argv[1],"r");
  if (pf == NULL){
    fprintf(stdout,"Fallo al abrir el archivo amigo \n");
    return 0;
  }
  if (stack== NULL || map == NULL || ele_visited == NULL){
    return 0;
  }
  temp = point_ini(0, 0, ERRORCHAR);
  if (temp==NULL){
    fprintf(stdout,"Fallo al iniciar el punto\n");
    return 0;
  }
  fgets(buff, MAX_POINTS,pf);
  sscanf(buff, "%d %d", &nrows, &ncols);
  /* leemos el fichero linea a linea */
  for(i=0; i < nrows;i++) {
    fgets(buff, MAX_POINTS,pf);
    for (j=0; j < ncols; j++) {
    /* ajustamos los atributos del punto leído  */
      if (point_setCoordinateX(temp, j)==ERROR){
        fprintf(stdout,"fallo al hacer set x:\n");
        return 0;
      }
      if (point_setCoordinateY(temp, i)==ERROR){
        fprintf(stdout,"fallo al hacer set y:\n");
        return 0;
      }
      if (buff[j] != ERRORCHAR && buff[j] != INPUT && buff[j] != VISITED && buff[j] != OUTPUT && buff[j] != BARRIER && buff[j] != SPACE ){
        fprintf(stdout,"fallo al hacer set p:\n");

        return 0;
      }
      if (point_setSymbol(temp, buff[j])==ERROR){
        fprintf(stdout,"fallo al hacer set: s\n");
        return 0;
      }
      if (point_isInput(temp)==TRUE){
        point_input = point_ini(point_getCoordinateX(temp),point_getCoordinateY(temp),INPUT);
      }
      if (element_setInfo(pele,temp)==ERROR){
        fprintf(stdout,"fallo al hacer set: elemento\n");
        return 0;
      }

     /* lo insertamos en la pila */
      stack_push(stack,pele);
    }
  }
  fclose (pf);
  if (point_input != NULL){

    while (stack_isEmpty(stack)==FALSE){

      ele_visited = stack_pop(stack);
      if (point_getSymbol(ele_visited)!= VISITED){

        point_setSymbol(ele_visited,VISITED);
        map_setPoint(map,ele_visited);

        for (i=0;i<POSIBLES_MOV;i++){
          ele_aux =map_getNeighborPoint(map,ele_visited,i);
          if (point_isOutput(ele_aux) == TRUE){
            return ele_aux;
          }
          if (point_isSpace(ele_aux) == TRUE){
            stack_push(stack,ele_aux);

          }
        }
      }
    }
  }
  /*otra cosa que se me ocurre que creo que va a ser la buena es :
  temp = point_ini(0, 0, ERRORCHAR);
  if (temp==NULL){
    fprintf(stdout,"Fallo al iniciar el punto\n");
    return 0;
  }
  fgets(buff, MAX_POINTS,pf);
  sscanf(buff, "%d %d", &nrows, &ncols);
  /* leemos el fichero linea a linea
  for(i=0; i < nrows;i++) {
    fgets(buff, MAX_POINTS,pf);
    for (j=0; j < ncols; j++) {
      if (point_setCoordinateX(temp, j)==ERROR){
        fprintf(stdout,"fallo al hacer set x:\n");
        return 0;
      }
      if (point_setCoordinateY(temp, i)==ERROR){
        fprintf(stdout,"fallo al hacer set y:\n");
        return 0;
      }
      if (buff[j] != ERRORCHAR && buff[j] != INPUT && buff[j] != VISITED && buff[j] != OUTPUT && buff[j] != BARRIER && buff[j] != SPACE ){
        fprintf(stdout,"fallo al hacer set p:\n");

        return 0;
      }
      if (point_setSymbol(temp, buff[j])==ERROR){
        fprintf(stdout,"fallo al hacer set: s\n");
        return 0;
      }
      if (point_isInput(temp)==TRUE){
        point_input = point_ini(point_getCoordinateX(temp),point_getCoordinateY(temp),INPUT);
      }
      if (element_setInfo(pele,temp)==ERROR){
        fprintf(stdout,"fallo al hacer set: elemento\n");
        return 0;
      }

      lo insertamos en la pila
      stack_push(stack,pele);
    }
  }*/
  fclose (pf);

  return 0;
}
