#include "test.h"
#include <QDebug>

Test::Test()
{
    Question task;
    qDebug()<< "testSize: " << m_questions.size();
}

std::vector<Question> Test::questions() const
{
    return m_questions;
}

void Test::AddTest(const QString& question, const QStringList& answers, int rightAnswer)
{
    Question task;
    task.m_question = question;
    task.m_answers = answers;
    task.m_rightAnswer = rightAnswer;

    m_questions.push_back(task);

    qDebug()<<"TestSize " << m_questions.size();
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

