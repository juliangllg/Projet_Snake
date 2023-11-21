#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "vue.c"


void main(void){
    int i = 0;
    int j = 0;
    int x = 20;
    int y = 20; 
    
    InitialiserGraphique();
    CreerFenetre(20,20,1240,950);
    fond();
    profondeur();
    cadrillage();
    
    Touche();
    FermerGraphique();

}

                