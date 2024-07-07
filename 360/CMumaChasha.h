#pragma once

#include <QWidget>
#include "ui_CMumaChasha.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CMumaChashaClass; };
QT_END_NAMESPACE

class CMumaChasha : public QWidget
{
	Q_OBJECT

public:
	CMumaChasha(QWidget *parent = nullptr);
	~CMumaChasha();

private:
	Ui::CMumaChashaClass *ui;
};
