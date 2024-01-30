#ifndef STACKWIDGET_H
#define STACKWIDGET_H

#include <QWidget>

class QPushButton;
class PageOne;
class PageTwo;
class QStackedWidget;

class StackWidget : public QWidget
{
    Q_OBJECT

public:
    StackWidget(QWidget *parent = nullptr);
    ~StackWidget();

private:
    void initUi();
    void sigAndslot();

private slots:
    void slotSwitchPage();

private:
    QPushButton     *m_pBtnOne;
    QPushButton     *m_pBtnTwo;
    PageOne         *m_pPageOne;
    PageTwo         *m_pPageTwo;
    QStackedWidget  *m_pStackedWgt;
};
#endif // STACKWIDGET_H
