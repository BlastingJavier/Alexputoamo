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
  Map *map;
  Point *point;
  FILE *pf;

  map = map_ini();

  if (argc < 2){
    fprintf(stderr,"Error con los argumentos %s<mx.txt>",argv[0]);
    return 0;
  }
  if (map == NULL){
    return 0;
  }
  point = point_ini(0,0,ERRORCHAR);
  if (point == NULL){
    return 0;
  }
  pf = fopen(argv[1],"r");
  if (pf == NULL){
    return 0;
  }
  map_read(pf,map);

  if (deep_map_point_search(map, point)==TRUE){
    fprintf(stdout,"Se ha encontrado el camino a la salida :");
  }
  else
  fprintf(stdout, "No ha podido encontrarse un camino\n");

  return 0;
}
