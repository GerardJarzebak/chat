#ifndef USER_H
#define USER_H
#include <string>
#include <QString>
#include <cstring>
#include <iostream>
#include <list>
#include <QPixmap>
#include <QPicture>
#include "QtSql"
#include <QtWidgets/QMessageBox>
using namespace std;


class user
{
public:
    user();
    user(int userid,QString username,QString userpassword,QString useremail,QPixmap useravatar,QStringList fl);

private:
   int userID;        // Attribute (int variable)
   QString username;
   QString password;
   QString email;
   QPixmap avatar;
   QStringList friendUsernames;
   QVector<int> friendsIdList;

public:
   void displayFriends();

   void setUsername(QString password);
   void setPassword(QString password);
   void setUserID(int userid);
   void setAvatar(QPixmap avatar);
   void setFriendsList(QVector<int> friends);
   int getUserID();



   QString getUsername();
   QString getEmail();
   QString getPassword();
   QPixmap getAvatar();

   QVector<int>& getFriendsIdList();
   QStringList& getFriendsList();
   QString getFriendsListAsString();

};

#endif // USER_H
