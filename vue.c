#include<graph.h>
#define TAILLE_CARRE 20

void cadrillage (void){
    int x=10; int y = 10;int j = 0; int i = 0;
    for (i; i<40; i++){
        for(j; j< 60; j++){
            DessinerRectangle(x,y,TAILLE_CARRE , TAILLE_CARRE );
            x+=10;
        }
        x = 10;
        y += 10;
        j=0;
    }
}

/*r=CouleurParComposante(255,0,0);
g=CouleurParComposante(0,255,0);
b=CouleurParComposante(0,0,255);
b=CouleurParComposante(255,255,255);
w=CouleurParComposante(255,150,0);
c=CouleurParComposante(255,0,0);
c=CouleurParComposante(255,0,0);*/

