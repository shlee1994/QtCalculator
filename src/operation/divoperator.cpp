#include "divoperator.h"

Operation* DivOperator::instance = 0;
double DivOperator::getResult()
{
    return numberA / numberB;
}

Operation *DivOperator::Instance()
{
   if(instance == 0)
       instance = new DivOperator;
   return instance;
}
