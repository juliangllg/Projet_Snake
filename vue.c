#include"controlleur.h"
#include"modele.h"
#include <stdlib.h>
#include<graph.h>
#include <time.h>
#include "vue.h"
#include <stdio.h>

#define Y_POMME 40
#define X_POMME 60
#define TAILLE_CARRE 20
#define CONSTANTE_VITESSE 100000


#define POSITION_POINTS_X 100
#define POSITION_POINTS_Y 900


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
    if ((*(localisation+0)<20 || *(localisation+0)>1200 || *(localisation+1)<20 || *(localisation+1)>800 )){
        ChoisirCouleurDessin(CouleurParComposante(255,0,0));
        RemplirRectangle(*(localisation+0), *(localisation+1),TAILLE_CARRE,TAILLE_CARRE);
        free(localisation);
        serpent->en_vie_bool = 0;
        EcrireTexte(620,875, "Game Over", 2);
        return 0;  
    }
    for (i=2;i<(serpent->taille*2)-1;i+=2){
        if (*(localisation+0) == *(localisation+i) && *(localisation+1) == *(localisation+i+1)){
            ChoisirCouleurDessin(CouleurParComposante(255,0,0));
            RemplirRectangle(*(localisation+0), *(localisation+1),TAILLE_CARRE,TAILLE_CARRE);
            free(localisation);
            serpent->en_vie_bool = 0;
            EcrireTexte(620,875, "Game Over", 2);
            return 0;  
        }
    }
    return 1;
}



void affiche_pomme(){   
    int i;
    int rose = ChargerSprite("images/Pomme_rose.png");
    for(i = 0; i<5; i++){
        AfficherSprite(rose,tab_pomme[i][0],tab_pomme[i][1]);
        }
}

void ChargerSpritePomme(void){
        int pomme_rose = ChargerSprite("images/Pomme_rose.png");
        int pomme_rouge = ChargerSprite("images/Pomme_rouge.png");
        int pomme_bleu = ChargerSprite("images/Pomme_jaune.png");
        int pomme_jaune = ChargerSprite("images/Pomme_bleu.png");
}

void attendre(int microsecondes){
	unsigned long attente = Microsecondes() + microsecondes;
	while (Microsecondes() < attente){
	
	}
}


void deplacement_serpent(struct Jeu *jeu){ 
	int x = 620; int y = 400;
        struct Serpent serpent = {4,
                                  1.25,
                                  1,
                                  CouleurParComposante(0,0,255),
                                  610,410,
                                  'd'}; /*Taille,Vitesse*/

        struct Pomme pomme = {1,'r',0,0};
        int* localisation = NULL;

        localisation = malloc((serpent.taille*2)*sizeof(int));

		/* Création des 5 premieres pommes */ 
	
        struct Pomme pomme_1 = {1,'r',rand()%X_POMME*20+20,rand()%Y_POMME*20+20};
        struct Pomme pomme_2 = {1,'r',rand()%X_POMME*20+20,rand()%Y_POMME*20+20};
        struct Pomme pomme_3 = {1,'r',rand()%X_POMME*20+20,rand()%Y_POMME*20+20};
        struct Pomme pomme_4 = {1,'r',rand()%X_POMME*20+20,rand()%Y_POMME*20+20};
        struct Pomme pomme_5 = {1,'r',rand()%X_POMME*20+20,rand()%Y_POMME*20+20};

        struct Pomme tab_pomme[5] = {pomme_1,pomme_2,pomme_3,pomme_4,pomme_5};
	
	    srand(time(NULL));
        unsigned char couleur_nouvelle_pomme,couleur_pomme_random;
        int pomme_rose = ChargerSprite("images/Pomme_rose.png");
        int pomme_rouge = ChargerSprite("images/Pomme_rouge.png");
        int pomme_bleu = ChargerSprite("images/Pomme_jaune.png");
        int pomme_jaune = ChargerSprite("images/Pomme_bleu.png");
        int i;
        unsigned char couleur_case = 220;
        int j;
		char affiche_score[4];
        unsigned long temps = 0;
        *(localisation+0) = 620;
        *(localisation+1) = 400;
        
        while ( serpent.en_vie_bool){
			
			/* Déplacement du serpent dans le tableau localisation */
            for(i=(serpent.taille*2)-1;i>2;i-=2){
                *(localisation+(i-1)) = *(localisation+(i-3));
                *(localisation+i) = *(localisation+(i-2));
            }   


            
            
            

            controle_jeu(&serpent);
			
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

			
		
            int en_vie = game_over(localisation, &serpent);
            


		  ChoisirCouleurDessin(CouleurParComposante(0,0,255));
          for (i=0;i<(serpent.taille*2)-1;i+=2){
                RemplirRectangle(*(localisation+i),*(localisation+i+1),TAILLE_CARRE, TAILLE_CARRE );
            }



          
			/* Gestion des pomme et du serpent */ 
            for(j=0; j<5; j++){

                if (*(localisation+0)== tab_pomme[j].x && *(localisation+1) == tab_pomme[j].y){
                    manger_pomme(&tab_pomme[j],&serpent);
                    jeu->total_point += 1;
					
					/* Convertion du score */ 
                 	sprintf(affiche_score, "%d", jeu->total_point);
					
                    localisation = realloc(localisation,serpent.taille*2*sizeof(int));
                    ChoisirCouleurDessin(CouleurParComposante(100,100,100));
                    RemplirRectangle(POSITION_POINTS_X,POSITION_POINTS_Y-50,100,100);
                    ChoisirCouleurDessin(CouleurParComposante(200,0,0));
                    EcrireTexte(POSITION_POINTS_X,POSITION_POINTS_Y,affiche_score,2);
                    
                    couleur_pomme_random = rand()%3;
                    if (couleur_pomme_random == 0){
                        couleur_nouvelle_pomme = 'r';
                    }
                    if (couleur_pomme_random == 1){
                        couleur_nouvelle_pomme = 'b';
                    }
                    if (couleur_pomme_random == 2){
                        couleur_nouvelle_pomme = 'j';
                    }
                    struct Pomme nouvelle_pomme = {1,couleur_nouvelle_pomme,rand()%X_POMME*20+20,rand()%Y_POMME*20+20};
                    tab_pomme[j] = nouvelle_pomme;
             
                }
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
     

			/* Gestion collision du serpent avec sa queue */
			
           


      


            if (couleur_case == 220 ){
                couleur_case = 180;
            }
            else{
                couleur_case = 220;
                
            }

			
            ChoisirCouleurDessin(CouleurParComposante(0,couleur_case,0));
            RemplirRectangle(*(localisation+((serpent.taille*2)-1)-1),*(localisation+((serpent.taille*2)-1)),TAILLE_CARRE, TAILLE_CARRE);
            ChoisirCouleurDessin(CouleurParComposante(0,0,0));
            DessinerRectangle(*(localisation+((serpent.taille*2)-1)-1),*(localisation+((serpent.taille*2)-1)),TAILLE_CARRE , TAILLE_CARRE );
            DessinerRectangle(*(localisation+((serpent.taille*2)-1)-1),*(localisation+((serpent.taille*2)-1)),TAILLE_CARRE , TAILLE_CARRE );


			attendre((int) (serpent.vitesse*CONSTANTE_VITESSE));

    }
	
}