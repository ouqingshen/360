#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <qfont.h>


mainwindow::mainwindow(QWidget *parent)
    : CFraneLessWidgetBase(parent)
    , ui(new Ui::mainwindowClass())
{
    initUI();
    ui->setupUi(this);
    this->setFocusPolicy(Qt::StrongFocus);
    QFont font("Arial");
    this->setFont(font);
}

mainwindow::~mainwindow()
{
    delete ui;
}

void mainwindow::initUI()
{   

    titleBar = new CTitleBar;
    toolBar = new CToolBar;
    m_pBottomBar = new CBottomBar();
    m_pMumaChasha = new CMumaChasha();
    stackWidgets = new QStackedWidget();
    m_pLittleWidget = new CLittleWidget();

    this->setFixedSize(900, 700);

    QVBoxLayout* layout_main = new QVBoxLayout(this);
    layout_main->setContentsMargins(0, 0, 0, 0);

    QVBoxLayout* layout_top = new QVBoxLayout;
    layout_top->setContentsMargins(0, 0, 0, 0);
    layout_top->setSpacing(0);

    stackWidgets->addWidget(m_pBottomBar);
    stackWidgets->addWidget(m_pMumaChasha);
    stackWidgets->setCurrentWidget(m_pBottomBar);

    QWidget* widget_center = new QWidget(this);
    QVBoxLayout* layout_center = new QVBoxLayout(widget_center);
    layout_center->setContentsMargins(0, 0, 0, 0);
    layout_center->setSpacing(0);

    layout_center->addWidget(stackWidgets);

    layout_top->addWidget(titleBar);
    layout_top->addWidget(toolBar);

    QWidget* widget_top = new QWidget(this);
    widget_top->setLayout(layout_top);
    widget_top->setStyleSheet("QWidget { background-color: rgb(20, 201, 113) }");
    widget_top->setContentsMargins(0, 0, 0, 0);

    layout_main->addWidget(widget_top);
    layout_main->addStretch();
    layout_main->addWidget(widget_center);
    layout_main->addStretch();
    layout_main->addWidget(m_pLittleWidget);

    toolBar->setStyleSheet("QWidget { background-color: rgb(20, 201, 113) }");

    this->setLayout(layout_main);
    this->setContentsMargins(0, 0, 0, 0);

    connect(titleBar, &CTitleBar::sig_close, this, [&] {
        qDebug() << "sig_close received";
        this->close();
        });

    connect(toolBar, &CToolBar::sig_MyPC, this, [&] {
        qDebug() << "sig_MyPC received";
        stackWidgets->setCurrentWidget(m_pBottomBar);
        });

    connect(toolBar, &CToolBar::sig_THK, this, [&] {
        qDebug() << "sig_THK received";
        stackWidgets->setCurrentWidget(m_pMumaChasha);
        });

}
