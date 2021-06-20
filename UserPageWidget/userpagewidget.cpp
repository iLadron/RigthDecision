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

        tempModel.setCourseId(inProgressQuery.value(rec.indexOf("id")).toInt());

        User tempAuthor = Database::getUserById(inProgressQuery.value(rec.indexOf("idAuthor")).toInt());

        QSqlQuery tempTestProgress = Database::getTestsByCourseId(inProgressQuery.value(rec.indexOf("id")).toInt());
        QSqlRecord tempRec = tempTestProgress.record();

        QSqlQuery tempCourseInfo = Database::getCourseInfoByCourseId(inProgressQuery.value(rec.indexOf("id")).toInt());
        QSqlRecord tempCourseInfoRec = tempCourseInfo.record();
        tempCourseInfo.next();

        tempModel.setDateBegin(tempCourseInfo.value(tempCourseInfoRec.indexOf("dateBegin")).toString());

        QStringList tempMarks = tempCourseInfo.value(tempCourseInfoRec.indexOf("marks")).toString().split(';');
        int counterMarks = 0;
        while (tempTestProgress.next()) {
            Test tempTest;
            QStringList questions = tempTestProgress.value(tempRec.indexOf("questions")).toString().split(';');
            QStringList answers = tempTestProgress.value(tempRec.indexOf("answers")).toString().split(';');
            QStringList rightAnswersNumbers = tempTestProgress.value(tempRec.indexOf("rightAnswerNumbers")).toString().split(';');
            tempTest.setId(tempTestProgress.value(tempRec.indexOf("id")).toInt());
            tempTest.setName(tempTestProgress.value(tempRec.indexOf("name")).toString());
            tempTest.setType("Тест");
            tempTest.setResult(tempMarks[counterMarks++]);
            for (int i = 0; i < questions.size();i++){
                QStringList answersSeperated;
                for(int j = 0+(i*4); j < 4+(i*4);j++){
                    answersSeperated.push_back(answers[j]);
                }
                tempTest.addQuestion(questions[i],answersSeperated,rightAnswersNumbers[i].toInt());
            }



            QStringList dateBeginData = tempModel.getDateBegin().split('-');

            QDate dateBegin;
            dateBegin.setDate(dateBeginData[0].toInt(), dateBeginData[1].toInt(),dateBeginData[2].toInt());
            dateBegin = dateBegin.addDays(tempTestProgress.value(tempRec.indexOf("timeToComplete")).toInt());

            tempTest.setDateEnd(dateBegin.toString("dd-MM-yyyy"));

            tempModel.addElement(tempTest);
        }


        QSqlQuery theoryQuery = Database::getTheoryByCourseId(inProgressQuery.value(rec.indexOf("id")).toInt());
        QSqlRecord theoryRec = theoryQuery.record();



        QStringList tempRead = tempCourseInfo.value(tempCourseInfoRec.indexOf("theoryRead")).toString().split(';');
        int counterRead = 0;
        while(theoryQuery.next()){

            TheoryModel tempTheory;
            tempTheory.setType("Теория");
            tempTheory.setDateEnd("Нет");
            tempTheory.setResult(tempRead[counterRead++]);
            tempTheory.setId(theoryQuery.value(theoryRec.indexOf("id")).toInt());
            tempTheory.setName(theoryQuery.value(theoryRec.indexOf("name")).toString());
            tempTheory.setTheory(theoryQuery.value(theoryRec.indexOf("text")).toString());

            tempModel.addElement(tempTheory);

        }

        tempModel.setData(inProgressQuery.value(rec.indexOf("name")).toString(),
                          tempAuthor,
                          inProgressQuery.value(rec.indexOf("shortDescription")).toString(),
                          inProgressQuery.value(rec.indexOf("rating")).toDouble());

        tempModel.setDateBegin(tempCourseInfo.value(tempCourseInfoRec.indexOf("dateBegin")).toString());
        tempModel.setIsComplete(tempCourseInfo.value(tempCourseInfoRec.indexOf("isCompleted")).toInt() == 1);
        m_inProgressCourses.push_back(tempModel);

        tempModel.resetModel();

    }


    QSqlQuery CreatedQuery = Database::getCreatedCourses();

    rec = CreatedQuery.record();

    while (CreatedQuery.next()) {

        CourseModel tempModel;
        User tempAuthor = Database::getUserById(CreatedQuery.value(rec.indexOf("idAuthor")).toInt());
        tempModel.setCourseId(CreatedQuery.value(rec.indexOf("id")).toInt());


        QSqlQuery tempTestProgress = Database::getTestsByCourseId(CreatedQuery.value(rec.indexOf("id")).toInt());
        QSqlRecord tempRec = tempTestProgress.record();


        QSqlQuery tempCourseInfo = Database::getCourseInfoByCourseId(CreatedQuery.value(rec.indexOf("id")).toInt());
        QSqlRecord tempCourseInfoRec = tempCourseInfo.record();

        while (tempTestProgress.next()) {
            Test tempTest;
            QStringList questions = tempTestProgress.value(tempRec.indexOf("questions")).toString().split(';');
            QStringList answers = tempTestProgress.value(tempRec.indexOf("answers")).toString().split(';');
            QStringList rightAnswersNumbers = tempTestProgress.value(tempRec.indexOf("rightAnswerNumbers")).toString().split(';');
            tempTest.setId(tempTestProgress.value(tempRec.indexOf("id")).toInt());
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

        QSqlQuery theoryQuery = Database::getTheoryByCourseId(CreatedQuery.value(rec.indexOf("id")).toInt());
        QSqlRecord theoryRec = theoryQuery.record();


        QStringList tempRead = tempCourseInfo.value(tempCourseInfoRec.indexOf("theoryRead")).toString().split(';');
        int counterRead = 0;
        while(theoryQuery.next()){

            TheoryModel tempTheory;
            tempTheory.setType("Теория");
            tempTheory.setDateEnd("Нет");
            tempTheory.setResult(tempRead[counterRead++]);
            tempTheory.setId(theoryQuery.value(theoryRec.indexOf("id")).toInt());
            tempTheory.setName(theoryQuery.value(theoryRec.indexOf("name")).toString());
            tempTheory.setTheory(theoryQuery.value(theoryRec.indexOf("text")).toString());

            tempModel.addElement(tempTheory);

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
    if(id == -1){
        CourseModel* model = new CourseModel();
        model->setIsCreator(true);
        model->setData("Введите название курса", *Database::getLoginedUser(),"Введите описание", -1);
        emit openCourse(model);
    }else{
        m_inProgressCourses[id].setIsCreator(false);
        emit openCourse(& m_inProgressCourses[id]);

    }
}

void UserPageWidget::changeCourse(int id)
{
    m_createdCourses[id].setIsCreator(true);
    emit openCourse(& m_createdCourses[id]);
}

QStringList UserPageWidget::getInProgressCourseData()
{
    QStringList data;
    for(int i = 0; i < m_inProgressCourses.size(); i++){
        data << (m_inProgressCourses[i].getData());
    }
    return data;
}

