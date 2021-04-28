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

public slots:
    QString registerUser(const QString name,const QString surname,const QString login,
                         const QString email,const QString password,const QString avatar);
    void openRegForm();
    void openLogForm();


signals:
    void isLoginSuccess(bool success);

public:
    RegistrationWidget(/*QSqlDatabase *db,*/QWidget *pwgt = 0);

private:
    //QSqlDatabase* m_db;

    QQuickWidget *m_logWidget, *m_regWidget;
    QVBoxLayout *m_mainLayout;
    QQmlContext *m_logContext, *m_regContext;


};

#endif // REGISTRATIONWIDGET_H
