#include "Toninho.h"
#include "ToninhoArduino.h"


Toninho* terceiro = new ToninhoArduino(6,5,10,9,0,7,12,13);

void setup() {
  Serial.begin(9600);
  
 // put your setup code here, to run once:

}

void loop() {
  //float distance;
  //terceiro->getDistanceOfProximitySensor(distance);
  //Serial.print(distance);
  //Serial.println(" cm");

  terceiro->seguirLinha();
  //terceiro->setVelocityInToninho(100,100);

}
