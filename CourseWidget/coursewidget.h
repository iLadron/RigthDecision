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

#include "coursemodel.h"
#include "courseelement.h"
#include "test.h"
#include "theorymodel.h"



class COURSEWIDGET_EXPORT CourseWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int windowState READ windowState WRITE setWindowState NOTIFY windowStateChanged)


public:
    CourseWidget(QWidget *pwdt = 0);

    int windowState() const;

public slots:
   // void saveTest();
    void setCourseModel(CourseModel*);
    void openElement(int index);
    void setWindowState(int windowState);

signals:

    void openLK();


    void windowStateChanged(int windowState);

private:

    QQuickWidget *m_courseWidget;
    QVBoxLayout *m_mainLayout;
    QQmlContext *m_courseContext;


    CourseModel *m_courseModel = nullptr;

    //std::vector<CourseElement> m_courseElements;
    //Test temp_test;

    int m_windowState = 0;
};

#endif // COURSEWIDGET_H
