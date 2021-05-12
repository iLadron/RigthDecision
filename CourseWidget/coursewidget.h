#ifndef COURSEWIDGET_H
#define COURSEWIDGET_H

#include "CourseWidget_global.h"


#include <QWidget>
#include <QQuickWidget>
#include <QQuickItem>
#include <QQmlContext>
#include <QVBoxLayout>
#include <QDir>
#include <QObject>



class COURSEWIDGET_EXPORT CourseWidget : public QWidget
{
    Q_OBJECT

public:
    CourseWidget(QWidget *pwdt = 0);
    int lol = 10;

private:

    QQuickWidget *m_courseWidget;
    QVBoxLayout *m_mainLayout;
    QQmlContext *m_courseContext;
};

#endif // COURSEWIDGET_H
