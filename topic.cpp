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
