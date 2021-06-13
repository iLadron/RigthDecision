#include "coursewidget.h"

CourseWidget::CourseWidget(QWidget *pwgt) : QWidget(pwgt)
{

    //Creating CourseForm
    m_courseWidget = new QQuickWidget(QUrl("qrc:/forms/forms/MainCourseForm.qml"));
    m_courseWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
  //  temp_test = new Test();

    m_mainLayout = new QVBoxLayout;
    m_mainLayout->addWidget(m_courseWidget);

    m_courseContext = m_courseWidget->rootContext();
    //m_courseContext->setContextProperty("Path", QDir::currentPath()+ "/../CourseWidget/forms/");
    m_courseContext->setContextProperty("testModel", &temp_test);
    m_courseContext->setContextProperty("Form",this);
    setLayout(m_mainLayout);



}

void CourseWidget::addQuestin(const QString &question, const QStringList &answers, int rightAnswer)
{
    qDebug()<<"asd";
    temp_test.AddTest(question, answers, rightAnswer);
}

void CourseWidget::saveTest()
{
    m_tests.push_back(temp_test);
    temp_test.clear();
}
