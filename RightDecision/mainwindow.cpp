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
    userPageWidget = new UserPageWidget();




    //Переходы между страниц
    connect(regWidget,SIGNAL(loginSuccess()), this, SLOT(openMainPage()));
    connect(mainPageWidget, SIGNAL(openLK()), this, SLOT(openLKPage()));
    connect(userPageWidget, SIGNAL(openMainWindow()), this, SLOT(openMainPage()));
    connect(userPageWidget, SIGNAL(openCreateCourseWidget()), this, SLOT(openCourse()));
    connect(courseWidget, SIGNAL(openLK()), this, SLOT(openLKPage()));


    //События
    connect(regWidget,SIGNAL(loginSuccess()), this, SLOT(afterLoginSuccsess()));

    layout = new QHBoxLayout();
    layout->addWidget(regWidget);
    layout->addWidget(courseWidget);
    layout->addWidget(mainPageWidget);
    layout->addWidget(userPageWidget);
    clearLayout(layout);
    regWidget->setVisible(true);
    w = new QWidget();
    w->setLayout(layout);
    setCentralWidget(w);





    /*

    manager = new QNetworkAccessManager();


    QObject::connect(manager, &QNetworkAccessManager::finished,
         this, [=](QNetworkReply *reply) {
             if (reply->error()) {
                 qDebug() << reply->errorString();
                 return;
             }

             QString answer = reply->readAll();

             qDebug() << answer;
         }
     );
*/
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openLogin()
{
    clearLayout(layout);
    //layout->addWidget(regWidget);
    w->setLayout(layout);
    setCentralWidget(w);
}

void MainWindow::openCourse()
{
    clearLayout(layout);
    courseWidget->setVisible(true);
    w->setLayout(layout);
    setCentralWidget(w);
}

void MainWindow::openMainPage()
{
    qDebug()<<"OpenMa2in";
    clearLayout(layout);
    mainPageWidget->setVisible(true);
    w->setLayout(layout);
    setCentralWidget(w);
}

void MainWindow::openLKPage()
{
    clearLayout(layout);
    userPageWidget->setVisible(true);
    w->setLayout(layout);
    setCentralWidget(w);
}

void MainWindow::clearLayout(QLayout *layout) {
    qDebug()<<layout->count();

    for (int i = 0; i < layout->count(); ++i) {
        QWidget *w = layout->itemAt(i)->widget();
        if(w != NULL)
            w->setVisible(false);
    }
    qDebug()<<layout->count();

}

void MainWindow::afterLoginSuccsess()
{
    userPageWidget->setUser({});
}

void MainWindow::on_pushButton_clicked()
{
    request.setUrl(QUrl("https://drive.google.com/uc?export=download&id=1LZV5vdcKEbj6ogYHrn_in6NYAjp53NTU"));
     manager->get(QNetworkRequest(QUrl("http://qt-project.org")));
}
