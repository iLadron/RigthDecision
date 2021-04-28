#include "database.h"

QString Database::registerUser(User newUser)
{
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

    return "true";
}

bool Database::isUserExist(User user)
{

}

Database::Database()
{
    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setDatabaseName("DIPLOM");
    m_db.setUserName("admin");
    m_db.setHostName("localhost");
    m_db.setPassword("adminspassword1A!");

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
