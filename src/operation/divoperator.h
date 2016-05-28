#ifndef DIVOPERATOR_H
#define DIVOPERATOR_H
#include "operation.h"

class DivOperator : public Operation
{
public:
    double getResult() override;
    static Operation *Instance();
protected:
    DivOperator() = default;
    static Operation *instance;
};

#endif // DIVOPERATOR_H
