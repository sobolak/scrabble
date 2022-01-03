#pragma once

#include <QDialog>
#include <QTimeEdit>
#include <QTimer>
#include "ui_Game_GUI_2.h"
#include <random>
#include <string>
#include "time.h"
#include "accounts.h"
#include "baza.h"

class Game_GUI_2 : public QDialog
{
	Q_OBJECT

public:
	Game_GUI_2(QWidget *parent = Q_NULLPTR);
	Game_GUI_2(User* user, User* user2, QWidget* parent = Q_NULLPTR);
	~Game_GUI_2();
	User* user;
	User* user2;
	Match* match;
	QTimer timer;
	gameMap gameMap1;
	player mufasa;
	player esteban;
	short int passCounter;

private:
	Ui::Game_GUI_2 ui;
	void refreshGameMap();
	void playerMove(player& player, char c);
	void playerLetterRefresh(char c);
	void gatherLetterToChange_1(player& playerGane , char c);
	void privacyBoard(char c); 
	void mufasaTimer();
private slots:
	void on_mufasaAdd_clicked();
private slots:
	void on_estebanAdd_clicked();
private slots:
	void on_mufasaChange_clicked();
private slots:
	void on_estebanChange_clicked();
private slots:
	void on_mufasaPass_clicked();
private slots:
	void on_estebanPass_clicked();
private slots:
	void on_pushButton_end_clicked();
};
