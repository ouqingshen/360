#include "CMumaChasha.h"

CMumaChasha::CMumaChasha(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::CMumaChashaClass())
{
	ui->setupUi(this);
}

CMumaChasha::~CMumaChasha()
{
	delete ui;
}
