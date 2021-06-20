#include "coursemodel.h"

CourseModel::CourseModel()
{

}

CourseModel::CourseModel(const CourseModel &model)
{
    /*
     *    std::vector<CourseEl> m_elements;
    std::vector<Test> m_tests;
    QString m_name;
    QString m_author;
    QString m_description;
     * */

    for(size_t i = 0; i < model.m_tests.size(); i++){
        m_tests.push_back(model.m_tests[i]);
    }

    for(size_t i = 0; i < model.m_theories.size(); i++){
        m_theories.push_back(model.m_theories[i]);
    }

    setName(model.name());
    setAuthorName(model.authorName());
    setDescription(model.description());

    m_author = model.m_author;
    m_description = model.m_description;
    m_rating = model.m_rating;
    m_courseId = model.m_courseId;
    setIsCreator(model.isCreator());

}

QHash<int, QByteArray> CourseModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    enum courseElRole{
        TypeRole = Qt::UserRole + 1,
        NameRole,
        ResultRole,
        DateEndRole
    };
    roles[TypeRole] = "Type";
    roles[NameRole] = "Name";
    roles[ResultRole] = "Result";
    roles[DateEndRole] = "DateEnd";
    return roles;
}

int CourseModel::rowCount(const QModelIndex &parent) const
{
    return m_tests.size() + m_theories.size();
}

int CourseModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant CourseModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

        if(index.row() < m_theories.size()){

            TheoryModel element = m_theories.at(index.row());

            switch (role) {
            case TypeRole:
                return element.type();
                break;
            case NameRole:
                return element.name();
                break;
            case ResultRole:
                return element.result();
                break;
            case DateEndRole:{
                return element.dateEnd();
                break;
            }
            default:
                return QVariant();
            }

        }else{
            Test element = m_tests.at(index.row() -m_theories.size());

            switch (role) {
            case TypeRole:
                return element.type();
                break;
            case NameRole:
                return element.name();
                break;
            case ResultRole:
                return element.result();
                break;
            case DateEndRole:
                return element.dateEnd();
                break;
            default:
                return QVariant();
            }
        }
}

void CourseModel::addElement(Test test)
{
    m_tests.push_back(test);
}

void CourseModel::addElement(TheoryModel model)
{
    m_theories.push_back(model);
}

void CourseModel::addTest(const QString &question, const QStringList &answers, int rightAnswer)
{
    m_tempTest.addQuestion(question, answers, rightAnswer);
}

void CourseModel::setData(const QString &name, const User& author, const QString &description, int rating)
{
    m_name = name;
    m_author = author;
    m_description = description;
    m_rating = rating;
}

Test *CourseModel::getTestByIndex(int index)
{
    return &m_tests[index];
}

TheoryModel *CourseModel::getTheoryByIndex(int index)
{
    return &m_theories[index];
}



QString CourseModel::name() const
{
    return m_name;
}

QString CourseModel::description() const
{
    return m_description;
}

bool CourseModel::isCreator() const
{
    return m_isCreator;
}

QString CourseModel::authorName() const
{
    return m_author.name;
}

QString CourseModel::getData()
{
    return m_name + ";" + m_author.name + ";" + m_description;
}

void CourseModel::setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(m_name);
}

void CourseModel::setDescription(QString description)
{
    if (m_description == description)
        return;

    m_description = description;
    emit descriptionChanged(m_description);
}

void CourseModel::setIsCreator(bool isCreator)
{
    if (m_isCreator == isCreator)
        return;

    m_isCreator = isCreator;
    emit isCreatorChanged(m_isCreator);
}

void CourseModel::setAuthorName(QString authorName)
{
    if (m_authorName == authorName)
        return;

    m_authorName = authorName;
    emit authorNameChanged(m_authorName);
}

void CourseModel::resetModel()
{
    beginResetModel();
    endResetModel();
}


Test *CourseModel::getTempTest()
{
    return &m_tempTest;
}

TheoryModel *CourseModel::getTheoryModel()
{
    return &m_tempTheory;
}



void CourseModel::saveTest(QString name, QString date, QString oldName)
{
    beginResetModel();
    m_tempTest.setName(name);
    m_tempTest.setDateEnd(date);

    for(int i = 0; i < m_tests.size();i++){
        if(m_tests[i].name()==oldName){
            m_tests[i].setDateEnd(date);
            m_tests[i].setName(name);
            //m_tests[i].setQuestions(m_tempTest.questions());
            m_tempTest.clear();
            return;

        }
    }

     m_tests.push_back(m_tempTest);
     m_tempTest.clear();
     endResetModel();
}

void CourseModel::saveTheory(QString name, QString theory, QString oldName)
{
    m_tempTheory.setName(name);
    m_tempTheory.setTheory(theory);
    std::vector<TheoryModel> tempVec;
    for(int i = 0; i < m_theories.size();i++){
        if(m_theories[i].name()==oldName){
            m_theories[i].setTheory(theory);
            m_theories[i].setName(name);
            m_tempTheory.setName("");
            m_tempTheory.setTheory("");
            return;
        }
    }

    m_theories.push_back(m_tempTheory);
    m_tempTheory.setName("");
    m_tempTheory.setTheory("");
}

void CourseModel::addQuestion(const QString &question, const QStringList &answers, int rightAnswer, QString oldName)
{
    for(int i = 0; i < m_tests.size();i++){
        if(m_tests[i].name()==oldName){
            m_tests[i].addQuestion(question,answers,rightAnswer);
            return;
        }
    }
    m_tempTest.addQuestion(question, answers, rightAnswer);
}

void CourseModel::saveTestResults()
{
    QString marks = "";
    for(int i = 0; i < m_tests.size(); i++){
        marks +=m_tests[i].result()+';';
    }

    Database::saveTestResults(m_courseId,marks);
}

void CourseModel::saveTheoryResults()
{
    QString marks = "";
    for(int i = 0; i < m_theories.size(); i++){
        marks +=m_theories[i].result()+';';
    }

    Database::saveTheoryResults(m_courseId,marks);
}

void CourseModel::saveCourse(QString courseName, QString courseDescription)
{
    QStringList testCreator;
    QStringList theoryCreator;
    QString courseCreator = "()";


    for(int i = 0; i < m_tests.size(); i++){
        QString questions ="";
        QString answers ="";
        QString rightAnswers="";

        for(int j =0; j < m_tests[i].questions().size(); j++){
            questions+=m_tests[i].questions()[i].m_question + ";";
            answers+=QString::number(m_tests[i].questions()[i].m_rightAnswer) + ";";
            for(int k = 0+(j*4); k < 4+(j*4);k++){
                answers+=m_tests[i].questions()[i].m_answers[k] + ";";
            }
        }

        QString value="(NULL, '%1', '%2', '%3','%4',%5,%6)";
        value = value.arg(m_tests[i].name())
                .arg(questions)
                .arg(answers)
                .arg(rightAnswers)
                .arg(m_tests[i].dateEnd().toInt())
                .arg(m_courseId);

        testCreator.push_back(value);
    }

    for(int i = 0; i <m_theories.size();i++){
        QString value = "(NULL,'%1','%2','',%3)";

        value = value.arg(m_theories[i].name())
                .arg(m_theories[i].theory())
                .arg(m_courseId);
        theoryCreator.push_back(value);
    }




}

int CourseModel::getCourseId() const
{
    return m_courseId;
}

void CourseModel::setCourseId(int courseId)
{
    m_courseId = courseId;
}

bool CourseModel::getIsCreator() const
{
    return m_isCreator;
}

bool CourseModel::getIsComplete() const
{
    return m_isComplete;
}

void CourseModel::setIsComplete(bool isComplete)
{
    m_isComplete = isComplete;
}

int CourseModel::getTheorySize()
{
    return m_theories.size();
}

int CourseModel::getTestsSize()
{
    return m_tests.size();
}

QString CourseModel::getDateBegin() const
{
    return m_dateBegin;
}

void CourseModel::setDateBegin(const QString &dateBegin)
{
    m_dateBegin = dateBegin;
}

