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

QStringList UserPageWidget::user() const
{
    return m_user;
}

void UserPageWidget::setUser(QStringList user)
{

    User* lUser = Database::getLoginedUser();

    m_user.clear();
    m_user.push_back(lUser->name);
    m_user.push_back(lUser->surname);
    m_user.push_back(lUser->login);
    m_user.push_back(lUser->email);

    emit userChanged(m_user);
}
