#define TAILLE_MAX_SERPENT 50 
#include "modele.h"

/*permet de diminuer la vitesse du serpent*/
void diminuer_vitesse(struct Serpent *serpent,float unite){

		if (serpent->vitesse < 3.5){
		serpent->vitesse += unite/1000;   
	}

}

/*permet d'augmenter la vitesse du serpent*/
void augmenter_vitesse(struct Serpent *serpent,float unite){
	if (serpent->vitesse > 1){
		serpent->vitesse -= unite/1000;  
	}

}


/*permet de modifier les valeur du serpent quand une pomme est manger*/
void manger_pomme(struct Pomme *pomme,struct Serpent *serpent,struct Jeu *jeu){
	serpent->taille += 2;
	jeu->total_point += 5;
	if (pomme->couleur == 'r'){
		augmenter_vitesse(serpent,115);
	}
	if (pomme->couleur == 'j'){
		diminuer_vitesse(serpent,75);
	}

}




