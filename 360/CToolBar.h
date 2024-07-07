#pragma once
#include <qwidget.h>
#include <CToolButton.h>
#include <QButtonGroup>
class CToolBar :
    public QWidget
{
    Q_OBJECT
public:
    CToolBar(QWidget * parent=nullptr);
    ~CToolBar();
signals:
    void sig_MyPC();
    void sig_THK();

public:
    void initUI();

private:
    CToolButton*  m_pMyPC =              nullptr;
    CToolButton*  m_pTHK=                nullptr;
    CToolButton*  m_pPCC=                nullptr;
    CToolButton*  m_pSystemFix=          nullptr;
    CToolButton*  m_pOA=                 nullptr;
    CToolButton*  m_pFunction=           nullptr;
    CToolButton*  m_pSolftWareManager=   nullptr;

    QButtonGroup* buttonGroup = nullptr;
};

