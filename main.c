#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#define TAILLE_CARRE 20

void main(void){
    int i = 0;
    int j = 0;
    int x = 20;
    int y = 20; 
    InitialiserGraphique();
    CreerFenetre(20,20,1240,950);
    EffacerEcran(CouleurParComposante(255,255,255));
    DessinerRectangle(20,20,1200,800)
    for (i; i<40; i++){
        for(j; j< 60; j++){
            DessinerRectangle(x,y,TAILLE_CARRE, TAILLE_CARRE);
            
            x+=20;
        }
        x = 20;
        y += 20;
        j=0;
    }
    Touche();
    FermerGraphique();

}