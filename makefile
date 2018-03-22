########################################################
CC=gcc
CFLAGS= -g -Wall -pedantic -ansi
EJS = p1_e1 p1_e2 p2_e1 p2_e2 p2_e3
########################################################
OBJECTSP1E1 = p1_e1.o point.o
OBJECTSP1E2 = p1_e2.o map.o point.o stack_element.o element-point.o
OBJECTSP2E1 = p2_e1.o stack_element.o element-int.o
OBJECTSP2E2 = p2_e2.o stack_element.o element-point.o map.o point.o
OBJECTSP2E3 = p2_e3.o stack_element.o element-point.o map.o point.o
########################################################
MEMORIES_TO_SUBMIT =*.pdf
DIST_NAME =P2_Prog2_G2163_P11
HEADERS_TO_SUBMIT=*.h
SOURCES_TO_SUBMIT=point.c map.c p1_e1.c p1_e2.c p2_e1.c p2_e2.c p2_e3.c stack_element.c element-int.c element-point.c
SUPPORT_TO_SUBMIT=makefile


.PHONY: all
all: $(EJS)

p1_e1: $(OBJECTSP1E1)
	$(CC) $(CFLAGS) -o p1_e1 $(OBJECTSP1E1)

p1_e2: $(OBJECTSP1E2)
	$(CC) $(CFLAGS) -o p1_e2 $(OBJECTSP1E2)

p2_e1: $(OBJECTSP2E1)
	$(CC) $(CFLAGS) -o p2_e1 $(OBJECTSP2E1)

p2_e2: $(OBJECTSP2E2)
	$(CC) $(CFLAGS) -o p2_e2 $(OBJECTSP2E2)

p2_e3: $(OBJECTSP2E3)
	$(CC) $(CFLAGS) -o p2_e3 $(OBJECTSP2E3)

p1_e1.o: p1_e1.c point.h
	$(CC) $(CFLAGS) -c p1_e1.c

p1_e2.o: p1_e2.c map.h
	$(CC) $(CFLAGS) -c p1_e2.c

p2_e1.o: p2_e1.c stack_element.h element.h
	$(CC) $(CFLAGS) -c p2_e1.c

p2_e2.o: p2_e2.c stack_element.h element.h map.h point.h
	$(CC) $(CFLAGS) -c p2_e2.c

p2_e3.o: p2_e3.c stack_element.h element.h map.h point.h types.h
	$(CC) $(CFLAGS) -c p2_e3.c

point.o: point.c point.h
	$(CC) $(CFLAGS) -c point.c

map.o: map.c map.h point.h element.h types.h stack_element.h
	$(CC) $(CFLAGS) -c map.c

stack_element.o: stack_element.c stack_element.h element.h types.h
	$(CC) $(CFLAGS) -c stack_element.c

element-int.o: element-int.c element.h
	$(CC) $(CFLAGS) -c element-int.c

element-point.o: element-point.c element.h point.h
	$(CC) $(CFLAGS) -c element-point.c

.PHONY: clean
clean:
	rm -rf *.o $(EJS) *dSYM #borra (APPLE)

.PHONY: run
run:
	@echo ">>>>>>Running p1_e1"
	./p1_e1
	@echo ">>>>>>Running p1_e2"
	./p1_e2
	@echo ">>>>>>Running p1_e1"
	./p1_e1
	@echo ">>>>>>Running p2_e1"
	./p2_e1

.PHONY : runvv
runvv:
	@echo ">>>>>>Running p1_e2 with valgrind"
	valgrind --leak-check=full ./p2_e1

.PHONY: runv
runv:
	@echo ">>>>>>Running p1_e1 with valgrind"
	valgrind --leak-check=full ./p1_e1
	@echo ">>>>>>Running p1_e2 with valgrind"
	valgrind --leak-check=full ./p1_e2

.PHONY: dist
dist:
	@echo "Preparando para enviar"
	rm -f $(DIST_NAME).rar #si existe los soobrescribe (borra antes)
	mkdir -p $(DIST_NAME) #crea un directorio donde van a estar los archivos
	cp $(HEADERS_TO_SUBMIT) $(SOURCES_TO_SUBMIT) $(SUPPORT_TO_SUBMIT) $(MEMORIES_TO_SUBMIT) $(DIST_NAME)/  #se ponen en el directorio recien creado los archivos incluyendo pdfs
	zip $(DIST_NAME).rar $(DIST_NAME)/* #Se genera el comprimido .tar con el directorio creado
	rm -rf $(DIST_NAME)
	@echo "Estado:listo para enviar"
