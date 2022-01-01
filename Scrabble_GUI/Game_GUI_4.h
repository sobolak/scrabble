#pragma once

#include <QDialog>
#include "ui_Game_GUI_4.h"
#include <random>
#include <string>
#include "accounts.h"
#include "baza.h"

class Game_GUI_4 : public QDialog
{
	Q_OBJECT

public:
	Game_GUI_4(QWidget *parent = Q_NULLPTR);
	Game_GUI_4(User* user, User* user2, User* user3, User* user4, QWidget* parent = Q_NULLPTR);
	~Game_GUI_4();
	User* user;
	User* user2;
	User* user3;
	User* user4;
	Match* match;
	gameMap gameMap1;
	player mufasa;
	player esteban;
	player zeromski;
	player rokoko;

private:
	Ui::Game_GUI_4 ui;
	void refreshGameMap();
	void playerMove(player& player, char c);
	void playerLetterRefresh(char c);
	void gatherLetterToChange_1(player& playerGane , char c);
	void privacyBoard(char c);
private slots:
	void on_mufasaAdd_clicked();
private slots:
	void on_estebanAdd_clicked();
private slots:
	void on_zeromskiAdd_clicked();
private slots:
	void on_rokokoAdd_clicked();
private slots:
	void on_mufasaChange_clicked();
private slots:
	void on_estebanChange_clicked();
private slots:
	void on_zeromskiChange_clicked();
private slots:
	void on_rokokoChange_clicked();
private slots:
	void on_mufasaPass_clicked();
private slots:
	void on_estebanPass_clicked();
private slots:
	void on_zeromskiPass_clicked();
private slots:
	void on_rokokoPass_clicked();
};
