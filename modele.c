#define TAILLE_MAX_SERPENT 50 
#include "modele.h"



void augmenter_vitesse(struct Serpent *serpent,float unite){
	if (serpent->vitesse > 0.5){
		serpent->vitesse -= unite/1000;  
	}

}

void diminuer_vitesse(struct Serpent *serpent,float unite){

		if (serpent->vitesse < 4.5){
		serpent->vitesse += unite/1000;   
	}

}

void manger_pomme(struct Pomme *pomme,struct Serpent *serpent){
	serpent->taille += 2;
	if (pomme->couleur == 'r'){
		augmenter_vitesse(serpent,5);
	}
	if (pomme->couleur == 'o'){
		diminuer_vitesse(serpent,5);
	}

}

void mourir(struct Serpent *serpent,struct Jeu *jeu){
	serpent->en_vie_bool = 0;
	jeu->en_pause = 1;
}

int collision(struct Serpent *serpent,struct Jeu *jeu,struct Obstacle *obstacle){
	if ((obstacle->x == serpent->x_head) || obstacle->y == serpent->y_head) {
		mourir(serpent,jeu);
		return 1;
	}
	else {
		return 0;
	}
}

/*
void creer_terrain(){
	int tableau[60][40];
 	int i;
	int j;
	int nb = 1;
	for (i=0;i<=60;i++){
		for (j=0;j<=40;i++){
		tableau[i][j] = nb;
		nb += 1;
		}
	}
	return tableau
}
*/
