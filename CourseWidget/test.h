#ifndef TEST_H
#define TEST_H


#include <QString>
#include <vector>
#include <QStringList>
#include <QAbstractItemModel>
#include <QFlags>
#include <QList>
#include <math.h>



#include "courseelement.h"
#include <QObject>

struct Question{

    QString m_question;
    QStringList m_answers;
    int m_rightAnswer;
};


class Test : public QAbstractListModel, public CourseElement
{

    Q_OBJECT
public:
    Test();
    Test(const Test& test);
    enum testRole{
        QuestionRole = Qt::UserRole + 1,
        AnswersRole
    };

    std::vector<Question> questions() const;
    void clear();



    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

public slots:
     void addQuestion(const QString& question, const QStringList& answers, int rightAnswer);
     void check(QList<int> arrayRes);



private:
    std::vector<Question> m_questions;


public:

signals:
};


#endif // TEST_H
