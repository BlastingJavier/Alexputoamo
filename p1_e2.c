#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "point.h"

#define MAX_FICHERO 100

int main (){
  FILE *f;
  Map * pl=NULL;
  char fichero[MAX_FICHERO];
  int nColumns;
  int nfilas;

  pl = map_ini();
  if (pl==NULL){
    return 1;
  }
  fprintf(stdout,"Dime el fichero de entrada de un mapa(escapa caracteres si el nombre del fichero tiene espacios): ");
  scanf("%s",fichero);
  f = fopen (fichero,"r");
  if (f == NULL){
    return 2;
  }

  if (map_read(f,pl)==ERROR){
    return 2;
  }
  else {
    nfilas = map_getNrows(pl);
    if (nfilas == (-1)){
      return 3;
    }
    nColumns = map_getNcols(pl);
    if (nColumns == (-1)){
      return 3;
    }

    fprintf(stdout,"%d",nfilas);
    fprintf(stdout," ");
    fprintf(stdout,"%d",nColumns);
    fprintf(stdout,"\n");
    /*Si se cambian los parametros de entrada*/
    if (map_print(stdout,pl)==(-1)){
      return 4;
    }
  }
  fclose (f);

  return 0;
}
