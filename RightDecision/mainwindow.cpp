#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    regWidget = new RegistrationWidget();

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(regWidget);
    QWidget *w = new QWidget;
    w->setLayout(layout);
    setCentralWidget(w);

}

MainWindow::~MainWindow()
{
    delete ui;
}

