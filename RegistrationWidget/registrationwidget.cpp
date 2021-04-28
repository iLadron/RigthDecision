#include "registrationwidget.h"


QString RegistrationWidget::registerUser(const QString name,const QString surname,const QString login,
                                         const QString email,const QString password,const QString avatar)
{
    User newUser = {name, surname, login, email, password, avatar};
    Database::GetInstance()->registerUser(newUser);

    return "true";
}

void RegistrationWidget::openRegForm(){
    m_mainLayout->replaceWidget(m_logWidget,m_regWidget);
}

void RegistrationWidget::openLogForm()
{
    m_mainLayout->replaceWidget(m_regWidget,m_logWidget);
}

RegistrationWidget::RegistrationWidget(/*QSqlDatabase *db,*/ QWidget *pwgt) : QWidget(pwgt)
{
    //Creating LoginForm
    m_logWidget = new QQuickWidget(QUrl("qrc:/forms/forms/LoginForm.qml"));
    m_logWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

    m_mainLayout = new QVBoxLayout;
    m_mainLayout->addWidget(m_logWidget);


    m_logContext = m_logWidget->rootContext();
    m_logContext->setContextProperty("Form",this);

    setLayout(m_mainLayout);


    //Creating RegistrationForm
    m_regWidget = new QQuickWidget(QUrl("qrc:/forms/forms/RegistrationForm.qml"));
    m_regWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

    m_regContext = m_regWidget->rootContext();
    m_regContext->setContextProperty("Form",this);

}
