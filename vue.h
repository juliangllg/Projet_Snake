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




void Update_Timer(int minute,int seconde, char timer[]);

void Timer(int* minute,int* seconde,unsigned long int* suivant,int* seconde_actuel,int* old_seconde,char timer[]);

#endif /* VUE_H */