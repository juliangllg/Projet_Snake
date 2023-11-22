
void controle_jeu(void){
	if (ToucheEnAttente() != 1){
		if (Touche() == 65362){
			printf("Haut\n");
			/* serpent->direction = 'h'*/
		}
		if (Touche() == 65363){
			printf("Droite\n");
		}
		if (Touche() == 65361){
			printf("Gauche\n");
		}
		if (Touche() == 65364){
			printf("Bas\n");
		}
	}
}

#define XK_leftarrow                     0x08fb  /* U+2190 LEFTWARDS ARROW */ 65361
#define XK_uparrow                       0x08fc  /* U+2191 UPWARDS ARROW */ 65362
#define XK_rightarrow                    0x08fd  /* U+2192 RIGHTWARDS ARROW */ 65363
#define XK_downarrow                     0x08fe  /* U+2193 DOWNWARDS ARROW */ 6534

/*
int controle_jeu(void){
	if (ToucheEnAttente() != 0){
		if (Touche() == 0x08fb){
			printf("Gauche\n");
		}
		if (Touche() == 0x08fc){
			printf("Haut\n");
		}
		if (Touche() == 0x08fd){
			printf("Droite\n");
		}
		if (Touche() == 0x08fe){
			printf("Bas\n");
		}
		return 0;
	}
	else {
		printf("Non");
	}
}
*/