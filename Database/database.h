#ifndef DATABASE_H
#define DATABASE_H

#include "Database_global.h"
#include <QString>
#include <QtSql>


struct User{
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
    bool isUserExist(User user);
    bool isEmailExist(User user);



    //Class functions
    static Database* GetInstance();

protected:
    Database();
    static Database *database_;
    QSqlDatabase m_db;

private:
};

#endif // DATABASE_H
