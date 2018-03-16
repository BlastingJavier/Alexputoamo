/*
* En este fichero se definen las funciones de destrucción, copia e impresión de elementos a almacenar en
* una pila para distintos tipos de datos
*/
/* Las siguientes funciones se usarán cuando se quieran guardar enteros en la pila. Ojo! Estas funciones
reciben un puntero a entero, no una estructura con un puntero a entero (igual que en el ejercicio P2_E1) */
void destroy_intp_function(void* e){
free((int*)e);
}
void * copy_intp_function(const void* e){
int * dst;
if (e == NULL)
return NULL;
dst = (int*)malloc(sizeof(int));
/*Copiamos el elemento*/
*(dst) = *((int*)e);
return dst;
}
int print_intp_function(FILE * f, const void* e){
if (f != NULL && e != NULL)
return fprintf(f, "[%d]", *((int*)e));
return -1;
}
/* Las siguientes se usarán cuando se quieran guardar puntos en la pila */
void destroy_point_function(void* e){
point_destroy((Point *)e);
}
void * copy_point_function(const void* e){
return point_copy((Point *)e);
}
int print_point_function(FILE * f, const void* e){
return point_print(f, (Point *)e);
}
