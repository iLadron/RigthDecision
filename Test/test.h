#ifndef TEST_H
#define TEST_H

#include <QString>
#include <vector>
#include <QStringList>
#include <QAbstractItemModel>


#include "Test_global.h"

struct Question{

    QString m_question;
    QStringList m_answers;
    int m_rightAnswer;
};


class TEST_EXPORT Test : public QAbstractItemModel
{
public:
    Test();
    enum testRole{
        QuestionRole = Qt::UserRole + 1,
        AnswersRole
    };

    void AddTest(const QString& question, const QStringList& answers, int rightAnswer);

    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    std::vector<Question> m_questions;
};




#endif // TEST_H
