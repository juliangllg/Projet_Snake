#include<graph.h>
#include <stdlib.h>
#include <stdio.h>

#include"controlleur.h"
#include"modele.h"
#include "vue.h"


#define Y_POMME 40
#define X_POMME 60
#define TAILLE_CARRE 20
#define CONSTANTE_VITESSE 100000

#define TAILLE_SERPENT_DEBUT 10
#define POSITION_POINTS_X 100
#define POSITION_POINTS_Y 900

#define CYCLE 1000000L

int num_pomme;
int tab_pomme[5][2];




/*Fais un cadrillage 60*40 (1200*800) pour le terrein de jeu.*/
void cadrillage (void){
    int x=20; int y = 20;int j = 0; int i = 0;
    for (i; i<40; i++){
        for(j; j< 30; j++){
            if(i%2 !=0){
                ChoisirCouleurDessin(CouleurParComposante(0,180,0));
                RemplirRectangle(x,y,TAILLE_CARRE,TAILLE_CARRE);
                ChoisirCouleurDessin(CouleurParComposante(0,220,0));
                RemplirRectangle(x+20, y,TAILLE_CARRE,TAILLE_CARRE);
                ChoisirCouleurDessin(CouleurParComposante(0,0,0));
                DessinerRectangle(x,y,TAILLE_CARRE , TAILLE_CARRE );
                DessinerRectangle(x+20,y,TAILLE_CARRE , TAILLE_CARRE );
                
            }
            else {
                ChoisirCouleurDessin(CouleurParComposante(0,220,0));
                RemplirRectangle(x,y,TAILLE_CARRE,TAILLE_CARRE);
                ChoisirCouleurDessin(CouleurParComposante(0,180,0));
                RemplirRectangle(x+20, y,TAILLE_CARRE,TAILLE_CARRE);
                ChoisirCouleurDessin(CouleurParComposante(0,0,0));
                DessinerRectangle(x,y,TAILLE_CARRE , TAILLE_CARRE );
                DessinerRectangle(x+20,y,TAILLE_CARRE , TAILLE_CARRE );
            }
            x+=40;
        }
        x = 20;
        y += 20;
        j=0;
    }
}
/*Fais un fond gris fonc?.*/
void fond (void){
    EffacerEcran(CouleurParComposante(100,100,100));
}



int game_over(int *localisation,struct Serpent *serpent){
    int i;

    /* Si le serpent sort du terrain */ 
    if ((*(localisation+0)<20 || *(localisation+0)>1200 || *(localisation+1)<20 || *(localisation+1)>800 )){
        ChoisirCouleurDessin(CouleurParComposante(255,0,0));
        RemplirRectangle(*(localisation+0), *(localisation+1),TAILLE_CARRE,TAILLE_CARRE);
        free(localisation);
        EcrireTexte(620,875, "Game Over", 2);
        return 0;  
    }

    /* Si la tête du serpent touche sa queue */ 
    for (i=2;i<(serpent->taille*2)-2;i+=2){
        if (*(localisation+0) == *(localisation+i) && *(localisation+1) == *(localisation+i+1)){
            ChoisirCouleurDessin(CouleurParComposante(255,0,0));
            RemplirRectangle(*(localisation+0), *(localisation+1),TAILLE_CARRE,TAILLE_CARRE);
            free(localisation);
            EcrireTexte(620,875, "Game Over", 2);
            return 0;  
        }
    }
    return serpent->en_vie_bool;
}


/*Affiche les sprites des pomme*/
void affiche_pomme(){   
    int i;
    int rose = ChargerSprite("images/Pomme_rose.png");
    for(i = 0; i<5; i++){
        AfficherSprite(rose,tab_pomme[i][0],tab_pomme[i][1]);
        }
}

/*Charge les sprites des pommes*/
void ChargerSpritePomme(void){
        int pomme_rose = ChargerSprite("images/Pomme_rose.png");
        int pomme_rouge = ChargerSprite("images/Pomme_rouge.png");
        int pomme_bleu = ChargerSprite("images/Pomme_jaune.png");
        int pomme_jaune = ChargerSprite("images/Pomme_bleu.png");
}

/*fait une pause entre chaque deplacement du seprent*/
void attendre(int microsecondes){
	unsigned long attente = Microsecondes() + microsecondes;
	while (Microsecondes() < attente){
	
	}
}

int apparait(const int* tab_serpent,struct Serpent serpent,int x,int y){
    int i;
    for (i=0;i<(serpent.taille*2)-2;i++){
        if (*(tab_serpent+i) == x && *(tab_serpent+i+1) == y){
            return 0;
        }
    }
    return 1;
}


void Update_Timer(int minute, int seconde, char timer[]) {

    snprintf(timer, 6, "%02d:%02d", minute, seconde);

    ChoisirCouleurDessin(CouleurParComposante(100, 100, 100));
    RemplirRectangle(1100, 850, 100, 100);
    ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
    EcrireTexte(1100, 900, timer, 2);

}

void Timer(int* minute, int* seconde, unsigned long int* suivant, int* seconde_actuel, int* old_seconde, char timer[]) {
    if (Microsecondes() > *suivant) {
        *suivant = Microsecondes() + CYCLE;

        *seconde_actuel = (*suivant / 1000000) % 60;

        if (*seconde_actuel != *old_seconde) {

            *old_seconde = *seconde_actuel;


            if (*seconde == 59) {
                *minute = *minute + 1;
                *seconde = 0;

                Update_Timer(*minute, *seconde, timer);
            } else {
                *seconde = *seconde + 1;

                Update_Timer(*minute, *seconde, timer);
            }
        }
    }
}

/*Boucle principal du jeu*/
void deplacement_serpent(struct Jeu *jeu){ 
        struct Serpent serpent = {TAILLE_SERPENT_DEBUT+1,
                                  1.25,
                                  1,
                                  610,410,
                                  'd',NULL,0,0,200};


        /* Pommes */

        printf("%hhu\n",serpent.bleu);
        struct Pomme pomme_1 = {1,'r',rand()%X_POMME*20+20,rand()%Y_POMME*20+20};
        struct Pomme pomme_2 = {1,'r',rand()%X_POMME*20+20,rand()%Y_POMME*20+20};
        struct Pomme pomme_3 = {1,'r',rand()%X_POMME*20+20,rand()%Y_POMME*20+20};
        struct Pomme pomme_4 = {1,'r',rand()%X_POMME*20+20,rand()%Y_POMME*20+20};
        struct Pomme pomme_5 = {1,'r',rand()%X_POMME*20+20,rand()%Y_POMME*20+20};
        struct Pomme tab_pomme[5] = {pomme_1,pomme_2,pomme_3,pomme_4,pomme_5};

        unsigned char couleur_pomme[3] = {'r','j','b'};
        int pomme_rose = ChargerSprite("images/Pomme_rose.png");
        int pomme_rouge = ChargerSprite("images/Pomme_rouge.png");
        int pomme_bleu = ChargerSprite("images/Pomme_jaune.png");
        int pomme_jaune = ChargerSprite("images/Pomme_bleu.png");



        /* Serpent */
        int* localisation = NULL;
        localisation = malloc((serpent.taille*2)*sizeof(int));
        *(localisation+0) = 620;
        *(localisation+1) = 400;
        unsigned char couleur_case = (TAILLE_SERPENT_DEBUT%2 == 0) ? 180:220 ;


        char affiche_score[4];
        unsigned long temps = 0;
        int i;
        int j;
        srand(time(NULL));


        int minute_np = 0;
        int seconde_np = -1;
        int suivant_np = 0;
        int seconde_actuel_np = 0;
        int old_seconde_np = 0;

        int* minute = &minute_np;
        int* seconde = &seconde_np;
        unsigned long int* suivant = &suivant_np;
        int* seconde_actuel = &seconde_actuel_np;
        int* old_seconde = &old_seconde_np;
        char timer[6];
        /*Boucle principal du jeu*/
        while ( serpent.en_vie_bool){
			
            
            Timer(minute,seconde,suivant,seconde_actuel,old_seconde,timer);

            
            
			/* Déplacement du serpent dans le tableau localisation */
            for(i=(serpent.taille*2)-1;i>2;i-=2){
                *(localisation+(i-1)) = *(localisation+(i-3));
                *(localisation+i) = *(localisation+(i-2));
            }   


            
            
            

             controle_jeu(&serpent,localisation);


			
    		if (serpent.direction == 'd'){
                *(localisation+0) += 20 ;
   
    		}
			
            if (serpent.direction == 'g'){
                *(localisation+0) -= 20 ;
 
    		}
			
            if (serpent.direction == 'h'){
                *(localisation+1) -= 20 ;
    		}
			
            if (serpent.direction == 'b'){
                *(localisation+1) += 20 ;
            }

			
		
            
            

             /* Dessin du serpent */
		      ChoisirCouleurDessin(CouleurParComposante(serpent.rouge,serpent.vert,serpent.bleu));
            for (i=0;i<(serpent.taille*2)-1;i+=2){
                RemplirRectangle(*(localisation+i),*(localisation+i+1),TAILLE_CARRE, TAILLE_CARRE );
            }




          
			/* Gestion des pomme et du serpent */ 
            for(j=0; j<5; j++){

                if (*(localisation+0)== tab_pomme[j].x && *(localisation+1) == tab_pomme[j].y){
                    manger_pomme(&tab_pomme[j],&serpent,jeu);
                    localisation = realloc(localisation,serpent.taille*2*sizeof(int));

                    /* Générer des couleurs aléatoires pour le serpent en évitant quelle soit trop verte */
                    do {
                        serpent.rouge = rand()%255;
                        serpent.vert = rand()%255;
                        serpent.bleu = rand()%255;
                    } while ((serpent.rouge + serpent.bleu)<serpent.vert);

					/* Convertion du score */ 
                 	sprintf(affiche_score, "%d", jeu->total_point);
					
                    
                    ChoisirCouleurDessin(CouleurParComposante(100,100,100));
                    RemplirRectangle(POSITION_POINTS_X,POSITION_POINTS_Y-50,100,100);
                    ChoisirCouleurDessin(CouleurParComposante(200,0,0));
                    EcrireTexte(POSITION_POINTS_X,POSITION_POINTS_Y,affiche_score,2);
                    

                    int x = rand()%X_POMME*20+20;
                    int y = rand()%Y_POMME*20+20;
                    do{
                        x = rand()%X_POMME*20+20;
                        y = rand()%Y_POMME*20+20;
                        struct Pomme nouvelle_pomme = {1,couleur_pomme[rand()%3],x,y};
                        tab_pomme[j] = nouvelle_pomme;
                    }while(apparait(localisation,serpent,x,y) != 1);
                    
                    
             
                }
            }

            if (serpent.taille == 2400 + 1){
                ChoisirCouleurDessin(CouleurParComposante(255,0,0));
                RemplirRectangle(*(localisation+0), *(localisation+1),TAILLE_CARRE,TAILLE_CARRE);
                free(localisation);
                EcrireTexte(620,875, "You", 2);
            }


            for (i=0;i<5;i++){
                if (tab_pomme[i].couleur == 'r'){
                    AfficherSprite(pomme_rose,tab_pomme[i].x+2,tab_pomme[i].y);
                }
                if (tab_pomme[i].couleur == 'j'){
                    AfficherSprite(pomme_jaune,tab_pomme[i].x+2,tab_pomme[i].y);
                }
                if (tab_pomme[i].couleur == 'b'){
                    AfficherSprite(pomme_bleu,tab_pomme[i].x+2,tab_pomme[i].y);
                }
            }
     

            couleur_case = (couleur_case == 220) ? 180:220 ;

			serpent.en_vie_bool = game_over(localisation, &serpent);
            ChoisirCouleurDessin(CouleurParComposante(0,couleur_case,0));
            RemplirRectangle(*(localisation+((serpent.taille*2)-1)-1),*(localisation+((serpent.taille*2)-1)),TAILLE_CARRE, TAILLE_CARRE);
            ChoisirCouleurDessin(CouleurParComposante(0,0,0));
            DessinerRectangle(*(localisation+((serpent.taille*2)-1)-1),*(localisation+((serpent.taille*2)-1)),TAILLE_CARRE , TAILLE_CARRE );
            DessinerRectangle(*(localisation+((serpent.taille*2)-1)-1),*(localisation+((serpent.taille*2)-1)),TAILLE_CARRE , TAILLE_CARRE );
            
			attendre((int) (serpent.vitesse*CONSTANTE_VITESSE));

    }
	
	
}