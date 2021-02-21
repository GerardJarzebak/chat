#include "topic.h"

topic::topic(QString topicname)
{
    this->topicname =topicname;
    this->messageHistory = QStringList();
    this->messageHistoryAsString = "";
}

QString topic::getTopicName()
{
    return this->topicname;
}

void topic::setTopicName(QString s)
{
    this->topicname = s;
}

QString& topic::getMessageHistoryAsString()
{
    return this->messageHistoryAsString;
}

QStringList topic::getMessageHistory()
{
    return this->messageHistory;
}

void topic::setMessageHistoryWithString(QString s)
{
    this->messageHistoryAsString = s;
}

topic * topic::getTopic()
{
    return this;
}
void topic::setTopicID(int id)
{
    this->topicID = id;
}
int topic::getTopicID()
{
    return this->topicID;
}

void topic::setMessageHistory(QStringList sl)
{
    this->messageHistory = sl;
}


void topic::setUsername1(QString u1)
{
    this->username1 = u1;
}
void topic::setUsername2(QString u2)
{
    this->username2 = u2;
}

QString topic::getUsername1()
{
    return this->username1;
}
QString topic::getUsername2()
{
    return this->username2;
}

QString & topic::getPastMessageHistoryAsString()
{
    return this->pastMessageHistoryAsString;
}
void topic::setPastMessageHistoryWithString(QString s)
{
    this->pastMessageHistoryAsString = s;
}
void topic::setPastMessageHistory(QStringList sl)
{
    this->pastMessageHistory = sl;
}
QStringList topic::getPastMessageHistory()
{
    return this->pastMessageHistory;
}

void topic::setMessageDatesHistoryAsString(QString s)
{
    this->messageDatesHistoryAsString = s;
}
void topic::setMessageDatesHistory(QStringList sl)
{
    this->messageDatesHistory = sl;
}
void topic::setPastMessageDatesHistoryAsString(QString s)
{
    this->pastMessageDatesHistoryAsString = s;
}
void topic::setPastMessageDateseHistory(QStringList sl)
{
    this->pastMessageDateseHistory = sl;
}
QStringList topic::getPastMessageDatesHistory()
{
    return this->pastMessageHistory;
}
QString & topic::getPastMessageDatesHistoryAsString()
{
    return this->pastMessageDatesHistoryAsString;
}
QStringList topic::getMessageDatesHistory()
{
    return this->messageDatesHistory;
}
QString & topic::getMessageDatesHistoryAsString()
{
    return this->messageDatesHistoryAsString;
}
