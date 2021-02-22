#ifndef REPORTWINDOW_H
#define REPORTWINDOW_H

#include <QWidget>
#include <user.h>
#include <topic.h>

namespace Ui {
class reportwindow;
}

class reportwindow : public QWidget
{
    Q_OBJECT

public:
    explicit reportwindow(QWidget *parent = nullptr,user * u = nullptr,topic * t = nullptr);
    ~reportwindow();
    void setUser(user * user);
    user* getUser();

private slots:
    void on_backToMainWindowButton_clicked();

private:
    Ui::reportwindow *ui;
    user * u;
    topic * t;
};

#endif // REPORTWINDOW_H
