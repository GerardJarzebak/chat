/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMqttClient>
#include "QtSql"
#include <topic.h>
#include "searchresultswindow.h"
#include <user.h>
#include <editaccountdetailswindow.h>
#include <reportwindow.h>
#include "QListWidgetItem"
#include "QBuffer"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void setClientPort(int p);
    void setUser(user * user);
    user* getUser();
    void setUser2(user * user);
    user* getUser2();
    Ui::MainWindow * getUI();
    void setADW( editaccountdetailswindow * adw);
    editaccountdetailswindow * getADW();
    void setEmojiList();
    void setTopic();
    user* getUserFromDB(QString username);
    void loadChatHistory(topic *t);
    void loadChatHistoryDesc(topic * t);
    topic* getCurrentTopic();

private slots:


    void updateLogStateChange();

    void on_RemoveFriendButton_clicked();

    void on_addFriendButton_clicked();

    void on_attachFileButton_clicked();

    void on_accountDetailsButton_clicked();

    void on_searchButton_clicked();

    void brokerDisconnected();

    void on_changeAvatarButton_clicked();

    void on_emojiList_itemClicked(QListWidgetItem *item);

    void on_friendsList_itemDoubleClicked(QListWidgetItem *item);





    void subcribe();

    void connectToTopic();

    void on_sendButton_clicked();

    void on_quitButton_clicked();

    void on_buttonConnect_clicked();

    void on_buttonSubscribe_clicked();

    void on_saveChatButton_clicked();

    void on_ascSortButton_clicked();

    void on_descSortButton_clicked();

    void on_searchButton_2_clicked();

    void on_reportButton_clicked();

private:
    Ui::MainWindow *ui;
    QMqttClient *m_client;
    user *u;
    user *u2;
    editaccountdetailswindow * adw;
    topic *currenttopic;
    searchresultswindow * srw;
    reportwindow * rw;

};

#endif // MAINWINDOW_H
