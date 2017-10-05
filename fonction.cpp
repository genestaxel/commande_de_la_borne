#include "fonction.h"
#include "terminal.h"
#include "Arduino.h" 


void commandeBarriere (int sens, int tours){
  pinMode(PAS1, OUTPUT);
  pinMode(PAS2, OUTPUT);
  pinMode(PAS3, OUTPUT);
  pinMode(PAS4, OUTPUT);
  if(sens){
    ouvrir(tours);
  }
  else{
    fermer(tours);
  }
}


void ouvrir (int tours){
  int i,j;
  for(i=0;i<tours;i++){
    for(j=0;j<12;j++){
      seq(1);
      delay(20);
      seq(2);
      delay(20);
      seq(3);
      delay(20);
      seq(4);
      delay(20);
    }
  }
}


void fermer (int tours){
  int i,j;
  for(i=0;i<tours;i++){
    for(j=0;j<12;j++){
      seq(4);
      delay(20);
      seq(3);
      delay(20);
      seq(2);
      delay(20);
      seq(1);
      delay(20);
    }
  }
}

void seq(int numeroSeq){
  switch(numeroSeq){
    case 1:
      digitalWrite(PAS1, HIGH);
      digitalWrite(PAS2, LOW);
      digitalWrite(PAS3, LOW);
      digitalWrite(PAS4, HIGH);
      break;
    case 2:
      digitalWrite(PAS1, LOW);
      digitalWrite(PAS2, HIGH);
      digitalWrite(PAS3, LOW);
      digitalWrite(PAS4, HIGH);
      break;
    case 3:
      digitalWrite(PAS1, LOW);
      digitalWrite(PAS2, HIGH);
      digitalWrite(PAS3, HIGH);
      digitalWrite(PAS4, LOW);
      break;
    case 4:
      digitalWrite(PAS1, HIGH);
      digitalWrite(PAS2, LOW);
      digitalWrite(PAS3, HIGH);
      digitalWrite(PAS4, LOW);
      break;
  }
}

void afficheMenu(int nombreVoiture, int nombrePlace){
  
    terminalCouleur(31, 47);
    terminalPosition(10,30);
    Serial.print("Nombre de voiture : ");
    Serial.println(nombreVoiture, DEC);
    
    terminalCouleur(31, 47);
    terminalPosition(12,30);
    Serial.print("Nombre de place : ");
    Serial.println(nombrePlace, DEC);
     
}

void afficheUtilisateur (void){
  
    terminalCouleur(31, 47);
    terminalPosition(2,30);
    Serial.print("bonjour et bienvenue !!");
    if (digitalRead(VALIDATION)==0){
        terminalPosition(3,30);
        Serial.print("veuillez inserer votre carte"); 
    }
    if (digitalRead(VALIDATION)==1){
        terminalPosition(3,30);
        Serial.print("veuillez retirer votre carte");
    }
}

