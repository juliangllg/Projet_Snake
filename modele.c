#define TAILLE_MAX_SERPENT 50 

struct Jeu{
	short int total_point,temps;
	unsigned char en_pause;
};

struct Serpent {
	short int taille;
	float vitesse;
	unsigned char en_vie_bool;
	char couleur;
	short int x,y;
	short int coordonee[TAILLE_MAX_SERPENT];
};

void remplir_tableau_coordonee(struct Serpent serpent){
	int i;
	for (i=0;i<TAILLE_MAX_SERPENT;i++){
		serpent.coordonee[i] = -1;
	}
}



struct Pomme {
	char points,couleur,x,y;
	char sprite[20];
};

struct Obstacle{
	short int x,y;
};

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
}

void manger_pomme(struct Pomme pomme,struct Jeu jeu){
	jeu.total_point += pomme.points;
}

void mourir(struct Serpent serpent,struct Jeu jeu){
	serpent.en_vie_bool = 0;
	jeu.en_pause = 1;
}

int collision(struct Serpent serpent,struct Jeu jeu,struct Obstacle obstacle){
	if ((obstacle.x == serpent.x) || obstacle.y == serpent.y) {
		mourir(serpent,jeu);
		return 1;
	}
	else {
		return 0;
	}
}

