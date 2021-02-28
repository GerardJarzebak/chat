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

/**
 * @brief
 *
 */
class loginwindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param parent
     */
    explicit loginwindow(QWidget *parent = nullptr);
    /**
     * @brief
     *
     */
    ~loginwindow();
    /**
     * @brief
     *
     */
    void setDatabase();
    /**
     * @brief
     *
     * @return QSqlDatabase
     */
    QSqlDatabase  getDatabse();

private:
    Ui::loginwindow *ui; /**< TODO: describe */
    QSqlDatabase database; /**< TODO: describe */
    MainWindow *mw; /**< TODO: describe */

private slots:

    /**
     * @brief
     *
     */
    void on_loginBtn_clicked();


    /**
     * @brief
     *
     */
    void on_toRegisterPageButton_clicked();
};

#endif // LOGINWINDOW_H

