#ifndef REGISTRATIONWIDGET_H
#define REGISTRATIONWIDGET_H

#include "RegistrationWidget_global.h"

#include <QWidget>
#include <QQuickWidget>
#include <QQuickItem>
#include <QQmlContext>
#include <QVBoxLayout>

#include <QtSql>
#include <QObject>

#include "database.h"

class REGISTRATIONWIDGET_EXPORT RegistrationWidget : public QWidget
{
    Q_OBJECT

public:
    RegistrationWidget(QWidget *pwgt = 0);

public slots:
    QString registerUser(const QString name,const QString surname,const QString login,
                         const QString email,const QString password);
    QString loginUser(const QString login, const QString password);


signals:
    void loginSuccess();

private:

    QQuickWidget *m_logWidget;
    QVBoxLayout *m_mainLayout;
    QQmlContext *m_logContext;
};

#endif // REGISTRATIONWIDGET_H
