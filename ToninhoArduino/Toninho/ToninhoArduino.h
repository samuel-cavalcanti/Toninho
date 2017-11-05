/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ToninhoArduino.h
 * Author: samuel
 *
 * Created on 4 de Novembro de 2017, 10:59
 *  Class Toninho :
 *  virtual bool detectedByLeft() = 0;
    virtual bool detectedByRight() = 0;
    virtual bool getDistanceOfProximitySensor(float &distance) = 0;
    virtual void setVelocityInToninho(float rightMotor, float leftMotor) =0;
    virtual void seguirLinha() = 0;
    virtual void delay(int time) = 0;
 */

#ifndef TONINHOARDUINO_H
#define TONINHOARDUINO_H

#include "Toninho.h"
#include "DCMotor.h"
#include "SensorLinha.h"
#include "SensorUltrassom.h"

class ToninhoArduino : public Toninho {
public: 
    ToninhoArduino(int _MotorForward_1 , int _MotorBackward_1,
                   int _MotorForward_2 , int _MotorBackward_2,
                   int _lineSensorRight, int _lineSensorLeft,
                   int _trigger        , int __echo);
    bool detectedByLeft();
    bool detectedByRight();
    bool getDistanceOfProximitySensor(float &distance);
    void seguirLinha();
    void setVelocityInToninho(float rightMotor, float leftMotor);
                   
                   


    
   
   
private:
    DCMotor* motorToninho;
    SensorLinha* sensorEsquerdo;
    SensorLinha* sensorDireito;
    SensorUltrassom * ultrassom;
    int rightVelocity = 100;
    int leftVelocity  = 100;
    


};

#endif /* TONINHOARDUINO_H */

