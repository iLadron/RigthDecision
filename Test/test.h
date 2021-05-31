#ifndef TEST_H
#define TEST_H

#include <QString>
#include <vector>
#include <QStringList>
#include <QAbstractItemModel>
#include <QFlags>


#include "Test_global.h"

struct Question{

    QString m_question;
    QStringList m_answers;
    int m_rightAnswer;
};


class TEST_EXPORT Test : public QAbstractListModel
{
public:
    Test();
    enum testRole{
        QuestionRole = Qt::UserRole + 1,
        AnswersRole
    };

    std::vector<Question> questions() const;



    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

public slots:
     void AddTest(const QString& question, const QStringList& answers, int rightAnswer);


private:
    std::vector<Question> m_questions;

public:

};




#endif // TEST_H
