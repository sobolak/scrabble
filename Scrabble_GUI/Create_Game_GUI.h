#pragma once

#include <QDialog>
#include "ui_Create_Game_GUI.h"
#include "accounts.h"

class Create_Game_GUI : public QDialog
{
	Q_OBJECT

public:
	User* user;

	Create_Game_GUI(QWidget *parent = Q_NULLPTR);
	Create_Game_GUI(User* user, QWidget *parent = Q_NULLPTR);
	~Create_Game_GUI();

private:
	Ui::Create_Game_GUI ui;
private slots:
	void on_pushButton_start_clicked();
private slots:
	void on_pushButton_return_clicked();
private slots:
	void on_pushButton_logout_clicked();
private slots:
	void on_radioButton_computer_clicked();
private slots:
	void on_radioButton_second_clicked();
private slots:
	void on_radioButton_third_clicked();
private slots:
	void on_radioButton_forth_clicked();

};
