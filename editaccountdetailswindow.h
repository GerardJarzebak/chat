#ifndef EDITACCOUNTDETAILSWINDOW_H
#define EDITACCOUNTDETAILSWINDOW_H

#include <QWidget>
#include <user.h>
#include <QtWidgets/QMessageBox>
namespace Ui {
class editaccountdetailswindow ;
}



/**
 * @brief
 *
 */
class editaccountdetailswindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param parent
     * @param u
     */
    explicit editaccountdetailswindow(QWidget *parent = nullptr,user * u = nullptr);
    /**
     * @brief
     *
     */
    ~editaccountdetailswindow();
    /**
     * @brief
     *
     */
    void displayInfo();
    /**
     * @brief
     *
     */
    void hideInfo();
    /**
     * @brief
     *
     * @return Ui::editaccountdetailswindow
     */
    Ui::editaccountdetailswindow * getUI();
    /**
     * @brief
     *
     * @param user
     */
    void setUser(user * user);
    /**
     * @brief
     *
     * @return user
     */
    user* getUser();

private slots:


    /**
     * @brief
     *
     */
    void on_changeUsernameButton_clicked();

    /**
     * @brief
     *
     */
    void on_backButton_clicked();

    /**
     * @brief
     *
     */
    void on_changeEmailButton_clicked();

    /**
     * @brief
     *
     */
    void on_changePasswordButton_clicked();

private:
    Ui::editaccountdetailswindow *ui; /**< TODO: describe */
    user *u; /**< TODO: describe */

};

#endif // EDITACCOUNTDETAILSWINDOW_H
