#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "vue.c"

void main(void){
    struct Serpent serpent = {3,2.0,1,CouleurParComposante(0,0,255),610,410,'d'}; /*milieu du tableau 620 et 410*/
    int i = 0;
    InitialiserGraphique();
    CreerFenetre(20,20,1240,950);
    fond();
    profondeur();
    cadrillage();
    ChoisirCouleurDessin(CouleurParComposante(255,0,0));
    /* Tester pour les fleches directionelles peut enlever */
	while (1){
		controle_jeu(&serpent);
	}
    for(i;i<200;i++){
       	DessinerSegment(serpent.x_head,serpent.y_head+i,serpent.x_head-i-serpent.taille*20,serpent.y_head);
        DessinerSegment(serpent.x_head+1,serpent.y_head+i,serpent.x_head-i-serpent.taille*20,serpent.y_head);
        DessinerSegment(serpent.x_head+2,serpent.y_head+i,serpent.x_head-i-serpent.taille*20,serpent.y_head);
        DessinerSegment(serpent.x_head-1,serpent.y_head+i,serpent.x_head-i-serpent.taille*20,serpent.y_head);
        DessinerSegment(serpent.x_head-2,serpent.y_head+i,serpent.x_head-i-serpent.taille*20,serpent.y_head);
        sleep(1);
    }
    Touche();
    FermerGraphique();

}

