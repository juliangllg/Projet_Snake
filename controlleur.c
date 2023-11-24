#include "modele.c"

void controle_jeu(struct Serpent *serpent){

	if(ToucheEnAttente() == 1){
		int touche = Touche();

		if (touche== 65362){
			printf("Haut\n");
			serpent->direction = 'h';
		}
		if (touche == 65363){
			printf("Droite\n");
			serpent->direction = 'd';
		}
		if (touche == 65361){
			printf("Gauche\n");
			serpent->direction = 'g';
		}
		if (touche == 65364){
			printf("Bas\n");
			serpent->direction = 'b';
		}
	}
		
}
	
	
	/*else{
		if (Touche() == 65362){
			printf("Haut\n");
			serpent->direction = 'h';
		}
		if (Touche() == 65363){
			printf("Droite\n");
			serpent->direction = 'd';
		
		}
		if (Touche() == 65361){
			printf("Gauche\n");
			serpent->direction = 'g';
		}
		if (Touche() == 65364){
			printf("Bas\n");
			serpent->direction = 'b';
		}
		
	}*/


#define XK_leftarrow                     0x08fb  /* U+2190 LEFTWARDS ARROW */ 65361
#define XK_uparrow                       0x08fc  /* U+2191 UPWARDS ARROW */ 65362
#define XK_rightarrow                    0x08fd  /* U+2192 RIGHTWARDS ARROW */ 65363
#define XK_downarrow                     0x08fe  /* U+2193 DOWNWARDS ARROW */ 6534
