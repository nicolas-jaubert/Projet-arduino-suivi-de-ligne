#include <Servo.h>

int position_bouton = 0 ;
int angle_servomoteur = 0 ;
Servo servo_pin_5;

int readPhoto = 0;
  
void setup()
{
  servo_pin_5.attach(5);
  Serial.begin(9600);
  
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  position_bouton = analogRead(A3) ;
  angle_servomoteur = map ( position_bouton , 0 , 1023 , 0 , 180 );
  servo_pin_5.write( angle_servomoteur );
  Serial.print("valeur du bouton = ");
  Serial.print(position_bouton);
  Serial.println();
  Serial.print("angle servomoteur = ");
  Serial.print(angle_servomoteur);
  Serial.print(" ");
  Serial.print("degres");
  Serial.println();
  Serial.print("---------------------------------");
  Serial.println();
  delay( 200 );

  readPhoto = analogRead(A1);
  if (readPhoto > 518) {
    digitalWrite(11, HIGH);
    delay(5000);
  } else {
    digitalWrite(11, LOW);
    delay(5000);
  }

}