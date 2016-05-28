#include "muloperator.h"

Operation* MulOperator::instance = 0;
double MulOperator::getResult()
{
    return numberA * numberB;
}

Operation *MulOperator::Instance()
{
   if(instance == 0)
       instance = new MulOperator;
   return instance;
}

