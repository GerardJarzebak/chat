#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user.h"
#include "registerwindow.h"
#include <string>
#include <QListWidget>
#include "QFontDatabase"
#include <QListView>
#include "editaccountdetailswindow.h"






void loginwindow::setDatabase()
{
    QSqlDatabase  database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("gjarzebak");
    database.setPassword("Q!w2e3r4t5y6");
    database.setDatabaseName("qt5");
    database.open();
    this->database = database;
}

QSqlDatabase  loginwindow::getDatabse()
{
    return this->database;
}



loginwindow::loginwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginwindow)
{
    this->setDatabase();
    ui->setupUi(this);
    this->setFixedSize(1280,720);
    ui->loginUsername->setPlaceholderText("Enter your username");
    ui->loginPassword->setPlaceholderText("Enter your password");
    ui->loginPassword->setEchoMode(QLineEdit::Password);




}

loginwindow::~loginwindow()
{
    delete ui;
}






void loginwindow::on_loginBtn_clicked()


{

    if (this->getDatabse().open())
    {

        QMessageBox::information(this, "Database Success", "Database Connection Success");
        QSqlQuery query(QSqlDatabase::database("My Connect"));

        QString username = ui -> loginUsername -> text();
        QString password = ui -> loginPassword -> text();


        query.prepare(QString("SELECT * FROM users WHERE username = :username AND password = :password"));
        query.bindValue(":username", username);
        query.bindValue(":password", password);

        if (!query.exec())
        {
          QMessageBox::information(this, "Failed", "Query failed to execute");

        }else {

            while (query.next()) {
              int idFromDB = query.value(0).toInt();
              QString usernameFromDB = query.value(1).toString();
              QString passwordFromDB = query.value(2).toString();


            if (usernameFromDB == username && passwordFromDB == password) {

                QMessageBox::information(this, "Success", "Login success");

                //Retrieving from DB all we need to know about logged in user
                QStringList fl = query.value(5).toString().split(",");


                QString emailFromDB = query.value(3).toString();
                QByteArray imageFromDB = query.value(4).toByteArray();
                QPixmap userAvatar = QPixmap();
                userAvatar.loadFromData(imageFromDB);

                //Creating the user from the information retrieved from DB

                user * u = new user(idFromDB, usernameFromDB, passwordFromDB, emailFromDB, userAvatar, fl);


                this -> hide();
                mw = new MainWindow(this);
                mw -> setUser(u);
                mw -> getUI() -> usernameLabel -> setText(u -> getUsername());
                mw -> getUI() -> avatarLabel -> setPixmap(userAvatar);

                for (QString friendusername: u -> getFriendsList()) {

                  mw -> getUI() -> friendsList -> addItem(friendusername);
                }
                mw -> show();


            }else {
                QMessageBox::information(this, "Failed", "Login Failed");
              }


            }

        }

    }else {
        QMessageBox::information(this, "Database Failed", "Database Connection Failed");
      }


}












void loginwindow::on_toRegisterPageButton_clicked()
{
    registerwindow * rw = new registerwindow(this);
    rw->show();


}
