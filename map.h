/*
*@brief Interfaz de mapa (TAD)
*
*@file map.h
@author FJNR & AMH
@version 1.0
@date 14/02/2018
@copyright GNU Public License
*/
#ifndef MAP_H
#define MAP_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "point.h"
#include "stack_element.h"
/*Estructura con componentes del mapa (caracteristicas) y el array de punteros
  a puntos*/
typedef struct _Map Map;

/*Diferentes movimientos de un punto*/
typedef enum {
  RIGHT=0,
  UP=1,
  LEFT=2,
  DOWN=3,
  STAY=4
} Move;


/**
* @brief Inicializa un mapa
* @param nada
* @return pm (estructura inicializada) o NULL
*/
Map * map_ini();


/**
* @brief Libera la memoria de un mapa
* @param pm : Puntero al mapa
* @return nada (void)
*/void map_free(Map * pm);


/**
* @brief Obtiene las filas del mapa
* @param pm : Puntero al mapa (constante,no se pretende modificar)
* @return (-1) o campo de filas (pm->nRows)
*/int map_getNrows(const Map * pm);


/**
* @brief Obtiene las columnas del mapa
* @param pm : Puntero al mapa (constante,no se pretende modificar)
* @return (-1) o campo de columnas (pm->nColumns)
*/int map_getNcols(const Map * pm);


/**
* @brief Obtiene el puntero de input
* @param pm : Puntero al mapa (constante,no se pretende modificar)
* @return NULL o campo de puntero a Point (pm->Input)
*/
Point * map_getInput(const Map * pm);


/**
* @brief Obtiene el puntero de output
* @param pm : Puntero al mapa (constante,no se pretende modificar)
* @return NULL o campo de puntero a Point (pm->Output)
*/
Point * map_getOutput(const Map * pm);


/**
* @brief Obtiene el punto vecino a el pasado por parametro
* @param pm : Puntero al mapa (constante,no se pretende modificar)
* @param pp : Puntero al point (constante,no se pretende modificar)
* @param move : tipo Move (indica el movimiento de nuestro punto)
* @return NULL o ppaux (el punto vecino (su localizacion)).
*/
Point * map_getNeighborPoint(const Map *pm, const Point *pp, const Move mov);


/**
* @brief Modifica el tamaño del mapa
* @param pm : Puntero al mapa (constante,no se pretende modificar)
* @param nRows : entero (numero de filas)
* @param nColumns : entero (numero de columnas)
* @return status OK o ERROR
*/
Status map_setSize(Map *pm, int nRows, int nColumns);


/**
* @brief Modifica un punto pasado por parametro
* @param pm : Puntero al mapa
* @param pp : Puntero a Point que (constante)
* @return status OK o ERROR
*/
Status map_setPoint(Map * pm, const Point* pp);


/**
* @brief Imprime el mapa pasado por fichero
* @param pf : Puntero a FILE (entrada de datos)
* @param pp : Puntero a Point que (constante)
* @return (-1)=>error o 0=>exito
*/
int map_print(FILE *pf, const Map * pm);


/**
* @brief Se encarga de leer el mapa
* @param pf : Puntero a FILE (entrada de datos)
* @param pl : Puntero a Map
* @return status OK o ERROR
*/
Status map_read (FILE *pf, Map *pl);


Bool deep_map_point_search (Map *map,Point* point_inp);

#endif
