#include "searchresultswindow.h"
#include "ui_searchresultswindow.h"

searchresultswindow::searchresultswindow(QWidget *parent,topic * t ,QString searchedMessage) :
    QDialog(parent),
    ui(new Ui::searchresultswindow)
{
    ui->setupUi(this);
    this->setFixedSize(1280,720);
    this->t = t;
    this->searchedMessage = searchedMessage;




      //this->t->getMessageHistoryAsString().split(",")

      QString mh = this->t->getMessageHistoryAsString().append(this->t->getPastMessageHistoryAsString());

        for(QString s : mh.split(","))
        {

            if(s.contains(searchedMessage))
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
