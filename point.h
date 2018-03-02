/*
*@brief Interfaz de puntos (TAD)
*
*@file point.h
@author FJNR & AMH
@version 1.0
@date 14/02/2018
@copyright GNU Public License
*/
#ifndef POINT_H
#define POINT_H

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "types.h"

/*
Constantes públicas que definen los tipos de puntos
que se permiten en un mapa
*/

#define ERRORCHAR 'E'
#define INPUT 'i'
#define VISITED 'v'
#define OUTPUT 'o'
#define BARRIER '+'
#define SPACE ' '

/*Estructura con componentes de un punto*/
typedef struct _Point Point;


/**
* @brief Inicializa un punto
* @param x coordenada
* @param y coordenada
* @param symbol char
* @return pp puntero a point (iniciado interiormente) o NULL
*/
Point * point_ini(int x, int y, char symbol);


/**
* @brief Libera la memoria de un punto
* @param pp puntero a Point
* @return nada (void)
*/
void point_destroy(Point *pp);


/**
* @brief Obtiene el campo de Point (x) ,de un punto
* @param pp puntero a Point (const no se pretende modificar)
* @return 0 o pp->x campo de Point (int) (coodenada x)
*/
int point_getCoordinateX(const Point *pp);


/**
* @brief Obtiene el campo de Point (y) ,de un punto
* @param pp puntero a Point (const no se pretende modificar)
* @return 0 o pp->y campo de Point (int) (coodenada y)
*/
int point_getCoordinateY(const Point * pp);


/**
* @brief Obtiene el campo (simbolo) ,de un punto
* @param pp puntero a Point (const no se pretende modificar)
* @return 0 o pp->symbol campo de Point (int) (symbolo asignado)
*/
char point_getSymbol(const Point *pp );


/**
* @brief Compara el punto dado con INPUT
* @param pp puntero a Point (const no se pretende modificar)
* @return Bool TRUE o FALSE
*/
Bool point_isInput(Point* pp);


/**
* @brief Compara el punto dado con OUTPUT
* @param pp puntero a Point (const no se pretende modificar)
* @return Bool TRUE o FALSE
*/
Bool point_isOutput(Point* pp);


/**
* @brief Compara el punto dado con BARRIER
* @param pp puntero a Point (const no se pretende modificar)
* @return Bool TRUE o FALSE
*/
Bool point_isBarrier(Point* pp);


/**
* @brief Compara el punto dado con SPACE
* @param pp puntero a Point (const no se pretende modificar)
* @return Bool TRUE o FALSE
*/
Bool point_isSpace(Point* pp);


/**
* @brief Modifica el campo x de un punto
* @param pp puntero a Point
* @param x coordenada nueva
* @return status OK o ERROR
*/
Status point_setCoordinateX(Point *pp, const int x);


/**
* @brief Modifica el campo y de un punto
* @param pp puntero a Point
* @param y coordenada nueva
* @return status OK o ERROR
*/
Status point_setCoordinateY(Point *pp, const int y);


/**
* @brief Modifica el simbolo de un punto
* @param pp puntero a Point
* @param symbol :Nuevo simbolo
* @return status OK o ERROR
*/
Status point_setSymbol(Point *pp, const char symbol);


/**
* @brief Compara dos puntos
* @param pp1 puntero a Point (const no se pretende modificar)
* @param pp2 puntero a Point (const no se pretende modificar)
* @return Bool TRUE o FALSE
*/
Bool point_equals(const Point *pp1 , const Point *pp2);


/**
* @brief Hace una copia de un punto
* @param pp1 puntero a Point (const no se pretende modificar)
* @return NULL o pp puntero a Point (modifica todos los campos)
*/
Point * point_copy(const Point *pp1);


/**
* @brief Imprime un punto
* @param pp1 puntero a Point (const no se pretende modificar)
* @param pf puntero a FILE ,el fichero.
* @return 0 o  la impresion
*/
int point_print(FILE *pf, const Point *pp);
#endif
