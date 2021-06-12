#include "coursewidget.h"

CourseWidget::CourseWidget(QWidget *pwgt) : QWidget(pwgt)
{

    //Creating CourseForm
    m_courseWidget = new QQuickWidget(QUrl("qrc:/forms/forms/MainCourseForm.qml"));
    m_courseWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    test = new Test();

    test->AddTest("1+1", {"1", "2", "3", "4"}, 4);
    test->AddTest("2+2", {"1", "2", "3", "4"}, 4);
    test->AddTest("3+3", {"1", "2", "3", "4"}, 4);


    m_mainLayout = new QVBoxLayout;
    m_mainLayout->addWidget(m_courseWidget);

    m_courseContext = m_courseWidget->rootContext();
    //m_courseContext->setContextProperty("Path", QDir::currentPath()+ "/../CourseWidget/forms/");
    m_courseContext->setContextProperty("testModel",test);
    m_courseContext->setContextProperty("Form",this);
    setLayout(m_mainLayout);



}

void CourseWidget::addQuestin(const QString &question, const QStringList &answers, int rightAnswer)
{
    qDebug()<<"asd";
    test->AddTest(question, answers, rightAnswer);
}
