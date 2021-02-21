#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

namespace Ui {
class registerwindow;
}

class registerwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit registerwindow(QWidget *parent = nullptr);
    ~registerwindow();
    void setDatabase();

private slots:
    void on_registerButton_clicked();




    void on_backToLoginButton_clicked();

private:
    Ui::registerwindow *ui;
    QSqlDatabase database;
};

#endif // REGISTERWINDOW_H
