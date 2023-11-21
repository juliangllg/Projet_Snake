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
};

struct Pomme {
	char points,couleur,x,y;
};

struct Obstacle{
	short int x,y;
}

void manger_pomme(struct Pomme pomme,struct Jeu jeu){
	jeu.total_point += pomme.points;
}

void mourir(struct Serpent serpent,struct Jeu jeu){
	serpent.en_vie_bool = 0;
	jeu.en_pause = 1;
}

void collision(struct Serpent serpent,struct Jeu jeu,struct Obstacle obstacle){
	if ((obstalce.x == serpent.x) || obstalce.y == serpent.y) {
		mourir(serpent,jeu);
	}
}

