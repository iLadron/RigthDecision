#include "course.h"

#include <QDir>

Course::Course(QWidget *pwgt)
{
    m_courseWidget = new QQuickWidget(QUrl("qrc:/forms/formss/MainCourseForm.qml"));
    m_courseWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

    m_mainLayout = new QVBoxLayout;
    m_mainLayout->addWidget(m_courseWidget);


    m_courseContext = m_courseWidget->rootContext();
    m_courseContext->setContextProperty("Form",this);

    setLayout(m_mainLayout);
}
