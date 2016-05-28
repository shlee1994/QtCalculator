#include "evaluation.h"
#include "comstat.h"
#include "digitstat.h"
#include "../operation/operatorfactory.h"
#include "../operation/addopreator.h"
Evaluation::Evaluation() : state(digitStat::Instance())
{
    oprtStack.push("=");
    oprtPrecede["+"]["+"] = '>'; oprtPrecede["-"]["+"] = '>';
    oprtPrecede["+"]["-"] = '>'; oprtPrecede["-"]["-"] = '>';
    oprtPrecede["+"]["*"] = '<'; oprtPrecede["-"]["*"] = '<';
    oprtPrecede["+"]["/"] = '<'; oprtPrecede["-"]["/"] = '<';
    oprtPrecede["+"]["("] = '<'; oprtPrecede["-"]["("] = '<';
    oprtPrecede["+"][")"] = '>'; oprtPrecede["-"][")"] = '>';
    oprtPrecede["+"]["="] = '>'; oprtPrecede["-"]["="] = '>';
    oprtPrecede["*"]["+"] = '>'; oprtPrecede["/"]["+"] = '>';
    oprtPrecede["*"]["-"] = '>'; oprtPrecede["/"]["-"] = '>';
    oprtPrecede["*"]["*"] = '>'; oprtPrecede["/"]["*"] = '>';
    oprtPrecede["*"]["/"] = '>'; oprtPrecede["/"]["/"] = '>';
    oprtPrecede["*"]["("] = '<'; oprtPrecede["/"]["("] = '<';
    oprtPrecede["*"][")"] = '>'; oprtPrecede["/"][")"] = '>';
    oprtPrecede["*"]["="] = '>'; oprtPrecede["/"]["="] = '>';
    oprtPrecede["("]["+"] = '<'; oprtPrecede[")"]["+"] = '>';
    oprtPrecede["("]["-"] = '<'; oprtPrecede[")"]["-"] = '>';
    oprtPrecede["("]["*"] = '<'; oprtPrecede[")"]["*"] = '>';
    oprtPrecede["("]["/"] = '<'; oprtPrecede[")"]["/"] = '>';
    oprtPrecede["("]["("] = '<'; oprtPrecede[")"]["("] = 'X';
    oprtPrecede["("][")"] = '='; oprtPrecede[")"][")"] = '>';
    oprtPrecede["("]["="] = 'X'; oprtPrecede[")"]["="] = '>';
    oprtPrecede["="]["+"] = '<';// oprtPrecede[")"]["+"] = ">";
    oprtPrecede["="]["-"] = '<'; //oprtPrecede[")"]["-"] = ">";
    oprtPrecede["="]["*"] = '<'; //oprtPrecede[")"]["*"] = ">";
    oprtPrecede["="]["/"] = '<'; //oprtPrecede[")"]["/"] = ">";
    oprtPrecede["="]["("] = '<'; //oprtPrecede[")"]["("] = "X";
    oprtPrecede["="][")"] = 'X'; //oprtPrecede[")"][")"] = ">";
    oprtPrecede["="]["="] = '='; //oprtPrecede[")"]["#"] = ">";
}

QString Evaluation::keyClicked(const QString &val)
{
    return state->keyClicked(this, val);
}

QString Evaluation::clear()
{
    numStack.clear();
    oprtStack.clear();
    oprtStack.push("=");
    valBuf.clear();
    expBuf.clear();
    return QString::number(0);
}

QString Evaluation::expRecord()
{
    return state->expRecord(this);
}

EStatue *Evaluation::changSat(EStatue *s)
{
    state = s;
    return state;
}

void Evaluation::dealWithOprt()
{
    QString optr = oprtStack.top();
    char preced = getPreced(optr, valBuf);
    do{
        switch (preced) {
        case '>':
        {
            QString oprt = oprtStack.pop();
            double num2 = numStack.pop();
            double num1 = numStack.pop();
            double result = 0;
            OperatorFactory* Factory = new OperatorFactory;
            Operation* operation = Factory->creatOperation(oprt);
            operation->setNumA(num1);
            operation->setNumB(num2);
            result = operation->getResult();
            numStack.push(result);
            break;
        }
        case '=':
            oprtStack.pop();
            return;
          //  break;
        }
    }while( !oprtStack.isEmpty() &&
            (preced = getPreced(oprtStack.top(), valBuf)) != '<' &&
            preced != 'X'
            );
}

double Evaluation::getResult()
{
       return numStack.pop();
}
