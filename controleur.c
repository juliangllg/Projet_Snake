#include "modele.h"
#include "controleur.h"

#define FLECHE_GAUCHE 65361    
#define FLECHE_HAUT 65362                   
#define FLECHE_DROITE 65363 
#define FLECHE_BAS 65364  
#define ECHAPE 65307
#define ESPACE 32

/*permet de changer lma direction du serpent quand on actionnne une touche*/
void controle_jeu(struct Serpent *serpent,int* localisation){
	
	while(ToucheEnAttente()){
		int touche = Touche();

			

			/*Touche fleche du haut change la direction du serpent*/
			if (touche == FLECHE_HAUT && serpent->direction != 'b' &&  serpent->direction != 'h' ){
				serpent->direction = 'h';
				return;
			}

			/*Touche fleche ded droite change la direction du serpent*/
			if (touche == FLECHE_DROITE && serpent->direction != 'g' &&  serpent->direction != 'd'){
				serpent->direction = 'd';
				return;
			}

			/*Touche fleche du bas change la direction du serpent*/
			if (touche == FLECHE_GAUCHE && serpent->direction != 'd'&&  serpent->direction != 'g'){
				serpent->direction = 'g';
				return;
			}

			/*Touche fleche du bas change la direction du serpent*/
			if (touche == FLECHE_BAS && serpent->direction != 'h'&&  serpent->direction != 'b'){
				serpent->direction = 'b';
				return;
			}

			/*Touche Echap quitte le jeu*/
			if (touche == ECHAPE){
				serpent->en_vie_bool = 0;
				return;
			}

			/* Touche espace met pause*/
			if (touche == ESPACE){
				int pause=0;

            	ChoisirCouleurDessin(CouleurParComposante(-serpent->rouge,-serpent->vert,-serpent->bleu));

            	RemplirRectangle(*(localisation),*(localisation+1),TAILLE_CARRE,TAILLE_CARRE);

            	ChoisirCouleurDessin(CouleurParComposante(0,0,0));
				EcrireTexte(620,875, "Pause", 2);

				while(pause != ESPACE){
					pause = Touche();
					if (pause == ECHAPE){
						serpent->en_vie_bool = 0;
					return;

					}

				}
				ChoisirCouleurDessin(CouleurParComposante(100,100,100));
				RemplirRectangle(620,840,150,50);
			}
			
			
			
		
		
	}
}
	
	

