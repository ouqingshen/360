#include "CToolButton.h"
#include <qpushbutton.h>

CToolButton::CToolButton(QString text, QString icon, QWidget* parent)
    : QToolButton(parent),
    m_text(text),
    m_icon(icon)
{
    connect(this, &QPushButton::clicked, this, &CToolButton::onButtonClicked);
    this->setFixedSize(100, 80);
    this->setIconSize(QSize(45, 45));
    this->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    this->setStyleSheet("QToolButton{border:none;font-size:14px;padding-top:3px;padding-bottom:3px;color:white}"
        "QToolButton:hover{background: qlineargradient(spread: pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgba(105, 105, 105, 128), stop:1 rgba(255, 255, 255, 0))}"
        "QToolButton:checked{ background: qlineargradient(spread: pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgba(105, 105, 105, 128), stop:1 rgba(255, 255, 255, 0))}"
    );
    this->setText(m_text);
    this->setIcon(QIcon(m_icon));
    this->setCheckable(true);
}

CToolButton::~CToolButton()
{

}