/********************************************************************************
** Form generated from reading UI file 'Scrabble_GUI.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCRABBLE_GUI_H
#define UI_SCRABBLE_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Scrabble_GUIClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Scrabble_GUIClass)
    {
        if (Scrabble_GUIClass->objectName().isEmpty())
            Scrabble_GUIClass->setObjectName(QString::fromUtf8("Scrabble_GUIClass"));
        Scrabble_GUIClass->resize(800, 600);
        centralWidget = new QWidget(Scrabble_GUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(225, 100, 350, 50));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 250, 200, 50));
        Scrabble_GUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Scrabble_GUIClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 22));
        Scrabble_GUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Scrabble_GUIClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Scrabble_GUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Scrabble_GUIClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Scrabble_GUIClass->setStatusBar(statusBar);

        retranslateUi(Scrabble_GUIClass);
        QObject::connect(pushButton, &QPushButton::clicked, Scrabble_GUIClass, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(Scrabble_GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *Scrabble_GUIClass)
    {
        Scrabble_GUIClass->setWindowTitle(QCoreApplication::translate("Scrabble_GUIClass", "Scrabble_GUI", nullptr));
        label->setText(QCoreApplication::translate("Scrabble_GUIClass", "Grafika scrabbli widzowie :)", nullptr));
        pushButton->setText(QCoreApplication::translate("Scrabble_GUIClass", "Ahoj przygodo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Scrabble_GUIClass: public Ui_Scrabble_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCRABBLE_GUI_H
