#include "customprogressbar.h"
#include <QPainter>

CustomProgressBar::CustomProgressBar(QWidget* parent)
    : QWidget(parent), m_value(0) {}

void CustomProgressBar::setValue(int value) {
    m_value = value;
    update();
}

void CustomProgressBar::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int size = qMin(width(), height());
    QRectF rect(10, 10, size - 20, size - 20);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(220, 220, 220));
    painter.drawEllipse(rect);

    painter.setBrush(QColor(85, 170, 255));
    painter.drawPie(rect, 90 * 16, -m_value * 360 * 16 / 100);

    painter.setPen(Qt::black);
    QFont font = painter.font();
    font.setPointSize(24);
    painter.setFont(font);
    painter.drawText(rect, Qt::AlignCenter, QString::number(m_value) + "分");
}