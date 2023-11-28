#include "modele.c"
#include "time.h"


void controle_jeu(struct Serpent *serpent){
	
	while(ToucheEnAttente()){
		int touche = Touche();

		if (touche == 65362 && serpent->direction != 'b' ){
			serpent->direction = 'h';
			break;
		}
		if (touche == 65363 && serpent->direction != 'g' ){
			serpent->direction = 'd';
			break;
		}
		if (touche == 65361 && serpent->direction != 'd'){
			serpent->direction = 'g';
			break;
		}
		if (touche == 65364 && serpent->direction != 'h'){
			serpent->direction = 'b';
			break;
		}
	}
}
	
	


#define XK_leftarrow                     0x08fb  /* U+2190 LEFTWARDS ARROW */ 65361
#define XK_uparrow                       0x08fc  /* U+2191 UPWARDS ARROW */ 65362
#define XK_rightarrow                    0x08fd  /* U+2192 RIGHTWARDS ARROW */ 65363
#define XK_downarrow                     0x08fe  /* U+2193 DOWNWARDS ARROW */ 6534
