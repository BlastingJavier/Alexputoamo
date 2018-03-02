/*
*@brief Implementacion EdD puntos
*
*@file point.c
@author FJNR & AMH
@version 1.0
@date 14/02/2018
@copyright GNU Public License
*/
#include<stdio.h>
#include<string.h>
#include "point.h"
/*Estructura con componentes de un punto*/
struct _Point {
char symbol;
int x;
int y;
};


/**
* @brief Inicializa un punto
* @param x coordenada
* @param y coordenada
* @param symbol char
* @return pp puntero a point (iniciado interiormente) o NULL
*/
Point *point_ini (int x, int y,char symbol){
  Point *pp;
  pp = (Point*)malloc(sizeof(Point));
  if (pp == NULL){
    return NULL;
  }
  else {
    pp->x = x;
    pp->y = y;
    pp->symbol = symbol;

  }
  return pp;
}


/**
* @brief Libera la memoria de un punto
* @param pp puntero a Point
* @return nada (void)
*/
void point_destroy (Point *pp){
  if (pp == NULL){
    return;
  }
  else {
    free(pp);
    return;
  }
}


/**
* @brief Modifica el campo x de un punto
* @param pp puntero a Point
* @param x coordenada nueva
* @return status OK o ERROR
*/
Status point_setCoordinateX (Point *pp ,const int x){
  if (pp == NULL){
    return ERROR;
  }
  else {
    pp->x = x;
    return OK;
  }
}


/**
* @brief Modifica el campo y de un punto
* @param pp puntero a Point
* @param y coordenada nueva
* @return status OK o ERROR
*/
Status point_setCoordinateY (Point *pp ,const int y){
  if (pp == NULL) {
    return ERROR;
  }
  else {
    pp->y = y;
    return OK;
  }
}


/**
* @brief Modifica el simbolo de un punto
* @param pp puntero a Point
* @param symbol :Nuevo simbolo
* @return status OK o ERROR
*/
Status point_setSymbol (Point *pp,const char symbol){
  if (pp == NULL){
    return ERROR;
  }
  else {
    pp->symbol = symbol;
    return OK;
  }
}


/**
* @brief Obtiene el campo de Point (x) ,de un punto
* @param pp puntero a Point (const no se pretende modificar)
* @return pp->x campo de Point (int) (coodenada x)
*/
int point_getCoordinateX (const Point *pp){
  if (pp == NULL){
    return 0;
  }
  else {
    return pp->x;
  }
}

/**
* @brief Obtiene el campo de Point (y) ,de un punto
* @param pp puntero a Point (const no se pretende modificar)
* @return pp->y campo de Point (int) (coodenada y)
*/
int point_getCoordinateY (const Point *pp){
  if (pp == NULL){
    return 0;
  }
  else {
    return pp->y;
  }
}


/**
* @brief Obtiene el campo (simbolo) ,de un punto
* @param pp puntero a Point (const no se pretende modificar)
* @return pp->symbol campo de Point (int) (symbolo asignado)
*/
char point_getSymbol (const Point *pp){
  if (pp == NULL){
    return 0;
  }
  else {
    return pp->symbol;
  }
}

/**
* @brief Hace una copia de un punto
* @param pp1 puntero a Point (const no se pretende modificar)
* @return pp puntero a Point (modifica todos los campos)
*/
Point * point_copy (const Point *pp1){
  Point *copia;
  int auxx , auxy;
  char auxsymbol;
  copia = (Point *)malloc(sizeof(Point));
  if (copia == NULL){
    return NULL;
  }
  if (pp1==NULL){
    return NULL;
  }
  else {
    auxx =  point_getCoordinateX(pp1);
    auxy =  point_getCoordinateY(pp1);
    auxsymbol =  point_getSymbol(pp1);
  }
  copia = point_ini(auxx,auxy,auxsymbol);
  return copia;
}


/**
* @brief Imprime un punto
* @param pp1 puntero a Point (const no se pretende modificar)
* @param pf puntero a FILE ,el fichero.
* @return 0 o  la impresion
*/
int point_print (FILE *pf ,const Point *pp){
  if (pp == NULL){
    return 0;
  }
  if (pf == NULL){
    return 0;
  }
  else {
    return fprintf(pf,"[(%d,%d):'%c']",pp->x,pp->y,pp->symbol);
  }
}

/**
* @brief Compara dos puntos
* @param pp1 puntero a Point (const no se pretende modificar)
* @param pp2 puntero a Point (const no se pretende modificar)
* @return Bool TRUE o FALSE
*/
Bool point_equals(const Point * pp1 , const Point * pp2){
  if (pp1 == NULL){
    return FALSE;
  }
  if (pp2 == NULL){
    return FALSE;
  }
  else {
    if ((pp1->x == pp2->x)&&(pp1->y ==pp2->y)&&(pp1->symbol == pp2->symbol)){
      return TRUE;
    }
    else {
      return FALSE;
    }

  }
}
                  /*FUNCIONES DERIVADAS*/
/**
* @brief Compara el punto dado con INPUT
* @param pp puntero a Point (const no se pretende modificar)
* @return Bool TRUE o FALSE
*/
Bool point_isInput(Point* pp){
  if (pp == NULL){
    return FALSE;
  }
  else {
    if (pp->symbol == INPUT){
      return TRUE;
    }
    else {
      return FALSE;
    }
  }
}


/**
* @brief Compara el punto dado con OUTPUT
* @param pp puntero a Point (const no se pretende modificar)
* @return Bool TRUE o FALSE
*/
Bool point_isOutput(Point* pp){
  if (pp == NULL){
    return FALSE;
  }
  else {
    if (pp->symbol == OUTPUT){
      return TRUE;
    }
    else {
      return FALSE;
    }
  }
}

/**
* @brief Compara el punto dado con BARRIER
* @param pp puntero a Point (const no se pretende modificar)
* @return Bool TRUE o FALSE
*/
Bool point_isBarrier(Point* pp){
  if (pp == NULL){
    return FALSE;
  }
  else {
    if (pp->symbol == BARRIER){
      return TRUE;
    }
    else {
      return FALSE;
    }
  }
}


/**
* @brief Compara el punto dado con SPACE
* @param pp puntero a Point (const no se pretende modificar)
* @return Bool TRUE o FALSE
*/
Bool point_isSpace(Point* pp){
  if (pp == NULL){
    return FALSE;
  }
  else {
    if (pp->symbol == SPACE){
      return TRUE;
    }
    else {
      return FALSE;
    }
  }
}
