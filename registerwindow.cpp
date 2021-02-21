#include "registerwindow.h"
#include "ui_registerwindow.h"

registerwindow::registerwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::registerwindow)
{
    ui->setupUi(this);
    this->setFixedSize(1280,720);
    ui->usernameRegister->setPlaceholderText("Enter your username");
    ui->passwordRegister->setPlaceholderText("Enter your password");
    ui->passwordRegister2->setPlaceholderText("Repeat your password");
    ui->emailRegister->setPlaceholderText("Enter your email");

}

registerwindow::~registerwindow()
{
    delete ui;
}


void registerwindow::setDatabase()
{
    QSqlDatabase  database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("gjarzebak");
    database.setPassword("Q!w2e3r4t5y6");
    database.setDatabaseName("qt5");
    database.open();
    this->database = database;
}

void registerwindow::on_registerButton_clicked() {

  if (this->database.open()) {

    //Retreive data from input fields

    QString usernameRegister = ui -> usernameRegister -> text();
    QString passwordRegister = ui -> passwordRegister -> text();
    QString passwordRegister2 = ui -> passwordRegister2 -> text();
    QString emailRegister = ui -> emailRegister -> text();

    //Run the query insert
    QSqlQuery qry;
    qry.prepare("INSERT INTO users (username,password,email)"
      "VALUES (:username,:password,:email)");
    qry.bindValue(":username", usernameRegister);
    qry.bindValue(":password", passwordRegister);
    qry.bindValue(":email", emailRegister);

    if (qry.exec()) {
      QMessageBox::information(this, "Inserted", "Data Inserted Successfully");
    } else {

      QMessageBox::information(this, "Not inserted", "Data is not inserted");
    }

  } else {

    QMessageBox::information(this, "Not Connected", "Database is not connected");
  }

}



void registerwindow::on_backToLoginButton_clicked()
{
    this->close();
}
