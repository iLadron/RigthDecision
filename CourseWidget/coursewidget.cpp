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
    m_courseContext->setContextProperty("Form",this);

    setLayout(m_mainLayout);


}

int CourseWidget::windowState() const
{
    return m_windowState;
}

void CourseWidget::setCourseModel(CourseModel * model)
{
    /*
    if(m_courseModel != nullptr){
        delete m_courseModel;
        m_courseModel = nullptr;
    }
    */
    m_courseModel = new CourseModel(*model);
    connect(m_courseModel, SIGNAL(openElement(int)),this,SLOT(openElement(int)));
    m_courseContext->setContextProperty("CourseModel", m_courseModel);


    setWindowState(2);
}

void CourseWidget::openElement(int index)
{
    if(index < m_courseModel->getTheorySize()){
        TheoryModel* theoryElement = m_courseModel->getTheoryByIndex(index);
        m_courseContext->setContextProperty("TheoryModel", theoryElement);
        m_courseContext->setContextProperty("TheoryName", theoryElement->name());
        m_courseContext->setContextProperty("TheoryText", theoryElement->theory());

        connect(theoryElement, SIGNAL(learnedSignal()),m_courseModel,SLOT(resetModel()));

        setWindowState(4);
    }else{
        //Test* testElement = m_courseModel->getTestByIndex(index-m_courseModel->getTheorySize());

        m_courseContext->setContextProperty("TestModel", m_courseModel->getTestByIndex(index-m_courseModel->getTheorySize()));
        m_courseContext->setContextProperty("TestName", m_courseModel->getTestByIndex(index-m_courseModel->getTheorySize())->name());

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

void CourseWidget::setTestModel()
{
    m_courseModel->getTempTest()->clear();
    m_courseModel->getTempTest()->setName("Введите название теста");
    m_courseModel->getTempTest()->setType("Тест");
    m_courseContext->setContextProperty("TestModel", m_courseModel->getTempTest());
    m_courseContext->setContextProperty("TestName", m_courseModel->getTempTest()->name());
}

void CourseWidget::setTheoryModel()
{

    m_courseModel->getTheoryModel()->setName("Введите название теории");
    m_courseModel->getTheoryModel()->setType("Теория");
    m_courseContext->setContextProperty("TheoryName", m_courseModel->getTheoryModel()->name());
    m_courseContext->setContextProperty("TheoryText", m_courseModel->getTheoryModel()->theory());
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
