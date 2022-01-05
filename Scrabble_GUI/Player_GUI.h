#pragma once

#include <QDialog>
#include "ui_Player_GUI.h"
#include "accounts.h"

class Player_GUI : public QDialog
{
	Q_OBJECT

public:
	User* user;
	Player_GUI(QWidget *parent = Q_NULLPTR);
	Player_GUI(User* user, QWidget* parent = Q_NULLPTR);
	~Player_GUI();

private:
	Ui::Player_GUI ui;

private slots:
	void on_pushButton_change_clicked();
private slots:
	void on_pushButton_menu_clicked();
private slots:
	void on_pushButton_logout_clicked();
};
