# Variable
CFLAGS = -ansi -pedantic -w 
OFILES = main.o vue.o modele.o controleur.o
EXEC = jouer

# Compilation du ficher executable "jouer.exe"
$(EXEC) : $(OFILES)
	gcc  -o $(EXEC)  $(OFILES) $(CFLAGS) -lgraph	


controleur.o : controleur.c  controleur.h 
	gcc -c controleur.c $(CFLAGS) -lgraph

modele.o : modele.c modele.h 
	gcc -c modele.c $(CFLAGS) -lgraph

vue.o : vue.c vue.h
	gcc -c vue.c $(CFLAGS) -lgraph

main.o : main.c vue.h modele.h
	gcc -c main.c $(CFLAGS) -lgraph

run:
	./$(EXEC)
	
	
clear:
	rm -rf *.o 