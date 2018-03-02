#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "element-point.h"

#define MAX_POINTS


int main (){
  char buff[MAX_POINTS];
  int i, j, nrows, ncols/*indice*/;
  Point *temp;
  Status st = ERROR;
  Element *pele;
  Stack *sta;

  pele = element_ini();
  Sta = stack_ini();

  /*creamos punto que se utiliza como buffer*/
  temp = point_ini(0, 0, ERRORCHAR);
  if (temp==NULL){
    return st;
  }
  /* asignamos dimensión al mapa */
  fgets(buff, MAX_POINTS, pf);
  sscanf(buff, "%d %d", &nrows, &ncols);
  if (st == ERROR){
    return ERROR;
  }
  /* leemos el fichero linea a linea */
  for(i=0; i < nrows;i++) {
    fgets(buff, MAX_POINTS, pf);
    for (j=0; j < ncols; j++) {
    /* ajustamos los atributos del punto leído  */
      if (element_setInfo(pele,&j,&i,&buff[&j])==ERROR){
        return ERROR;
      }
      if (point_setCoordinateX(temp, j)==ERROR){
        return ERROR;
      }
      if (point_setCoordinateY(temp, i)==ERROR){
        return ERROR;
      }
      if (buff[j] != ERRORCHAR && buff[j] != INPUT && buff[j] != VISITED && buff[j] != OUTPUT && buff[j] != BARRIER && buff[j] != SPACE ){
        return ERROR;
      }
      if (point_setSymbol(temp, buff[j])==ERROR){
        return ERROR;
      }
     /* lo insertamos en la pila */
      stack_push(Sta,pele);
    }
  }

  /* libera recursos */
  point_destroy(temp);
  /* no cerramos el fichero ya que lo han abierto fuera */turn 0;
}
