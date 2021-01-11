#include <Servo.h>

int position_bouton = 0 ;													//Positionnement du bouton par rapport au potentiomètre
int angle_servomoteur = 0 ;													//Positionnement du Servomoteur par rapport à un angle
Servo servo_pin_5;															//Identité du Servomoteur

int readPhoto = 0;															//Fonction de lecture des capteurs de lumière
  
void setup()																//Initialisation des paramètres
{
  servo_pin_5.attach(5);
  Serial.begin(9600);														//Initialisation de la Carte Arduino
  
  pinMode(A1, INPUT);														//Capteur de lumière gauche
  pinMode(A2, INPUT);														//Capteur de lumière droit
  
  pinMode(11, OUTPUT);														//Moteur gauche
  pinMode(10, OUTPUT);														//Moteur droit
}

void loop()																	//Boucle du programme
{
  position_bouton = analogRead(A3);											//Lecture de l'emplacement du potentiomètre
  angle_servomoteur = map ( position_bouton , 0 , 1023 , 0 , 180 );			//Initialisation du potentiomètre
  servo_pin_5.write( angle_servomoteur );									//Rafraîchissement de la prise de mesure
  Serial.print("valeur du bouton = ");										//Indentation de la valeur
  Serial.print(position_bouton);											//Prise de la mesure du potentiomètre
  Serial.println();															//Saut de ligne
  Serial.print("angle servomoteur = ");										//Indentation de la valeur
  Serial.print(angle_servomoteur);											//Prise de la mesure de l'angle du Servomoteur
  Serial.print(" ");														//Indentation de la valeur
  Serial.print("degres");													//Indentation de la valeur
  Serial.println();															//Saut de ligne
  Serial.print("---------------------------------");						//Indentation de la valeur
  Serial.println();															//Saut de ligne
  delay( 200 );																//Délai de la boucle
  
  readPhoto = analogRead(A1);												//Fonction de lecture du premier capteur
  if (readPhoto > 518) {													//Programme d'action vis-à-vis du non-lux du capteur
    digitalWrite(11, HIGH);													//Activation du moteur
    delay(1000); 															//Délai de la boucle
  } else {																	//Programme d'action vis-à-vis du lux du premier capteur
    digitalWrite(11, LOW);													//Désactivation du moteur
    delay(1000);															//Délai de la boucle
  }
  
    readPhoto = analogRead(A2);												//Fonction de lecture du deuxième capteur
  if (readPhoto < 518) {													//Programme d'action vis-à-vis du lux du premier capteur
    digitalWrite(10, HIGH);													//Activation du moteur
    delay(1000);															//Délai de la boucle
  } else {																	//Programme d'action vis-à-vis du non-lux du capteur
    digitalWrite(10, LOW);													//Désactivation du moteur
    delay(1000);															//Délai de la boucle
  }
}
