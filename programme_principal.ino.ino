#include "fonction.h"
#include "terminal.h"

void setup() {
  // put your setup code here, to run once:
  pinMode (BOUCLEAMONT, INPUT);
  pinMode (BOUCLEAVAL, INPUT);
  pinMode (VALIDATION, INPUT);
  Serial.begin(9600);
  
  }

void loop() {//début du programme
  //initialization nombre de voiture
    int tempo=0, testTempo=1;
    static int nombreVoiture=0;
    static int nombrePlace=200;

   afficheUtilisateur();   
   if (digitalRead(BOUCLEAMONT)==1 && digitalRead(BOUCLEAVAL)==0){ //selection d'entrée
      
      if(digitalRead(VALIDATION)==1){ //controle de validation de carte ou de code
          afficheUtilisateur();
          commandeBarriere(OUVRIR,2); //début du sous programme d'ouverture de la barriére pour véhicule entrant
          while (digitalRead(BOUCLEAMONT)==1 && digitalRead(BOUCLEAVAL)==0 && testTempo==1){
              tempo++;
              delay(30);
              if(tempo==1000){
                  testTempo=0;
              }
          }
          if (digitalRead(BOUCLEAVAL)==1 || digitalRead(BOUCLEAMONT)==0){
                  if(digitalRead(BOUCLEAVAL)==1 || digitalRead(BOUCLEAMONT)==1){
                      while(digitalRead(BOUCLEAVAL)==1 || digitalRead(BOUCLEAMONT)==1);
                      nombreVoiture++;
                      nombrePlace--;
                      afficheMenu(nombreVoiture,nombrePlace);
                  }  
          }
        commandeBarriere(FERMER,2);  
     }//fin du sous programme    
     
  }//fin de la selection d'entrée 
      
    
      

     
   if (digitalRead(BOUCLEAVAL)==1 && digitalRead(BOUCLEAMONT)==0){//selection de sortie
    
      commandeBarriere(OUVRIR,2);//début du sous programme d'ouverture de la barriére pour véhicule sortant 
      while (digitalRead(BOUCLEAVAL)==1 && digitalRead(BOUCLEAMONT)==0);
      if(digitalRead (BOUCLEAVAL)==1 || digitalRead(BOUCLEAMONT)==1){
        
          while(digitalRead(BOUCLEAMONT)==1 || digitalRead (BOUCLEAVAL)==1);;
          nombreVoiture--;
          nombrePlace++;
          afficheMenu(nombreVoiture,nombrePlace); 
      } 
      commandeBarriere(FERMER,2);//fin du sous programme 
   }//fin de la selection de sortie   
}//fin du programme
