#ifndef USERPAGEWIDGET_H
#define USERPAGEWIDGET_H

#include "UserPageWidget_global.h"

#include <QWidget>
#include <QQuickWidget>
#include <QQuickItem>
#include <QQmlContext>
#include <QVBoxLayout>

#include <QtSql>
#include <QObject>

class USERPAGEWIDGET_EXPORT UserPageWidget : public QWidget
{
    Q_OBJECT

public:
    UserPageWidget(QWidget *pwgt = 0);

signals:
    void openMainWindow();

private:

    QQuickWidget *m_lkWidget;
    QVBoxLayout *m_mainLayout;
    QQmlContext *m_lkContext;
};

#endif // USERPAGEWIDGET_H
