#pragma once

#include <QtWidgets/QWidget>
#include "ui_mainwindow.h"
#include "CFraneLessWidgetBase.h"
#include <qstackedwidget.h>
#include "CTopWidget.h"
#include "CBottomBar.h"
#include "CMumaChasha.h"

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
    CTopWidget* m_pTopWidget = nullptr;
    CBottomBar* m_pBottomBar = nullptr;
    CMumaChasha* m_pMumaChasha = nullptr;

   QStackedWidget* stackWidgets = nullptr;


};
