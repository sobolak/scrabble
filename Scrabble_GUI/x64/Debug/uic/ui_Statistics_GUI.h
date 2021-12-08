/********************************************************************************
** Form generated from reading UI file 'Statistics_GUI.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICS_GUI_H
#define UI_STATISTICS_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Statistics_GUI
{
public:
    QPushButton *pushButton_logout;
    QPushButton *pushButton_return;
    QTableWidget *tableWidget_stats;
    QLabel *label_name;

    void setupUi(QDialog *Statistics_GUI)
    {
        if (Statistics_GUI->objectName().isEmpty())
            Statistics_GUI->setObjectName(QString::fromUtf8("Statistics_GUI"));
        Statistics_GUI->resize(803, 600);
        pushButton_logout = new QPushButton(Statistics_GUI);
        pushButton_logout->setObjectName(QString::fromUtf8("pushButton_logout"));
        pushButton_logout->setGeometry(QRect(700, 10, 75, 24));
        pushButton_return = new QPushButton(Statistics_GUI);
        pushButton_return->setObjectName(QString::fromUtf8("pushButton_return"));
        pushButton_return->setGeometry(QRect(270, 460, 231, 91));
        tableWidget_stats = new QTableWidget(Statistics_GUI);
        if (tableWidget_stats->columnCount() < 1)
            tableWidget_stats->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_stats->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget_stats->rowCount() < 10)
            tableWidget_stats->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_stats->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_stats->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_stats->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_stats->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_stats->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_stats->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_stats->setVerticalHeaderItem(6, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_stats->setVerticalHeaderItem(7, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_stats->setVerticalHeaderItem(8, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_stats->setVerticalHeaderItem(9, __qtablewidgetitem10);
        tableWidget_stats->setObjectName(QString::fromUtf8("tableWidget_stats"));
        tableWidget_stats->setGeometry(QRect(250, 70, 281, 331));
        tableWidget_stats->setAutoScrollMargin(16);
        tableWidget_stats->setShowGrid(true);
        tableWidget_stats->setWordWrap(true);
        tableWidget_stats->horizontalHeader()->setMinimumSectionSize(32);
        label_name = new QLabel(Statistics_GUI);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(600, 20, 49, 16));

        retranslateUi(Statistics_GUI);

        QMetaObject::connectSlotsByName(Statistics_GUI);
    } // setupUi

    void retranslateUi(QDialog *Statistics_GUI)
    {
        Statistics_GUI->setWindowTitle(QCoreApplication::translate("Statistics_GUI", "Statistics_GUI", nullptr));
        pushButton_logout->setText(QCoreApplication::translate("Statistics_GUI", "Logout", nullptr));
        pushButton_return->setText(QCoreApplication::translate("Statistics_GUI", "Return to menu", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_stats->verticalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Statistics_GUI", "Ilo\305\233\304\207 rozegranych meczy", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_stats->verticalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Statistics_GUI", "Ilo\305\233\304\207 wygranych meczy", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_stats->verticalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Statistics_GUI", "% wygranych meczy", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_stats->verticalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Statistics_GUI", "Ilo\305\233\304\207 przegranych meczy", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_stats->verticalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Statistics_GUI", "% przegranych meczy", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_stats->verticalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Statistics_GUI", "Ilo\305\233\304\207 wygranych pod rz\304\205d", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_stats->verticalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Statistics_GUI", "Max ilo\305\233\304\207 wygranych pod rz\304\205d", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_stats->verticalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Statistics_GUI", "Ilo\305\233\304\207 u\305\202o\305\274onych s\305\202\303\263w", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_stats->verticalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Statistics_GUI", "\305\232rednio liter na s\305\202owo", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_stats->verticalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Statistics_GUI", "\305\232rednio punkt\303\263w na s\305\202owo", nullptr));
        label_name->setText(QCoreApplication::translate("Statistics_GUI", "Name :)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Statistics_GUI: public Ui_Statistics_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICS_GUI_H
