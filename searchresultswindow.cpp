#include "searchresultswindow.h"
#include "ui_searchresultswindow.h"
#include <QInputDialog>
#include <QSqlQuery>

searchresultswindow::searchresultswindow(QWidget *parent,topic * t ,QString searchedMessage) :
    QDialog(parent),
    ui(new Ui::searchresultswindow)
{

    ui->setupUi(this);
    this->setFixedSize(1280,720);
    this->t = t;
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

void searchresultswindow::on_editMessageButton_clicked()
{
/*
    if(this->getUI()->listOfSearchedMessages->currentItem() != nullptr){
           QString selectedMessage = this->getUI()->listOfSearchedMessages->currentItem()->text();
           QInputDialog * id = new QInputDialog();
           QString userInput = id -> getText(this, "Editing highlighted message", "Please edit the message and press ok to save it");

           this->getUI()->listOfSearchedMessages->currentItem()->setText(userInput);






           QSqlQuery query(QSqlDatabase::database("QMYSQL"));
           query.prepare("SELECT * from topics where topicname = :topicname ORDER BY id  ASC");
           query.bindValue(":topicname", t -> getTopicName());





           if (query.exec()) {
             while (query.next()) {

               QString topicnameFromDB = query.value(1).toString();

               if (t -> getTopicName() == topicnameFromDB) {








                 int idFromDB = query.value(0).toInt();
                 QString user1FromDb = query.value(2).toString();
                 QString user2FromDb = query.value(3).toString();
                 QString topicmessagesFromDB = query.value(4).toString();
                 QString messageDatesFromDB = query.value(5).toString();



                 for(QString s : topicmessagesFromDB.split(","))
                 {

                     QString str("this is a string"); // The initial string.
                     QString subStr("is"); // String to replace.
                     QString newStr("at"); // Replacement string.

                     str.replace(str.indexOf(subStr), subStr.size(), newStr);



                     if(s == selectedMessage){
                         topicmessagesFromDB.split(",").at(topicmessagesFromDB.split(",").indexOf(s)) = userInput;
                     }


                 }




                 t -> getPastMessageHistoryAsString().append(topicmessagesFromDB);
                 t->getMessageDatesHistoryAsString().append(messageDatesFromDB);

                 for (QString s: topicmessagesFromDB.split(",")) {
                   t -> getPastMessageHistory().append(s);
                   ui -> editLog -> insertPlainText(s);
                   ui -> editLog -> insertPlainText("\n");

                 }

                 for (QString s: messageDatesFromDB.split(",")) {
                   t -> getPastMessageDatesHistory().append(s);

                 }

               }

             }

           } else {

             QMessageBox::information(this, "Failure", "The database query to load chat history didnt run properly");
           }












           bool flag = true;
           int a = this->getTopic()->getMessageDatesHistory().indexOf(selectedMessage);
           if(flag)
           {
               this->getTopic()->getMessageHistory().replace(a,userInput);
               this->getTopic()->getMessageHistoryAsString()="";
               for(QString s : this->getTopic()->getMessageHistory())
               {
                   this->getTopic()->getMessageHistoryAsString().append(s);
               }
               flag = false;


           }

           int b = this->getTopic()->getPastMessageDatesHistory().indexOf(selectedMessage);
           if(flag == true){


               this->getTopic()->getPastMessageHistory().replace(b,userInput);
               this->getTopic()->getPastMessageHistoryAsString()="";
               for(QString s : this->getTopic()->getPastMessageHistory())
               {
                   this->getTopic()->getPastMessageHistoryAsString().append(s);
               }

           }




       }else{
           QMessageBox::information(this, "No message highlighted", "Please highlight the message you would like to edit");
       }

*/
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


{     /* if(this->getUI()->listOfSearchedMessages->currentItem() != nullptr){
       QString selectedMessage = this->getUI()->listOfSearchedMessages->currentItem()->text();


       delete ui->listOfSearchedMessages->takeItem(ui->listOfSearchedMessages->row(ui->listOfSearchedMessages->currentItem()));


       QMessageBox::information(this, "Deleting highlighted message", "This message has been deleted from the conversation history");








       bool flag = true;
       int a = this->getTopic()->getMessageDatesHistory().indexOf(selectedMessage);
       int b = this->getTopic()->getPastMessageDatesHistory().indexOf(selectedMessage);


       if(flag)
       {   this->getTopic()->getMessageHistory().removeAt(a);
           this->getTopic()->getMessageDatesHistory().removeAt(a);
           this->getTopic()->getMessageHistoryAsString()="";
           this->getTopic()->getMessageDatesHistoryAsString()="";
           for(QString s : this->getTopic()->getMessageHistory())
           {
               this->getTopic()->getMessageHistoryAsString().append(s + ",");
               this->getTopic()->getMessageDatesHistoryAsString().append(s + ",");
           }flag = false;

       }

       if(flag == true){
           this->getTopic()->getPastMessageHistory().removeAt(b);
           this->getTopic()->getPastMessageDatesHistory().removeAt(b);
           this->getTopic()->getPastMessageHistoryAsString()="";
           this->getTopic()->getPastMessageDatesHistoryAsString()="";
           for(QString s : this->getTopic()->getPastMessageHistory())
           {
               this->getTopic()->getPastMessageHistoryAsString().append(s+ ",");
               this->getTopic()->getPastMessageDatesHistoryAsString().append(s+ ",");
           }

       }






    }else{
        QMessageBox::information(this, "No message highlighted", "Please highlight the message you would like to delete");
    }

    this->saveEditsToDB();*/

}




