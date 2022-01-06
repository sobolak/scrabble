#pragma once

#include <QDialog>
#include "ui_History_GUI.h"
#include "accounts.h"

class History_GUI : public QDialog
{
	Q_OBJECT

public:
	User* user;
	vector<Match*>* matchesList;
	History_GUI(QWidget *parent = Q_NULLPTR);
	History_GUI(User* user, QWidget* parent = Q_NULLPTR);
	~History_GUI();

private:
	Ui::History_GUI ui;
private slots:
	void on_pushButton_logout_clicked();
private slots:
	void on_pushButton_return_clicked();
private slots:
	void on_pushButton_replay_clicked();
};
