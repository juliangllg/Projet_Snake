# Variable
CFLAGS = -ansi -pedantic 
OFILES = main.o vue.o modele.o controlleur.o
EXEC = jouer

# Compilation du ficher executable "jouer.exe"
$(EXEC) : $(OFILES)
	gcc $(CFLAGS) -o $(EXEC)  $(OFILES) -lgraph	

controlleur.o : controlleur.c  controlleur.h 
	gcc $(CFLAGS) -c controlleur.c -lgraph

modele.o : modele.c modele.h 
	gcc $(CFLAGS) -c modele.c -lgraph

vue.o : vue.c vue.h
	gcc $(CFLAGS) -c vue.c -lgraph

main.o : main.c vue.h modele.h
	gcc $(CFLAGS) -c main.c -lgraph
