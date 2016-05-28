#ifndef ADDOPREATOR_H
#define ADDOPREATOR_H
#include "operation.h"
class AddOpreator : public Operation
{
public:
    double getResult() override;
    static Operation *Instance();
protected:
    AddOpreator() = default;
    static Operation *instance;
};

#endif // ADDOPREATOR_H
