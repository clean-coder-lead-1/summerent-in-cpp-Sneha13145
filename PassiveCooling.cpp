#include "PassiveCooling.h"
#include <stdio.h>

PassiveCooling::PassiveCooling()
{
}

PassiveCooling::~PassiveCooling()
{
}

void PassiveCooling::getTemperatureLimits(double& lowerLimit, double& upperLimit)
{
  lowerLimit = 0;
  upperLimit = 35;
}