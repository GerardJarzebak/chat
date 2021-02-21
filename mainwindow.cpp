#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <user.h>
#include <QtCore/QDateTime>
#include <QtMqtt/QMqttClient>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QInputDialog>
#include <QFontDatabase>
#include <QListWidget>
#include <QListWidgetItem>
#include <QFileDialog>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)


{
    ui->setupUi(this);
    this->setEmojiList();
    this->setFixedSize(1280,720);

    m_client = new QMqttClient(this);




    m_client->setHostname("localhost");
    m_client->setPort(1883);

    connect(m_client, &QMqttClient::stateChanged, this, &MainWindow::updateLogStateChange);
    connect(m_client, &QMqttClient::disconnected, this, &MainWindow::brokerDisconnected);

    connect(m_client, &QMqttClient::messageReceived, this, [this](const QByteArray &message, const QMqttTopicName &topic) {
        const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(" Received Topic: ")
                    + topic.name()
                    + QLatin1String(" Message: ")
                    + message
                    + QLatin1Char('\n');
        ui->editLog->insertPlainText(content);
    });

    connect(m_client, &QMqttClient::pingResponseReceived, this, [this]() {
        const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(" PingResponse")
                    + QLatin1Char('\n');
        ui->editLog->insertPlainText(content);
    });

    //connect(ui->lineEditHost, &QLineEdit::textChanged, m_client, &QMqttClient::setHostname);
    //connect(ui->spinBoxPort, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::setClientPort);


    updateLogStateChange();
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::setUser(user * user)
{
    this->u = user;
}
 user* MainWindow::getUser()
 {
     return this->u;
 }

 void MainWindow::on_quitButton_clicked()
 {
     QApplication::quit();
 }

void MainWindow::updateLogStateChange()
{
    const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(": State Change")
                    + QString::number(m_client->state())
                    + QLatin1Char('\n');
    ui->editLog->insertPlainText(content);
}



void MainWindow::setClientPort(int p)
{
    m_client->setPort(p);
}

void MainWindow::brokerDisconnected()
{
  //  ui->lineEditHost->setEnabled(true);
  //  ui->spinBoxPort->setEnabled(true);
    //ui->buttonConnect->setText(tr("Connect"));
}







void MainWindow::connectToTopic()
{
    if (m_client->state() == QMqttClient::Disconnected) {

        m_client->connectToHost();
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Im in connected to host"));
    } else {

        m_client->disconnectFromHost();
    }
}

void MainWindow::subcribe()
{
    auto subscription = m_client->subscribe(this->currenttopic->getTopicName());
    if (!subscription) {
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
        return;
    }
}




void MainWindow::on_changeAvatarButton_clicked() {
  //allow to attach the new avatar file + Ok/Cancel buttons

  //QSqlQuery query(QSqlDatabase::database("My Connect"));

  //query.prepare(QString("SELECT * FROM users WHERE username = :username AND password = :password"));

  QString filename = QFileDialog::getOpenFileName(this, "Please select your new avatar", "path/home/", "Image Files (*.jpg *.jpeg *.png");

  if (QString::compare(filename, QString()) != 0) {

    QMessageBox::information(this, "New avatar selected : ", filename);
    this -> getUI() -> avatarLabel -> setPixmap(filename);
    this -> getUser() -> setAvatar(filename);
    QSqlQuery query(QSqlDatabase::database("My Connect"));

    //Converting our Pixmap to byte array
    QByteArray bArray;
    QBuffer buffer( & bArray);
    buffer.open(QIODevice::WriteOnly);
    this -> getUser() -> getAvatar().save( & buffer, "PNG");

    if (bArray.isEmpty()) {
      QMessageBox::information(this, "FAILURE", "THE IMAGE SEEMS TO BE EMPTY");
    } else {
      QMessageBox::information(this, "SUCCESS", "IMAGE UPLOADED TO THE DATABASE");
      QSqlQuery query(QSqlDatabase::database("QMYSQL"));
      query.prepare("UPDATE users SET avatar = :avatar WHERE id = :id");
      query.bindValue(":id", this -> getUser() -> getUserID());
      query.bindValue(":avatar", bArray, QSql::In | QSql::Binary);

      query.exec();
    }

  } else {
    QMessageBox::information(this, "FAILURE", "NO VALID FILE SELECTED");
  }

}












void MainWindow::on_sendButton_clicked()
{
    if (m_client->publish(this->currenttopic->getTopicName(), ui->lineEditMessage->text().toUtf8()) == -1)
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));

}


Ui::MainWindow * MainWindow::getUI()
{
    return this->ui;
}

void MainWindow::setEmojiList()
{

    this->getUI()->emojiList->setFlow(QListView::LeftToRight);


    QStringList *qsl = new QStringList;

    qsl->append("👍");
    qsl->append("👍");
    qsl->append("👎");
    qsl->append("💪");
    qsl->append("😂");
    qsl->append("🙂");
    qsl->append("😞");
    qsl->append("🥳");
    qsl->append("😂");
    qsl->append("🙏");
    qsl->append("😎");
    qsl->append("😴");
    qsl->append("😡");
    qsl->append("😭");
    qsl->append("🧐");
    qsl->append("😎");
    qsl->append("😞");
    qsl->append("😖");
    qsl->append("😤");
    qsl->append("🤕");
    qsl->append("😲");
    qsl->append("🤫");
    qsl->append("🥺");
    qsl->append("😍");
    qsl->append("😁"); 
    qsl->append("🥊");
    qsl->append("🏆");
    qsl->append("🎮");
    qsl->append("🍷");
    qsl->append("🍽");
    qsl->append("🍻");
    qsl->append("👑");




    for (int i=0; i<qsl->length(); i++)
       {
        //QListWidgetItem *qlwi = new QListWidgetItem;
        //qlwi->setText(qsl->at(i));
        this->getUI()->emojiList->addItem(qsl->at(i));
       }





}


void MainWindow::on_RemoveFriendButton_clicked()
{
    //Removes friend from the list and also removes him from the database too
    //mw->getUI()->friendsList->addItem(friendusername);}

    //What needs to be done is remove selected element from that list + remove him from the list of logged user's usernames + do an sql query and edit the string

    //this->getUI()->friendsList->removeItemWidget();
    QInputDialog * id = new QInputDialog();
    QString userInput = id->getText(this,"Remove your friend","Please enter the name of the friend you want to remove");


    if(this->getUser()->getFriendsList().contains(userInput))
    {
        QSqlQuery query(QSqlDatabase::database("QMYSQL"));
        query.prepare("SELECT * from users where username = :userInput");
        query.bindValue(":userInput",userInput);



                 if (query.exec()) {
                     while (query.next()) {
                       int idFromDB = query.value(0).toInt();
                       QString usernameFromDB = query.value(1).toString();

//where the 0 comes from
                       //why no change

                     if (usernameFromDB == userInput) {

                         this->getUser()->getFriendsIdList().removeOne(idFromDB);
                         this->getUser()->getFriendsList().removeOne(usernameFromDB);

                         QString newFriendsListForDB = this->getUser()->getFriendsListAsString();


                         query.prepare("UPDATE users SET friendsList = :friendsList WHERE id = :userid");
                         query.bindValue(":userid",this->getUser()->getUserID());
                         query.bindValue(":friendsList",newFriendsListForDB);


                         if (query.exec()) {
                             qDeleteAll(this->getUI()->friendsList->findItems((usernameFromDB), Qt::MatchFixedString));

                             QMessageBox::information(this, "Success", "Person removed from your friends list!!");
                             break;

                         } else {

                           QMessageBox::information(this, "FAILURE", "Could not remove this person from your list");
                         }


                     }else {
                         QMessageBox::information(this, "Failed", "Problem accessing the database");
                       }


                     }



                 } else {

                   QMessageBox::information(this, "FAILURE", "QUERY NOT EXECUTED PROPERLY");
                 }
    }
    else
    {
        QMessageBox::information(this, "Success", "This user was on your friends list!");
    }





    //this->getUI()->friendsList->findItems(userInput,)


   // qDeleteAll(this->getUI()->friendsList->findItems(userInput,QT::QStringMatcher));

    //this->getUI()->friendsList.get
    //this->getUI()->friendsList



}





void MainWindow::setUser2(user * user)
{
    this->u2 = user;
}


user* MainWindow::getUser2()
{
    return this->u2;
}


void MainWindow::setADW( editaccountdetailswindow * adw)
{

    this->adw = adw;

}


editaccountdetailswindow * MainWindow::getADW()
{
    return this->adw;
}




void MainWindow::on_attachFileButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Please elect file to attach","path/home/");
    QMessageBox::information(this,"Selected : ",filename);
}


void MainWindow::on_accountDetailsButton_clicked()
{
    editaccountdetailswindow * adw = new editaccountdetailswindow(this,this->getUser());


    this->setADW(adw);

    adw->show();

}










void MainWindow::on_emojiList_itemClicked(QListWidgetItem *item)
{
  QString x = item->text();
  this->getUI()->lineEditMessage->insert(x);
}

void MainWindow::on_friendsList_itemDoubleClicked(QListWidgetItem *item)
{
    QString x = item->text();

    user * newSelectedUser = this->getUserFromDB(x);



    this->setUser2(newSelectedUser);
    this->getUI()->selectedUser->setText(newSelectedUser->getUsername());
    this->setTopic();
    this->getUI()->topicName->setText(this->currenttopic->getTopicName());
}


void MainWindow::setTopic()
{

    QString t;

     if (this->getUser()->getUserID() > this->getUser2()->getUserID()){

         t = this->getUser()->getUsername() + "TO" + this->getUser2()->getUsername() ;
     }else {

        t = this->getUser2()->getUsername() + "TO" + this->getUser()->getUsername() ;
     }



    this->currenttopic = new topic(t);




}





user * MainWindow::getUserFromDB(QString username) {


    QSqlQuery query(QSqlDatabase::database("QMYSQL"));
  query.prepare("SELECT * from users where username = :username");
  query.bindValue(":username", username);\

  user * returnedUser = NULL;

  if (query.exec()) {
    while (query.next()) {

      QString usernameFromDB = query.value(1).toString();

      if (usernameFromDB == username) {

        int idFromDB = query.value(0).toInt();
        QString passwordFromDB = query.value(2).toString();
        QString emailFromDb = query.value(3).toString();
        QString avatarFromDb = query.value(4).toString();

        QStringList flFromDb = query.value(5).toString().split(",");

        QByteArray imageFromDB = query.value(4).toByteArray();
        QPixmap userAvatarFromDB = QPixmap();
        userAvatarFromDB.loadFromData(imageFromDB);

        returnedUser = new user(idFromDB, usernameFromDB, passwordFromDB, emailFromDb, avatarFromDb, flFromDb);
        return returnedUser;

        break;

      } else {


        return  returnedUser;

      }

    }

  } else {

      return  returnedUser;

  }
}

void MainWindow::on_addFriendButton_clicked() //check if user already on the friends list
{
  //Add to the query and add to the list and save query to the database
  QInputDialog * id = new QInputDialog();
  QString userInput = id -> getText(this, "Add Your Friend", "Please enter your friend's username");

  user * newFriend = this -> getUserFromDB(userInput);


  if (newFriend != NULL)
  {
    this->setUser2(newFriend);
    //Append the friends list for the first user

    this->getUser()->getFriendsIdList().append(this -> getUser2() -> getUserID());
    QString newFriendsListForDB = this -> getUser() -> getFriendsListAsString();


    QSqlQuery query(QSqlDatabase::database("QMYSQL"));
    query.prepare("UPDATE users SET friendsList = :friendsList WHERE id = :userid");
    query.bindValue(":userid", this -> getUser() -> getUserID());
    query.bindValue(":friendsList", newFriendsListForDB);

    if (query.exec()) {
      this -> getUI() -> friendsList -> addItem(this -> getUser2() -> getUsername());
      this -> getUser() -> getFriendsList().append(this -> getUser2() -> getUsername());
      this -> getUser() -> getFriendsIdList().append(this -> getUser2() -> getUserID());
      QMessageBox::information(this, "Success", "Added a new friend to your list!");

    } else {

      QMessageBox::information(this, "FAILURE", "Could not add this friend to your list");
    }

  } else {
    QMessageBox::information(this, "Failed", "No such person in the database");
  }

}


void MainWindow::on_searchButton_clicked()
{
    QString lookedUpUsername = ui->friendSearchBar->text();


    if(!lookedUpUsername.isEmpty()){

    user * searcheduser = this->getUserFromDB(lookedUpUsername);

    if(searcheduser != NULL)
    {
      this->setUser2(searcheduser);
      this->setTopic();
      this->getUI()->selectedUser->setText(searcheduser->getUsername());
      this->getUI()->topicName->setText(this->currenttopic->getTopicName());


    } else{

        QMessageBox::information(this, "Failed", "User not found in the database");
    }}
    else{
        QMessageBox::information(this, "Failed", "Please input the username first");
    }




}





void MainWindow::on_buttonConnect_clicked()
{
    if(!this->getUI()->topicName->text().isEmpty())
    {


        if (m_client->state() == QMqttClient::Disconnected) {

            m_client->connectToHost();
        } else {
            this->getUI()->buttonConnect->setText("Connect");
            m_client->disconnectFromHost();
        }



    }else
    {
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Please select the user before trying to connect to the topic "));
    }
}

void MainWindow::on_buttonSubscribe_clicked()
{
    if(!this->getUI()->topicName->text().isEmpty())
    {



        auto subscription = m_client->subscribe(this->currenttopic->getTopicName());
        if (!subscription) {
            QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
            return;
        }


    }else
    {
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Please select the user before trying to subscribe to the topic "));
    }
}
