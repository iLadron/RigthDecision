#include "theorymodel.h"

TheoryModel::TheoryModel()
{

}

TheoryModel::TheoryModel(const TheoryModel &theory)
{
    setName(theory.name());
    setType(theory.type());
    setDateEnd(theory.dateEnd());
    setResult(theory.result());
    setTheory(theory.theory());
}

TheoryModel &TheoryModel::operator=(const TheoryModel &theory)
{
    return *this;
}

QString TheoryModel::theory() const
{
    return m_theory;
}

void TheoryModel::learned()
{
    setResult("Пройдена");
    emit learnedSignal();
}

int TheoryModel::id() const
{
    return m_id;
}

void TheoryModel::setId(int id)
{
    m_id = id;
}

void TheoryModel::setTheory(const QString &theory)
{
    m_theory = theory;
}
