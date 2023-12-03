# Variable
CFLAGS = -ansi -pedantic -lgraph
OFILES = main.o vue.o modele.o controlleur.o
EXEC = jouer

# Compilation du ficher executable "jouer.exe"
$(EXEC) : $(OFILES)
	gcc $(CFLAGS) -o $(EXEC)  $(OFILES)

controlleur.o : controlleur.c  controlleur.h 
	gcc $(CFLAGS) -c controlleur.c

modele.o : modele.c modele.h 
	gcc $(CFLAGS) -c modele.c

vue.o : vue.c vue.h
	gcc $(CFLAGS) -c vue.c

main.o : main.c vue.h modele.h
	gcc $(CFLAGS) -c main.c
