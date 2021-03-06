#ifndef THEORYMODEL_H
#define THEORYMODEL_H

#include <QString>
#include <vector>
#include <QStringList>
#include <QAbstractItemModel>
#include <QFlags>

#include "courseelement.h"
#include <QObject>

class TheoryModel : public QObject, public CourseElement
{
    Q_OBJECT
public:
    TheoryModel();
    TheoryModel(const TheoryModel& theory);
    TheoryModel &operator=(const TheoryModel& theory);


    void setTheory(const QString &theory);

    int id() const;
    void setId(int id);

public slots:
    QString theory() const;
    void learned();

signals:
    void learnedSignal();

private:

    QString m_theory;
    int m_id;
};

#endif // THEORYMODEL_H
