#include"controlleur.c"
#include<graph.h>
#include <time.h>
#include <unistd.h>
#define TAILLE_CARRE 20


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

/*Fais un fond gris foncé.*/

void fond (void){
    EffacerEcran(CouleurParComposante(100,100,100));
}

void game_over(void){
    ChoisirCouleurDessin(CouleurParComposante(255,255,255));
    EcrireTexte(620,875, "Game Over", 1);
}

void initialisation(void){
    struct Serpent serpent = {3,2.0,1,CouleurParComposante(0,0,255),610,410,'d'}; /*milieu du tableau 620 et 410*/
    }

int x = 620; int y = 400; int boucle_jeu = 1;

void deplacement_serpent(void){ 
        struct Serpent serpent = {3,2.0,1,CouleurParComposante(0,0,255),610,410,'d'}; /*milieu du tableau 620 et 410*/

        while (boucle_jeu && serpent.en_vie_bool == 1){
        controle_jeu(&serpent);
            
		if (serpent.direction == 'd'){
		    ChoisirCouleurDessin(serpent.couleur);
            x+=20;
            RemplirRectangle(x,y,TAILLE_CARRE,TAILLE_CARRE);

            
		}
        if (serpent.direction == 'g'){
		    ChoisirCouleurDessin(serpent.couleur);
            x-=20;
            RemplirRectangle(x,y,TAILLE_CARRE, TAILLE_CARRE);
            
		}
        if (serpent.direction == 'h'){
		    ChoisirCouleurDessin(serpent.couleur);
            y-=20;
            RemplirRectangle(x,y,TAILLE_CARRE, TAILLE_CARRE);
            
		}
        if (serpent.direction == 'b'){
		    ChoisirCouleurDessin(serpent.couleur);
            y+=20;
            RemplirRectangle(x,y,TAILLE_CARRE, TAILLE_CARRE);
        }
        if (x<20 || x>1200 || y<20 || y>800){
            serpent.en_vie_bool = 0;
            ChoisirCouleurDessin(CouleurParComposante(255,0,0));
            RemplirRectangle(x,y,TAILLE_CARRE, TAILLE_CARRE );
            game_over();
        }
        printf("%d,%d", x, y);
        usleep(150000);
    }
	
}