#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>


mainwindow::mainwindow(QWidget *parent)
    : CFraneLessWidgetBase(parent)
    , ui(new Ui::mainwindowClass())
{
    initUI();
    ui->setupUi(this);
    this->setFocusPolicy(Qt::StrongFocus);
    setAttribute(Qt::WA_Hover);
}

mainwindow::~mainwindow()
{
    delete ui;
}

void mainwindow::initUI()
{   
    m_pTopWidget = new CTopWidget();
    m_pBottomBar = new CBottomBar();
    m_pMumaChasha = new CMumaChasha();

    stackWidgets = new QStackedWidget(this);
   // stackWidgets->addWidget(m_pBottomBar);
    stackWidgets->addWidget(m_pMumaChasha);

    
    stackWidgets->setCurrentWidget(m_pBottomBar);

    this->setFixedSize(900,700);




    QVBoxLayout* layout_main = new QVBoxLayout(this);

    layout_main->setContentsMargins(0,0,0,0);
    layout_main->addWidget(m_pTopWidget);
    layout_main->addStretch();
    layout_main->addWidget(m_pBottomBar);
    layout_main->addWidget(stackWidgets);
    layout_main->addStretch();



    
  
    // 设置this的布局为layout_main  
    this->setLayout(layout_main);
    






    connect(m_pTopWidget, &CTopWidget::sig_close, this, [&] {this->close(); });
    connect(m_pTopWidget, &CTopWidget::sig_MyPC, this, [&] {stackWidgets->setCurrentWidget(m_pBottomBar); });
    connect(m_pTopWidget, &CTopWidget::sig_THK, this, [&] {stackWidgets->setCurrentWidget(m_pBottomBar); });
}
