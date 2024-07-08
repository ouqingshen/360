#include "CTopWidget.h"
#include <QVBoxLayout>

CTopWidget::CTopWidget(QWidget* parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);
	setAttribute(Qt::WA_Hover);
	initUI();
}

CTopWidget::~CTopWidget()
{
}

void CTopWidget::initUI()
{
	this->setStyleSheet("QWidget{background-color:rgb(20, 201, 113)}");
	this->setStyleSheet("QWidget{background-color:black}");
	//this->setStyleSheet("QWidget { background-color: rgba(0, 0, 0, 0); }");
	this->setContentsMargins(0,0,0,0);

	QVBoxLayout* topWidgetLayout = new QVBoxLayout(this);
	topWidgetLayout->setContentsMargins(0,0,0,0);
	topWidgetLayout->setSpacing(0);

	m_pTitleBar = new CTitleBar();
	m_pToolBar = new CToolBar();


	topWidgetLayout->addWidget(m_pTitleBar);
	topWidgetLayout->addWidget(m_pToolBar);

	this->setLayout(topWidgetLayout);





	connect(m_pTitleBar, &CTitleBar::sig_close, this, [=] {emit sig_close(); });
	connect(m_pToolBar, &CToolBar::sig_MyPC, this,[=] {emit sig_MyPC(); });
	connect(m_pToolBar, &CToolBar::sig_THK, this,[=] {emit sig_THK(); });
}
