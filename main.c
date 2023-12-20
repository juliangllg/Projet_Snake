#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "vue.h"
#include "modele.h"
#define LONGEUR 950
#define HAUTEUR 1240

void main(void){
    struct Jeu jeu = {0,0,0,LONGEUR,HAUTEUR,1};
    InitialiserGraphique();
	CreerFenetre(20,20,jeu.fenetre_hauteur,jeu.fenetre_longeur);
	fond();
	cadrillage();
	
	deplacement_serpent(&jeu);
	FermerGraphique();
	
}
