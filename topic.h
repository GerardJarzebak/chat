#ifndef TOPIC_H
#define TOPIC_H
#include <QString>
#include <QStringList>

class topic
{
public:
    topic(QString topicname);
    QString getTopicName();
    void setTopicName(QString s);
    QString &getMessageHistoryAsString();
    void setMessageHistoryWithString(QString s);
    void setMessageHistory(QStringList sl);
    QStringList getMessageHistory();
    topic * getTopic();
    void setTopicID(int id);
    int getTopicID();

    void setUsername1(QString u1);
    void setUsername2(QString u2);

    QString getUsername1();
    QString getUsername2();



private:
    QString topicname;
    QStringList messageHistory;
    QString messageHistoryAsString;
    int topicID;
    QString username1;
    QString username2;
};

#endif // TOPIC_H
