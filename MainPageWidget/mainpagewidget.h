#ifndef MAINPAGEWIDGET_H
#define MAINPAGEWIDGET_H

#include "MainPageWidget_global.h"

#include <QWidget>
#include <QQuickWidget>
#include <QQuickItem>
#include <QQmlContext>
#include <QVBoxLayout>

#include <QtSql>
#include <QObject>

class MAINPAGEWIDGET_EXPORT MainPageWidget : public QWidget
{
    Q_OBJECT

public:
    MainPageWidget(QWidget *pwgt = 0);

signals:
    void openLK();

private:
    QQuickWidget *m_mainWidget;
    QVBoxLayout *m_mainLayout;
    QQmlContext *m_mainContext;
};

#endif // MAINPAGEWIDGET_H
