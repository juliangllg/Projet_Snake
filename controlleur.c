#include "modele.c"
#include "time.h"


#define XK_leftarrow                     0x08fb  /* U+2190 LEFTWARDS ARROW */ 
#define XK_uparrow                       0x08fc  /* U+2191 UPWARDS ARROW */ 
#define XK_rightarrow                    0x08fd  /* U+2192 RIGHTWARDS ARROW */ 
#define XK_downarrow                     0x08fe  /* U+2193 DOWNWARDS ARROW */


void controle_jeu(struct Serpent *serpent){
	
	while(ToucheEnAttente()){
		int touche = Touche();

		if (touche == 65362 && serpent->direction != 'b' &&  serpent->direction != 'b' ){
			serpent->direction = 'h';


		}
		if (touche == 65363 && serpent->direction != 'g' &&  serpent->direction != 'g'){
			serpent->direction = 'd';


		}
		if (touche == 65361 && serpent->direction != 'd'&&  serpent->direction != 'd'){
			serpent->direction = 'g';
			

		}
		if (touche == 65364 && serpent->direction != 'h'&&  serpent->direction != 'h'){
			serpent->direction = 'b';
			

		}
	}
}
	
	


