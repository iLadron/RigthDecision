#include "userpagewidget.h"

UserPageWidget::UserPageWidget(QWidget * pwdt) : QWidget(pwdt)
{
    m_lkWidget = new QQuickWidget(QUrl("qrc:/forms/UserPageFrom.qml"));
    m_lkWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);


    m_mainLayout = new QVBoxLayout;
    m_mainLayout->addWidget(m_lkWidget);

    m_lkContext = m_lkWidget->rootContext();
    m_lkContext->setContextProperty("Form",this);

    setLayout(m_mainLayout);

    /*
    CourseModel model;

    model.setData("First Course", "Andrey", "My first Test course");

    CourseEl el;
    el.type = "Пробный тип1";
    el.name = "Пробное имя1";
    el.result = "test result1";
    el.endDate = "test date1";

    model.addElement(el);

    el.type = "Пробный тип2";
    el.name = "Пробное имя2";
    el.result = "test result2";
    el.endDate = "test date2";

    model.addElement(el);

    el.type = "Пробный тип3";
    el.name = "Пробное имя3";
    el.result = "test result3";
    el.endDate = "test date3";
    model.addElement(el);

    m_createdCourses.push_back(model);

    model.setData("second Course", "Andrey2", "My second Test course");

    el.type = "Пробный тип1";
    el.name = "Пробное имя1";
    el.result = "test result1";
    el.endDate = "test date1";

    model.addElement(el);

    el.type = "Пробный тип2";
    el.name = "Пробное имя2";
    el.result = "test result2";
    el.endDate = "test date2";

    model.addElement(el);

    el.type = "Пробный тип3";
    el.name = "Пробное имя3";
    el.result = "test result3";
    el.endDate = "test date3";
    model.addElement(el);
    m_createdCourses.push_back(model);
*/
}

QStringList UserPageWidget::user() const
{
    return m_user;
}

void UserPageWidget::setUser(QStringList user)
{

    User* lUser = Database::getLoginedUser();

    m_user.clear();
    m_user.push_back(lUser->name);
    m_user.push_back(lUser->surname);
    m_user.push_back(lUser->login);
    m_user.push_back(lUser->email);

    emit userChanged(m_user);
}

void UserPageWidget::refreshCourses()
{
    m_inProgressCourses.clear();
    m_createdCourses.clear();

    QSqlQuery inProgressQuery = Database::getInProgressCourses();

    QSqlRecord rec = inProgressQuery.record();

    while (inProgressQuery.next()) {

        CourseModel tempModel;
        User tempAuthor = Database::getUserById(inProgressQuery.value(rec.indexOf("idAuthor")).toInt());

        QSqlQuery tempTestProgress = Database::getTestsByCourseId(inProgressQuery.value(rec.indexOf("id")).toInt());

        QSqlRecord tempRec = tempTestProgress.record();


        while (tempTestProgress.next()) {
            Test tempTest;
            QStringList questions = tempTestProgress.value(tempRec.indexOf("questions")).toString().split(';');
            QStringList answers = tempTestProgress.value(tempRec.indexOf("answers")).toString().split(';');
            QStringList rightAnswersNumbers = tempTestProgress.value(tempRec.indexOf("rightAnswerNumbers")).toString().split(';');
            tempTest.setName(tempTestProgress.value(tempRec.indexOf("name")).toString());
            tempTest.setType("Тест");
            for (int i = 0; i < questions.size();i++){
                QStringList answersSeperated;
                for(int j = 0+(i*4); j < 4+(i*4);j++){
                    answersSeperated.push_back(answers[j]);
                }
                tempTest.addQuestion(questions[i],answersSeperated,rightAnswersNumbers[i].toInt());
            }
            tempModel.addElement(tempTest);
        }


        tempModel.setData(inProgressQuery.value(rec.indexOf("name")).toString(),
                          tempAuthor,
                          inProgressQuery.value(rec.indexOf("shortDescription")).toString(),
                          inProgressQuery.value(rec.indexOf("rating")).toDouble());
        m_inProgressCourses.push_back(tempModel);

    }


    QSqlQuery CreatedQuery = Database::getCreatedCourses();

    rec = CreatedQuery.record();

    while (CreatedQuery.next()) {

        CourseModel tempModel;
        User tempAuthor = Database::getUserById(CreatedQuery.value(rec.indexOf("idAuthor")).toInt());

        QSqlQuery tempTestProgress = Database::getTestsByCourseId(CreatedQuery.value(rec.indexOf("id")).toInt());

        QSqlRecord tempRec = tempTestProgress.record();


        while (tempTestProgress.next()) {
            Test tempTest;
            QStringList questions = tempTestProgress.value(tempRec.indexOf("questions")).toString().split(';');
            QStringList answers = tempTestProgress.value(tempRec.indexOf("answers")).toString().split(';');
            QStringList rightAnswersNumbers = tempTestProgress.value(tempRec.indexOf("rightAnswerNumbers")).toString().split(';');
            for (int i = 0; i < questions.size();i++){
                QStringList answersSeperated;
                for(int j = 0+(i*4); j < 4+(i*4);j++){
                    answersSeperated.push_back(answers[j]);
                }
                tempTest.addQuestion(questions[i],answersSeperated,rightAnswersNumbers[i].toInt());
            }
            tempModel.addElement(tempTest);
        }


        tempModel.setData(CreatedQuery.value(rec.indexOf("name")).toString(),
                          tempAuthor,
                          CreatedQuery.value(rec.indexOf("shortDescription")).toString(),
                          CreatedQuery.value(rec.indexOf("rating")).toDouble());
        m_createdCourses.push_back(tempModel);

    }

}

QStringList UserPageWidget::getCreatedCourseData()
{
    QStringList data;
    for(int i = 0; i < m_createdCourses.size(); i++){
        data.push_back(m_createdCourses[i].getData());
    }
    return data;
}

void UserPageWidget::openCourse(int id)
{
    emit openCourse(& m_inProgressCourses[id]);
}

QStringList UserPageWidget::getInProgressCourseData()
{
    QStringList data;
    for(int i = 0; i < m_inProgressCourses.size(); i++){
        data << (m_inProgressCourses[i].getData());
    }
    return data;
}

