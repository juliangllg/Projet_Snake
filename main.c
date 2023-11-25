#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "vue.c"

void main(void){
    int i = 0;
    InitialiserGraphique();
    CreerFenetre(20,20,1240,950);
    fond();
    cadrillage();
    ChoisirCouleurDessin(CouleurParComposante(255,0,0));
    deplacement_serpent();
    sleep(2);
    Touche();
    FermerGraphique();
}
