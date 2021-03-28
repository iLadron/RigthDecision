#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "registrationwidget.h"

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

private:
    Ui::MainWindow *ui;
    RegistrationWidget* regWidget;

    static bool createConnection(){
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setDatabaseName("Diplom");
        db.setUserName("admin");
        db.setHostName("localhost");
        db.setPassword("adminspassword1A!");

        if(db.open()){
            qDebug()<<"Error. Can't open database";
            qDebug()<<db.lastError();
            return false;
        }

        QStringList s = db.tables();

        foreach(QString str, s){
            qDebug()<<"Table " <<str;
        }
        return true;
    }
};
#endif // MAINWINDOW_H
