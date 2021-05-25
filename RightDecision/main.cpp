#include "mainwindow.h"

#include <QApplication>
#include "registrationwidget.h"
#include <QIcon>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.setWindowTitle("Right decision");
    w.setWindowIcon(QIcon("qrc:/rcs/logo.png"));
    w.show();
    //connect database;
    Database::GetInstance();


    return a.exec();
}
