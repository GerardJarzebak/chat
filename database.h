#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QSqlDatabase>

class database
{
public:
    database();
    QSqlDatabase getDatabase();
};

#endif // DATABASE_H
