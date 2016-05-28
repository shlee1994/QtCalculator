#include "calculator.h"
#include "../calculater/digitstat.h"
#include <QString>
#include <QGridLayout>
calculator::calculator(QWidget *parent)
    : QWidget(parent)
{    
    //create and init a lineEdit to show the result.
    dspTmp = new QLineEdit("0");
    dspTmp->setAlignment(Qt::AlignRight);
    dspTmp->setReadOnly(true);

    //expression display
    dspRcd = new QLineEdit;
    dspRcd->setAlignment(Qt::AlignRight);
    dspRcd->setReadOnly(true);

    //display layout.
    QGridLayout* dspLayout = new QGridLayout();
    dspLayout->addWidget(dspRcd,0,0);
    dspLayout->addWidget(dspTmp,1,0);

    //create digit pushbutton.
    QPushButton* digitsBtn[10];
    for(int i = 1; i < 10; ++i){
        digitsBtn[i] = createBtn(QString::number(i), SLOT(keyClicked()));
    }
    digitsBtn[0] = createBtn(QString::number(0), SLOT(keyClicked()));

    //keybord layout.
    QGridLayout* keybordLayout = new QGridLayout;
    for(int i = 1; i < 10; ++i){
        int ral = (i - 1) / 3;
        int col = (i - 1) % 3;
        keybordLayout->addWidget(digitsBtn[i], ral, col);
    }
    keybordLayout->addWidget(digitsBtn[0], 3, 0);

    //other pushbuttons.
    QPushButton* pntBtn = createBtn(".", SLOT(keyClicked()));
    keybordLayout->addWidget(pntBtn, 3, 1);
    QPushButton* eqlBtn = createBtn("=", SLOT(keyClicked()));
    keybordLayout->addWidget(eqlBtn, 3, 2);
    QPushButton* mulBtn = createBtn("*", SLOT(keyClicked()));
    keybordLayout->addWidget(mulBtn, 0, 3);
    QPushButton* divBtn = createBtn("/", SLOT(keyClicked()));
    keybordLayout->addWidget(divBtn, 1, 3);
    QPushButton* addBtn = createBtn("+", SLOT(keyClicked()));
    keybordLayout->addWidget(addBtn, 2, 3 );
    QPushButton* subBtn = createBtn("-", SLOT(keyClicked()));
    keybordLayout->addWidget(subBtn, 3, 3);
    QPushButton* clrBtn = createBtn("C", SLOT(clearClicked()));
    keybordLayout->addWidget(clrBtn, 0, 4);
    QPushButton* lbkBtn = createBtn("(", SLOT(keyClicked()));
    keybordLayout->addWidget(lbkBtn, 1, 4);
    QPushButton* rbkBtn = createBtn(")", SLOT(keyClicked()));
    keybordLayout->addWidget(rbkBtn, 2, 4);


    //mainLayout.
    QGridLayout* mainLayout = new QGridLayout(this);
    mainLayout->addLayout(dspLayout, 0, 0);
    mainLayout->addLayout(keybordLayout, 1, 0);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    //creat a Evaluation object to calculate.
    eval = new Evaluation;
}

calculator::~calculator()
{

}

//commom Pushbutton-Create funtion.
QPushButton *calculator::createBtn(const QString &str, const char *member)
{
    QPushButton *btn = new QPushButton(str);
    connect(btn, SIGNAL(clicked()), this, member);
    return btn;
}

void calculator::keyClicked()
{
     dspTmp->setText(eval->keyClicked(
                         qobject_cast<QPushButton*>(sender())->text()));
     dspRcd->setText(eval->expRecord());
}

void calculator::clearClicked()
{
   dspTmp->setText(eval->clear());
   dspRcd->setText(eval->expRecord());
   eval->changSat(digitStat::Instance());
}

void calculator::eqlClicked()
{

}
