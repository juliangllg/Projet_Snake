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
	int x = 620; int y = 400;
	while (1){
        if(Touche() != Touche()){
            controle_jeu(&serpent);
        }
		

		if (serpent.direction == 'd'){
		    ChoisirCouleurDessin(serpent.couleur);
            x+=20;
            RemplirRectangle(x,y,20,20);
            
		}
        if (serpent.direction == 'g'){
		    ChoisirCouleurDessin(serpent.couleur);
            x-=20;
            RemplirRectangle(x,y,20,20);
            
		}
        if (serpent.direction == 'h'){
		    ChoisirCouleurDessin(serpent.couleur);
            y-=20;
            RemplirRectangle(x,y,20,20);
            
		}
        if (serpent.direction == 'b'){
		    ChoisirCouleurDessin(serpent.couleur);
            y+=20;
            RemplirRectangle(x,y,20,20);
            

		}
        
		
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
