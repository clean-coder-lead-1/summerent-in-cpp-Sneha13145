#include "ICoolingType.h"
#include "typewise-alert.h"

class CoolingTypeFactory
{
  public:
     CoolingTypeFactory();
     ~CoolingTypeFactory();
     static ICoolingType* getCoolingType(CoolingType coolingType);
}
