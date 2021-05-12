#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "registrationwidget.h"
#include "coursewidget.h"
#include "mainpagewidget.h"

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
    void openMainPage(int id);


private:

    //windows
    Ui::MainWindow *ui;
    RegistrationWidget *regWidget;
    CourseWidget *courseWidget;
    MainPageWidget *mainPageWidget;


    //Layouts
    QHBoxLayout *layout;
    QWidget *w;

    //
    User *m_user;

};
#endif // MAINWINDOW_H
