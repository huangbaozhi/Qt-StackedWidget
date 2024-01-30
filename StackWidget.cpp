#include "StackWidget.h"
#include "PageOne.h"
#include "PageTwo.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>

StackWidget::StackWidget(QWidget *parent)
    : QWidget(parent)
{
    initUi();
    sigAndslot();
}

StackWidget::~StackWidget()
{
}

void StackWidget::initUi()
{
    QVBoxLayout *pVMainLyt = new QVBoxLayout(this);

    QHBoxLayout *pHBtnLyt = new QHBoxLayout(this);
    m_pBtnOne = new QPushButton(this);
    m_pBtnOne->setText("页面1");
    m_pBtnTwo = new QPushButton(this);
    m_pBtnTwo->setText("页面2");
    pHBtnLyt->addWidget(m_pBtnOne);
    pHBtnLyt->addWidget(m_pBtnTwo);

    m_pPageOne = new PageOne(this);
    m_pPageTwo = new PageTwo(this);

    m_pStackedWgt = new QStackedWidget(this);
    m_pStackedWgt->addWidget(m_pPageOne);
    m_pStackedWgt->addWidget(m_pPageTwo);

    pVMainLyt->addLayout(pHBtnLyt);
    pVMainLyt->addWidget(m_pStackedWgt);
}

void StackWidget::sigAndslot()
{
    connect(m_pBtnOne, &QPushButton::clicked, this, &StackWidget::slotSwitchPage);
    connect(m_pBtnTwo, &QPushButton::clicked, this, &StackWidget::slotSwitchPage);
}

void StackWidget::slotSwitchPage()
{
    QPushButton* pBtn = dynamic_cast<QPushButton*>(QObject::sender());

    if(!pBtn)
    {
        return;
    }

    if (pBtn == m_pBtnOne && m_pPageOne)
    {
        m_pStackedWgt->setCurrentWidget(m_pPageOne);
    }
    else if (pBtn == m_pBtnTwo && m_pPageTwo)
    {
        m_pStackedWgt->setCurrentWidget(m_pPageTwo);
    }
}

