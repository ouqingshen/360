#pragma once

#include <QtWidgets/QWidget>
#include "ui_mainwindow.h"
#include "CFraneLessWidgetBase.h"
#include <qstackedwidget.h>
#include "CBottomBar.h"
#include "CMumaChasha.h"
#include "CTitleBar.h"
#include "CToolBar.h"
#include "CLittleWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindowClass; };
QT_END_NAMESPACE

class mainwindow : public CFraneLessWidgetBase
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

private:
    void initUI();

private:
    Ui::mainwindowClass *ui;
    CTitleBar* titleBar = nullptr;
    CToolBar* toolBar = nullptr;
    CBottomBar* m_pBottomBar = nullptr;
    CMumaChasha* m_pMumaChasha = nullptr;

   QStackedWidget* stackWidgets = nullptr;
   CLittleWidget* m_pLittleWidget = nullptr;
};
