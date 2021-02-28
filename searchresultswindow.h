#ifndef SEARCHRESULTSWINDOW_H
#define SEARCHRESULTSWINDOW_H

#include <QDialog>
#include "topic.h"
#include "QMessageBox"
#include <QListWidget>
#include "user.h"


namespace Ui {
class searchresultswindow;
}

/**
 * @brief
 *
 */
class searchresultswindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param parent
     * @param t
     * @param searchedMessage
     */
    explicit searchresultswindow(QWidget *parent = nullptr,user * u = nullptr,topic * t = nullptr ,QString searchedMessage = "");
    /**
     * @brief
     *
     */
    ~searchresultswindow();
    /**
     * @brief
     *
     * @return topic
     */
    topic * getTopic();
    /**
     * @brief
     *
     * @return QString
     */
    QString getSearchedMessage();
    /**
     * @brief
     *
     * @return Ui::searchresultswindow
     */
    Ui::searchresultswindow * getUI();
    /**
     * @brief
     *
     */
    void saveEditsToDB();


    /**
     * @brief
     *
     * @param t
     */
    void setTopic(topic * t);
    /**
     * @brief
     *
     * @param sm
     */
    void setSearchedMessage(QString sm);
    user * getUser();

private slots:
    /**
     * @brief
     *
     */
    void on_backToMainWindow_clicked();

    /**
     * @brief
     *
     * @param item
     */
    void on_listOfSearchedMessages_itemDoubleClicked(QListWidgetItem *item);

    /**
     * @brief
     *
     */
    void on_viewMessageButton_clicked();

    /**
     * @brief
     *
     */
    void on_editMessageButton_clicked();

    /**
     * @brief
     *
     */
    void on_deleteMessageButton_clicked();

private:
    Ui::searchresultswindow *ui; /**< TODO: describe */
    topic * t; /**< TODO: describe */
    user * u;
    QString searchedMessage; /**< TODO: describe */
};

#endif // SEARCHRESULTSWINDOW_H
