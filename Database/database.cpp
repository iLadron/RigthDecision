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
    QString strReg = "INSERT INTO Users(id, name, surname, login, email, password) "
                     "VALUES(NULL, '%1', '%2', '%3', '%4', '%5') ";
    str = strReg.arg(newUser.name)
            .arg(newUser.surname)
            .arg(newUser.login)
            .arg(newUser.email)
            .arg(newUser.password);

    if(!query.exec(str)){
        qDebug()<<"Error reg user";
    }

    return "";
}

QString Database::loginUser(User user)
{
    if(!isUserExist(user)){
        return /*tr*/("Логин не зарегестрирован");
    }

    QSqlQuery query;
    QString str;
    QString strLog = "SELECT * FROM Users WHERE login = '%1' AND password = '%2'";
    str = strLog.arg(user.login).arg(user.password);
    query.exec(str);
    if(query.size() == 0){
        return /*tr*/("Неверный пароль");
    }

    QSqlRecord rec = query.record();
    query.next();

    if(m_loginedUser == nullptr){
        m_loginedUser = new User();
    }

    m_loginedUser->id = query.value(rec.indexOf("id")).toInt();
    m_loginedUser->email = query.value(rec.indexOf("email")).toString();
    m_loginedUser->login = query.value(rec.indexOf("login")).toString();
    m_loginedUser->name = query.value(rec.indexOf("name")).toString();
    m_loginedUser->password = query.value(rec.indexOf("password")).toString();
    m_loginedUser->surname = query.value(rec.indexOf("surname")).toString();

    return QString::number(query.value(rec.indexOf("id")).toInt());

}

bool Database::isUserExist(User user)
{

    QSqlQuery query;
    QString res;
    QString strCommand = "SELECT * FROM Users WHERE login = '%1'";
    res = strCommand.arg(user.login);
    query.clear();
    query.exec(res);
    return query.size() != 0;
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

void Database::logout()
{
    m_loginedUser = nullptr;
}

User Database::getUserById(int id)
{
    QSqlQuery query;
    QString res;
    QString strCommand = "SELECT * FROM Users WHERE id = '%1'";
    res = strCommand.arg(id);
    query.exec(res);

    QSqlRecord rec = query.record();
    query.next();

    User resUser;

    resUser.id = query.value(rec.indexOf("id")).toInt();
    resUser.email = query.value(rec.indexOf("email")).toString();
    resUser.login = query.value(rec.indexOf("login")).toString();
    resUser.name = query.value(rec.indexOf("name")).toString();
    resUser.password = query.value(rec.indexOf("password")).toString();
    resUser.surname = query.value(rec.indexOf("surname")).toString();

    return resUser;
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
}

Database* Database::database_ = nullptr;
User* Database::m_loginedUser = nullptr;

Database *Database::GetInstance()
{
    if(database_ == nullptr){
        database_ = new Database();        
    }
    return database_;
}

User *Database::getLoginedUser()
{
    return m_loginedUser;
}

QSqlQuery Database::getInProgressCourses()
{
    QSqlQuery query;
    QString res;
    QString strCommand = "SELECT * FROM Course c join UserHasCourse uha on c.id = uha.idCourse WHERE uha.idUser = '%1'";
    res = strCommand.arg(m_loginedUser->id);
    query.exec(res);
    return query;
}

QSqlQuery Database::getCreatedCourses()
{
    QSqlQuery query;
    QString res;
    QString strCommand = "SELECT * FROM Course WHERE idAuthor = '%1'";
    res = strCommand.arg(m_loginedUser->id);
    query.exec(res);
    return query;
}

QSqlQuery Database::getTestsByCourseId(int id)
{
    QSqlQuery query;
    QString res;
    QString strCommand = "SELECT * FROM Test WHERE idCourse = '%1'";
    res = strCommand.arg(id);
    query.exec(res);
    return query;
}

QSqlQuery Database::getTheoryByCourseId(int id)
{
    QSqlQuery query;
    QString res;
    QString strCommand = "SELECT * FROM Theory WHERE idCourse = '%1'";
    res = strCommand.arg(id);
    query.exec(res);
    return query;
}

void Database::saveTestResults(int idCoure, QString answer)
{
    QSqlQuery query;
    QString str;
    QString strReg = "update UserHasCourse set marks = '%1' WHERE idUser = '%2' AND idCourse = '%3'";

    str = strReg.arg(answer).arg(m_loginedUser->id).arg(idCoure);
    query.exec(str);

}

void Database::saveTheoryResults(int idCoure, QString answer)
{
    QSqlQuery query;
    QString str;
    QString strReg = "update UserHasCourse set theoryRead = '%1' WHERE idUser = '%2' AND idCourse = '%3'";

    str = strReg.arg(answer).arg(m_loginedUser->id).arg(idCoure);
    query.exec(str);
}

void Database::saveCourse(int idCourse,QStringList tests, QStringList theories)
{
    QSqlQuery query;
    QString str;
    QString strReg = "delete from Test WHERE idCourse = '%1'; delete from Theory WHERE idCourse = '%1'";

    str = strReg.arg(idCourse);
    query.exec(str);



    QString testValues="";
    QString theoryValues="";

    for(int i = 0; i < tests.size();i++){
        testValues+=tests[i] + ',';
    }

    testValues[testValues.size()-1] = ';';

    for(int i = 0; i < theories.size();i++){
        theoryValues+=theories[i] + ",";
    }
    theoryValues[theoryValues.size()-1] = ';';

    QSqlQuery query2;
    QString strReg2 = "INSERT INTO Test(id, name,questions,answers, rightAnswerNumbers,timeToComplete,idCourse) VALUES " + testValues;

    query2.exec(strReg2);


    QSqlQuery query3;
    QString strReg3 = "INSERT INTO Theory(id,name,text, Result,idCourse) VALUES " + theoryValues;

    query3.exec(strReg3);


}

QSqlQuery Database::getCourseInfoByCourseId(int id)
{
    QSqlQuery query;
    QString res;
    QString strCommand = "SELECT * FROM UserHasCourse WHERE idCourse = '%1' AND idUser = '%2'";
    res = strCommand.arg(id).arg(m_loginedUser->id);
    query.exec(res);
    return query;
}
