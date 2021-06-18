#include "courseelement.h"

CourseElement::CourseElement()
{

}

CourseElement::CourseElement(const CourseElement &el)
{
    m_type = el.m_type;
    m_name = el.m_name;
    m_result =el.m_result;
    m_dateEnd = el.m_dateEnd;
}

QString CourseElement::type() const
{
    return m_type;
}

void CourseElement::setType(const QString &type)
{
    m_type = type;
}

QString CourseElement::name() const
{
    return m_name;
}

void CourseElement::setName(const QString &name)
{
    m_name = name;
}

QString CourseElement::result() const
{
    return m_result;
}

void CourseElement::setResult(const QString &result)
{
    m_result = result;
}

QString CourseElement::dateEnd() const
{
    return m_dateEnd;
}

void CourseElement::setDateEnd(const QString &dateEnd)
{
    m_dateEnd = dateEnd;
}
