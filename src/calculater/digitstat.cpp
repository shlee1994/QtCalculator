#include "digitstat.h"
#include "comstat.h"
EStatue *digitStat::instance = 0;
//int digitStat::MaxSize;
EStatue *digitStat::Instance()
{
   if(instance ==0)
       instance = new digitStat;
   return instance;
}

QString digitStat::expRecord(Evaluation *eva)
{
    return eva->expBuf;
}

QString digitStat::keyClicked(Evaluation *eva, const QString &keyVal)
{
    //if operation is completed , clear buffs.
    if(eva->valBuf == "=")
        eva->clear();
    //disallow operator.
    if(comStat::isOperator(keyVal) || keyVal == ")" || keyVal == "=")
        return eva->valBuf.isEmpty() ? QString::number(0) : eva->valBuf;


    eva->expBuf.append(eva->valBuf);
    if(keyVal == "("){
        //if "(" is after digits autoly add an "*".
        if(eva->valBuf[0].isDigit())
            eva->oprtStack.push("*");
        eva->oprtStack.push(keyVal);
        eva->valBuf = keyVal;
        return keyVal;
    }
    else{
       //digit-key is clicked after an operator.
      //  if(comStat::isOperator(eva->valBuf)) {
      //  }

        if(keyVal == ".")
            eva->valBuf = "0.";
        else
            eva->valBuf = keyVal;
        eva->changSat(comStat::Instance());
        return eva->valBuf;
    }
}
