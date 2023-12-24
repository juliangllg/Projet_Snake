#ifndef VUE_H
#define VUE_H



void cadrillage (void);

void fond (void);

int game_over( int *, struct Serpent *serpent);



void deplacement_serpent(struct Jeu *jeu);

void attendre(int microsecondes);



int apparait(const int* tab_serpent,struct Serpent serpent,int x,int y);




void affiche_timer(int minute,int seconde, char timer[]);

void Timer(int* minute,int* seconde,unsigned long int* suivant,int* seconde_actuel,int* old_seconde,char timer[]);

#endif /* VUE_H */