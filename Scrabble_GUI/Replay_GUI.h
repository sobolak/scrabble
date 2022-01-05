#pragma once

#include <QDialog>
#include "ui_Replay_GUI.h"
#include "accounts.h"
#include <map>

using std::map;

class Replay_GUI : public QDialog
{
	Q_OBJECT

public:
	User* user;
	vector<Move*>* movesList;
	map<string, int> logins;
	Replay_GUI(QWidget *parent = Q_NULLPTR);
	Replay_GUI(User* user, int matchID, QWidget* parent = Q_NULLPTR);
	~Replay_GUI();

private:
	Ui::Replay_GUI ui;
private slots:
	void on_pushButton_return_clicked();
private slots:
	void on_pushButton_continue_clicked();
};
