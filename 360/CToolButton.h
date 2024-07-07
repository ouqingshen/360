#pragma once
#include <QToolButton>
#include <QEvent>
class CToolButton :
	public QToolButton
{
	Q_OBJECT

public:
	CToolButton(QString text, QString icon, QWidget* parent=nullptr);
	~CToolButton();



signals:
	void sig_clicked();

private:
	QString m_text;
	QString m_icon;
};
