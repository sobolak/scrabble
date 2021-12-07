/********************************************************************************
** Form generated from reading UI file 'Logging_GUI.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGGING_GUI_H
#define UI_LOGGING_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Logging_GUI
{
public:
    QLabel *label_registration;
    QPushButton *pushButton_login;
    QLabel *label_logging;
    QLabel *label_reg_login;
    QLabel *label_login;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_reg_password;
    QLineEdit *lineEdit_reg_login;
    QLineEdit *lineEdit_confirm_password;
    QLineEdit *lineEdit_login;
    QLabel *label_confirm_password;
    QLabel *label_password;
    QLabel *label_reg_password;
    QPushButton *pushButton_register;

    void setupUi(QWidget *Logging_GUI)
    {
        if (Logging_GUI->objectName().isEmpty())
            Logging_GUI->setObjectName(QString::fromUtf8("Logging_GUI"));
        Logging_GUI->resize(800, 600);
        label_registration = new QLabel(Logging_GUI);
        label_registration->setObjectName(QString::fromUtf8("label_registration"));
        label_registration->setGeometry(QRect(490, 100, 281, 61));
        pushButton_login = new QPushButton(Logging_GUI);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        pushButton_login->setGeometry(QRect(60, 310, 121, 31));
        label_logging = new QLabel(Logging_GUI);
        label_logging->setObjectName(QString::fromUtf8("label_logging"));
        label_logging->setGeometry(QRect(20, 100, 341, 61));
        label_reg_login = new QLabel(Logging_GUI);
        label_reg_login->setObjectName(QString::fromUtf8("label_reg_login"));
        label_reg_login->setGeometry(QRect(520, 190, 55, 16));
        label_login = new QLabel(Logging_GUI);
        label_login->setObjectName(QString::fromUtf8("label_login"));
        label_login->setGeometry(QRect(20, 190, 55, 16));
        lineEdit_password = new QLineEdit(Logging_GUI);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(80, 230, 113, 22));
        lineEdit_reg_password = new QLineEdit(Logging_GUI);
        lineEdit_reg_password->setObjectName(QString::fromUtf8("lineEdit_reg_password"));
        lineEdit_reg_password->setGeometry(QRect(580, 220, 113, 22));
        lineEdit_reg_login = new QLineEdit(Logging_GUI);
        lineEdit_reg_login->setObjectName(QString::fromUtf8("lineEdit_reg_login"));
        lineEdit_reg_login->setGeometry(QRect(580, 190, 113, 22));
        lineEdit_confirm_password = new QLineEdit(Logging_GUI);
        lineEdit_confirm_password->setObjectName(QString::fromUtf8("lineEdit_confirm_password"));
        lineEdit_confirm_password->setGeometry(QRect(580, 260, 113, 22));
        lineEdit_login = new QLineEdit(Logging_GUI);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));
        lineEdit_login->setGeometry(QRect(80, 190, 113, 22));
        label_confirm_password = new QLabel(Logging_GUI);
        label_confirm_password->setObjectName(QString::fromUtf8("label_confirm_password"));
        label_confirm_password->setGeometry(QRect(460, 260, 101, 20));
        label_password = new QLabel(Logging_GUI);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setGeometry(QRect(20, 230, 55, 16));
        label_reg_password = new QLabel(Logging_GUI);
        label_reg_password->setObjectName(QString::fromUtf8("label_reg_password"));
        label_reg_password->setGeometry(QRect(520, 230, 55, 16));
        pushButton_register = new QPushButton(Logging_GUI);
        pushButton_register->setObjectName(QString::fromUtf8("pushButton_register"));
        pushButton_register->setGeometry(QRect(560, 320, 131, 31));

        retranslateUi(Logging_GUI);

        QMetaObject::connectSlotsByName(Logging_GUI);
    } // setupUi

    void retranslateUi(QWidget *Logging_GUI)
    {
        Logging_GUI->setWindowTitle(QCoreApplication::translate("Logging_GUI", "Logging_GUI", nullptr));
        label_registration->setText(QCoreApplication::translate("Logging_GUI", "<html><head/><body><p><span style=\" font-size:14pt;\">Registration</span></p></body></html>", nullptr));
        pushButton_login->setText(QCoreApplication::translate("Logging_GUI", "Login", nullptr));
        label_logging->setText(QCoreApplication::translate("Logging_GUI", "<html><head/><body><p><span style=\" font-size:14pt;\">Logging</span></p></body></html>", nullptr));
        label_reg_login->setText(QCoreApplication::translate("Logging_GUI", "Login:", nullptr));
        label_login->setText(QCoreApplication::translate("Logging_GUI", "Login:", nullptr));
        label_confirm_password->setText(QCoreApplication::translate("Logging_GUI", "Confirm password:", nullptr));
        label_password->setText(QCoreApplication::translate("Logging_GUI", "Password:", nullptr));
        label_reg_password->setText(QCoreApplication::translate("Logging_GUI", "Password:", nullptr));
        pushButton_register->setText(QCoreApplication::translate("Logging_GUI", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Logging_GUI: public Ui_Logging_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGGING_GUI_H
