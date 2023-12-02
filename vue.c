#include"controlleur.c"
#include<graph.h>
#include <time.h>
#include <unistd.h>
#define Y_POMME 40
#define X_POMME 60
#define TAILLE_CARRE 20
#define CONSTANTE_VITESSE 100000





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


int tableau_pomme(int tableau[5][2]){
    int num_pomme;
    for(num_pomme=0; num_pomme<5; num_pomme++){
            tableau[num_pomme][0] = rand()%X_POMME*20+20;
            tableau[num_pomme][1] = rand()%Y_POMME*20+20;
        }
    return tableau[5][2];
}

void affiche_pomme(int tableau[5][2]){   
    int i;
    int rose = ChargerSprite("images/Pomme_rose.png");
    
    for(i = 0; i<5; i++){
        AfficherSprite(rose,tableau[i][0],tableau[i][1]);
        }
    
}


void initialisation(void){
    struct Serpent serpent = {4,2.0,1,CouleurParComposante(0,0,255),610,410,'d'}; /*milieu du tableau 620 et 410*/
    }
    
int x = 620; int y = 400; int boucle_jeu = 1;
void deplacement_serpent(struct Jeu *jeu){ 

        struct Serpent serpent = {10,
                                  1.25,
                                  1,
                                  CouleurParComposante(0,0,255),
                                  610,410,
                                  'd',}; /*Taille,Vitesse*/
        struct Pomme pomme = {1,'r',0,0};
        int localisation[serpent.taille][2];

    

    
        localisation[0][0] = 620;
        localisation[0][1] = 400;
        
        int tab_pomme[5][2];
        int num_pomme;
        for(num_pomme=0; num_pomme<5; num_pomme++){
            tab_pomme[num_pomme][0] = rand()%X_POMME*20+20;
            tab_pomme[num_pomme][1] = rand()%Y_POMME*20+20;
        }
        
        int i;
        int n;
        int j;
        while (boucle_jeu && serpent.en_vie_bool){
        
        
         
        ChoisirCouleurDessin(CouleurParComposante(0,0,255));

        controle_jeu(&serpent);
		if (serpent.direction == 'd'){
            x+=20;
            localisation[0][0] = x ;
        affiche_pomme(tab_pomme);
            
		}
        if (serpent.direction == 'g'){
            x-=20;
            localisation[0][0] = x ;

         
		}
        if (serpent.direction == 'h'){
            y-=20;
            localisation[0][1] = y ;


  
		}
        if (serpent.direction == 'b'){
            y+=20;
            localisation[0][1] = y ;


    
        }


        if (x<20 || x>1200 || y<20 || y>800 ){
            serpent.en_vie_bool = 0;
            ChoisirCouleurDessin(CouleurParComposante(255,0,0));

            game_over();
        }


        for(j; j<5; j++){
            if (localisation[0][0] == tab_pomme[j][0] && localisation[0][1] == tab_pomme[j][1]){
                serpent.taille += 1;
                tab_pomme[j][0] = rand()%X_POMME*20+20;
                tab_pomme[j][1] = rand()%Y_POMME*20+20;
            }
        }

        for (i=1;i<serpent.taille;i++){
            if (localisation[0][0] == localisation[i][0] && localisation[0][1] == localisation[i][1]){
                game_over();

            }
        }
            
        for(i=0;i<serpent.taille;i++){
            printf("{[%d,%d]}--",localisation[i][0],localisation[i][1]);
            
        }
        printf("\n\n");
        for (i=serpent.taille;i>0;i--){
            localisation[i][0] = localisation[i-1][0];
            localisation[i][1] = localisation[i-1][1];
        }
            
        for (i=0;i<serpent.taille;i++){
            RemplirRectangle(localisation[i][0],localisation[i][1],TAILLE_CARRE, TAILLE_CARRE );
        }


        /*
        printf("\t\t\t\t\t\t\t\tSpeed = %.3f\n",serpent.vitesse);
        printf("%d,%d\n",localisation[0][0],localisation[0][1]);
        */
        n+= 1;
        if (n%2 == 0){
            ChoisirCouleurDessin(CouleurParComposante(0,220,0));  
        }
        else{
            ChoisirCouleurDessin(CouleurParComposante(0,180,0));
        }
        RemplirRectangle(localisation[serpent.taille][0],localisation[serpent.taille][1],TAILLE_CARRE, TAILLE_CARRE);

        ChoisirCouleurDessin(CouleurParComposante(0,0,0));
        DessinerRectangle(localisation[serpent.taille][0],localisation[serpent.taille][1],TAILLE_CARRE , TAILLE_CARRE );
        DessinerRectangle(localisation[serpent.taille][0]+20,localisation[serpent.taille][1],TAILLE_CARRE , TAILLE_CARRE );

        usleep((int) (serpent.vitesse*CONSTANTE_VITESSE));

    }
	
}