#ifndef REGISTRATIONWIDGET_H
#define REGISTRATIONWIDGET_H

#include "RegistrationWidget_global.h"

#include <QWidget>
#include <QQuickWidget>
#include <QQuickItem>
#include <QQmlContext>
#include <QVBoxLayout>

#include <QtSql>

#include<QObject>

class REGISTRATIONWIDGET_EXPORT RegistrationWidget : public QWidget
{

    Q_OBJECT

public slots:
    void tryLogin(const QString& login, const QString& password){
        qDebug()<<"log and pass " << login<<" "<<password;
    }

signals:
    void isLoginSuccess(bool success);

public:
    RegistrationWidget(/*QSqlDatabase *db,*/QWidget *pwgt = 0);

private:
    //QSqlDatabase* m_db;

};

#endif // REGISTRATIONWIDGET_H
