#pragma once

#include <QDialog>
#include "ui_Results_GUI.h"
#include "accounts.h"

class Results_GUI : public QDialog
{
	Q_OBJECT

public:
	User* user;
	Results_GUI(QWidget* parent = Q_NULLPTR);
	Results_GUI(User* user, User* estebanUser, User* zeromskiUser, User* rokokoUser, Match* match, QWidget* parent = Q_NULLPTR);
	~Results_GUI();

private:
	Ui::Results_GUI ui;
private slots:
	void on_pushButton_continue_clicked();
};
