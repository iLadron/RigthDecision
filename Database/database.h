#ifndef DATABASE_H
#define DATABASE_H

#include "Database_global.h"
#include <QString>
#include <QtSql>


struct User{
    int id = -1;
    QString name;
    QString surname;
    QString login;
    QString email;
    QString password;

};

/*
struct db_Test{
    int id;
    QString name;
    QString questions;
    QString answers;
    QString rightAnswerNumbers;
    int daysToComplete;
};

*/

class DATABASE_EXPORT Database
{
public:
    //For users functions
    QString registerUser(User newUser);
    QString loginUser(User user);
    bool isUserExist(User user);
    bool isEmailExist(User user);
    static void logout();

    static User getUserById(int id);


    //Class functions
    static Database* GetInstance();
    static User* getLoginedUser();

    //function for Course Model
    static QSqlQuery getInProgressCourses();
    static QSqlQuery getCreatedCourses();

    static QSqlQuery getTestsByCourseId(int id);
    static QSqlQuery getTheoryByCourseId(int id);

    static void saveTestResults(int idCoure, QString answer);


    static QSqlQuery getCourseInfoByCourseId(int id);


protected:
    Database();
    static Database *database_;
    QSqlDatabase m_db;

private:

    static User *m_loginedUser;
};

#endif // DATABASE_H
