#include "addopreator.h"

Operation* AddOpreator::instance = 0;
double AddOpreator::getResult()
{
    return numberA + numberB;
}

Operation *AddOpreator::Instance()
{
   if(instance == 0)
      instance = new AddOpreator;
   return instance;
}
