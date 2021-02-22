#include "editaccountdetailswindow.h"
#include "ui_editaccountdetailswindow.h"
#include <user.h>
editaccountdetailswindow::editaccountdetailswindow(QWidget *parent,user * u) :
    QDialog(parent),
    ui(new Ui::editaccountdetailswindow)
{
    ui->setupUi(this);
    this->u=u;
    this->setFixedSize(1280,720);

    ui->emailLabel->setText(u->getEmail());
    ui->usernameLabel->setText(u->getUsername());
}

editaccountdetailswindow::~editaccountdetailswindow()
{
    delete ui;
}


Ui::editaccountdetailswindow * editaccountdetailswindow::getUI()
{
    return this->ui;
}

void editaccountdetailswindow::setUser(user * user)
{
    this->u = user;
}
 user* editaccountdetailswindow::getUser()
 {
     return this->u;
 }



/*void editaccountdetailswindow::setMW( Ui::MainWindow * mw)
{
    this->mw = mw;
}*/
/*
void editaccountdetailswindow::displayInfo()
{
    this->show();
}

void editaccountdetailswindow::hideInfo()
{
    this->close();
}


void setMW( MainWindow * mw)
{

}*/

/*Ui::MainWindow * mw getMW()
{
    return this->mw;
}*/



void editaccountdetailswindow::on_backButton_clicked()
{
    this->close();
}

void editaccountdetailswindow::on_changeEmailButton_clicked()
{

    QString newemail = ui->newEmailEnter->text();


    QSqlQuery query(QSqlDatabase::database("QMYSQL"));
    query.prepare("UPDATE users SET email = :newemail WHERE id = :userid");
    query.bindValue(":userid",this->getUser()->getUserID());
    query.bindValue(":newemail",newemail);
    this->ui->newEmailEnter->setText(newemail);


    if (query.exec()) {
        QMessageBox::information(this, "WORKED", "EMAIL UPDATED");
       } else {

        QMessageBox::information(this, "FAILURE", "EMAIL NOT UPDATED");
       }

}

void editaccountdetailswindow::on_changeUsernameButton_clicked()
{
    QString newusername = ui->newUsernameEnter->text();


    QSqlQuery query(QSqlDatabase::database("QMYSQL"));
    query.prepare("UPDATE users SET username = :newusername WHERE id = :userid");
    query.bindValue(":userid",this->getUser()->getUserID());
    query.bindValue(":newusername",newusername);
    this->ui->usernameLabel->setText(newusername);


    if (query.exec()) {
      QMessageBox::information(this, "WORKED", "USERNAME UPDATED");
    } else {

      QMessageBox::information(this, "FAILURE", "USERNAME NOT UPDATED");
    }

}

void editaccountdetailswindow::on_changePasswordButton_clicked()
{
    QString currentpassword = ui->currentPasswordEnter->text();
    QString newpassword = ui->newPassword->text();
    QString newpasswordconfirmation = ui->newPassword2->text();

       QSqlQuery query(QSqlDatabase::database("QMYSQL"));
       query.prepare("UPDATE users SET password = :password WHERE id = :userid");
       query.bindValue(":userid",this->getUser()->getUserID());
       query.bindValue(":password",newpassword);

       if (newpassword.isEmpty() || newpasswordconfirmation.isEmpty() || currentpassword.isEmpty()) {

            QMessageBox::information(this,"ERROR","PLEASE FILL IN ALL FIELDS");
       }else {
            if (newpassword == newpasswordconfirmation && currentpassword == this->u->getPassword()) {
                if (query.exec()) {
                  QMessageBox::information(this, "WORKED", "PASSWORD UPDATED");
                } else {

                  QMessageBox::information(this, "FAILURE", "PASSWORD NOT UPDATED");
                }



            }else{
                QMessageBox::information(this,"ERROR","PASSWORDS DONT MATCH");
            }
       }
}
