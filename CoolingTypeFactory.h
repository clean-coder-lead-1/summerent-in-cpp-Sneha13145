#include "ICoolingType.h"

class CoolingTypeFactory
{
  public:
     CoolingTypeFactory();
     ~CoolingTypeFactory();
     static ICoolingType* getCoolingType();
}
