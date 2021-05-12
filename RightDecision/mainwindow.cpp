#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    regWidget = new RegistrationWidget();
    courseWidget = new CourseWidget();
    mainPageWidget = new MainPageWidget();

    connect(regWidget,SIGNAL(loginSuccess(int)), this, SLOT(openMainPage(int)));

    layout = new QHBoxLayout();
    layout->addWidget(regWidget);
    w = new QWidget();
    w->setLayout(layout);
    setCentralWidget(w);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openLogin()
{
    delete layout->takeAt(0);
    layout->addWidget(regWidget);
    w->setLayout(layout);
    setCentralWidget(w);
}

void MainWindow::openCourse()
{
    delete layout->takeAt(0);
    layout->addWidget(courseWidget);
    w->setLayout(layout);
    setCentralWidget(w);
}

void MainWindow::openMainPage(int id)
{
    delete layout->takeAt(0);
    layout->addWidget(mainPageWidget);
    w->setLayout(layout);
    setCentralWidget(w);
}

