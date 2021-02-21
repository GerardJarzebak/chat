#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDialog>
#include <user.h>
#include "mainwindow.h"

namespace Ui {
class loginwindow;
}

class loginwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit loginwindow(QWidget *parent = nullptr);
    ~loginwindow();
    void setDatabase();
    QSqlDatabase  getDatabse();

private:
    Ui::loginwindow *ui;
    QSqlDatabase database;
    MainWindow *mw;

private slots:

    void on_loginBtn_clicked();


    void on_toRegisterPageButton_clicked();
};

#endif // LOGINWINDOW_H

