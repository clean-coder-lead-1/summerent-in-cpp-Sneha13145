#pragma once

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

void calculateTemperatureLimits(CoolingType coolingType, double& lowerLimit, double& upperLimit);

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

std::vector<double> lowerTempLimit;
std::vector<double> upperTempLimit;
std::map<coolingType, double> temperatureLimits;

void checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

void sendAlert(AlertTarget alertTarget, BreachType breachType);
void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
