#ifndef SENSORULTRASSOM


#define SENSORULTRASSOM


class SensorUltrassom {
  public:

    SensorUltrassom(int trigger, int echo);
    float getDistance ();
    void debug();
    
  private:
  
  int _trigger;
  int _echo;
};

#endif  //endif SensorUltrassom
