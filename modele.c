#define TAILLE_MAX_SERPENT 50 

struct Jeu{
	short int total_point;
	short int temps;
	unsigned char en_pause;
};

struct Serpent {
	short int taille;
	float vitesse;
	unsigned char en_vie_bool;
	char couleur;
	short int x_head,y_head;
	char direction;
	int localisation[TAILLE_MAX_SERPENT][2];
};

/*void remplir_tableau_coordonee(struct Serpent *serpent){
	int i;
	for (i=0;i<TAILLE_MAX_SERPENT;i++){
		serpent->coordonee[i] = -1;
	}   	
}*/

struct Pomme {
	char points,couleur,x,y;
};

struct Obstacle{
	short int x,y;
};

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

void manger_pomme(struct Pomme *pomme,struct Jeu *jeu,struct Serpent *serpent){
	jeu->total_point += pomme->points;
	serpent->taille += 1;
	if (pomme->couleur == 'r'){
		augmenter_vitesse(serpent,100);
	}
	if (pomme->couleur == 'o'){
		diminuer_vitesse(serpent,100);
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
