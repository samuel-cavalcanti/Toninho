
#include "DCMotor.h"

DCMotor::DCMotor(int in1, int in2, int in3, int in4) { // in1, in2 ==  MOtorRight  , in3, in4 == MOtorLeft
  _in1 = in1;
  _in2 = in2;
  _in3 = in3;
  _in4 = in4;

  interval = 20;
}

void DCMotor::backward() {
  clockwise(_in1, _in2);
  clockwise(_in3, _in4);
}

void DCMotor::forward() {
  antiClockwise(_in1, _in2);
  antiClockwise(_in3, _in4);
}

void DCMotor::left() {
  clockwise(_in1, _in2);
  antiClockwise(_in3, _in4);
}

void DCMotor::right() {
  antiClockwise(_in1, _in2);
  clockwise(_in3, _in4);
}

void DCMotor::stop() {
  stopDCMotor(_in1, _in2);
  stopDCMotor(_in3, _in4);

}

void DCMotor::slowForward() {

  if (slowMode(1000))
    stop();

  else
    forward();

}

void DCMotor::slowBackward() {
  if (slowMode(40))
    stop();
  else
    backward();

}

void DCMotor::slowLeft() {
  if (slowMode(interval))
    stop();
  else
    left();

}

void DCMotor::slowRight() {
  if (slowMode(interval))
    stop();
  else
    right();

}

void DCMotor::rightBack() {

  antiClockwise(_in1, _in2);
  stopDCMotor(_in3, _in4);
}

void DCMotor::leftBack() {
  stopDCMotor(_in1, _in2);
  antiClockwise(_in3, _in4);
}

void DCMotor::clockwise(int inx, int iny) {
  digitalWrite(inx, 1); digitalWrite(iny, 0);
}

void DCMotor::antiClockwise(int inx, int iny) {
  digitalWrite(inx, 0); digitalWrite(iny, 1);
}

bool DCMotor::slowMode(long interval) {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis > interval) {

    estado = !estado;
    previousMillis = currentMillis;
  }

  if (estado)
    return true;
  else
    return false;

}

void DCMotor::stopDCMotor(int inx, int iny) {
  digitalWrite(inx, 0); digitalWrite(iny, 0);
}



// in1, in2 ==  MOtorRight  , in3, in4 == MOtorLeft
void DCMotor::setVelocity(int velRight, int velLeft) {

  if ( velLeft > 0) {
    analogWrite(_in2, velLeft);
    analogWrite(_in1, 0);
  }
  
  else {
    analogWrite(_in1, velLeft);
    analogWrite(_in2, 0);

  }

  if (velRight > 0 ) {
    analogWrite(_in4, velRight);
    analogWrite(_in3, 0);
  }

  else {
    analogWrite(_in3, velRight);
    analogWrite(_in4, 0);
  }



}





