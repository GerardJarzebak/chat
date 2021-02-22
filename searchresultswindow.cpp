#include "searchresultswindow.h"
#include "ui_searchresultswindow.h"
#include <QInputDialog>

searchresultswindow::searchresultswindow(QWidget *parent,topic * t ,QString searchedMessage) :
    QDialog(parent),
    ui(new Ui::searchresultswindow)
{
    ui->setupUi(this);
    this->setFixedSize(1280,720);
    this->t = t;
    this->searchedMessage = searchedMessage;
    this->getUI()->searchedMessageLabel->setText(searchedMessage);






      //this->t->getMessageHistoryAsString().split(",")

      QString mh = this->t->getMessageHistoryAsString().append(this->t->getPastMessageHistoryAsString());

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
    QString selectedMessage = this->getUI()->listOfSearchedMessages->currentItem()->text();

    QInputDialog * id = new QInputDialog();
    id->setTextValue(selectedMessage);
    QString userInput = id -> getText(this, "Edit the message", "Please edit the message and press ok to save it");

}

void searchresultswindow::on_deleteMessageButton_clicked()
{
       QString selectedMessage = this->getUI()->listOfSearchedMessages->currentItem()->text();
       QMessageBox::information(this, "Success", "This message has been deleted from the conversation history");
}
