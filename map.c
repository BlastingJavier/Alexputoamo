/*
*@brief Implementacion del mapa (EdD)
*
*@file map.c
@author FJNR & AMH
@version 1.0
@date 14/02/2018
@copyright GNU Public License
*/
#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "point.h"
#include "types.h"
#define MAX_POINTS 4096
#define EXCELENTISIMA_FORMULA(x,y,nColumns) ((y*nColumns)+x)
/*Va por ti Alberto*/

/*Estructura con componentes del mapa (caracteristicas) y el array de punteros
  a puntos*/
struct _Map {
  int nColumns;
  int nRows;
  Point *pInput;
  Point *pOutput;
  Point *Points[MAX_POINTS];
};


/**
* @brief Inicializa un mapa
* @param nada
* @return pm (estructura inicializada)
*/
Map * map_ini(){
  int i;
  Map *pm;
  pm = (Map*) malloc (sizeof(Map));
  if (pm == NULL){
    return NULL;
  }
  else {
    for (i=0; i<MAX_POINTS; i++){
      pm->Points[i]=NULL;
    }
    pm->pOutput=NULL;
    pm->pInput=NULL;
    pm->nRows=0;
    pm->nColumns=0;
    }
  return pm;
}


/**
* @brief Libera la memoria de un mapa
* @param pm : Puntero al mapa
* @return nada (void)
*/
void map_free(Map * pm){
  int i;
  if (pm == NULL){
    return;
  }
  else {
    for (i=0; i<MAX_POINTS; i++){
      free(pm->Points[i]);
    }
    free(pm);
  }
}


/**
* @brief Obtiene las filas del mapa
* @param pm : Puntero al mapa (constante,no se pretende modificar)
* @return campo de filas (pm->nRows)
*/
int map_getNrows(const Map * pm){
  if (pm == NULL){
    return (-1);
  }
  else {
    return pm->nRows;
  }
}


/**
* @brief Obtiene las columnas del mapa
* @param pm : Puntero al mapa (constante,no se pretende modificar)
* @return campo de columnas (pm->nColumns)
*/
int map_getNcols(const Map * pm){
  if (pm == NULL){
    return (-1);
  }
  else {
    return pm->nColumns;
  }
}


/**
* @brief Obtiene el puntero de input
* @param pm : Puntero al mapa (constante,no se pretende modificar)
* @return campo de puntero a Point (pm->Input)
*/
Point * map_getInput(const Map *pm){
  if (pm==NULL){
    return NULL;
  }
  else {
    return pm->pInput;
  }
}


/**
* @brief Obtiene el puntero de output
* @param pm : Puntero al mapa (constante,no se pretende modificar)
* @return campo de puntero a Point (pm->Output)
*/
Point * map_getOutput(const Map *pm){
  if (pm==NULL){
    return NULL;
  }
  else {
    return pm->pOutput;
  }
}


/**
* @brief Obtiene el punto vecino a el pasado por parametro
* @param pm : Puntero al mapa (constante,no se pretende modificar)
* @param pp : Puntero al point (constante,no se pretende modificar)
* @param move : tipo Move (indica el movimiento de nuestro punto)
* @return ppaux (el punto vecino (su localizacion)).
*/
Point * map_getNeighborPoint(const Map *pm, const Point *pp, const Move mov){
  Point * ppaux;
  if (point_getCoordinateX(pp) < (pm->nColumns) || point_getCoordinateY(pp) < (pm->nRows) ||(point_getCoordinateX(pp)*point_getCoordinateY(pp)) < 0){
    return NULL;
  }

  if (pm == NULL){
    return NULL;
  }
  else {
    if (mov == RIGHT){
      ppaux=(Point *)(long )EXCELENTISIMA_FORMULA(point_getCoordinateX(pp)+1,point_getCoordinateY(pp),pm->nColumns);
    }
    else if (mov == UP){
      ppaux=(Point *)(long )EXCELENTISIMA_FORMULA(point_getCoordinateX(pp),point_getCoordinateY(pp)+1,pm->nColumns);
    }
    else if (mov == LEFT){
      ppaux=(Point *)(long )EXCELENTISIMA_FORMULA(point_getCoordinateX(pp)-1,point_getCoordinateY(pp),pm->nColumns);
    }
    else if (mov == DOWN){
      ppaux=(Point *)(long )EXCELENTISIMA_FORMULA(point_getCoordinateX(pp),point_getCoordinateY(pp)-1,pm->nColumns);
    }
    /*STAY*/
    else {
      ppaux=(Point *)(long )EXCELENTISIMA_FORMULA(point_getCoordinateX(pp),point_getCoordinateY(pp),pm->nColumns);
    }
    return ppaux;
  }
}


/**
* @brief Modifica el tamaño del mapa
* @param pm : Puntero al mapa (constante,no se pretende modificar)
* @param nRows : entero (numero de filas)
* @param nColumns : entero (numero de columnas)
* @return status OK o ERROR
*/
Status map_setSize(Map *pm, int nRows, int nColumns){
  int i;
  if (pm == NULL){
    return ERROR;
  }
  else {
    pm->nRows = nRows;
    pm->nColumns = nColumns;
    for (i=0;i<MAX_POINTS;i++){
      pm->Points[i] = NULL;
    }

  }
  return OK;
}


/**
* @brief Modifica un punto pasado por parametro
* @param pm : Puntero al mapa
* @param pp : Puntero a Point que (constante)
* @return status OK o ERROR
*/
Status map_setPoint(Map * pm, const Point* pp){
  Point * ppaux;
  int k;
  if (pm == NULL|| pp==NULL){
    return ERROR;
  }
  else {
    k = EXCELENTISIMA_FORMULA(point_getCoordinateX(pp), point_getCoordinateY(pp),pm->nColumns);
    ppaux = (pm->Points[k]);
    if (ppaux == NULL){
      pm->Points[k]=point_copy(pp);
    }
    else{
      point_setSymbol(pm->Points[k], point_getSymbol(pp));
    }
    return OK;
  }
}


/**
* @brief Imprime el mapa pasado por fichero
* @param pf : Puntero a FILE (entrada de datos)
* @param pp : Puntero a Point que (constante)
* @return (-1)=>error o 0=>exito
*/
int map_print(FILE *pf, const Map * pm){
  int i,j;
  char flag;

  Point * point;
  if (!pf || !pm){
    return (-1);
  }
  else {
    for (i=0; i<(pm->nRows); i++){
      for (j=0; j<(pm->nColumns); j++){
        point=pm->Points[(i*pm->nColumns)+j];
        flag=point_getSymbol(point);
        fprintf(pf, "%c", flag);
      }
      fprintf (pf, "\n");
    }
  }
  return 0;
}


/**
* @brief Se encarga de leer el mapa
* @param pf : Puntero a FILE (entrada de datos)
* @param pl : Puntero a Map
* @return status OK o ERROR
*/
Status map_read (FILE *pf, Map *pl) {
 char buff[MAX_POINTS];
 int i, j, nrows, ncols/*indice*/;
 Point *temp;
 Status st = ERROR;

 if (pl==NULL || pf==NULL){
   return st;
 }
 /*creamos punto que se utiliza como buffer*/
 temp = point_ini(0, 0, ERRORCHAR);
 if (temp==NULL){
   return st;
 }
 /* asignamos dimensión al mapa */
 fgets(buff, MAX_POINTS, pf);
 sscanf(buff, "%d %d", &nrows, &ncols);
 st = map_setSize (pl, nrows, ncols);
 if (st == ERROR){
   return ERROR;
 }
 /* leemos el fichero linea a linea */
 for(i=0; i < nrows;i++) {
   fgets(buff, MAX_POINTS, pf);
   for (j=0; j < ncols; j++) {
   /* ajustamos los atributos del punto leído  */
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
    /* insertamos el punto en el mapa  */
     if (map_setPoint(pl,temp)==ERROR){
       return ERROR;
     }
   }
 }

 /* libera recursos */
 point_destroy(temp);
 /* no cerramos el fichero ya que lo han abierto fuera */
 return OK;
}

BOOL deep_map_point_search (Map *map,Point* point_inp,Stack* stack){
  Element *ele;
  Element *ele_visited;
  Point * p_aux;
  if (map == NULL || point_inp == NULL || stack == NULL){
    return FALSE;
  }
  ele = element_ini();

  if (ele == NULL){
    return FALSE;
  }
  stack_push(stack,element_setInfo(ele,point_inp));
  while (stack_isEmpty(stack)==FALSE){
    ele_visited = stack_pop(stack);

    if (point_getSymbol(element_setInfo(ele,point_inp))!= VISITED){
      map_setPoint(map,element_setInfo(ele,point_inp));
      for (i=0;i<4;i++){
        p_aux = map_getNeighborPoint(map,point_inp,i);
        if (point_isOutput(p_aux) == TRUE){
          return p_aux;
        }
        if (point_isSpace(p_aux) == TRUE{
          stack_push(stack,p_aux);
        }
      }
    }
  }
}
