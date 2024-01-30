#include "PageOne.h"
#include <QLabel>

PageOne::PageOne(QWidget *parent)
    : QWidget{parent}
{
    setStyleSheet("background-color: red;");

    QLabel *pLbl = new QLabel(this);
    pLbl->setText("页面1");
}
