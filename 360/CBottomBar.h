#pragma once
#include <qwidget.h>
#include <qprogressbar.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include "customprogressbar.h"
class CBottomBar :
    public QWidget
{
    Q_OBJECT
public:
    CBottomBar(QWidget* parent=nullptr);
    ~CBottomBar();

    void setupUI();

    QLabel* scoreLabel;
    QLabel* statusLabel;
    QLabel* hintLabel;
    QPushButton* checkButton;
    CustomProgressBar* progressBar;

};

