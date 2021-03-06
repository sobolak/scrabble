#pragma once

#include <QDialog>
#include "ui_Game_GUI.h"
#include "accounts.h"
#include "baza.h"


class Game_GUI : public QDialog
{
	Q_OBJECT

public:
	User* user;
	User* userComputer;
	Match* match;
	Game_GUI(QWidget *parent = Q_NULLPTR);
	Game_GUI(User* user, User* userComputer, QWidget* parent = Q_NULLPTR);
	~Game_GUI();
	gameMap gameMap1;
	player mufasa;
	short int passCounter;

private:
	Ui::Game_GUI ui;
	void refreshGameMap();
	void playerMove(player &player);
	void playerLetterRefresh(player player);
	void changeCurrentPlayer(player playerPlay);
	void gatherLetterToChange_1(player& playerGane);
private slots:
	void on_pushButton_add_clicked();
private slots:
	void on_pushButton_change_clicked();
private slots:
	void on_pushButton_pass_clicked();
private slots:
	void on_pushButton_end_clicked();
};
