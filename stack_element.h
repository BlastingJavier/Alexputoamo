/*
*@brief Interfaz de stack (TAD)
*
*@file stack_element.h
@author FJNR & AMH
@version 1.0
@date 22/02/2018
@copyright GNU Public License
*/

#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"
#include "element.h"


typedef struct _Stack Stack;
/**------------------------------------------------------------------
Inicializa la pila reservando memoria. Salida: NULL si ha habido error o la pila si ha ido bien
------------------------------------------------------------------*/
Stack * stack_ini();
/**------------------------------------------------------------------
Elimina la pila Entrada: la pila que se va a eliminar
------------------------------------------------------------------*/
void stack_destroy(Stack *s);
/**------------------------------------------------------------------
Inserta un elemento en la pila. Entrada: un elemento y la pila donde insertarlo. Salida: ERROR si no logra
insertarlo, OK si lo logra
------------------------------------------------------------------*/
Status stack_push(Stack *s, const Element *ele);
/**------------------------------------------------------------------
Extrae un elemento en la pila. Entrada: la pila de donde extraerlo. Salida: NULL si no logra extraerlo o el
elemento extraido si lo logra. Nótese que la pila quedará modificada
------------------------------------------------------------------*/
Element * stack_pop(Stack *s);
/**------------------------------------------------------------------
Copia un elemento (reservando memoria) sin modificar el top de la pila. Entrada: la pila de donde copiarlo.
Salida: NULL si no logra copiarlo o el elemento si lo logra
------------------------------------------------------------------*/
Element * stack_top(const Stack *s);
/**------------------------------------------------------------------
Comprueba si la pila esta vacia. Entrada: pila. Salida: TRUE si está vacia o FALSE si no lo esta
------------------------------------------------------------------*/
Bool stack_isEmpty(const Stack *s);
/**------------------------------------------------------------------
Comprueba si la pila esta llena. Entrada: pila. Salida: TRUE si está llena o FALSE si no lo esta
------------------------------------------------------------------*/
Bool stack_isFull(const Stack *s);
/**------------------------------------------------------------------
Imprime toda la pila, colocando el elemento en la cima al principio de la impresión (y un elemento por línea).
Entrada: pila y fichero donde imprimirla. Salida: Devuelve el número de caracteres escritos.
------------------------------------------------------------------*/
int stack_print(FILE* pf, const Stack* s);
void comprobar_pila(FILE* pf,const Stack *s);
#endif
