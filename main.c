#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#define TAILLE_CARRE 10

void main(void){
    int i = 0;
    int j = 0;
    int x = 10;
    int y = 10; 
    InitialiserGraphique();
    CreerFenetre(20,20,620,430);
    for (i; i<40; i++){
        for(j; j< 60; j++){
            DessinerRectangle(x,y,TAILLE_CARRE, TAILLE_CARRE);
            x+=10;
        }
        x = 10;
        y += 10;
        j=0;
    }
    Touche();
    FermerGraphique();

}