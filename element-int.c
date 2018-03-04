#include <stdio.h>
#include <stdlib.h>
#include "element.h"

struct _Element {
  int *info;
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



Status element_setInfo(Element *ele, void* po){
  if (ele == NULL || po == NULL){
    return ERROR;
  }
  if (ele->info != NULL){
    free(ele->info);
  }
  ele->info = (int*)malloc(sizeof(int));
  if (ele->info == NULL){
    return ERROR;
  }
  *(ele->info) = *((int *)po);
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
  aux = (Element *)malloc(sizeof(Element));
  if (aux==NULL){
    return NULL;
  }
  aux->info = (int*)malloc(sizeof(int));
  if (aux->info == NULL){
    return NULL;
  }
  *(aux->info) = *(ele->info);
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
    return fprintf (pf ,"%d\n",*((int*)ele->info));
  }
}
