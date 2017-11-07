#include "Toninho.h"
#include "ToninhoArduino.h"


/*
roteador,
bateria,
fone, 
celular,

*/
#define trigger 12
#define echo 13
#define lineSensorLeft 0
#define lineSensorRight 7
#define dcMotorLeftForward 6
#define dcMotorLeftBackward 5
#define dcMotorRightForward 10
#define dcMotorRightBackward 9


Toninho* terceiro = new ToninhoArduino(dcMotorLeftForward, dcMotorLeftBackward,
                                       dcMotorRightForward, dcMotorRightBackward,
                                       lineSensorLeft,      lineSensorRight,
                                       trigger,               echo);

void setup() {
  Serial.begin(9600);
  
 // put your setup code here, to run once:

}

void loop() {
  float distance;
  terceiro->getDistanceOfProximitySensor(distance);
  Serial.print(distance);
  Serial.println(" cm");

  terceiro->seguirLinha();
  //terceiro->setVelocityInToninho(100,100);

}
