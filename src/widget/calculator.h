#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include "../calculater/evaluation.h"

class calculator : public QWidget
{
    Q_OBJECT

public:
    calculator(QWidget *parent = 0);
    ~calculator();
    QPushButton *createBtn(const QString &str, const char* member);

private slots:
    void keyClicked();
    void clearClicked();
    /*void digitClicked();
    void pntClicked();*/
    void eqlClicked();

private:

   QLineEdit* dspTmp;
   QLineEdit* dspRcd;
   Evaluation* eval;
};

#endif // CALCULATOR_H
