#include "ICoolingType.h"

class PassiveCooling:public ICoolingType
{
   PassiveCooling();
   ~PassiveCooling();
   
   void getTemperatureLimits(double& lowerLimit, double& upperLimit);
}
