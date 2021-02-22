#ifndef SEARCHRESULTSWINDOW_H
#define SEARCHRESULTSWINDOW_H

#include <QDialog>
#include "topic.h"
#include "QMessageBox"
#include <QListWidget>


namespace Ui {
class searchresultswindow;
}

class searchresultswindow : public QDialog
{
    Q_OBJECT

public:
    explicit searchresultswindow(QWidget *parent = nullptr,topic * t = nullptr ,QString searchedMessage = "");
    ~searchresultswindow();
    topic * getTopic();
    QString getSearchedMessage();
    Ui::searchresultswindow * getUI();
    void saveEditsToDB();


    void setTopic(topic * t);
    void setSearchedMessage(QString sm);

private slots:
    void on_backToMainWindow_clicked();

    void on_listOfSearchedMessages_itemDoubleClicked(QListWidgetItem *item);

    void on_viewMessageButton_clicked();

    void on_editMessageButton_clicked();

    void on_deleteMessageButton_clicked();

private:
    Ui::searchresultswindow *ui;
    topic * t;
    QString searchedMessage;
};

#endif // SEARCHRESULTSWINDOW_H
