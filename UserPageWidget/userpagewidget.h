#ifndef USERPAGEWIDGET_H
#define USERPAGEWIDGET_H

#include "UserPageWidget_global.h"

#include <QWidget>
#include <QQuickWidget>
#include <QQuickItem>
#include <QQmlContext>
#include <QVBoxLayout>

#include <QVector>
#include <vector>
#include <QtSql>
#include <QObject>


#include "coursemodel.h"
#include "database.h"

class USERPAGEWIDGET_EXPORT UserPageWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QStringList user READ user WRITE setUser NOTIFY userChanged)


public:
    UserPageWidget(QWidget *pwgt = 0);

    QStringList user() const;

public slots:
    void setUser(QStringList user);
    void refreshCourses();
    QStringList getInProgressCourseData();
    QStringList getCreatedCourseData();
    void openCourse(int id);


signals:
    void openMainWindow();
    void openCreateCourseWidget();
    void logout();
    void openCourse(CourseModel* model);


    void userChanged(QStringList user);

private:

    QQuickWidget *m_lkWidget;
    QVBoxLayout *m_mainLayout;
    QQmlContext *m_lkContext;
    QStringList m_user;

    std::vector<CourseModel> m_createdCourses;
    std::vector<CourseModel> m_inProgressCourses;


};



#endif // USERPAGEWIDGET_H
