#define TAILLE_MAX_SERPENT 50 
#include "modele.h"
#define DELTA 1000000L


void augmenter_vitesse(struct Serpent *serpent,float unite){
	if (serpent->vitesse > 1){
		serpent->vitesse -= unite/1000;  
	}

}

void diminuer_vitesse(struct Serpent *serpent,float unite){

		if (serpent->vitesse < 3.5){
		serpent->vitesse += unite/1000;   
	}

}

void manger_pomme(struct Pomme *pomme,struct Serpent *serpent){
	serpent->taille += 2;
	if (pomme->couleur == 'r'){
		augmenter_vitesse(serpent,115);
	}
	if (pomme->couleur == 'j'){
		diminuer_vitesse(serpent,75);
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

void update_timer(unsigned long int start) {
	int secondes = ((Microsecondes() - start) / DELTA);
	int minutes = 0;
	char buf[100];
		
	while (secondes >= 60) {
		minutes += 1;
		secondes -= 60;
	}
	ChoisirCouleurDessin(CouleurParNom("white"));
	snprintf(buf, 100, "Temps : %02d:%02d", minutes, secondes);
	EcrireTexte(20, 20, buf, 1);
}
unsigned long int start_timer(unsigned long int start) {
	start = Microsecondes() - start;
	update_timer(start);
	return start;
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
