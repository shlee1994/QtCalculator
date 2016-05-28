#ifndef EVALUATION_H
#define EVALUATION_H

#include <QString>
#include "estatue.h"
#include <QString>
#include <QStack>
#include <QVector>
#include <QMap>

class EStatue;
class Evaluation
{
    friend class digitStat;
    friend class comStat;
public:
    Evaluation();
    QString keyClicked(const QString &val);
    QString clear();
    QString expRecord(void);
    EStatue *changSat(EStatue *s);
    char getPreced(const QString &op1, const QString &op2){
        return oprtPrecede[op1][op2];
    }
    void dealWithOprt();
    double getResult();

private:
    EStatue *state;
    QString valBuf;
    QString expBuf;

    QStack<double> numStack;
    QStack<QString> oprtStack;
    QMap<QString, QMap<QString, char> > oprtPrecede;
};

#endif // EVALUATION_H
