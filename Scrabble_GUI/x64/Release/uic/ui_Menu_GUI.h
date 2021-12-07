/********************************************************************************
** Form generated from reading UI file 'Menu_GUI.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_GUI_H
#define UI_MENU_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Menu_GUI
{
public:
    QPushButton *pushButton_profile;
    QPushButton *pushButton_play;
    QPushButton *pushButton_logout;
    QPushButton *pushButton_ranking;
    QLabel *label_user;
    QPushButton *pushButton_settings;
    QLabel *label_name;
    QLabel *label_avatar;

    void setupUi(QDialog *Menu_GUI)
    {
        if (Menu_GUI->objectName().isEmpty())
            Menu_GUI->setObjectName(QString::fromUtf8("Menu_GUI"));
        Menu_GUI->resize(800, 600);
        pushButton_profile = new QPushButton(Menu_GUI);
        pushButton_profile->setObjectName(QString::fromUtf8("pushButton_profile"));
        pushButton_profile->setGeometry(QRect(110, 200, 171, 61));
        pushButton_play = new QPushButton(Menu_GUI);
        pushButton_play->setObjectName(QString::fromUtf8("pushButton_play"));
        pushButton_play->setGeometry(QRect(460, 310, 171, 61));
        pushButton_logout = new QPushButton(Menu_GUI);
        pushButton_logout->setObjectName(QString::fromUtf8("pushButton_logout"));
        pushButton_logout->setGeometry(QRect(680, 20, 101, 31));
        pushButton_ranking = new QPushButton(Menu_GUI);
        pushButton_ranking->setObjectName(QString::fromUtf8("pushButton_ranking"));
        pushButton_ranking->setGeometry(QRect(460, 200, 171, 61));
        label_user = new QLabel(Menu_GUI);
        label_user->setObjectName(QString::fromUtf8("label_user"));
        label_user->setGeometry(QRect(460, 20, 55, 16));
        pushButton_settings = new QPushButton(Menu_GUI);
        pushButton_settings->setObjectName(QString::fromUtf8("pushButton_settings"));
        pushButton_settings->setGeometry(QRect(110, 310, 171, 61));
        label_name = new QLabel(Menu_GUI);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(530, 20, 55, 16));
        label_avatar = new QLabel(Menu_GUI);
        label_avatar->setObjectName(QString::fromUtf8("label_avatar"));
        label_avatar->setGeometry(QRect(610, 10, 51, 41));

        retranslateUi(Menu_GUI);

        QMetaObject::connectSlotsByName(Menu_GUI);
    } // setupUi

    void retranslateUi(QDialog *Menu_GUI)
    {
        Menu_GUI->setWindowTitle(QCoreApplication::translate("Menu_GUI", "Menu_GUI", nullptr));
        pushButton_profile->setText(QCoreApplication::translate("Menu_GUI", "Player's profile", nullptr));
        pushButton_play->setText(QCoreApplication::translate("Menu_GUI", "Play", nullptr));
        pushButton_logout->setText(QCoreApplication::translate("Menu_GUI", "Logout", nullptr));
        pushButton_ranking->setText(QCoreApplication::translate("Menu_GUI", "Ranking", nullptr));
        label_user->setText(QCoreApplication::translate("Menu_GUI", "User:", nullptr));
        pushButton_settings->setText(QCoreApplication::translate("Menu_GUI", "Settings", nullptr));
        label_name->setText(QCoreApplication::translate("Menu_GUI", "<login>", nullptr));
        label_avatar->setText(QCoreApplication::translate("Menu_GUI", "<avatar>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu_GUI: public Ui_Menu_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_GUI_H
