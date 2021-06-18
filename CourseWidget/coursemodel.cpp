#include "coursemodel.h"

CourseModel::CourseModel()
{
}

CourseModel::CourseModel(const CourseModel &model)
{
    /*
     *    std::vector<CourseEl> m_elements;
    std::vector<Test> m_tests;
    QString m_name;
    QString m_author;
    QString m_description;
     * */

    for(size_t i = 0; i < model.m_elements.size(); i++){
        m_elements.push_back(model.m_elements[i]);
    }

    setName(model.name());
    setAuthorName(model.authorName());
    setDescription(model.description());

    m_author = model.m_author;
    m_description = model.m_description;
    m_rating = model.m_rating;
    m_courseId = model.m_courseId;

}

QHash<int, QByteArray> CourseModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    enum courseElRole{
        TypeRole = Qt::UserRole + 1,
        NameRole,
        ResultRole,
        DateEndRole
    };
    roles[TypeRole] = "Type";
    roles[NameRole] = "Name";
    roles[ResultRole] = "Result";
    roles[DateEndRole] = "DateEnd";
    return roles;
}

int CourseModel::rowCount(const QModelIndex &parent) const
{
    return m_elements.size();
}

int CourseModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant CourseModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    CourseElement element = m_elements.at(index.row());

    switch (role) {
    case TypeRole:
        return element.type();
        break;
    case NameRole:
        return element.name();
        break;
    case ResultRole:
        return element.result();
        break;
    case DateEndRole:
        return element.dateEnd();
        break;
    default:
        return QVariant();
    }

}

void CourseModel::addElement(CourseElement element)
{
    m_elements.push_back(element);
}

void CourseModel::addTest(const QString &question, const QStringList &answers, int rightAnswer)
{
    m_tempTest.addQuestion(question, answers, rightAnswer);
}

void CourseModel::setData(const QString &name, const User& author, const QString &description, int rating)
{
    m_name = name;
    m_author = author;
    m_description = description;
    m_rating = rating;
}

CourseElement* CourseModel::getElementByIndex(int index)
{
    return &m_elements[index];
}

QString CourseModel::name() const
{
    return m_name;
}

QString CourseModel::description() const
{
    return m_description;
}

bool CourseModel::isCreator() const
{
    return m_isCreator;
}

QString CourseModel::authorName() const
{
    return m_author.name;
}

QString CourseModel::getData()
{
    return m_name + ";" + m_author.name + ";" + m_description;
}

void CourseModel::setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(m_name);
}

void CourseModel::setDescription(QString description)
{
    if (m_description == description)
        return;

    m_description = description;
    emit descriptionChanged(m_description);
}

void CourseModel::setIsCreator(bool isCreator)
{
    if (m_isCreator == isCreator)
        return;

    m_isCreator = isCreator;
    emit isCreatorChanged(m_isCreator);
}

void CourseModel::setAuthorName(QString authorName)
{
    if (m_authorName == authorName)
        return;

    m_authorName = authorName;
    emit authorNameChanged(m_authorName);
}

