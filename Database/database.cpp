#include "database.h"

QString Database::registerUser(User newUser)
{
    if(isUserExist(newUser)){
        return /*tr*/("Логин уже зарегестрирован");
    }

    if(isEmailExist(newUser)){
        return /*tr*/("Потча уже зарегестрирована");
    }
    QSqlQuery query;
    QString str;
    QString strReg = "INSERT INTO Users(id, name, surname, login, email, password, avatar) "
                     "VALUES(NULL, '%1', '%2', '%3', '%4', '%5', '%6') ";
    str = strReg.arg(newUser.name)
            .arg(newUser.surname)
            .arg(newUser.login)
            .arg(newUser.email)
            .arg(newUser.password)
            .arg(newUser.avatar);

    if(!query.exec(str)){
        qDebug()<<"Error reg user";
    }

    return "";
}

bool Database::isUserExist(User user)
{
    QSqlQuery query;
    QString res;
    QString strCommand = "SELECT * FROM Users WHERE login = '%1'";
    res = strCommand.arg(user.login);
    query.exec(res);
    return query.size();
}

bool Database::isEmailExist(User user)
{
    QSqlQuery query;
    QString res;
    QString strCommand = "SELECT * FROM Users WHERE email = '%1'";
    res = strCommand.arg(user.email);
    query.exec(res);
    return query.size();
}


Database::Database()
{
    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setDatabaseName("6Zfmd53HCv");
    m_db.setUserName("6Zfmd53HCv");
    m_db.setHostName("remotemysql.com");
    m_db.setPassword("K2Xf5L3JT8");

    if(!m_db.open()){
        qDebug()<<"Error. Can't open database";
        qDebug()<<m_db.lastError();
    }

    QStringList s = m_db.tables();

    foreach(QString str, s){
        qDebug()<<"Table " <<str;
    }
}

Database* Database::database_ = nullptr;

Database *Database::GetInstance()
{
    if(database_ == nullptr){
        database_ = new Database();
    }
    return database_;
}
