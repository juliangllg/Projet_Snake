#include"controlleur.h"
#include"modele.h"
#include<graph.h>
#include <time.h>
#include <unistd.h>
#include "vue.h"
#define Y_POMME 40
#define X_POMME 60
#define TAILLE_CARRE 20
#define CONSTANTE_VITESSE 100000



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

void game_over(void){
    ChoisirCouleurDessin(CouleurParComposante(255,255,255));
    EcrireTexte(620,875, "Game Over", 2);
}



void affiche_pomme(){   
    int i;
    int rose = ChargerSprite("images/Pomme_rose.png");
    for(i = 0; i<5; i++){
        AfficherSprite(rose,tab_pomme[i][0],tab_pomme[i][1]);
        }
}


void initialisation(void){
    struct Serpent serpent = {4,2.0,1,CouleurParComposante(0,0,255),610,410,'d'}; /*milieu du tableau 620 et 410*/
    }


int x = 620; int y = 400; int boucle_jeu = 1;
void deplacement_serpent(struct Jeu *jeu){ 
    srand(time(NULL))
    for(num_pomme=0; num_pomme<5; num_pomme++){
            tab_pomme[num_pomme][0] = rand()%X_POMME*20+20;
            tab_pomme[num_pomme][1] = rand()%Y_POMME*20+20;
        }
        struct Serpent serpent = {4,
                                  1.25,
                                  1,
                                  CouleurParComposante(0,0,255),
                                  610,410,
                                  'd',}; /*Taille,Vitesse*/

        struct Pomme pomme = {1,'r',0,0};
        int* localisation = NULL;

        localisation = malloc((serpent.taille*2)*sizeof(int));

        
        int i;
        int n = 1;
        int j;

        *(localisation+0) = 620;
        *(localisation+1) = 400;
        
        while (boucle_jeu && serpent.en_vie_bool){
        for(i=(serpent.taille*2)-1;i>2;i-=2){
            *(localisation+(i-1)) = *(localisation+(i-3));
            *(localisation+i) = *(localisation+(i-2));
        }   

        affiche_pomme();
        
         
        ChoisirCouleurDessin(CouleurParComposante(0,0,255));

        controle_jeu(&serpent);
		if (serpent.direction == 'd'){
            x+=20;
            *(localisation+0) = x ;
      
            
		}
        if (serpent.direction == 'g'){
            x-=20;
            *(localisation+0)= x ;

         
		}
        if (serpent.direction == 'h'){
            y-=20;
            *(localisation+1)= y ;


  
		}
        if (serpent.direction == 'b'){
            y+=20;
            *(localisation+1)= y ;


    
        }


        if (x<20 || x>1200 || y<20 || y>800 ){
            serpent.en_vie_bool = 0;
            ChoisirCouleurDessin(CouleurParComposante(255,0,0));
            RemplirRectangle(*(localisation+0), *(localisation+1),TAILLE_CARRE,TAILLE_CARRE);
            game_over();
            break;
            

            
        }

        printf("\n");
        for(j=0; j<5; j++){

            if (*(localisation+0)== tab_pomme[j][0] && *(localisation+1) == tab_pomme[j][1]){
                serpent.taille += 1;
        
                localisation = realloc(localisation,serpent.taille*2*sizeof(int));
                tab_pomme[j][0] = rand()%X_POMME*20+20;
                tab_pomme[j][1] = rand()%Y_POMME*20+20;
            }
        }


        

        for (i=2;i<(serpent.taille*2)-1;i+=2){
            if (*(localisation+0) == *(localisation+i) && *(localisation+1) == *(localisation+i+1)){
                ChoisirCouleurDessin(CouleurParComposante(255,0,0));
                RemplirRectangle(*(localisation+0), *(localisation+1),TAILLE_CARRE,TAILLE_CARRE);
                game_over();
                break;
                
            }
        }


        for (i=0;i<(serpent.taille*2)-2;i+=2){
            printf("--[%d,%d]--",*(localisation+i),*(localisation+i+1));
        }



        for (i=0;i<(serpent.taille*2)-1;i+=2){
            RemplirRectangle(*(localisation+i),*(localisation+i+1),TAILLE_CARRE, TAILLE_CARRE );
        }



        if (n == 0 && !(*(localisation+0)== tab_pomme[j][0] && *(localisation+1) == tab_pomme[j][1])){
            n = 1;
            ChoisirCouleurDessin(CouleurParComposante(0,220,0));  
        }
        else{
            n = 0;
            ChoisirCouleurDessin(CouleurParComposante(0,180,0));
        }

        RemplirRectangle(*(localisation+((serpent.taille*2)-1)-1),*(localisation+((serpent.taille*2)-1)),TAILLE_CARRE, TAILLE_CARRE);

        ChoisirCouleurDessin(CouleurParComposante(0,0,0));
        DessinerRectangle(*(localisation+((serpent.taille*2)-1)-1),*(localisation+((serpent.taille*2)-1)),TAILLE_CARRE , TAILLE_CARRE );
        DessinerRectangle(*(localisation+((serpent.taille*2)-1)-1)+20,*(localisation+((serpent.taille*2)-1)),TAILLE_CARRE , TAILLE_CARRE );
        usleep((int) (serpent.vitesse*CONSTANTE_VITESSE));

    }
	
}