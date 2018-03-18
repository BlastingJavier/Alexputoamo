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
  Stack *stack;
  map = map_ini();
  stack = stack_ini();

  if (argc < 2){
    fprintf(stderr,"Error con los argumentos %s<mx.txt>",argv[0]);
    return 0;
  }
  if (map == NULL){
    return 0;
  }
  pf = fopen(argv[1],"r");
  if (pf == NULL){
    return 0;
  }
  map_read(pf,map);

  deep_map_point_search(map, point, stack);

  return 0;
}
