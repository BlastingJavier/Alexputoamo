#include <stdio.h>
#include <stdlib.h>

#include "stack_element.h"
#include "point.h"

struct _Element {
  Point *coordenadax;
  Point *coordenaday;
  Point *elesymbol;
};

Element * element_ini(){
  Element *new_element;
  new_element = (Element*)malloc(sizeof(Element));
  if (new_element == NULL){
    return NULL;
  }
  new_element->coordenadax = NULL;
  new_element->coordenaday = NULL;
  new_element->elesymbol = NULL;

  return new_element;
}
void element_destroy(Element *ele){
  if (ele == NULL){
    return;
  }
  free(ele->coordenadax);
  free(ele->coordenaday);
  free(ele->elesymbol);

  free(ele);
  return;
}
Status element_setInfo(Element *ele, void* px , void* py , void*ps){
  if (ele == NULL || po == NULL){
    return ERROR;
  }
  if (ele->coordenadax != NULL && ele->coordenaday != NULL && ele->elesymbol != NULL){
    free(ele->coordenadax);
    free(ele->coordenaday);
    free(ele->elesymbol);
  }
  ele = (Point*)malloc(sizeof(Point));
  if (ele == NULL){
    return ERROR;
  }
  *(ele->coordenadax) = point_getCoordinateX ((int*)px);
  *(ele->coordenaday) = point_getCoordinateX ((int*)py);
  *(ele->elesymbol) = point_getCoordinateX ((char*)ps);

  return OK;
}
Point * element_getCoordinatex(Element *ele){
  if (ele == NULL){
    return NULL;
  }
  return ele->coordenadax;
}
Point * element_getCoordinatey(Element *ele){
  if (ele == NULL){
    return NULL;
  }
  return ele->coordenaday;
}
Point * element_getSymbol(Element *ele){
  if (ele == NULL){
    return NULL;
  }
  return ele->elesymbol;
}
Element *element_copy (const Element *ele){
  Element *aux;
  if (ele == NULL){
    return NULL;
  }
  aux = (Element *)malloc(sizeof(Element));
  if (aux==NULL){
    return NULL;
  }
  *(aux->coordenadax) = *(ele->coordenadax);
  *(aux->coordenaday) = *(ele->coordenaday);
  *(aux->elesymbol) = *(ele->elesymbol);

  return aux;
}
Bool element_equals (const Element *ele , const Element *ele2){
  if (ele == NULL){
    return FALSE;
  }
  if (point_equals(ele,ele2)==TRUE){
    return TRUE;
  }
  return FALSE;
}
int element_print (FILE *pf , const Element * ele){
  if (ele == NULL || pf == NULL || ele->coordenadax == NULL || ele->coordenaday == NULL|| ele->elesymbol == NULL){
    return 0;
  }
  else {
    return fprintf (pf ,"%d\n",*((int*)ele->info));
  }
}
