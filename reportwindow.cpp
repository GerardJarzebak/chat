#include "reportwindow.h"
#include "ui_reportwindow.h"
#include <QSql>
#include <QStringList>

reportwindow::reportwindow(QWidget *parent,user * u,topic * t) :
    QWidget(parent),
    ui(new Ui::reportwindow)
{
    ui->setupUi(this);
    this->setFixedSize(1280,720);
    this->u = u;
    this->t = t;


   ui->usernameValueLabel->setText(u->getUsername());
   ui->numberOfFriendsLabel->setNum(u->getFriendsList().count());





   QSqlQuery query(QSqlDatabase::database("QMYSQL"));
   query.prepare("SELECT * from topics where topicname = :topicname order by id asc");
   query.bindValue(":topicname",t->getTopicName());



    if (query.exec()) {





        QString allMessages = "";
        int messageCounter = 0;
        while (query.next()) {
             allMessages.append(query.value(4).toString());

        }
        for(QString s : allMessages.split(","))
        {
            messageCounter++;
        }   ui->numberOfMessagesSentLabel->setNum(messageCounter);

    }else{
        QMessageBox::information(this, "Query didnt execute", "Couldnt get information about amount of users");
        ui->numberOfAppUsersLabel->setText("Not available");
    }







   query.prepare("SELECT COUNT(id) from users");

    if (query.exec()) {
        while (query.next()) {
        //ui->numberOfAppUsersLabel->setText(query.value(0).toString());
        ui->numberOfAppUsersLabel->setNum(query.value(0).toInt());
        }

    }else{
        QMessageBox::information(this, "Query didnt execute", "Couldnt get information about amount of users");
        ui->numberOfAppUsersLabel->setText("Not available");
    }



    ui->numberOfFilesSharedLabel->setText("Temporarly not available");

    QString firstDate;
    query.prepare("SELECT messagedates from topics where topicname = :topicname order by id asc");
    query.bindValue(":topicname",t->getTopicName());

    if (query.exec()) {
        while (query.next()) {
        firstDate = query.value(5).toString();
        break;
        }

    }else{
        QMessageBox::information(this, "Query didnt execute", "Couldnt get information about first message");
        ui->firstMessageSentOnLabel->setText("Not available");
    }
    QStringList firstDates = firstDate.split(",");

    ui->firstMessageSentOnLabel->setText(firstDates.at(0));







}

reportwindow::~reportwindow()
{
    delete ui;
}

void reportwindow::on_backToMainWindowButton_clicked()
{
    this->close();
}

void reportwindow::setUser(user * user)
{
    this->u = user;
}
user* reportwindow::getUser()
{
    return this->u;
}
