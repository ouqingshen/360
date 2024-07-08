#include "CLittleWidget.h"
#include <QLabel>
#include <QHBoxLayout>
CLittleWidget::CLittleWidget(QWidget* parent)
{
    // 创建水平布局
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->setSpacing(20); // 设置控件之间的间距
    mainLayout->setContentsMargins(10, 10, 10, 10); // 设置布局的边距

    // 安全防护中心
    QLabel* protectionCenterIcon = new QLabel(this);
    QPixmap protectionPixmap(":/mainwindow/resources/THK.svg");
    protectionCenterIcon->setPixmap(protectionPixmap);
    QLabel* protectionCenterText = new QLabel("安全防护中心\n1235天实时守护", this);
    QVBoxLayout* protectionCenterLayout = new QVBoxLayout();
    protectionCenterLayout->addWidget(protectionCenterIcon);
    protectionCenterLayout->addWidget(protectionCenterText);

    QWidget* protectionCenterWidget = new QWidget(this);
    protectionCenterWidget->setLayout(protectionCenterLayout);

    // 360安全大脑
    QLabel* securityBrainIcon = new QLabel(this);
    QPixmap brainPixmap(":/mainwindow/resources/THK.svg");
    securityBrainIcon->setPixmap(brainPixmap);
    QLabel* securityBrainText = new QLabel("360安全大脑\n5个异常行为", this);
    QVBoxLayout* securityBrainLayout = new QVBoxLayout();
    securityBrainLayout->addWidget(securityBrainIcon);
    securityBrainLayout->addWidget(securityBrainText);

    QWidget* securityBrainWidget = new QWidget(this);
    securityBrainWidget->setLayout(securityBrainLayout);

    // 反欺诈服务
    QLabel* antiFraudIcon = new QLabel(this);
    QPixmap fraudPixmap(":/mainwindow/resources/THK.svg");
    antiFraudIcon->setPixmap(fraudPixmap);
    QLabel* antiFraudText = new QLabel("反欺诈服务", this);
    QVBoxLayout* antiFraudLayout = new QVBoxLayout();
    antiFraudLayout->addWidget(antiFraudIcon);
    antiFraudLayout->addWidget(antiFraudText);

    QWidget* antiFraudWidget = new QWidget(this);
    antiFraudWidget->setLayout(antiFraudLayout);

    // 弹窗过滤
    QLabel* popupFilterIcon = new QLabel(this);
    QPixmap popupPixmap(":/mainwindow/resources/THK.svg");
    popupFilterIcon->setPixmap(popupPixmap);
    QLabel* popupFilterText = new QLabel("弹窗过滤", this);
    QVBoxLayout* popupFilterLayout = new QVBoxLayout();
    popupFilterLayout->addWidget(popupFilterIcon);
    popupFilterLayout->addWidget(popupFilterText);

    QWidget* popupFilterWidget = new QWidget(this);
    popupFilterWidget->setLayout(popupFilterLayout);

    // 电脑助手
    QLabel* pcAssistantIcon = new QLabel(this);
    QPixmap assistantPixmap(":/mainwindow/resources/THK.svg");
    pcAssistantIcon->setPixmap(assistantPixmap);
    QLabel* pcAssistantText = new QLabel("电脑助手", this);
    QVBoxLayout* pcAssistantLayout = new QVBoxLayout();
    pcAssistantLayout->addWidget(pcAssistantIcon);
    pcAssistantLayout->addWidget(pcAssistantText);

    QWidget* pcAssistantWidget = new QWidget(this);
    pcAssistantWidget->setLayout(pcAssistantLayout);

    // 驱动大师
    QLabel* driverMasterIcon = new QLabel(this);
    QPixmap driverPixmap(":/mainwindow/resources/THK.svg");
    driverMasterIcon->setPixmap(driverPixmap);
    QLabel* driverMasterText = new QLabel("驱动大师", this);
    QVBoxLayout* driverMasterLayout = new QVBoxLayout();
    driverMasterLayout->addWidget(driverMasterIcon);
    driverMasterLayout->addWidget(driverMasterText);

    QWidget* driverMasterWidget = new QWidget(this);
    driverMasterWidget->setLayout(driverMasterLayout);

    // 搜索更多
    QLabel* searchMoreIcon = new QLabel(this);
    QPixmap searchPixmap(":/mainwindow/resources/THK.svg");
    searchMoreIcon->setPixmap(searchPixmap);
    QLabel* searchMoreText = new QLabel("搜索更多", this);
    QVBoxLayout* searchMoreLayout = new QVBoxLayout();
    searchMoreLayout->addWidget(searchMoreIcon);
    searchMoreLayout->addWidget(searchMoreText);

    QWidget* searchMoreWidget = new QWidget(this);
    searchMoreWidget->setLayout(searchMoreLayout);

    // 将所有小部件添加到主布局
    mainLayout->addWidget(protectionCenterWidget);
    mainLayout->addWidget(securityBrainWidget);
    mainLayout->addStretch();
    mainLayout->addWidget(antiFraudWidget);
    mainLayout->addWidget(popupFilterWidget);
    mainLayout->addWidget(pcAssistantWidget);
    mainLayout->addWidget(driverMasterWidget);
    mainLayout->addWidget(searchMoreWidget);

    this->setLayout(mainLayout);
}

CLittleWidget::~CLittleWidget()
{
}
