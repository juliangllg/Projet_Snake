#include "modele.h"
#include "controlleur.h"

#define XK_leftarrow                     0x08fb  /* U+2190 LEFTWARDS ARROW */ 
#define XK_uparrow                       0x08fc  /* U+2191 UPWARDS ARROW */ 
#define XK_rightarrow                    0x08fd  /* U+2192 RIGHTWARDS ARROW */ 
#define XK_downarrow                     0x08fe  /* U+2193 DOWNWARDS ARROW */
#define ESCAPE 65307


void controle_jeu(struct Serpent *serpent,struct Jeu *jeu){
	
	while(ToucheEnAttente()){
		int touche = Touche();

			

			/*Touche fleche du haut change la direction du serpent*/
			if (touche == 65362 && serpent->direction != 'b' &&  serpent->direction != 'h' ){
				serpent->direction = 'h';
				return;
			}

			/*Touche fleche ded droite change la direction du serpent*/
			if (touche == 65363 && serpent->direction != 'g' &&  serpent->direction != 'd'){
				serpent->direction = 'd';
				return;
			}

			/*Touche fleche du bas change la direction du serpent*/
			if (touche == 65361 && serpent->direction != 'd'&&  serpent->direction != 'g'){
				serpent->direction = 'g';
				return;
			}

			/*Touche fleche du bas change la direction du serpent*/
			if (touche == 65364 && serpent->direction != 'h'&&  serpent->direction != 'b'){
				serpent->direction = 'b';
				return;
			}

			/*Touche Echap quitte le jeu*/
			if (touche == 65307){
				serpent->en_vie_bool = 0;
				return;
			}

			/* Touche espace met pause*/
			if (touche == 32){
				int pause=0;
				EcrireTexte(620,875, "Pause", 2);
				while(pause != 32){
					pause = Touche();
				}
				ChoisirCouleurDessin(CouleurParComposante(100,100,100));
				RemplirRectangle(620,840,150,50);
			}

			
			
		
		
	}
}
	
	

