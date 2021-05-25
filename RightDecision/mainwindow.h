#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "registrationwidget.h"
#include "coursewidget.h"
#include "mainpagewidget.h"
#include "userpagewidget.h"

#include <QMainWindow>

#include <QSql>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:

    //opens
    void openLogin();
    void openCourse();
    void openMainPage();
    void openLKPage();


private:

    //windows
    Ui::MainWindow *ui;
    RegistrationWidget *regWidget;
    CourseWidget *courseWidget;
    MainPageWidget *mainPageWidget;
    UserPageWidget *userPageWidget;


    //Layouts
    QHBoxLayout *layout;
    QWidget *w;

    //
    User *m_user;

private:
    void clearLayout(QLayout *layout);


};
#endif // MAINWINDOW_H
