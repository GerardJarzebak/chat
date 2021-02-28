#include "searchresultswindow.h"
#include "ui_searchresultswindow.h"
#include <QInputDialog>
#include <QSqlQuery>
#include <QtCore/QDateTime>

searchresultswindow::searchresultswindow(QWidget *parent,user * u,topic * t ,QString searchedMessage) :
    QDialog(parent),
    ui(new Ui::searchresultswindow)
{

    ui->setupUi(this);
    this->setFixedSize(1280,720);
    this->t = t;
    this->u = u;
    this->searchedMessage = searchedMessage;
    this->getUI()->searchedMessageLabel->setText(searchedMessage);
    this->ui->listOfSearchedMessages->clear();




      QString mh = this->t->getMessageHistoryAsString();

        for(QString s : mh.split(","))
        {

            if(s.contains(searchedMessage,Qt::CaseInsensitive))
            {
              this->ui->listOfSearchedMessages->addItem(s);
            }
        }

        mh = this->t->getPastMessageHistoryAsString();

        for(QString s : mh.split(","))
        {

            if(s.contains(searchedMessage,Qt::CaseInsensitive))
            {
              this->ui->listOfSearchedMessages->addItem(s);
            }
        }





}

searchresultswindow::~searchresultswindow()
{
    delete ui;
}


topic * searchresultswindow::getTopic()
{
    return this->t;
}



void searchresultswindow::setTopic(topic * t)
{
    this->t = t;
}

QString searchresultswindow::getSearchedMessage()
{
    return this->searchedMessage;
}



void searchresultswindow::setSearchedMessage(QString sm)
{
    this->searchedMessage = sm;
}

void searchresultswindow::on_backToMainWindow_clicked()
{
    this->ui->listOfSearchedMessages->clear();
    this->close();
}
Ui::searchresultswindow * searchresultswindow::getUI()
{
    return this->ui;
}

void searchresultswindow::on_listOfSearchedMessages_itemDoubleClicked(QListWidgetItem *item)
{

}

void searchresultswindow::on_viewMessageButton_clicked()
{
    QString selectedMessage = this->getUI()->listOfSearchedMessages->currentItem()->text();
    QMessageBox::information(this, "Displaying selected message", selectedMessage);
}

user * searchresultswindow::getUser()
{
    return this->u;
}

void searchresultswindow::on_editMessageButton_clicked()
{

    if(this->getUI()->listOfSearchedMessages->currentItem() != nullptr){
           QString selectedMessage = this->getUI()->listOfSearchedMessages->currentItem()->text();
           QInputDialog * id = new QInputDialog();
           QString userInput = id -> getText(this, "Editing highlighted message", "Please edit the message and press ok to save it");
           userInput = this->getUser()->getUsername() + QLatin1String(": ") + QLatin1String(": ") + userInput + QLatin1String(" - ") + QDateTime::currentDateTime().toString() + QLatin1Char('\n');


           this->getUI()->listOfSearchedMessages->currentItem()->setText(userInput);
           QString newMessageHistory = this->getTopic()->getPastMessageHistoryAsString().append(this->getTopic()->getMessageHistoryAsString());

           //this->getTopic()->getMessageHistoryAsString().replace(selectedMessage,userInput);
           //this->getTopic()->getMessageHistory() = this->getTopic()->getPastMessageHistoryAsString().split(",");

           newMessageHistory.replace(selectedMessage,userInput);

           QSqlQuery query(QSqlDatabase::database("QMYSQL"));
           query.prepare("UPDATE topics SET topicmessages = :topicmessages WHERE topicname = :topicname");
           query.bindValue(":topicmessages",newMessageHistory);
           query.bindValue(":topicname",this->getTopic()->getTopicName());


           if(query.exec())
           {
               QMessageBox::information(this,"Success","Message updated succesfully");


           }else{
               QMessageBox::information(this,"Failure","Problem when executing the query");
           }






}


    else
    {
        QMessageBox::information(this, "No message highlighted", "Please highlight the message you would like to edit");
    }


}


void searchresultswindow::saveEditsToDB()
{
    if(!this->getTopic()->getTopicName().isEmpty())
    {
              QSqlQuery query(QSqlDatabase::database("QMYSQL"));

              query.prepare("INSERT INTO topics (topicname,user1,user2,topicmessages,messagedates)"
                          "VALUES (:topicname,:user1,:user2,:topicmessages,:messagedates)");

              query.bindValue(":topicname",this->getTopic()->getTopicName());
              query.bindValue(":user1",this->getTopic()->getUsername1());
              query.bindValue(":user2",this->getTopic()->getUsername2());
              query.bindValue(":topicmessages",this->getTopic()->getMessageHistoryAsString());
              query.bindValue(":messagedates",this->getTopic()->getMessageDatesHistoryAsString());


            if(query.exec()){

                 QMessageBox::information(this, "Saved", "New topic has been saved to the database!");
             }else {
                 QMessageBox::information(this, "Not saved Saved", "Error when writing the topic to the database");
             }
    }else{
        QMessageBox::information(this, "Not saved Saved", "Nothing to save yet");
    }
}

void searchresultswindow::on_deleteMessageButton_clicked()


{


    if(this->getUI()->listOfSearchedMessages->currentItem() != nullptr){

        QString selectedMessage = this->getUI()->listOfSearchedMessages->currentItem()->text();


        delete ui->listOfSearchedMessages->takeItem(ui->listOfSearchedMessages->row(ui->listOfSearchedMessages->currentItem()));


        QMessageBox::information(this, "Deleting highlighted message", "This message has been deleted from the conversation history");




           QString newMessageHistory = this->getTopic()->getPastMessageHistoryAsString().append(this->getTopic()->getMessageHistoryAsString());

           //this->getTopic()->getMessageHistoryAsString().replace(selectedMessage,userInput);
           //this->getTopic()->getMessageHistory() = this->getTopic()->getPastMessageHistoryAsString().split(",");

           newMessageHistory.replace(selectedMessage,"");
           newMessageHistory.remove("");

           QSqlQuery query(QSqlDatabase::database("QMYSQL"));
           query.prepare("UPDATE topics SET topicmessages = :topicmessages WHERE topicname = :topicname");
           query.bindValue(":topicmessages",newMessageHistory);
           query.bindValue(":topicname",this->getTopic()->getTopicName());


           if(query.exec())
           {
               QMessageBox::information(this,"Success","Message updated succesfully");

           }else{
               QMessageBox::information(this,"Failure","Problem when executing the query");
           }





}


    else
    {
        QMessageBox::information(this, "No message highlighted", "Please highlight the message you would like to edit");
    }


}




