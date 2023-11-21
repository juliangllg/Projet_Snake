#include<graph.h>
#define TAILLE_CARRE 20

void cadrillage (void){
    int x=20; int y = 20;int j = 0; int i = 0;
    for (i; i<40; i++){
        for(j; j< 30; j++){
            if(i%2 !=0){
                ChoisirCouleurDessin(CouleurParComposante(0,0,0));
                DessinerRectangle(x,y,TAILLE_CARRE , TAILLE_CARRE );
                ChoisirCouleurDessin(CouleurParComposante(0,180,0));
                RemplirRectangle(x,y,TAILLE_CARRE,TAILLE_CARRE);
                DessinerRectangle(x+20,y,TAILLE_CARRE,TAILLE_CARRE);
                ChoisirCouleurDessin(CouleurParComposante(0,220,0));
                RemplirRectangle(x+20, y,TAILLE_CARRE,TAILLE_CARRE);
            }
            else {
                ChoisirCouleurDessin(CouleurParComposante(0,0,0));
                DessinerRectangle(x,y,TAILLE_CARRE , TAILLE_CARRE );
                ChoisirCouleurDessin(CouleurParComposante(0,220,0));
                RemplirRectangle(x,y,TAILLE_CARRE,TAILLE_CARRE);
                DessinerRectangle(x+20,y,TAILLE_CARRE,TAILLE_CARRE);
                ChoisirCouleurDessin(CouleurParComposante(0,180,0));
                RemplirRectangle(x+20, y,TAILLE_CARRE,TAILLE_CARRE);
            }

            x+=40;
        }
        x = 20;
        y += 20;
        j=0;
    }
}

void fond (void){
    EffacerEcran(CouleurParComposante(0,0,0));
    ChoisirCouleurDessin(CouleurParComposante(0,255,0));
    RemplirRectangle(20,20,1200,800);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
}



/*r=CouleurParComposante(255,0,0);
g=CouleurParComposante(0,255,0);
b=CouleurParComposante(0,0,255);
b=CouleurParComposante(255,255,255);
w=CouleurParComposante(255,150,0);
c=CouleurParComposante(255,0,0);
c=CouleurParComposante(255,0,0);*/

