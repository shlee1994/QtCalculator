#ifndef ESTATUE_H
#define ESTATUE_H

#include <QString>
#include "evaluation.h"
class Evaluation;
class EStatue
{
public:
    EStatue();
    virtual QString expRecord(Evaluation *eva);
    virtual QString keyClicked(Evaluation *eva, const QString &keyVal);

    double calculate(const QString &oprt, double num1, double num2);
};

#endif // ESTATUE_H
