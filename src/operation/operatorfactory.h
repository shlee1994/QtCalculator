#ifndef OPERATORFACTORY_H
#define OPERATORFACTORY_H
#include "operation.h"
#include <QString>

class OperatorFactory
{
public:
    OperatorFactory();
    Operation* creatOperation(const QString &op);
};

#endif // OPERATORFACTORY_H
