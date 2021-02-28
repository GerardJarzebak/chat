#ifndef REPORTWINDOW_H
#define REPORTWINDOW_H

#include <QWidget>
#include <user.h>
#include <topic.h>

namespace Ui {
class reportwindow;
}

/**
 * @brief
 *
 */
class reportwindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param parent
     * @param u
     * @param t
     */
    explicit reportwindow(QWidget *parent = nullptr,user * u = nullptr,topic * t = nullptr);
    /**
     * @brief
     *
     */
    ~reportwindow();
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
    void on_backToMainWindowButton_clicked();

private:
    Ui::reportwindow *ui; /**< TODO: describe */
    user * u; /**< TODO: describe */
    topic * t; /**< TODO: describe */
};

#endif // REPORTWINDOW_H
