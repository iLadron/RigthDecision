#include "registrationwidget.h"

RegistrationWidget::RegistrationWidget(QWidget* pwgt) : QWidget(pwgt)
{
    QQuickWidget* pv = new QQuickWidget(QUrl("qrc:/forms/forms/RegistrationForm.qml"));
    pv->setResizeMode(QQuickWidget::SizeRootObjectToView);
    QVBoxLayout* pvbx = new QVBoxLayout;
    pvbx->addWidget(pv);
    setLayout(pvbx);
}
