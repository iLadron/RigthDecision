#ifndef COURSEMODEL_H
#define COURSEMODEL_H

#include <QString>
#include <vector>
#include <QStringList>
#include <QAbstractItemModel>
#include <QFlags>

#include "test.h"
#include "theorymodel.h"
#include "database.h"


class CourseModel : public QAbstractTableModel
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(bool isCreator READ isCreator WRITE setIsCreator NOTIFY isCreatorChanged)
    Q_PROPERTY(QString authorName READ authorName WRITE setAuthorName NOTIFY authorNameChanged)

public:
    CourseModel();
    CourseModel(const CourseModel& model);
    enum courseElRole{
        TypeRole = Qt::UserRole + 1,
        NameRole,
        ResultRole,
        DateEndRole
    };

    // QAbstractItemModel interface
public:
    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    void addElement(CourseElement);
    void addElement(Test);
    void addElement(TheoryModel);
    void addTest(const QString& question, const QStringList& answers, int rightAnswer);
    void setData(const QString& name, const User& author, const QString& description, int rating);

    Test* getTestByIndex(int index);
    TheoryModel* getTheoryByIndex(int index);

    QString name() const;

    QString description() const;

    bool isCreator() const;

    QString authorName() const;

    QString getDateBegin() const;
    void setDateBegin(const QString &dateBegin);

    bool getIsComplete() const;
    void setIsComplete(bool isComplete);

    int getTheorySize();
    int getTestsSize();


public slots:
    QString getData();

    void setName(QString name);

    void setDescription(QString description);

    void setIsCreator(bool isCreator);

    void setAuthorName(QString authorName);

    void resetModel();

signals:
    void nameChanged(QString name);

    void descriptionChanged(QString description);

    void isCreatorChanged(bool isCreator);

    void authorNameChanged(QString authorName);

    void openElement(int index);

private:
    std::vector<Test> m_tests;
    std::vector<TheoryModel> m_theories;

    QString m_name;
    User m_author;
    QString m_description;
    double m_rating;
    int m_courseId;


    Test m_tempTest;

    bool m_isCreator;
    QString m_authorName;

    QString m_dateBegin;
    bool m_isComplete;
};

#endif // COURSEMODEL_H
