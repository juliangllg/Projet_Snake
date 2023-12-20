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
        struct Serpent serpent = {TAILLE_SERPENT_DEBUT+1,
                                  1.25,
                                  1,
                                  610,410,
                                  'd'};


        /* Pommes */

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

        int serpent_rouge= 0;
        int serpent_vert = 0;
        int serpent_bleu = 155;
        unsigned char couleur_case = (TAILLE_SERPENT_DEBUT%2 == 0) ? 180:220 ;


        char affiche_score[4];
        unsigned long temps = 0;
        int i;
        int j;
        srand(time(NULL));


        while ( serpent.en_vie_bool){
			
			/* Déplacement du serpent dans le tableau localisation */
            for(i=(serpent.taille*2)-1;i>2;i-=2){
                *(localisation+(i-1)) = *(localisation+(i-3));
                *(localisation+i) = *(localisation+(i-2));
            }   


            
            
            

             controle_jeu(&serpent,&jeu);

			
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
		  ChoisirCouleurDessin(CouleurParComposante(serpent_rouge,serpent_vert,serpent_bleu));
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
                        serpent_rouge = rand()%255;
                        serpent_vert = rand()%255;
                        serpent_bleu = rand()%255;
                    } while ((serpent_rouge +serpent_bleu)<serpent_vert);

					/* Convertion du score */ 
                 	sprintf(affiche_score, "%d", jeu->total_point);
					
                    
                    ChoisirCouleurDessin(CouleurParComposante(100,100,100));
                    RemplirRectangle(POSITION_POINTS_X,POSITION_POINTS_Y-50,100,100);
                    ChoisirCouleurDessin(CouleurParComposante(200,0,0));
                    EcrireTexte(POSITION_POINTS_X,POSITION_POINTS_Y,affiche_score,2);
                    
                    struct Pomme nouvelle_pomme = {1,couleur_pomme[rand()%3],rand()%X_POMME*20+20,rand()%Y_POMME*20+20};
                    tab_pomme[j] = nouvelle_pomme;
             
                }
            }

            if (serpent.taille == 2400 + 1){
                printf("Gagné\n");
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
	free(localisation);
	
}