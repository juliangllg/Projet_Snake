#ifndef VUE_H
#define VUE_H

void cadrillage (void);

void fond (void);

int game_over( int *, struct Serpent *serpent);

void affiche_pomme();

void initialisation(void);

void deplacement_serpent(struct Jeu *jeu);

void menu_principal();
#endif /* VUE_H */