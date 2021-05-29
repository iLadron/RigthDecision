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

#include "test.h"



class COURSEWIDGET_EXPORT CourseWidget : public QWidget
{
    Q_OBJECT

public:
    CourseWidget(QWidget *pwdt = 0);

signals:

    void openLK();

private:

    QQuickWidget *m_courseWidget;
    QVBoxLayout *m_mainLayout;
    QQmlContext *m_courseContext;

    std::vector<Test> m_tests;


};

#endif // COURSEWIDGET_H
