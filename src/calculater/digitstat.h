#ifndef DIGITSTAT_H
#define DIGITSTAT_H

#include "estatue.h"

class digitStat : public EStatue
{
public:
    static const int MaxSize = 10;
    static EStatue* Instance();
    QString expRecord(Evaluation *eva) override;
    QString keyClicked(Evaluation *eva, const QString &keyVal) override;
protected:
    digitStat() = default;
private:
   static EStatue *instance;
};

#endif // DIGITSTAT_H
