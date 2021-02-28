#ifndef TOPIC_H
#define TOPIC_H
#include <QString>
#include <QStringList>

/**
 * @brief
 *
 */
class topic
{
public:
    /**
     * @brief
     *
     * @param topicname
     */
    topic(QString topicname);
    /**
     * @brief
     *
     * @return QString
     */
    QString getTopicName();
    /**
     * @brief
     *
     * @param s
     */
    void setTopicName(QString s);
    /**
     * @brief
     *
     * @return QString
     */
    QString &getMessageHistoryAsString();
    /**
     * @brief
     *
     * @param s
     */
    void setMessageHistoryWithString(QString s);
    /**
     * @brief
     *
     * @param sl
     */
    void setMessageHistory(QStringList sl);
    /**
     * @brief
     *
     * @return QStringList
     */
    QStringList getMessageHistory();
    /**
     * @brief
     *
     * @return topic
     */
    topic * getTopic();
    /**
     * @brief
     *
     * @param id
     */
    void setTopicID(int id);
    /**
     * @brief
     *
     * @return int
     */
    int getTopicID();

    /**
     * @brief
     *
     * @param u1
     */
    void setUsername1(QString u1);
    /**
     * @brief
     *
     * @param u2
     */
    void setUsername2(QString u2);

    /**
     * @brief
     *
     * @return QString
     */
    QString getUsername1();
    /**
     * @brief
     *
     * @return QString
     */
    QString getUsername2();

    /**
     * @brief
     *
     * @return QString
     */
    QString &getPastMessageHistoryAsString();
    /**
     * @brief
     *
     * @param s
     */
    void setPastMessageHistoryWithString(QString s);
    /**
     * @brief
     *
     * @param sl
     */
    void setPastMessageHistory(QStringList sl);
    /**
     * @brief
     *
     * @return QStringList
     */
    QStringList getPastMessageHistory();

    /**
     * @brief
     *
     * @param s
     */
    void setMessageDatesHistoryAsString(QString s);
    /**
     * @brief
     *
     * @param sl
     */
    void setMessageDatesHistory(QStringList sl);
    /**
     * @brief
     *
     * @param s
     */
    void setPastMessageDatesHistoryAsString(QString s);
    /**
     * @brief
     *
     * @param sl
     */
    void setPastMessageDateseHistory(QStringList sl);
    /**
     * @brief
     *
     * @return QStringList
     */
    QStringList getPastMessageDatesHistory();
    /**
     * @brief
     *
     * @return QString
     */
    QString &getPastMessageDatesHistoryAsString();
    /**
     * @brief
     *
     * @return QStringList
     */
    QStringList getMessageDatesHistory();
    /**
     * @brief
     *
     * @return QString
     */
    QString &getMessageDatesHistoryAsString();



private:
    QString topicname; /**< TODO: describe */
    QStringList messageHistory; /**< TODO: describe */
    QString messageHistoryAsString; /**< TODO: describe */
    int topicID; /**< TODO: describe */
    QString username1; /**< TODO: describe */
    QString username2; /**< TODO: describe */
    QStringList pastMessageHistory; /**< TODO: describe */
    QString pastMessageHistoryAsString; /**< TODO: describe */

    QStringList messageDatesHistory; /**< TODO: describe */
    QString messageDatesHistoryAsString; /**< TODO: describe */
    QStringList pastMessageDateseHistory; /**< TODO: describe */
    QString pastMessageDatesHistoryAsString; /**< TODO: describe */
};

#endif // TOPIC_H
