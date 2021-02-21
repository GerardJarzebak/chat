#include "user.h"
#include <QtWidgets/QMessageBox>
#include <QTextStream>

user::user()
{

}

user::user(int userid,QString username,QString userpassword,QString useremail,QPixmap useravatar,QStringList fl)
{
    this->avatar = useravatar;
    this->userID = userid;
    this->username = username;
    this->password = userpassword;
    this->email = useremail;


    for (QString number : fl)
    {
        QTextStream out(stdout);


        this->friendsIdList.append(number.toInt());

    }

    QSqlQuery query(QSqlDatabase::database("My Connect"));

    for (int x : this->friendsIdList)
    {
        query.prepare(QString("SELECT username FROM users WHERE id = :x"));
        query.bindValue(":x",x);
        query.exec();

        while(query.next())
        {
        QString friendusername = query.value(0).toString();
        this->friendUsernames.append(friendusername);
        }
    }
}

QVector<int>& user::getFriendsIdList()
{
    return this->friendsIdList;
}

QString user::getPassword()
{

    return this->password;
}

QString user::getUsername()
{
    return this->username;
}

void user::setAvatar(QPixmap avatar)
{
    this->avatar = avatar;
}

void user::setFriendsList(QVector<int> friends)
{
    this->friendsIdList = friends;
}

QPixmap user::getAvatar()
{
    return this->avatar;
}

QStringList& user::getFriendsList()
{
    return this->friendUsernames;
}
QString user::getEmail()
{
    return this->email;
}
int user::getUserID()
{
    return this->userID;
}
QString user::getFriendsListAsString()
{

    QString x;

    for (int s : this->getFriendsIdList() )
    {

        x.append(QString::number(s));
        x.append(",");

    }
    x.chop(1);

    return x;
}
