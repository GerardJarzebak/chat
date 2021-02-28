#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

namespace Ui {
class registerwindow;
}

/**
 * @brief
 *
 */
class registerwindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param parent
     */
    explicit registerwindow(QWidget *parent = nullptr);
    /**
     * @brief
     *
     */
    ~registerwindow();
    /**
     * @brief
     *
     */
    void setDatabase();

private slots:
    /**
     * @brief
     *
     */
    void on_registerButton_clicked();




    /**
     * @brief
     *
     */
    void on_backToLoginButton_clicked();

private:
    Ui::registerwindow *ui; /**< TODO: describe */
    QSqlDatabase database; /**< TODO: describe */
};

#endif // REGISTERWINDOW_H
