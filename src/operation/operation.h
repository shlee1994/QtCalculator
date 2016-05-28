#ifndef OPERATION_H
#define OPERATION_H


class Operation
{
public:
    Operation();
    virtual double getResult() = 0;
    void setNumA(double num){
        numberA = num;
    }
    void setNumB(double num){
        numberB = num;
    }

protected:
    double numberA, numberB;
};

#endif // OPERATION_H
