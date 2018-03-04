/*
*@brief Interfaz de elemento (TAD)
*
*@file element.h
@author FJNR & AMH
@version 1.0
@date 22/02/2018
@copyright GNU Public License
*/
#ifndef ELEMENT_H
#define ELEMENT_H
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "types.h"
#include "point.h"
#include "map.h"


typedef struct _Element Element;
/**------------------------------------------------------------------
Inicializa un elemento de pila. Salida: Puntero al elemento inicializado o NULL en caso de error
------------------------------------------------------------------*/
Element * element_ini();
/**------------------------------------------------------------------
Elimina un elemento. Entrada: Elemento a destruir.
------------------------------------------------------------------*/
void element_destroy(Element *ele);
/**------------------------------------------------------------------
Modifica los datos de un elemento. Entrada: El elemento a modificar y el contenido a guardar en dicho
elemento. Salida: OK o ERROR si ha habido error.
------------------------------------------------------------------*/
Status element_setInfo(Element *ele, void* po);
/**------------------------------------------------------------------
Devuelve el contenido de Element. Entrada: El elemento. Salida: El contenido de Element o NULL si ha
habido error.
------------------------------------------------------------------*/
void * element_getInfo(Element *ele);
/**------------------------------------------------------------------
Copia un elemento en otro, reservando memoria. Entrada: el elemento a copiar. Salida: Devuelve un puntero
al elemento copiado o NULL en caso de error.
------------------------------------------------------------------*/
Element * element_copy(const Element *ele);
/**------------------------------------------------------------------
Compara dos elementos. Entrada: dos elementos a comparar. Salida: Devuelve TRUE en caso de ser iguales
y si no FALSE
------------------------------------------------------------------*/
Bool element_equals(const Element *ele, const Element *ele2);
/**------------------------------------------------------------------
Imprime en un fichero ya abierto el elemento. Entrada: Fichero en el que se imprime y el elemento a imprimir.
Salida: Devuelve el número de caracteres escritos.
------------------------------------------------------------------*/
int element_print(FILE *pf, const Element * ele);
#endif
