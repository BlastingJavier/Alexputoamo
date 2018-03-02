#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include "stack_element.h"
#define MAX 5

int main (){
  int num1 , num2 , num3;
  int i, aux;
  Stack * s1 , *s_impar , *s_par;
  Element * ele;

  s1 = stack_ini();
  s_par = stack_ini();
  s_impar = stack_ini();
  ele = element_ini();

  printf("Pila total: ");
  comprobar_pila(stdout,s1);

  printf ("Introduce un numero");
  scanf("%d",&num1);
  element_setInfo(ele,&num1);
  stack_push (s1,ele);

  printf ("Introduce un numero");
  scanf("%d",&num2);
  element_setInfo(ele,&num2);
  stack_push (s1,ele);

  printf ("Introduce un numero");
  scanf("%d",&num3);
  element_setInfo(ele,&num3);
  stack_push (s1,ele);

  printf("Pila total: ");
  comprobar_pila(stdout,s1);

  printf("\n");
  stack_print(stdout,s1);

  for (i=0;i<3;i++){
    ele = stack_pop(s1);
    aux = *((int*)element_getInfo(ele));
    if (aux%2 == 0){
      stack_push(s_par,ele);
    }
    else {
      stack_push(s_impar,ele);
    }
  }
  printf("Imprimiendo la pila: ");;
  comprobar_pila(stdout,s_par);
  printf("Con numeros pares: ");
  stack_print(stdout, s_par);

  printf("Imprimiendo la pila :");
  comprobar_pila(stdout ,s_impar);
  printf("Con numeros impares: ");
  stack_print(stdout , s_impar);

  return 0;
}
