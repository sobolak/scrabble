#pragma once

#include <QDialog>
#include "ui_Game_GUI.h"
#include "baza.h"

class Game_GUI : public QDialog
{
	Q_OBJECT

public:
	Game_GUI(QWidget *parent = Q_NULLPTR);
	~Game_GUI();
	gameMap gameMap1;
	player mufasa;

private:
	Ui::Game_GUI ui;
	void refreshGameMap();
private slots:
	void on_pushButton_add_clicked();
private slots:
	void on_pushButton_change_clicked();
};
