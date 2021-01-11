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