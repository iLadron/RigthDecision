#ifndef COURSEELEMENT_H
#define COURSEELEMENT_H

#include <QString>
#include <QObject>

class CourseElement
{

public:
    CourseElement();
    CourseElement(const CourseElement&);


    QString type() const;
    void setType(const QString &type);

    QString name() const;
    void setName(const QString &name);

    QString result() const;
    void setResult(const QString &result);

    QString dateEnd() const;
    void setDateEnd(const QString &dateEnd);

private:
    QString m_type;
    QString m_name;
    QString m_result;
    QString m_dateEnd;
};

#endif // COURSEELEMENT_H
