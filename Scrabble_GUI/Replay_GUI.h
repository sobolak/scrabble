#pragma once

#include <QDialog>
#include "ui_Replay_GUI.h"
#include "accounts.h"

class Replay_GUI : public QDialog
{
	Q_OBJECT

public:
	User* user;
	Replay_GUI(QWidget *parent = Q_NULLPTR);
	Replay_GUI(User* user, QWidget* parent = Q_NULLPTR);
	~Replay_GUI();

private:
	Ui::Replay_GUI ui;
private slots:
	void on_pushButton_return_clicked();
//private slots:
//	void on_pushButton_continue_clicked();
};
