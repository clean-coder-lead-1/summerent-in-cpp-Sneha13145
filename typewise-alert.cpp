#include "typewise-alert.h"
#include <stdio.h>

double lowerTempLimit[3] = {0,0,0};
double upperTempLimit[3] = {35,45,40};
const char* Temperature[3] = {"Normal", "too low", "too high"};


BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(
    CoolingType coolingType, double temperatureInC) {
  int lowerLimit = 0;
  int upperLimit = 0;
  calculateTemperatureLimits(coolingType, lowerLimit, upperLimit);
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void calculateTemperatureLimits(CoolingType coolingType, int& lowerLimit, int& upperLimit){
   lowerLimit = lowerTempLimit[coolingType];
   upperLimit = upperTempLimit[coolingType];
}

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );

  sendAlert(alertTarget, breachType);
}

void sendAlert(
    AlertTarget alertTarget, BreachType breachType) {
   switch(alertTarget) {
     case TO_CONTROLLER:
       sendToController(breachType);
       break;
     case TO_EMAIL:
       sendToEmail(breachType);
       break;
  }
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  const char* temp = Temperature[breachType];
  printf("To: %s\n", recepient);
  printf("Hi, the temperature is %s\n", temp);
}
