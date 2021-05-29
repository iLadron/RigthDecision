#include "coursewidget.h"

CourseWidget::CourseWidget(QWidget *pwgt) : QWidget(pwgt)
{
    //Creating CourseForm
    m_courseWidget = new QQuickWidget(QUrl("qrc:/forms/forms/MainCourseForm.qml"));
    m_courseWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

    m_mainLayout = new QVBoxLayout;
    m_mainLayout->addWidget(m_courseWidget);

    m_courseContext = m_courseWidget->rootContext();
    //m_courseContext->setContextProperty("Path", QDir::currentPath()+ "/../CourseWidget/forms/");
    m_courseContext->setContextProperty("Form",this);


    setLayout(m_mainLayout);

}
