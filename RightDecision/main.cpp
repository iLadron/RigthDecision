#include "mainwindow.h"

#include <QApplication>

#include "registrationwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;
    w.setWindowTitle("Right decision");
    w.show();
    //connect database;
    Database::GetInstance();

    return a.exec();
}
