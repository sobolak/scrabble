#pragma once

#include <QDialog>
#include "ui_Menu_GUI.h"
#include "accounts.h"

class Menu_GUI : public QDialog
{
	Q_OBJECT

public:
	User* user;
	Menu_GUI(QWidget* parent = Q_NULLPTR);
	Menu_GUI(User* user, QWidget* parent = Q_NULLPTR);
	~Menu_GUI();

private:
	Ui::Menu_GUI ui;
private slots:
	void on_pushButton_play_clicked();
private slots:
	void on_pushButton_logout_clicked();
private slots:
	void on_pushButton_statistics_clicked();
	//private slots:
	//	void on_pushButton_settings_clicked();
};