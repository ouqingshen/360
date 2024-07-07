#include "CBottomBar.h"
#include <QVBoxLayout>


CBottomBar::CBottomBar(QWidget* parent):QWidget(parent),
scoreLabel(new QLabel("96分")),
statusLabel(new QLabel("已很久未体检，请立即体检")),
hintLabel(new QLabel("今日体检可进行5次")),
checkButton(new QPushButton("立即体检")),
progressBar(new CustomProgressBar(this))
{
    setupUI();
}

CBottomBar::~CBottomBar()
{

}


void CBottomBar::setupUI()
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addStretch();
    progressBar->setValue(96);
    progressBar->setFixedSize(150, 150);

    QFont scoreFont = scoreLabel->font();
    scoreFont.setPointSize(24);
    scoreLabel->setFont(scoreFont);

    QVBoxLayout* progressLayout = new QVBoxLayout();
    progressLayout->addWidget(progressBar, 0, Qt::AlignCenter);

    mainLayout->addLayout(progressLayout);
    mainLayout->addWidget(statusLabel, 0, Qt::AlignCenter);
    mainLayout->addWidget(hintLabel, 0, Qt::AlignCenter);
    mainLayout->addWidget(checkButton, 0, Qt::AlignCenter);
    this->setLayout(mainLayout);


    checkButton->setFixedSize(160,60);
    checkButton->setStyleSheet(R"(
        QPushButton {
            background-color: #4CAF50;
            color: white;
            border: none;
            padding: 10px 20px;
            text-align: center;
            text-decoration: none;
            display: inline-block;
            font-size: 16px;
            margin: 4px 2px;
            transition-duration: 0.4s;
            cursor: pointer;
            border-radius: 10px;
        }
        QPushButton:hover {
            background-color: white;
            color: black;
            border: 2px solid #4CAF50;
        }
    )");

    connect(checkButton, &QPushButton::clicked, this, [this]() {
        int newScore = qrand() % 101;
        scoreLabel->setText(QString::number(newScore) + "分");
        progressBar->setValue(newScore);
        });
}
