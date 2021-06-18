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
    //m_courseContext->setContextProperty("testModel", &temp_test);
    setLayout(m_mainLayout);


    /*
    CourseEl el;
    el.type = "Пробный тип1";
    el.name = "Пробное имя1";
    el.result = "test result1";
    el.endDate = "test date1";

    m_courseModel->addElement(el);

    el.type = "Пробный тип2";
    el.name = "Пробное имя2";
    el.result = "test result2";
    el.endDate = "test date2";

    m_courseModel->addElement(el);

    el.type = "Пробный тип3";
    el.name = "Пробное имя3";
    el.result = "test result3";
    el.endDate = "test date3";

    m_courseModel->addElement(el);

*/

}

int CourseWidget::windowState() const
{
    return m_windowState;
}

void CourseWidget::setCourseModel(CourseModel * model)
{
    if(m_courseModel != nullptr){
        delete m_courseModel;
        m_courseModel = nullptr;
    }
    m_courseModel = new CourseModel(*model);
    connect(m_courseModel, SIGNAL(openElement(int)),this,SLOT(openElement(int)));
    m_courseContext->setContextProperty("CourseModel", m_courseModel);

    m_courseContext->setContextProperty("Form",this);

    setWindowState(2);
}

void CourseWidget::openElement(int index)
{
    CourseElement* element = m_courseModel->getElementByIndex(index);
    if(element->type() == "Тест"){
        Test* testElement = static_cast<Test*>(element);
        m_courseContext->setContextProperty("TestModel", testElement);
        m_courseContext->setContextProperty("TestName", testElement->name());
        m_courseContext->setContextProperty("Form",this);

        setWindowState(3);
    }
}

void CourseWidget::setWindowState(int windowState)
{
    if (m_windowState == windowState)
        return;

    m_windowState = windowState;
    emit windowStateChanged(m_windowState);
}

//void CourseWidget::addQuestin(const QString &question, const QStringList &answers, int rightAnswer)
//{
//    qDebug()<<"asd";
//    temp_test.AddTest(question, answers, rightAnswer);
//}

//void CourseWidget::saveTest()
//{
//    m_courseElements.push_back(temp_test);
//    temp_test.clear();
//}
