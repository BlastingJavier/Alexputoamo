#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack_element.h"
#include "point.h"

#include "element.h"

#define MAX_POINTS 100


int main (int argc, char *argv[]){
  char buff[MAX_POINTS];
  int i, j, nrows, ncols/*indice*/;
  Point *temp;
  Element *pele;
  Stack *sta;
  FILE *pf;

  pele = element_ini();
  sta = stack_ini();

  if (argc != 2){
    fprintf(stderr, "Usa esto companero amigo , maquina ,tifon %s <m1.txt>\n",argv[0]);
    return 0;
  }
  /*creamos punto que se utiliza como buffer*/
  pf = fopen (argv[0],"r");
  if (pf == NULL){
    fprintf(stdout,"Fallo al abrir el archivo amigo\n");
    return 0;
  }
  temp = point_ini(0, 0, ERRORCHAR);
  if (temp==NULL){
    fprintf(stdout,"Fallo al iniciar el punto\n");
    return 0;
  }
  /* asignamos dimensión al mapa */
  fgets(buff, MAX_POINTS,pf);
  sscanf(buff, "%d %d", &nrows, &ncols);

  fprintf(stdout,"hola amigo");
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
      if (element_setInfo(pele,temp)==ERROR){
        fprintf(stdout,"fallo al hacer set: elemento\n");
        return 0;
      }
      point_print(stdout,temp);
     /* lo insertamos en la pila */
      stack_push(sta,pele);
    }
  }
  fprintf(stdout,"he llegado hasta aqui amigo\n");
  comprobar_pila(stdout,sta);
  stack_print(stdout,sta);
  /* libera recursos */
  point_destroy(temp);
  element_destroy(pele);
  stack_destroy(sta);
  fclose (pf);

  /* no cerramos el fichero ya que lo han abierto fuera */
  return 0;
}
