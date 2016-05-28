#include "operatorfactory.h"
#include "addopreator.h"
#include "muloperator.h"
#include "suboperator.h"
#include "divoperator.h"
OperatorFactory::OperatorFactory()
{

}

Operation *OperatorFactory::creatOperation(const QString &op)
{
    Operation* oprt = NULL;
    if(op == "+")
       oprt = AddOpreator::Instance();
    else if(op == "*")
        oprt = MulOperator::Instance();
    else if(op == "-")
        oprt = subOperator::Instance();
    else if(op == "/")
        oprt = DivOperator::Instance();
    return oprt;

}
