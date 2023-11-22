#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "vue.c"


void main(void){
    
    InitialiserGraphique();
    CreerFenetre(20,20,1240,950);
    fond();
    profondeur();
    cadrillage();

    DessinerSegment(250,250,50,50);
    Touche();
    FermerGraphique();

}

