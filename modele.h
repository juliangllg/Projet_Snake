#ifndef MODELE_H
#define MODELE_H

#define TAILLE_CARRE 20

struct Jeu{
	int total_point;
	short int temps;
	unsigned char en_pause;
	short int fenetre_longeur,fenetre_hauteur;
	unsigned char en_jeu;
};

struct Serpent {
	short int taille;
	float vitesse;
	unsigned char en_vie_bool;
	short int x_head,y_head;
	char direction;
	int * localisation;
	unsigned char rouge,vert,bleu;
};


struct Pomme {
	char points,couleur;
	int x,y;
};



void augmenter_vitesse(struct Serpent *serpent,float unite);

void diminuer_vitesse(struct Serpent *serpent,float unite);

void manger_pomme(struct Pomme *pomme,struct Serpent *serpent,struct Jeu *jeu);






#endif /* MODELE_H */