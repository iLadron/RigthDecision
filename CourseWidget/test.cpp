#include "test.h"
#include <QDebug>

Test::Test()
{
    Question task;
    qDebug()<< "testSize: " << m_questions.size();
}

Test::Test(const Test &test)
{
    m_questions = test.questions();
    setDateEnd(test.dateEnd());
    setName(test.name());
    setResult(test.result());
    setType(test.type());    
}

std::vector<Question> Test::questions() const
{
    return m_questions;
}

void Test::clear()
{
    m_questions.clear();
    setName("");
    setDateEnd("");
}

void Test::setQuestions(std::vector<Question> questions)
{
    beginResetModel();
    m_questions = questions;
    endResetModel();
}

void Test::addQuestion(const QString& question, const QStringList& answers, int rightAnswer)
{
    beginResetModel();
    Question task;
    task.m_question = question;
    task.m_answers = answers;
    task.m_rightAnswer = rightAnswer;

    m_questions.push_back(task);
    endResetModel();

    qDebug()<<"TestSize " << m_questions.size();
}

void Test::check(QList<int> arrayRes)
{
    int result = 0;
    for(int i = 0; i <arrayRes.size();i++){
        if(arrayRes[i] == 3)
            arrayRes[i] = 2;
        if(arrayRes[i] == 5)
            arrayRes[i] = 3;
        if(arrayRes[i] == 7)
            arrayRes[i] = 4;
    }
    for(int i = 0; i < m_questions.size(); i++){
        if(arrayRes[i] == m_questions[i].m_rightAnswer){
            result++;
        }
    }

    double tempa = (static_cast<double>(result)/static_cast<double>(m_questions.size())) * 5;
    beginResetModel();
        setResult(QString::number(ceil(tempa)));
    endResetModel();
}




QHash<int, QByteArray> Test::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[QuestionRole] = "Question";
    roles[AnswersRole] = "Answers";
    return roles;
}

int Test::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
    return 0;

    return m_questions.size();
}
QVariant Test::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    Question quest = m_questions.at(index.row());

    switch (role) {
    case QuestionRole:
        return quest.m_question;
        break;
    case AnswersRole:
        return quest.m_answers;
        break;
    default:
        return QVariant();
    }
}

Qt::ItemFlags Test::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

