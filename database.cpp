#include "database.h"

database::database()
{

}

QSqlDatabase database::getDatabase()
{

    QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("gjarzebak");
    database.setPassword("Q!w2e3r4t5y6");
    database.setDatabaseName("qt5");

    return database;


}
