#ifndef COMSTAT_H
#define COMSTAT_H
#include "estatue.h"
#include <QSet>
class comStat : public EStatue
{
public:
    static bool isOperator(const QString &str);
    static QSet<QString> operators;
    static EStatue* Instance();
    QString expRecord(Evaluation *eva) override;
    QString keyClicked(Evaluation *eva, const QString &keyVal) override;
protected:
    comStat() = default;
private:
    static EStatue* instance;
};

#endif // COMSTAT_H
