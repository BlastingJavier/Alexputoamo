#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include "point.h"

struct _Element {
  Point *info;
};

Element * element_ini(){
  Element *new_element;
  new_element = (Element*)malloc(sizeof(Element));
  if (new_element == NULL){
    return NULL;
  }
  new_element->info = NULL;

  return new_element;
}



void element_destroy(Element *ele){
  if (ele == NULL){
    return;
  }
  free(ele->info);
  free(ele);
  return;
}



Status element_setInfo(Element *ele,void *po){
  if (ele == NULL || po == NULL){
    return ERROR;
  }
  if (ele->info != NULL){
    free(ele->info);
  }
  /*point_ini(point_getCoordinateX(point_copy((Point*)po)),point_getCoordinateY(point_copy((Point*)po)),point_getSymbol(point_copy((Point*)po)));*/
  ele->info = point_copy((Point*)po);
  if (ele->info == NULL){
    return ERROR;
  }
  return OK;
}



void * element_getInfo(Element *ele){
  if (ele == NULL){
    return NULL;
  }
  return ele->info;
}



Element *element_copy (const Element *ele){
  Element *aux;
  if (ele == NULL){
    return NULL;
  }
  aux = element_ini();
  if (aux==NULL){
    return NULL;
  }
  aux->info = point_copy(ele->info);
  if (aux->info == NULL ){
    return NULL;
  }
  return aux;
}



Bool element_equals (const Element *ele , const Element *ele2){
  if (ele == NULL){
    return FALSE;
  }
  if (ele->info == ele2->info){
    return TRUE;
  }
  return FALSE;
}



int element_print (FILE *pf , const Element * ele){
  if (ele == NULL || pf == NULL || ele->info == NULL){
    return 0;
  }
  else {
    return fprintf (pf ,"[(%d,%d):'%c']\n",point_getCoordinateX(ele->info),point_getCoordinateY(ele->info),point_getSymbol(ele->info));
  }
}
