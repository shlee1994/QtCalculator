#ifndef SUBOPERATOR_H
#define SUBOPERATOR_H
#include "operation.h"

class subOperator : public Operation
{
public:
    double getResult() override;
    static Operation *Instance();
protected:
    subOperator() = default;
    static Operation *instance;

};

#endif // SUBOPERATOR_H
