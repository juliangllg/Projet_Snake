#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "vue.h"
#include "modele.h"

void main(void){
    struct Jeu jeu = {0,0,0};
    InitialiserGraphique();
    CreerFenetre(20,20,1240,950);
    fond();
    cadrillage();
    deplacement_serpent(&jeu);
    sleep(2);
    Touche();
    FermerGraphique();
}
