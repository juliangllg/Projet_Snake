#ifndef MODELE_H
#define MODELE_H

struct Jeu{
	int total_point;
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
};


struct Pomme {
	char points,couleur;
	int x,y;
};

struct Liste_pommes{
	int liste[5];
};

struct Obstacle{
	short int x,y;
};


void augmenter_vitesse(struct Serpent *serpent,float unite);

void diminuer_vitesse(struct Serpent *serpent,float unite);

void manger_pomme(struct Pomme *pomme,struct Serpent *serpent);

void mourir(struct Serpent *serpent,struct Jeu *jeu);

int collision(struct Serpent *serpent,struct Jeu *jeu,struct Obstacle *obstacle);
#endif /* MODELE_H */