#include "test.h"

Test::Test()
{
}

void Test::AddTest(const QString& question, const QStringList& answers, int rightAnswer)
{
    Question task;
    task.m_question = question;
    task.m_answers = answers;
    task.m_rightAnswer = rightAnswer;

    m_questions.push_back(task);
}

QHash<int, QByteArray> Test::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[QuestionRole] = "QuestionRole";
    roles[AnswersRole] = "AnswersRole";
    return roles;
}

int Test::rowCount(const QModelIndex &parent) const
{
    return m_questions.size();
}
