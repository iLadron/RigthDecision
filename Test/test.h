#ifndef TEST_H
#define TEST_H

#include <QString>
#include <vector>

#include "Test_global.h"

class Question{
public:
    Question();

    void setQuestion(QString question);

    QString getQuestion();

protected:
    QString m_question;
};

class SimpleQuestion : public Question{
public:
    SimpleQuestion();

private:

};

class TEST_EXPORT Test
{
public:
    Test();
    void addQuestion(Question);

private:
    std::vector<Question> m_questions;
};




#endif // TEST_H
