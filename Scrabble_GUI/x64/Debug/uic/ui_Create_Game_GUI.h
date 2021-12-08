/********************************************************************************
** Form generated from reading UI file 'Create_Game_GUI.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_GAME_GUI_H
#define UI_CREATE_GAME_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Create_Game_GUI
{
public:
    QPushButton *pushButton_return;
    QComboBox *comboBox_difficulty;
    QLabel *label_user;
    QLabel *label_second_player;
    QPushButton *pushButton_start;
    QLabel *label_name_2;
    QPushButton *pushButton_logout;
    QComboBox *comboBox_name;
    QLabel *label_avatar;
    QLabel *label_difficulty;
    QLabel *label_name;

    void setupUi(QDialog *Create_Game_GUI)
    {
        if (Create_Game_GUI->objectName().isEmpty())
            Create_Game_GUI->setObjectName(QString::fromUtf8("Create_Game_GUI"));
        Create_Game_GUI->resize(800, 600);
        pushButton_return = new QPushButton(Create_Game_GUI);
        pushButton_return->setObjectName(QString::fromUtf8("pushButton_return"));
        pushButton_return->setGeometry(QRect(100, 270, 221, 41));
        comboBox_difficulty = new QComboBox(Create_Game_GUI);
        comboBox_difficulty->setObjectName(QString::fromUtf8("comboBox_difficulty"));
        comboBox_difficulty->setGeometry(QRect(300, 150, 111, 22));
        label_user = new QLabel(Create_Game_GUI);
        label_user->setObjectName(QString::fromUtf8("label_user"));
        label_user->setGeometry(QRect(440, 20, 55, 16));
        label_second_player = new QLabel(Create_Game_GUI);
        label_second_player->setObjectName(QString::fromUtf8("label_second_player"));
        label_second_player->setGeometry(QRect(30, 150, 61, 16));
        pushButton_start = new QPushButton(Create_Game_GUI);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setGeometry(QRect(380, 270, 221, 41));
        label_name_2 = new QLabel(Create_Game_GUI);
        label_name_2->setObjectName(QString::fromUtf8("label_name_2"));
        label_name_2->setGeometry(QRect(170, 90, 101, 16));
        pushButton_logout = new QPushButton(Create_Game_GUI);
        pushButton_logout->setObjectName(QString::fromUtf8("pushButton_logout"));
        pushButton_logout->setGeometry(QRect(660, 20, 101, 31));
        comboBox_name = new QComboBox(Create_Game_GUI);
        comboBox_name->setObjectName(QString::fromUtf8("comboBox_name"));
        comboBox_name->setGeometry(QRect(140, 150, 111, 22));
        label_avatar = new QLabel(Create_Game_GUI);
        label_avatar->setObjectName(QString::fromUtf8("label_avatar"));
        label_avatar->setGeometry(QRect(590, 10, 51, 41));
        label_difficulty = new QLabel(Create_Game_GUI);
        label_difficulty->setObjectName(QString::fromUtf8("label_difficulty"));
        label_difficulty->setGeometry(QRect(310, 90, 101, 16));
        label_name = new QLabel(Create_Game_GUI);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(510, 20, 55, 16));

        retranslateUi(Create_Game_GUI);

        QMetaObject::connectSlotsByName(Create_Game_GUI);
    } // setupUi

    void retranslateUi(QDialog *Create_Game_GUI)
    {
        Create_Game_GUI->setWindowTitle(QCoreApplication::translate("Create_Game_GUI", "Create_Game_GUI", nullptr));
        pushButton_return->setText(QCoreApplication::translate("Create_Game_GUI", "Return to menu", nullptr));
        label_user->setText(QCoreApplication::translate("Create_Game_GUI", "User:", nullptr));
        label_second_player->setText(QCoreApplication::translate("Create_Game_GUI", "2nd player", nullptr));
        pushButton_start->setText(QCoreApplication::translate("Create_Game_GUI", "Start game", nullptr));
        label_name_2->setText(QCoreApplication::translate("Create_Game_GUI", "Name", nullptr));
        pushButton_logout->setText(QCoreApplication::translate("Create_Game_GUI", "Logout", nullptr));
        label_avatar->setText(QCoreApplication::translate("Create_Game_GUI", "<avatar>", nullptr));
        label_difficulty->setText(QCoreApplication::translate("Create_Game_GUI", "Difficulty level", nullptr));
        label_name->setText(QCoreApplication::translate("Create_Game_GUI", "<login>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Create_Game_GUI: public Ui_Create_Game_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_GAME_GUI_H
