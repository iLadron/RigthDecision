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
    QString avatar;

};

class DATABASE_EXPORT Database
{
public:
    //For users functions
    QString registerUser(User newUser);
    QString loginUser(User user);
    bool isUserExist(User user);
    bool isEmailExist(User user);
    static void logout();


    //Class functions
    static Database* GetInstance();
    static User* getLoginedUser();

protected:
    Database();
    static Database *database_;
    QSqlDatabase m_db;

private:

    static User *m_loginedUser;
};

#endif // DATABASE_H
