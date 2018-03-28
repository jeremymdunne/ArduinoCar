#include "HCSR04.h"


HCSR04::HCSR04(int trig, int echo, long maxPulseMicros){
  _trig = trig;
  _echo = echo;
  _maxPulseMicros = maxPulseMicros;
  pinMode(_trig, OUTPUT);
  pinMode(_echo, INPUT);
}

HCSR04::HCSR04(int trig, int echo){
  _trig = trig;
  _echo = echo;
  pinMode(_trig, OUTPUT);
  pinMode(_echo, INPUT);
}

long HCSR04::getTimeMicros(){
  digitalWrite(_trig,LOW);
  delayMicroseconds(2);
  digitalWrite(_trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(_trig,LOW);
  return pulseIn(_echo,HIGH,_maxPulseMicros);
}


float HCSR04::getDistance(){
  long time = getTimeMicros();
  if(time == 0) return -1;
  return SPEED_OF_SOUND * (time/1000000.0);
}
