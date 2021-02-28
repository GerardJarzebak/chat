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


/**
 * @brief
 *
 */
class user
{
public:
    /**
     * @brief
     *
     */
    user();
    /**
     * @brief
     *
     * @param userid
     * @param username
     * @param userpassword
     * @param useremail
     * @param useravatar
     * @param fl
     */
    user(int userid,QString username,QString userpassword,QString useremail,QPixmap useravatar,QStringList fl);

private:
   int userID;        // Attribute (int variable) /**< TODO: describe */
   QString username; /**< TODO: describe */
   QString password; /**< TODO: describe */
   QString email; /**< TODO: describe */
   QPixmap avatar; /**< TODO: describe */
   QStringList friendUsernames; /**< TODO: describe */
   QVector<int> friendsIdList; /**< TODO: describe */

public:
   /**
    * @brief
    *
    */
   void displayFriends();

   /**
    * @brief
    *
    * @param password
    */
   void setUsername(QString password);
   /**
    * @brief
    *
    * @param password
    */
   void setPassword(QString password);
   /**
    * @brief
    *
    * @param userid
    */
   void setUserID(int userid);
   /**
    * @brief
    *
    * @param avatar
    */
   void setAvatar(QPixmap avatar);
   /**
    * @brief
    *
    * @param friends
    */
   void setFriendsList(QVector<int> friends);
   /**
    * @brief
    *
    * @return int
    */
   int getUserID();



   /**
    * @brief
    *
    * @return QString
    */
   QString getUsername();
   /**
    * @brief
    *
    * @return QString
    */
   QString getEmail();
   /**
    * @brief
    *
    * @return QString
    */
   QString getPassword();
   /**
    * @brief
    *
    * @return QPixmap
    */
   QPixmap getAvatar();

   /**
    * @brief
    *
    * @return QVector<int>
    */
   QVector<int>& getFriendsIdList();
   /**
    * @brief
    *
    * @return QStringList
    */
   QStringList& getFriendsList();
   /**
    * @brief
    *
    * @return QString
    */
   QString getFriendsListAsString();

};

#endif // USER_H
