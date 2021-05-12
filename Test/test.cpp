#include "test.h"

Test::Test()
{
}

void Question::setQuestion(QString question)
{
    m_question = question;
}

QString Question::getQuestion()
{
    return m_question;
}
