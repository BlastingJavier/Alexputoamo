/*
*@brief Pila de elementos
*
*@file stack_element.c
@author FJNR & AMH
@version 1.0
@date 22/02/2018
@copyright GNU Public License
*/
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "types.h"
#include "element.h"
#include "stack_element.h"

#define MAXSTACK 1200

struct _Stack {
  int top;
  Element* item[MAXSTACK];
};

Stack * stack_ini(){
  Stack * new_stack;
  int i;
  new_stack = (Stack*)malloc (sizeof(Stack));
  if (new_stack == NULL){
    return NULL;
  }
  new_stack->top = 0;

  for (i=0;i<MAXSTACK;i++){
    new_stack->item[i] = NULL;
  }

  return new_stack;
}

void stack_destroy(Stack *s){
  int i;
  if (s == NULL){
    return;
  }
  for (i=0;i<s->top;i++){
    free(s->item[i]);

  }
  free (s);
  return;
}
Status stack_push(Stack *s, const Element *ele){
  if (!s || !ele){
    return ERROR;
  }
  if (stack_isFull(s) == TRUE){
    return ERROR;
  }
  s->item[s->top] = element_copy(ele);
  if (s->item[s->top] == NULL){
    return ERROR;
  }
  s->top++;
  return OK;
}

Element * stack_pop(Stack *s){
  Element * aux =NULL;
  if (s == NULL){
    return NULL;
  }
  if (stack_isEmpty(s) == TRUE){
    return NULL;
  }
  aux = s->item[(s->top)-1];
  s->item[s->top] = NULL;
  s->top--;
  return aux;
}
Element * stack_top(const Stack *s){
  Element *aux;
  if (s == NULL){
    return NULL;
  }
  if (stack_isEmpty(s)==FALSE){
    aux = element_copy(s->item[s->top]);
  }
  return aux;
}
Bool stack_isEmpty(const Stack *s){
  if (s == NULL){
    return FALSE;
  }
  if (s->top == 0){
    return TRUE;
  }
  return FALSE;
}
Bool stack_isFull(const Stack *s){
  if (s == NULL){
    return FALSE;
  }
  if (s->top == (MAXSTACK-1)){
    return TRUE;
  }
  return FALSE;
}
int stack_print(FILE* pf, const Stack* s){
  int i;
  if (s == NULL){
    return 0;
  }
  for (i=s->top;i>=0;i--){
    element_print(stdout,s->item[i]);
  }
  return 1;
}
void comprobar_pila(FILE* pf,const Stack *s){
  if (s == NULL){
    return ;
  }
  else {
    /*Control de errores: Comprobacion del estado de la pila*/
    if (stack_isEmpty(s)==TRUE && stack_isFull(s)==FALSE){
      fprintf(pf,"(no llena , vacia)");
      fprintf(pf,"\n");
    }
    else if (stack_isEmpty(s)==FALSE && stack_isFull(s)==TRUE){
      fprintf(pf,"(Llena , no vacia)");
      fprintf(pf,"\n");
    }
    else if (stack_isEmpty(s)==FALSE && stack_isFull(s)==FALSE){
      fprintf(pf,"(no llena , no vacia)");
      fprintf(pf,"\n");
    }
    else {
      return;/*Una pila no puede estar llena y vacia a la vez*/
    }
  }
}
