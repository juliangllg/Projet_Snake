#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "vue.c"
#define TAILLE_CARRE 20

void main(void){
    int i = 0;
    int j = 0;
    int x = 20;
    int y = 20; 
    InitialiserGraphique();
    CreerFenetre(20,20,1240,950);
    EffacerEcran(CouleurParComposante(255,255,255));
    DessinerRectangle(20,20,1200,800);
    cadrillage();
    Touche();
    FermerGraphique();

}