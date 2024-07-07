#include "CTitleBar.h"
#include <QHBoxLayout>
#include <qt_windows.h>
CTitleBar::CTitleBar(QWidget* p)
{
	initUI();
}

CTitleBar::~CTitleBar()
{
}

void CTitleBar::initUI()
{
	this->setContentsMargins(0,0,0,0);
	this->setAttribute(Qt::WA_StyledBackground);

	this->setFixedHeight(32 + 5 * 2);
	this->setStyleSheet("background-color:rgb(20, 201, 113)");
	m_pLogo = new QLabel(this);

	QPixmap pixmap(":/mainwindow/resources/logo.png");
	pixmap = pixmap.scaled(60, 60, Qt::KeepAspectRatio, Qt::SmoothTransformation); // 保持比例缩放  
	m_pLogo->setPixmap(pixmap);
	m_pLogo->setStyleSheet(
		"QLabel {"
		"    background-image: url(:/mainwindow/resources/logo.png);"
		"    background-repeat: no-repeat;" 
		"    background-position: center;" 
		"}"
		"QLabel:hover {"
		"    border: 2px solid rgb(255, 255, 255);" 
		"}"
	);


	m_pTitleTextLabel = new QLabel(this);
	m_pTitleTextLabel->setAttribute(Qt::WA_TranslucentBackground);
	m_pTitleTextLabel->setText("360安全卫士");
	m_pTitleTextLabel->setStyleSheet("QLabel { color: white; }");	m_pTitleTextLabel->setFixedWidth(120);

	m_pMinBtn = new QPushButton(this);
	m_pMinBtn->setFixedSize(32, 32);
	m_pMinBtn->setStyleSheet("QPushButton{background-image:url(:/mainwindow/resources/min.svg);border:none;background-repeat:no-repeat;background-position: top;background-color: transparent}" \
		"QPushButton:hover{background-image:url(:/mainwindow/resources/min_hover.svg);border:none;background-repeat:no-repeat;background-position: top}");
	m_pMinBtn->setAttribute(Qt::WA_TranslucentBackground);

	m_pMaxBtn = new QPushButton(this);
	m_pMaxBtn->setFixedSize(32, 32);
	m_pMaxBtn->setStyleSheet("QPushButton{background-image:url(:/mainwindow/resources/max.svg);border:none;background-repeat:no-repeat;background-position: center;background-color: transparent}");
	m_pMaxBtn->setAttribute(Qt::WA_TranslucentBackground);

	m_pCloseBtn = new QPushButton(this);
	m_pCloseBtn->setFixedSize(32, 32);
	m_pCloseBtn->setStyleSheet("QPushButton{background-image:url(:/mainwindow/resources/close.svg);border:none;background-repeat:no-repeat;background-position: center;background-color: transparent}" \
		"QPushButton:hover{background-image:url(:/mainwindow/resources/close_hover.svg);border:none;background-repeat:no-repeat;background-position: center}");
	m_pCloseBtn->setAttribute(Qt::WA_TranslucentBackground);

	QHBoxLayout* pHlay = new QHBoxLayout(this);
	pHlay->addWidget(m_pLogo);
	pHlay->addWidget(m_pTitleTextLabel);
	pHlay->addStretch();
	pHlay->addWidget(m_pMinBtn);
	pHlay->addWidget(m_pMaxBtn);
	pHlay->addWidget(m_pCloseBtn);

	//pHlay->setContentsMargins(5, 5, 5, 5);
	pHlay->setContentsMargins(0,0,0,0);


	connect(m_pMinBtn, &QPushButton::clicked, this, &CTitleBar::onClicked);
	connect(m_pMaxBtn, &QPushButton::clicked, this, &CTitleBar::onClicked);
	connect(m_pCloseBtn, &QPushButton::clicked, this, &CTitleBar::onClicked);
}

void CTitleBar::mousePressEvent(QMouseEvent* event)
{
	if (ReleaseCapture())
	{
		QWidget* pWindow = this->window();
		if (pWindow->isTopLevel())
		{
			SendMessage(HWND(pWindow->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
		}
	}
}
void CTitleBar::mouseDoubleClickEvent(QMouseEvent* event)
{
	m_pMaxBtn->click();
}
void CTitleBar::onClicked() {
	QPushButton* pButton = qobject_cast<QPushButton*>(sender());
	QWidget* pWindow = this->window();
	if (pButton == m_pMaxBtn)
	{
		if (pWindow->isMaximized())
		{
			pWindow->showNormal();
		}
		else {
			pWindow->showMaximized();
		}
	}
	else if (pButton == m_pMinBtn)
	{
		pWindow->showMinimized();
	}
	else if (pButton == m_pCloseBtn)
	{
		emit sig_close();
	}
}