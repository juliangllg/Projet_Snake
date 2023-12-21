#ifndef VUE_H
#define VUE_H

void cadrillage (void);

void fond (void);

int game_over( int *, struct Serpent *serpent);

void affiche_pomme();

void initialisation(void);

void deplacement_serpent(struct Jeu *jeu);

void menu_principal();

int apparait(const int* tab_serpent,struct Serpent serpent,int x,int y);
#endif /* VUE_H */