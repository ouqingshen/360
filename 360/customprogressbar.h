#ifndef CUSTOMPROGRESSBAR_H
#define CUSTOMPROGRESSBAR_H

#include <QWidget>

class CustomProgressBar : public QWidget {
    Q_OBJECT

public:
    CustomProgressBar(QWidget* parent = nullptr);
    void setValue(int value);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    int m_value;
};

#endif
