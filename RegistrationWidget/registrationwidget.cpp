#include "registrationwidget.h"


RegistrationWidget::RegistrationWidget(/*QSqlDatabase *db,*/ QWidget *pwgt) : QWidget(pwgt)
{
    //m_db = db;
    QQuickWidget* pv = new QQuickWidget(QUrl("qrc:/forms/forms/RegistrationForm.qml"));
    pv->setResizeMode(QQuickWidget::SizeRootObjectToView);

    QVBoxLayout* pvbx = new QVBoxLayout;
    pvbx->addWidget(pv);
    setLayout(pvbx);

    QQmlContext *pcon = pv->rootContext();
    pcon->setContextProperty("registrationForm",this);


}

