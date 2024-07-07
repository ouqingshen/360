#pragma once
#include <qwidget.h>
#include "CTitleBar.h"
#include "CToolBar.h"
class CTopWidget :
    public QWidget
{
    Q_OBJECT

public:
    CTopWidget(QWidget* parent=nullptr);
    ~CTopWidget();

    void initUI();

signals:
    void sig_close();
    void sig_MyPC();
   void sig_THK();

private:
    CTitleBar* m_pTitleBar = nullptr;
    CToolBar* m_pToolBar = nullptr;
};

