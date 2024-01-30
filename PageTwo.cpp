#include "PageTwo.h"
#include <QLabel>

PageTwo::PageTwo(QWidget *parent)
    : QWidget{parent}
{
    setStyleSheet("background-color: Green;");

    QLabel *pLbl = new QLabel(this);
    pLbl->setText("页面2");
}
