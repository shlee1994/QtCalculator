#include "suboperator.h"

Operation* subOperator::instance = 0;
double subOperator::getResult()
{
    return numberA - numberB;
}

Operation *subOperator::Instance()
{
   if(instance == 0)
       instance = new subOperator;
   return instance;
}
