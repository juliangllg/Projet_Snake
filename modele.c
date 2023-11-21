struct Jeu{
	short int total_point,temps;
	unsigned char en_pause;
};
	
struct Serpent {
	short int taille;
	float vitesse;
	unsigned char en_vie_bool;
};

struct Pomme {
	char points,couleur,x,y;
};

void manger_pomme(struct Pomme pomme,struct Jeu jeu){
	jeu.total_point += pomme.points;

}

void mourir(struct Serpent serpent,struct Jeu jseu){
	serpent.en_vie_bool = 0;
	jeu.en_pause = 1;

}
