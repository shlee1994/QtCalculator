#include "comstat.h"
#include "digitstat.h"
EStatue* comStat::instance = 0;
QSet<QString> comStat::operators = {
    "+", "-", "*", "/"
};
bool comStat::isOperator(const QString &str)
{
   if(operators.contains(str)) return true;
   else return false;
}

EStatue *comStat::Instance()
{
    if(instance == 0)
        instance = new comStat;
    return instance;
}

QString comStat::expRecord(Evaluation *eva)
{
    return eva->expBuf;
}

QString comStat::keyClicked(Evaluation *eva,const QString &keyVal)
{
    if(eva->valBuf[0].isDigit() || eva->valBuf == ")")
//    if(true)
    {
        //clicked digits-key.
        if(keyVal[0].isDigit() && eva->valBuf.size() < digitStat::MaxSize)
        {
            eva->valBuf.append(keyVal);
        }
        //clicked point.
        else if(keyVal == "."){
            if(!eva->valBuf.contains(".")){
                eva->valBuf.append(".");
            }
        }
        //clicked "("
        else if(keyVal == ")" && !eva->oprtStack.contains("("))
        {}

               //clicked an operator.
        else{
            if(eva->valBuf.endsWith("."))
                eva->valBuf.append("0");

            if(keyVal == "(" && !isOperator(eva->valBuf))
                eva->oprtStack.push("*");

                eva->expBuf.append(eva->valBuf);
                bool ok;
                double value = eva->valBuf.toDouble(&ok);
                if(ok)
                    eva->numStack.push(value);
                eva->valBuf = keyVal;

                eva->dealWithOprt();
                if(eva->oprtStack.isEmpty() && eva->valBuf =="=")
                {
                    QString result = QString::number(eva->numStack.top());
                    //eva->clear();
                    eva->changSat(digitStat::Instance());
                    return result;
                }
                else if(keyVal == ")")
                {

                }
                else{

                    eva->oprtStack.push(keyVal);
                    eva->changSat(digitStat::Instance());
                }
        }
    }
    else if(eva->valBuf == ".")
        eva->valBuf = "0.";
    return eva->valBuf;
}
