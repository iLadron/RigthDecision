#include "mainpagewidget.h"

MainPageWidget::MainPageWidget(QWidget *pwgt) : QWidget(pwgt)
{
    m_mainWidget = new QQuickWidget(QUrl("qrc:/forms/MainWindow.qml"));
    m_mainWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

    m_mainLayout = new QVBoxLayout;
    m_mainLayout->addWidget(m_mainWidget);

    m_mainContext = m_mainWidget->rootContext();
    m_mainContext->setContextProperty("Form",this);

    setLayout(m_mainLayout);
}
