/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ToninhoArduino.cpp
 * Author: samuel
 * 
 * Created on 4 de Novembro de 2017, 10:59
 */

#include "ToninhoArduino.h"




ToninhoArduino::ToninhoArduino(int _MotorForward_1,  int _MotorBackward_1, int _MotorForward_2 , int _MotorBackward_2, int _lineSensorRight, int _lineSensorLeft, int _trigger , int _echo) {

    motorToninho   = new DCMotor(_MotorForward_1, _MotorBackward_1, _MotorForward_2, _MotorBackward_2);
    sensorEsquerdo = new SensorLinha(_lineSensorLeft);
    sensorDireito  = new SensorLinha(_lineSensorRight);
    ultrassom      = new SensorUltrassom( _trigger,_echo );
   
        
}

bool ToninhoArduino::detectedByLeft(){

    if (sensorEsquerdo->detectedBySensor() )
        return true;
    else 
        return false;


}

bool ToninhoArduino::detectedByRight(){
    
        if (sensorDireito->detectedBySensor() )
            return true;
        else 
            return false;
            
    
    }

bool ToninhoArduino::getDistanceOfProximitySensor(float &distance){

    distance =  ultrassom->getDistance();
    
    if(distance < 51)
        return true;
    else 
        return false;


}

void ToninhoArduino::setVelocityInToninho(float leftMotor, float rightMotor){
    // int velRight = (int) rightMotor;
    // int velLeft = (int) leftMotor;
    motorToninho->setVelocity(leftMotor, rightMotor);

}

void ToninhoArduino::seguirLinha(){
    int teste = 150;

    


     if ( detectedByLeft() and  ! detectedByRight() ){
        leftVelocity  =   150;  rightVelocity =  -180;
        setVelocityInToninho(leftVelocity, rightVelocity);
        delay(150);
        
    
     }  


     else if ( !detectedByLeft() and   detectedByRight() ){
        leftVelocity  =   -180;  rightVelocity =  150;
        setVelocityInToninho(leftVelocity, rightVelocity);
        delay(150);
        
       

    }

    // (detectedByLeft())  ? leftVelocity = 100 : leftVelocity = -150;
    // (detectedByRight()) ? rightVelocity  = 100 : rightVelocity  = --150;




    
    setVelocityInToninho(-180, -180);
    



        // Serial.print("t: ");
        // Serial.println(t);

       
    

        //delay(1000);

}