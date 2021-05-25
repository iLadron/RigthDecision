#include "userpagewidget.h"

UserPageWidget::UserPageWidget(QWidget * pwdt) : QWidget(pwdt)
{
    m_lkWidget = new QQuickWidget(QUrl("qrc:/forms/UserPageFrom.qml"));
    m_lkWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

    m_mainLayout = new QVBoxLayout;
    m_mainLayout->addWidget(m_lkWidget);

    m_lkContext = m_lkWidget->rootContext();
    m_lkContext->setContextProperty("Form",this);

    setLayout(m_mainLayout);
}
