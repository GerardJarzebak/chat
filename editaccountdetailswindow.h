#ifndef EDITACCOUNTDETAILSWINDOW_H
#define EDITACCOUNTDETAILSWINDOW_H

#include <QWidget>
#include <user.h>
#include <QtWidgets/QMessageBox>
namespace Ui {
class editaccountdetailswindow ;
}



class editaccountdetailswindow : public QWidget
{
    Q_OBJECT

public:
    explicit editaccountdetailswindow(QWidget *parent = nullptr,user * u = nullptr);
    ~editaccountdetailswindow();
    void displayInfo();
    void hideInfo();
    Ui::editaccountdetailswindow * getUI();
    void setUser(user * user);
    user* getUser();

private slots:
    void on_pushButton_2_clicked();

    void on_changeUsernameButton_clicked();

    void on_backButton_clicked();

    void on_changeEmailButton_clicked();

    void on_changePasswordButton_clicked();

private:
    Ui::editaccountdetailswindow *ui;
    user *u;

};

#endif // EDITACCOUNTDETAILSWINDOW_H
