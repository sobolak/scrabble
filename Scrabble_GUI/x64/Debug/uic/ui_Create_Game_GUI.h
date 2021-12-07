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
    QPushButton *pushButton;
    QComboBox *comboBox_4;
    QLabel *label;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QLabel *label_5;
    QPushButton *pushButton_5;
    QComboBox *comboBox;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_2;

    void setupUi(QDialog *Create_Game_GUI)
    {
        if (Create_Game_GUI->objectName().isEmpty())
            Create_Game_GUI->setObjectName(QString::fromUtf8("Create_Game_GUI"));
        Create_Game_GUI->resize(800, 600);
        pushButton = new QPushButton(Create_Game_GUI);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 270, 221, 41));
        comboBox_4 = new QComboBox(Create_Game_GUI);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(300, 150, 111, 22));
        label = new QLabel(Create_Game_GUI);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(440, 30, 55, 16));
        label_4 = new QLabel(Create_Game_GUI);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 150, 61, 16));
        pushButton_2 = new QPushButton(Create_Game_GUI);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(380, 270, 221, 41));
        label_5 = new QLabel(Create_Game_GUI);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(170, 90, 101, 16));
        pushButton_5 = new QPushButton(Create_Game_GUI);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(660, 20, 101, 31));
        comboBox = new QComboBox(Create_Game_GUI);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(140, 150, 111, 22));
        label_3 = new QLabel(Create_Game_GUI);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(590, 10, 51, 41));
        label_6 = new QLabel(Create_Game_GUI);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(310, 90, 101, 16));
        label_2 = new QLabel(Create_Game_GUI);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(510, 30, 55, 16));

        retranslateUi(Create_Game_GUI);

        QMetaObject::connectSlotsByName(Create_Game_GUI);
    } // setupUi

    void retranslateUi(QDialog *Create_Game_GUI)
    {
        Create_Game_GUI->setWindowTitle(QCoreApplication::translate("Create_Game_GUI", "Create_Game_GUI", nullptr));
        pushButton->setText(QCoreApplication::translate("Create_Game_GUI", "Return to menu", nullptr));
        label->setText(QCoreApplication::translate("Create_Game_GUI", "User:", nullptr));
        label_4->setText(QCoreApplication::translate("Create_Game_GUI", "2nd player", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Create_Game_GUI", "Start game", nullptr));
        label_5->setText(QCoreApplication::translate("Create_Game_GUI", "Name", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Create_Game_GUI", "Logout", nullptr));
        label_3->setText(QCoreApplication::translate("Create_Game_GUI", "<avatar>", nullptr));
        label_6->setText(QCoreApplication::translate("Create_Game_GUI", "Difficulty level", nullptr));
        label_2->setText(QCoreApplication::translate("Create_Game_GUI", "<login>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Create_Game_GUI: public Ui_Create_Game_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_GAME_GUI_H
