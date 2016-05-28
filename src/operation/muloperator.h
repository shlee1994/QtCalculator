#ifndef MULOPERATOR_H
#define MULOPERATOR_H
#include "operation.h"

class MulOperator : public Operation
{
public:
    double getResult() override;
    static Operation* Instance();
protected:
    MulOperator() = default;
    static Operation* instance;
};

#endif // MULOPERATOR_H
