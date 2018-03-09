#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "map.h"
#include "point.h"
#include "element.h"
#include "stack_element.h"
#define POSIBLES_MOV 4
#define MAX_POINTS 100

int main (int argc , char *argv[]){
  FILE *pf;
  char buff[MAX_POINTS]; /*Para leer el archivo*/
  int i,j,nrows,ncols;
  Point *point_input,*temp,*point_aux,*neighbor_point;
  Map *map;
  Stack *stack, *stack2;
  Element *ele_visited, *pele;
  stack = stack_ini();
  stack2 = stack_ini();
  pele = element_ini();
  ele_visited = element_ini();
  map = map_ini();

  if (argc != 2){
    fprintf(stderr,"Problema con el numero de argumentos amigo: %s <mx.txt>",argv[0]);
    return 0;
  }
  pf = fopen (argv[1],"r");
  if (pf == NULL){
    fprintf(stdout,"Error al abrir el archivo\n");
    return 0;
  }
  if (stack== NULL || map == NULL || ele_visited == NULL){
    return 0;
  }

  temp = point_ini(0, 0, ERRORCHAR);
  if (temp==NULL){
    fprintf(stdout,"Error al iniciar el punto\n");
    return 0;
  }

  fgets(buff, MAX_POINTS, pf);
  sscanf(buff, "%d %d", &nrows, &ncols);

  if (map_setSize (map, nrows, ncols) == ERROR){
    return 0;
  }
  /* leemos el fichero linea a linea */
  for(i=0; i < nrows; i++) {
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
      if (map_setPoint(map,temp)==ERROR){
        return 0;
      }
      if (element_setInfo(pele,temp)==ERROR){
        fprintf(stdout,"fallo al hacer set: elemento\n");
        return 0;
      }

     /* lo insertamos en la pila */
      stack_push(stack,pele);
    }
  }
  while (stack_isEmpty(stack)==FALSE){
    ele_visited = stack_pop(stack);

    if ((point_setSymbol(element_getInfo(ele_visited),point_getSymbol(element_getInfo(ele_visited)))!= VISITED)){

      point_setSymbol(element_getInfo(ele_visited),VISITED);
      map_setPoint(map,element_getInfo(ele_visited));

      for (i=0;i<POSIBLES_MOV;i++){
        point_aux = element_getInfo(ele_visited);
        neighbor_point = map_getNeighborPoint(map,point_aux,i);
        if (point_isOutput(neighbor_point)==TRUE){
          /*Se encuentra la salida*/
          fprintf(stdout,"Éxito al encontrar la salida");
        }
        if (point_isSpace(neighbor_point)==TRUE){
          stack_push(stack,ele_visited);
          stack_push(stack2,ele_visited);
        }

      }
    }
  }

  fprintf (stdout, "Error al encontrar la salida \n");
  comprobar_pila(stdout,stack);
  comprobar_pila(stdout,stack2);
  stack_print(stdout,stack);
  stack_print(stdout,stack2);

  /* libera recursos */
  point_destroy(temp);
  point_destroy(point_aux);
  point_destroy(neighbor_point);
  point_destroy(point_input);

  element_destroy(pele);
  element_destroy(ele_visited);

  stack_destroy(stack);
  stack_destroy(stack2);

  fclose (pf);

  return 0;
}
