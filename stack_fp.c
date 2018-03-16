#include "element.h"

Stack * stack_ini(destroy_element_function_type f1, copy_element_function_type f2, print_element_function_type f3){

}

void stack_destroy(Stack *s){
  int i;

  if (s == NULL){
    return;
  }

  for (i=0; i<s->top; i++){
    element_destroy(s->datos[i]);
  }
  free (s);
}

Status stack_push(Stack *s, const void *ele){
  Element *ayudita;

  if (s == NULL || ele == NULL){
    return NULL;
  }

  s->datos[s->top]=element_copy(ele);
  if (s->datos[s->top]==NULL){
    return NULL;
  }
  s->top++;
}

void * stack_pop(Stack *s){
  Element *copia;

  if (s==NULL){
    return;
  }
  
}
