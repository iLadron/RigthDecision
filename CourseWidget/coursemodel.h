#ifndef COURSEMODEL_H
#define COURSEMODEL_H

#include <QString>
#include <vector>
#include <QStringList>
#include <QAbstractItemModel>
#include <QFlags>

#include "courseelement.h"
#include "test.h"
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
    void addTest(const QString& question, const QStringList& answers, int rightAnswer);
    void setData(const QString& name, const User& author, const QString& description, int rating);

    CourseElement* getElementByIndex(int index);

    QString name() const;

    QString description() const;

    bool isCreator() const;

    QString authorName() const;

public slots:
    QString getData();

    void setName(QString name);

    void setDescription(QString description);

    void setIsCreator(bool isCreator);

    void setAuthorName(QString authorName);

signals:
    void nameChanged(QString name);

    void descriptionChanged(QString description);

    void isCreatorChanged(bool isCreator);

    void authorNameChanged(QString authorName);

    void openElement(int index);

private:
    std::vector<CourseElement> m_elements;


    QString m_name;
    User m_author;
    QString m_description;
    double m_rating;
    int m_courseId;


    Test m_tempTest;

    bool m_isCreator;
    QString m_authorName;
};

#endif // COURSEMODEL_H
