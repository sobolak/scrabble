#pragma once

#include <QDialog>
#include "ui_Player_GUI.h"

class Player_GUI : public QDialog
{
	Q_OBJECT

public:
	Player_GUI(QWidget *parent = Q_NULLPTR);
	~Player_GUI();

private:
	Ui::Player_GUI ui;

//private slots:
//	void on_pushButton_change_clicked();
private slots:
	void on_pushButton_menu_clicked();
};
