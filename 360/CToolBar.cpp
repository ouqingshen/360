#include "CToolBar.h"
#include <QHBoxLayout>

CToolBar::CToolBar(QWidget* parent) :buttonGroup(new QButtonGroup(this))
{

	initUI();
}

CToolBar::~CToolBar()
{

}

void CToolBar::initUI()
{		
	this->setContentsMargins(0,0,0,0);
	this->setMouseTracking(true);
	

	    m_pMyPC = new CToolButton("我的电脑", ":/toolbutton/resources/diannaotijian.svg", this);
	    m_pTHK = new CToolButton("木马查杀", ":/mainwindow/resources/THK.svg", this);
	    m_pPCC = new CToolButton("电脑清理", ":/toolbutton/resources/diannaotijian.svg", this);
	    m_pSystemFix = new CToolButton("系统修复", ":/toolbutton/resources/diannaotijian.svg", this);
	    m_pOA = new CToolButton("优化加速", ":/toolbutton/resources/diannaotijian.svg", this);
	    m_pFunction = new CToolButton("功能大全", ":/toolbutton/resources/diannaotijian.svg", this);
	    m_pSolftWareManager = new CToolButton("软件管家", ":/toolbutton/resources/diannaotijian.svg", this);

		m_pMyPC->setChecked(true);

		buttonGroup->addButton(m_pMyPC);
		buttonGroup->addButton(m_pTHK);
		buttonGroup->addButton(m_pPCC);
		buttonGroup->addButton(m_pSystemFix);
		buttonGroup->addButton(m_pOA);
		buttonGroup->addButton(m_pFunction);
		buttonGroup->addButton(m_pSolftWareManager);

	

		buttonGroup->setExclusive(true);

		QHBoxLayout* toolLayout = new QHBoxLayout(this);
		toolLayout->setContentsMargins(0,0,0,0);
		toolLayout->addWidget(m_pMyPC);
		toolLayout->addWidget(m_pTHK);
		toolLayout->addWidget(m_pPCC);
		toolLayout->addWidget(m_pSystemFix);	
		toolLayout->addWidget(m_pOA);
		toolLayout->addWidget(m_pFunction);
		toolLayout->addWidget(m_pSolftWareManager);

		this->setStyleSheet("QWidget { background-color: rgb(20, 201, 133) }");
		this->setLayout(toolLayout);


		connect(m_pMyPC, &CToolButton::sig_clicked, this, [=] {emit sig_MyPC(); });
		connect(m_pTHK, &CToolButton::sig_clicked, this, [=] {emit sig_THK(); });
}
