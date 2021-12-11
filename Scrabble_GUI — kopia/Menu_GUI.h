#pragma once

#include <QDialog>
#include "ui_Menu_GUI.h"

class Menu_GUI : public QDialog
{
	Q_OBJECT

public:
	Menu_GUI(QWidget *parent = Q_NULLPTR);
	~Menu_GUI();

private:
	Ui::Menu_GUI ui;
private slots:
	void on_pushButton_play_clicked();
private slots:
	void on_pushButton_logout_clicked();
private slots:
	void on_pushButton_ranking_clicked();
};
