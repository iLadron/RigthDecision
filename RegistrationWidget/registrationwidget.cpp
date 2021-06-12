#include "registrationwidget.h"


RegistrationWidget::RegistrationWidget(QWidget *pwgt) : QWidget(pwgt)
{
    //Creating LoginForm
    m_logWidget = new QQuickWidget(QUrl("qrc:/forms/forms/MainLogReg.qml"));
    m_logWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

    m_mainLayout = new QVBoxLayout;
    m_mainLayout->addWidget(m_logWidget);

    m_logContext = m_logWidget->rootContext();
    m_logContext->setContextProperty("Form",this);

    setLayout(m_mainLayout);
}


QString RegistrationWidget::registerUser(const QString name,const QString surname,const QString login,
                                         const QString email,const QString password,const QString avatar)
{
    User newUser;
    newUser.name = name;
    newUser.surname = surname;
    newUser.login = login;
    newUser.email = email;
    newUser.password = password;
    newUser.avatar = avatar;
    return Database::GetInstance()->registerUser(newUser);
}

QString RegistrationWidget::loginUser(const QString login, const QString password)
{
    User newUser;
    newUser.login = login;
    newUser.password = password;
    QString temp =  Database::GetInstance()->loginUser(newUser);
    bool ok;
    temp.toInt(&ok);
    if(ok){
        emit loginSuccess();
        return "success";
    }
    return temp;
}
