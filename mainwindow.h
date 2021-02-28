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
#include <QtAlgorithms>



namespace Ui {
class MainWindow;
}

/**
 * @brief
 *
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param parent
     */
    explicit MainWindow(QWidget *parent = nullptr);
    /**
     * @brief
     *
     */
    ~MainWindow();

public slots:
    /**
     * @brief
     *
     * @param p
     */
    void setClientPort(int p);
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
    /**
     * @brief
     *
     * @param user
     */
    void setUser2(user * user);
    /**
     * @brief
     *
     * @return user
     */
    user* getUser2();
    /**
     * @brief
     *
     * @return Ui::MainWindow
     */
    Ui::MainWindow * getUI();
    /**
     * @brief
     *
     * @param adw
     */
    void setADW( editaccountdetailswindow * adw);
    /**
     * @brief
     *
     * @return editaccountdetailswindow
     */
    editaccountdetailswindow * getADW();
    /**
     * @brief
     *
     */
    void setEmojiList();
    /**
     * @brief
     *
     */
    void setTopic();
    /**
     * @brief
     *
     * @param username
     * @return user
     */
    user* getUserFromDB(QString username);
    /**
     * @brief
     *
     * @param t
     */
    void loadChatHistory(topic *t);
    /**
     * @brief
     *
     * @param t
     */
    void loadChatHistoryDesc(topic * t);
    /**
     * @brief
     *
     * @return topic
     */
    topic* getCurrentTopic();

private slots:


    /**
     * @brief
     *
     */
    void updateLogStateChange();

    /**
     * @brief
     *
     */
    void on_RemoveFriendButton_clicked();

    /**
     * @brief
     *
     */
    void on_addFriendButton_clicked();

    /**
     * @brief
     *
     */
    void on_attachFileButton_clicked();

    /**
     * @brief
     *
     */
    void on_accountDetailsButton_clicked();

    /**
     * @brief
     *
     */
    void on_searchButton_clicked();

    /**
     * @brief
     *
     */
    void brokerDisconnected();

    /**
     * @brief
     *
     */
    void on_changeAvatarButton_clicked();

    /**
     * @brief
     *
     * @param item
     */
    void on_emojiList_itemClicked(QListWidgetItem *item);

    /**
     * @brief
     *
     * @param item
     */
    void on_friendsList_itemDoubleClicked(QListWidgetItem *item);





    /**
     * @brief
     *
     */
    void subcribe();

    /**
     * @brief
     *
     */
    void connectToTopic();

    /**
     * @brief
     *
     */
    void on_sendButton_clicked();

    /**
     * @brief
     *
     */
    void on_quitButton_clicked();

    /**
     * @brief
     *
     */
    void on_buttonConnect_clicked();

    /**
     * @brief
     *
     */
    void on_buttonSubscribe_clicked();

    /**
     * @brief
     *
     */
    void on_saveChatButton_clicked();

    /**
     * @brief
     *
     */
    void on_ascSortButton_clicked();

    /**
     * @brief
     *
     */
    void on_descSortButton_clicked();

    /**
     * @brief
     *
     */
    void on_searchButton_2_clicked();

    /**
     * @brief
     *
     */
    void on_reportButton_clicked();

private:
    Ui::MainWindow *ui; /**< TODO: describe */
    QMqttClient *m_client; /**< TODO: describe */
    user *u; /**< TODO: describe */
    user *u2; /**< TODO: describe */
    editaccountdetailswindow * adw; /**< TODO: describe */
    topic *currenttopic; /**< TODO: describe */
    searchresultswindow * srw; /**< TODO: describe */
    reportwindow * rw; /**< TODO: describe */

};

#endif // MAINWINDOW_H
