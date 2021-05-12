#ifndef COURSE_H
#define COURSE_H

#include <QWidget>
#include <QQuickWidget>
#include <QQuickItem>
#include <QQmlContext>
#include <QVBoxLayout>
#include <QObject>

#include "Course_global.h"


class COURSE_EXPORT Course  : public QWidget
{
    Q_OBJECT

    //Q_PROPERTY(int lol READ lol WRITE setLol NOTIFY lolChanged)
public:

    Course(QWidget *pwgt = 0);


public slots:


signals:

private:
    QQuickWidget *m_courseWidget;
    QVBoxLayout *m_mainLayout;
    QQmlContext *m_courseContext;
    int m_lol;
};

#endif // COURSE_H
